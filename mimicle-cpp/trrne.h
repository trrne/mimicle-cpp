#pragma once 

#include <stdlib.h> 

namespace trrne {
	inline static void scene_setting(Color background, Vec2 size) {
		Scene::SetBackground(background);
		Window::Resize((int)size.x, (int)size.y);
	}

	inline static void scene_setting(Color $bg, int $width, int $height) {
		scene($bg, s3d::Vec2($width, $height));
	}

	inline static Font make_font(
		int size,
		Typeface type = Typeface::Regular,
		FontStyle style = FontStyle::Default
	) {
		return Font(size, type, style);
	}

	inline static Font make_font(int $size, String $path) {
		return Font($size, $path);
	}

	template<class T, size_t N>
	inline static int length(T(&$arr)[N]) {
		return sizeof($arr) / sizeof(T);
	}

	inline static Rect make_rect(s3d::Vec2 $pos, s3d::Vec2 $size) {
		return Rect(
			(Rect::value_type)$pos.x,
			(Rect::value_type)$pos.y,
			(Rect::value_type)$size.x,
			(Rect::value_type)$size.y
		);
	}

	inline static Rect make_rect(s3d::Vec2 $pos, double $width, double $height) {
		return Rect(
			(Rect::value_type)$pos.x,
			(Rect::value_type)$pos.y,
			(Rect::value_type)$width,
			(Rect::value_type)$height
		);
	}

	inline static Circle make_circle(s3d::Vec2 $pos, double $radius) {
		return Circle(
			(Circle::value_type)$pos.x,
			(Circle::value_type)$pos.y,
			(Circle::value_type)$radius
		);
	}

	inline static TextureRegion load_resized_texture(String $path, double $scale) {
		return Texture($path).resized($scale);
	}

	inline static TextureRegion load_resized_texture(String $path, s3d::Vec2 $size) {
		return Texture($path).resized($size);
	}

	template <class BEFORE, class AFTER>
	inline static AFTER cast(BEFORE before) {
		return (AFTER)before;
	}
}
