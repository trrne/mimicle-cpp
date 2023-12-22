#pragma once
#include <vector>

using namespace std;

namespace trrne
{
	class Background
	{
	private:
		const int CORE = 2;
		Array<s3d::Vec2> poses;
		Array<s3d::TextureRegion> backs;
		Array<s3d::Color> colors;

		//vector<s3d::Vec2> poses2;
		//vector<s3d::TextureRegion> backs2;
		//vector<s3d::Color> colors2;

		double speed;

		const double UPSCALE_RATIO = 1.1;
		const s3d::Vec2 INIT_POSITION{ 1280, 0 };
		const double RETURN_POINT = Scene::Width() * -UPSCALE_RATIO;

		bool scrollable = true;

	public:
		Background(double speed) : speed(speed) {
			for (int i = 0; i < CORE; ++i) {
				poses.push_back(INIT_POSITION * s3d::Vec2::One() * i);
				backs.push_back(Texture(config::paths::background).resized(Scene::Size() * UPSCALE_RATIO));
				colors.push_back(RandomColorF());
			}
		}

		void update() {
			for (int i = 0; i < CORE; ++i) {
				backs[i].draw(poses[i], colors[i]);
				if (poses[i].x <= RETURN_POINT) {
					colors[i] = RandomColorF();
					poses[i] = INIT_POSITION;
				}
			}
		}

		void draw() {
			if (!scrollable) {
				return;
			}

			for (int i = 0; i < CORE; ++i) {
				poses[i] += s3d::Vec2(-1, 0) * speed * Scene::DeltaTime();
			}
		}
	};
}
