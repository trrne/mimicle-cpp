#pragma once

namespace trrne
{
	struct Vec2 : s3d::Vec2
	{
	public:
		using s3d::Vec2::Vector2D;

		static double magnitude(s3d::Vec2 $pos)
		{
			return std::sqrt($pos.x * $pos.x + $pos.y * $pos.y);
		}

		static double distance(s3d::Vec2 $a, s3d::Vec2 $b)
		{
			return magnitude($a - $b);
		}

		static s3d::Vec2 floor(s3d::Vec2 $a)
		{
			return s3d::Vec2(std::floor($a.x), std::floor($a.y));
		}
	};
}
