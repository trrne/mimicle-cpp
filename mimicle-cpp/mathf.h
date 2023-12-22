#pragma once

#include <math.h>
using namespace std;

namespace trrne
{
	class mathf
	{
	public:
		static double floor(double $a)
		{
			return $a < (long)$a ? (long)($a - 1.0) : (long)$a;
		}

		static double round(double $a, int $digit)
		{
			return floorf((powf($a * 10, $digit) * 2 + 1) / 2) / powf(10, $digit);
		}
	};
}
