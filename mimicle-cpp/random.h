#pragma once

#include <chrono>

using namespace std;
using chrono::system_clock;

namespace trrne {
	class random {
	public:
		inline static int randint(int $min, int $max) {
			return $min + (int)(rand() * ($max - $min + 1) / (1 + RAND_MAX));
		}

		inline static double randdouble(double $min, double $max) {
			system_clock::duration now = chrono::system_clock::now().time_since_epoch();
			system_clock::rep ns = chrono::duration_cast<chrono::nanoseconds>(now).count();
			mt19937_64 mt64(ns);
			uniform_real_distribution<float> r($min, $max - 1);
			return r(mt64);

		}

		inline static double randdouble(double $max) {
			return randdouble(0, $max);
		}

		template <class T>
		inline static int randchoice(s3d::Array<T> $array) {
			return randint(0, (int)$array.size());
		}

		template <class T>
		inline static T choice(T t[], const int size) {
			return t[randint(size)];
		}

		template <class T>
		inline static T choice(Array<T> t) {
			return t[randint(sizeof(t))];
		}
	};
}
