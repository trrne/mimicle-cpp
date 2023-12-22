#pragma once

namespace trrne {
	class Player {
	private:
		HP hp;
		double speed;
		bool controllable;
		Texture tex;
		TextureRegion texture_region;

		s3d::Vec2 pre_pos;

	public:
		s3d::Vec2 position;
		Player(int max_hp, double speed, s3d::Vec2 init_position)
			: position(init_position),
			controllable(true),
			speed(speed)
		{
			hp = HP(max_hp);
			pre_pos = position;

			tex = Texture(config::paths::player);
			texture_region = tex.resized(100).mirrored();
		}

		void update() {
			if (!controllable) {
				return;
			}

			s3d::Vec2 axis = inputs::axis().normalize();
			position += Scene::DeltaTime() * speed * axis;
		}

		void draw() {
			texture_region.drawAt(position);
		}

		bool get_controllable() {
			return controllable;
		}

		void set_controllable(const bool $bool) {
			controllable = $bool;
		}

		s3d::Vec2 get_velocity() {
			// 速度取得 https://nekojara.city/unity-object-velocity
			s3d::Vec2 _pos = position,
				v = (_pos - pre_pos) / Scene::DeltaTime();
			pre_pos = position;
			return s3d::Vec2(std::floor(v.x), std::floor(v.y));
		}
	};
}
