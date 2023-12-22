#include <Siv3D.hpp> 
#include <random>

void Main()
{
	trrne::scene_setting(Palette::Darkcyan, trrne::config::inits::window_size);
	auto font30 = trrne::make_font(30);

	auto background = trrne::Background(500);
	auto player = trrne::Player(100, 350, Vec2(160, Scene::Center().y));
	auto rocket = trrne::Rocket(20, 0.2, 1500.0);

	auto player_teleporter = trrne::Teleporter(&player.position);
	player_teleporter.teleport(Scene::CenterF());

	while (System::Update()) {
		player.update();
		rocket.shot();
		rocket.reload();
		background.update();

		player.draw();
		rocket.update(player.position);
		background.draw();

#if _DEBUG
		const Color font_color = Palette::Antiquewhite;

		// マウスの座標
		font30(U"mouse: {}"_fmt(Cursor::Pos())).draw(0, font30.fontSize() * 0, font_color);
		trrne::make_circle(Cursor::Pos(), 30).draw(ColorF(Palette::Green, 0.5));

		// プレイヤーの座標
		font30(U"x: {}"_fmt(player.position.x)).draw(0, font30.fontSize() * 1, font_color);
		font30(U"y: {}"_fmt(player.position.y)).draw(0, font30.fontSize() * 2, font_color);

		font30(U"bullets: {}"_fmt(rocket.get_remain())).draw(0, font30.fontSize() * 4, font_color);
#endif
	}
}
