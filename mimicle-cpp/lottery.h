#pragma once

#include <iostream>
#include <vector>

typedef ll long long;
using ull = unsigned long long;
using namespace std;

namespace trrne
{
	class lottery
	{
	public:
		inline static int bst(double* weights_arr, const int length) {
			if (length < 0) {
				throw exception();
			}

			vector<double> weights;
			for (int i = 0; i < length; ++i) {
				weights.push_back(weights_arr[i]);
			}

			double total = 0.0;
			vector<double> totals;
			for (int i = 0; i < length; ++i) {
				total += weights[i];
				totals.push_back(total);
			}

			double r = random::randdouble(0.0, total);
			int bottom = 0, top = length - 1;
			while (bottom < top) {
				int middle = (bottom + top) / 2;
				if (r > totals[middle]) {
					bottom = middle + 1;
				}
				else {
					if (r >= (middle > 0 ? totals[(ull)middle - 1] : 0.0)) {
						return middle;
					}
					top = middle;
				}
			}
		}
	};
}
