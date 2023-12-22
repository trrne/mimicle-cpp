#pragma once

namespace trrne
{
	class Rocket
	{
	private:
		int max_stock;
		int remain_stock;

		Stopwatch rapid_sw;
		bool is_reloading = false;
		double rapid_rate;
		double shot_power;

		double reload_time = 1;
		Stopwatch reload_sw;

		s3d::Vec2 pos{ 0, 0 };

		Array<Bullet> bullets;
		std::vector<Bullet> bullets2;

	public:
		Rocket(int $max_stock, double $rapid_rate, double $shot_power)
			: max_stock($max_stock),
			remain_stock($max_stock),
			rapid_rate($rapid_rate),
			shot_power($shot_power)
		{
			rapid_sw.start();
		}

		void set_max_stock(int $value)
		{
			max_stock = $value;
		}

		int get_max() const
		{
			return max_stock;
		}

		int get_remain() const
		{
			return remain_stock;
		}

		double get_ratio() const
		{
			return (double)remain_stock / (double)max_stock;
		}

		void shot()
		{
			if (remain_stock > 0
				&& !is_reloading
				&& rapid_sw.sF() >= rapid_rate
				&& trrne::config::keys::shot.pressed())
			{
				bullets << trrne::Bullet(shot_power, pos);
				--remain_stock;
				rapid_sw.restart();
			}
		}

		void reload()
		{
			if (!is_reloading
				&& remain_stock < max_stock
				&& trrne::config::keys::reload.down())
			{
				is_reloading = true;
				rapid_sw.restart();
			}

			if (is_reloading && rapid_sw.sF() >= reload_time)
			{
				remain_stock = max_stock;
				is_reloading = false;
			}
		}

		void update(s3d::Vec2 $pos)
		{
			pos = $pos;
			for (auto& bullet : bullets)
				bullet.update();
		}
	};

}
