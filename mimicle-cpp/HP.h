#pragma once

namespace trrne
{
	class HP
	{
		int max;
		int remain;
	public:
		HP() : max(100), remain(100) {}
		HP(int $max) : max($max), remain($max) { }

		void get_max(int $max)
		{
			max = $max;
			remain = $max;
		}

		int get_max()
		{
			return max;
		}

		int get_remain()
		{
			return remain;
		}

		float get_ratio()
		{
			return (float)remain / (float)max;
		}

		bool is_zero()
		{
			return remain <= 0;
		}

		void healing(int $amount)
		{
			if (Math::Sign($amount) == -1)
			{
				damage($amount);
				return;
			}
			remain += $amount;
			remain = std::clamp(remain, 0, max);
			if (remain > max)
				remain = max;
		}

		void damage(int $amount)
		{
			if (Math::Sign($amount) == 1)
			{
				healing($amount);
				return;
			}
			remain -= $amount;
			remain = std::clamp(remain, 0, max);
			if (remain < 0)
				remain = 0;
		}
	};
}

