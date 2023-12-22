#pragma once

namespace trrne
{
	struct config
	{
	public:
		struct inits
		{
		public:
			inline static const s3d::Vec2 window_size = s3d::Vec2(1280, 720);
		};

		struct paths
		{
		public:
			inline static String player = U"player/player.png";
			inline static String bullet = U"player/bullet1.png";
			inline static String background = U"background/background.png";
		};

		struct keys
		{
		public:
			inline static auto shot = KeySpace;
			inline static auto reload = KeyLShift;
		};
	};
}
