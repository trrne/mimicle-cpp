#pragma once

using namespace s3d::detail;

namespace trrne
{
	class inputs
	{
	private:
		XInput_impl xi = XInput(0);

	public:
		enum class GET
		{
			BOTH,
			ARROW,
			WASD
		};

		enum class TYPE
		{
			UP = 0,
			PRESSED = 1,
			DOWN = 2
		};

		enum class INDEX
		{
			UP = 0,		// W, A
			LEFT = 1,	// A, B
			BOTTOM = 2, // S, X
			RIGHT = 3	// D, Y
		};

		enum class LR
		{
			LEFT,
			RIGHT
		};

		int index;
		double play;

		bool aio[4];
		bool keyboard[4];
		bool arrow[4];

		double triggers[2];
		bool button[4];

		inputs(int $index = 0, double $play = 0.8)
			: xi($index), index($index), play($play),
			aio(), keyboard(), arrow(), triggers(), button()
		{}

		s3d::Vec2 stick(LR $index)
		{
			switch ($index)
			{
			case LR::LEFT:
				return s3d::Vec2(xi.leftThumbX, xi.leftThumbY);
			case LR::RIGHT:
				return s3d::Vec2(xi.rightThumbX, xi.rightThumbY);
			default:
				return s3d::Vec2::Zero();
			}
		}

		void update(TYPE $type)
		{
			switch ($type)
			{
			case TYPE::UP:
				aio[(int)INDEX::UP] = (KeyUp | KeyW | xi.buttonUp).pressed() || stick(LR::LEFT).y > play;
				aio[(int)INDEX::LEFT] = (KeyLeft | KeyA | xi.buttonLeft).pressed() || stick(LR::LEFT).x < -play;
				aio[(int)INDEX::BOTTOM] = (KeyDown | KeyS | xi.buttonDown).pressed() || stick(LR::LEFT).y < -play;
				aio[(int)INDEX::RIGHT] = (KeyRight | KeyD | xi.buttonRight).pressed() || stick(LR::LEFT).x > play;
				keyboard[(int)INDEX::UP] = KeyW.pressed();
				keyboard[(int)INDEX::LEFT] = KeyA.pressed();
				keyboard[(int)INDEX::BOTTOM] = KeyS.pressed();
				keyboard[(int)INDEX::RIGHT] = KeyD.pressed();
				arrow[(int)INDEX::UP] = KeyUp.pressed();
				arrow[(int)INDEX::LEFT] = KeyLeft.pressed();
				arrow[(int)INDEX::BOTTOM] = KeyDown.pressed();
				arrow[(int)INDEX::RIGHT] = KeyRight.pressed();
				button[(int)INDEX::UP] = xi.buttonA.pressed();
				button[(int)INDEX::LEFT] = xi.buttonB.pressed();
				button[(int)INDEX::BOTTOM] = xi.buttonX.pressed();
				button[(int)INDEX::RIGHT] = xi.buttonY.pressed();
				break;
			case TYPE::PRESSED:
				aio[(int)INDEX::UP] = (KeyUp | KeyW | xi.buttonUp).up() || stick(LR::LEFT).y > play;
				aio[(int)INDEX::LEFT] = (KeyLeft | KeyA | xi.buttonLeft).up() || stick(LR::LEFT).x < -play;
				aio[(int)INDEX::BOTTOM] = (KeyDown | KeyS | xi.buttonDown).up() || stick(LR::LEFT).y < -play;
				aio[(int)INDEX::RIGHT] = (KeyRight | KeyD | xi.buttonRight).up() || stick(LR::LEFT).x > play;
				keyboard[(int)INDEX::UP] = KeyW.up();
				keyboard[(int)INDEX::LEFT] = KeyA.up();
				keyboard[(int)INDEX::BOTTOM] = KeyS.up();
				keyboard[(int)INDEX::RIGHT] = KeyD.up();
				arrow[(int)INDEX::UP] = KeyUp.up();
				arrow[(int)INDEX::LEFT] = KeyLeft.up();
				arrow[(int)INDEX::BOTTOM] = KeyDown.up();
				arrow[(int)INDEX::RIGHT] = KeyRight.up();
				button[(int)INDEX::UP] = xi.buttonA.up();
				button[(int)INDEX::LEFT] = xi.buttonB.up();
				button[(int)INDEX::BOTTOM] = xi.buttonX.up();
				button[(int)INDEX::RIGHT] = xi.buttonY.up();
				break;
			case TYPE::DOWN:
				aio[(int)INDEX::UP] = (KeyUp | KeyW | xi.buttonUp).down() || stick(LR::LEFT).y > play;
				aio[(int)INDEX::LEFT] = (KeyLeft | KeyA | xi.buttonLeft).down() || stick(LR::LEFT).x < -play;
				aio[(int)INDEX::BOTTOM] = (KeyDown | KeyS | xi.buttonDown).down() || stick(LR::LEFT).y < -play;
				aio[(int)INDEX::RIGHT] = (KeyRight | KeyD | xi.buttonRight).down() || stick(LR::LEFT).x > play;
				keyboard[(int)INDEX::UP] = KeyW.down();
				keyboard[(int)INDEX::LEFT] = KeyA.down();
				keyboard[(int)INDEX::BOTTOM] = KeyS.down();
				keyboard[(int)INDEX::RIGHT] = KeyD.down();
				arrow[(int)INDEX::UP] = KeyUp.down();
				arrow[(int)INDEX::LEFT] = KeyLeft.down();
				arrow[(int)INDEX::BOTTOM] = KeyDown.down();
				arrow[(int)INDEX::RIGHT] = KeyRight.down();
				button[(int)INDEX::UP] = xi.buttonA.down();
				button[(int)INDEX::LEFT] = xi.buttonB.down();
				button[(int)INDEX::BOTTOM] = xi.buttonX.down();
				button[(int)INDEX::RIGHT] = xi.buttonY.down();
				break;
			}
		}

		static double horizontal(s3d::InputGroup $lefts = KeyA | KeyLeft,
			s3d::InputGroup $rights = KeyD | KeyRight)
		{
			if ($rights.pressed())
			{
				return 1;
			}
			if ($lefts.pressed())
			{
				return -1;
			}
			return 0;
		}

		static double vertical(s3d::InputGroup $ups = KeyW | KeyUp,
			s3d::InputGroup $downs = KeyS | KeyDown)
		{
			if ($ups.pressed())
				return -1;
			if ($downs.pressed())
				return 1;
			return 0;
		}

		static s3d::Vec2 axis()
		{
			return s3d::Vec2(horizontal(), vertical());
		}
	};
}
