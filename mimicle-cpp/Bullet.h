#pragma once

namespace trrne
{
	class Bullet
	{
	private:
		TextureRegion tex;
		double speed;

		const s3d::Vec2 offset{ 25, -20 };

		s3d::Vec2 pos;
	public:
		Bullet(double $speed, s3d::Vec2 $pos) : speed($speed)
		{
			tex = Texture(config::paths::bullet).mirrored().resized(25);
			pos = $pos + offset;
		}

		void update()
		{
			pos += s3d::Vec2(1, 0) * speed * Scene::DeltaTime();
			tex.draw(pos);
		}

		s3d::Vec2 get_pos()
		{
			return pos;
		}
	};
}
