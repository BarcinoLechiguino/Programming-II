#include <iostream>
#include <math.h>


class Pixel {

private:
	short int red;
	short int green;
	short int blue;

public:
	Pixel() : red(0), green(0), blue(0) {}

	Pixel(short int red, short int green, short int blue) : red(red), green(green), blue(blue) {}

	Pixel mix(Pixel pixel1) {

		Pixel newP;
		newP.red = (red + pixel1.red) / 2;
		newP.green = (green + pixel1.green) / 2;
		newP.blue = (blue + pixel1.blue) / 2;

		return newP;
	}

	short int Red() const { return red; }
	short int Green() const { return green; }
	short int Blue() const { return blue; }
};

int main() {

	Pixel black;
	Pixel blue(0, 0, 255);
	Pixel red(255, 0, 0);
	Pixel mixed = red.mix(blue);

	std::cout << black.Red() << " " << black.Green() << " " << black.Blue() << std::endl;
	std::cout << mixed.Red() << " " << mixed.Green() << " " << mixed.Blue() << std::endl;
	system("pause");
	return 0;
}


#if 0
class Clock {

private:
	short int hours;
	short int minutes;
	short int seconds;

public:

	Clock() : hours(0), minutes(0), seconds(0) { }

	Clock(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) { }

	short int geth() const { return hours; }
	short int getm() const { return minutes; }
	short int gets() const { return seconds; }

	void equalClocks(Clock clock1, Clock clock2) {

		if (clock1.hours == clock2.hours && clock1.minutes == clock2.minutes && clock1.seconds == clock2.seconds) {

			std::cout << "Clocks are equal" << std::endl;
		}
		else {

			std::cout << "Clocks are not equal" << std::endl;
		}
	}

	void fastClock(Clock clock1, Clock clock2) {

		if (clock1.hours > clock2.hours) {

			std::cout << "Clock1 shows a time after" << std::endl;
		}

		if (clock1.hours < clock2.hours) {

			std::cout << "Clock2 shows a time after" << std::endl;
		}

		if (clock1.hours == clock2.hours) {

			if (clock1.minutes > clock2.minutes) {

				std::cout << "Clock1 shows a time after" << std::endl;
			}

			if (clock1.minutes < clock2.minutes) {

				std::cout << "Clock2 shows a time after" << std::endl;
			}

			if (clock1.minutes == clock2.minutes) {

				if (clock1.seconds > clock2.seconds) {

					std::cout << "Clock1 shows a time after" << std::endl;
				}

				if (clock1.seconds < clock2.seconds) {

					std::cout << "Clock2 shows a time after" << std::endl;
				}

				if (clock1.seconds == clock2.seconds) {

					std::cout << "Clock1 and clock2 have the same time" << std::endl;
				}
			}
		}
	}

	void seth(short int Hours) { hours = Hours; }
	void setm(short int Minutes) { minutes = Minutes; }
	void sets(short int Seconds) { seconds = Seconds; }

	void printTime(Clock clock1, Clock clock2) {

		std::cout << clock1.hours << ":" << clock1.minutes << ":" << clock1.seconds << std::endl;
		std::cout << clock2.hours << ":" << clock2.minutes << ":" << clock2.seconds << std::endl;
	}
};

int main() {

	Clock clock;
	Clock clock1(12, 51, 56);
	Clock clock2(12, 11, 56);

	clock.equalClocks(clock1, clock2);
	clock.fastClock(clock1, clock2);
	clock.printTime(clock1, clock2);

	system("pause");
	return 0;
}
#endif

#if 0
class Vec3 {

public:
	float x;
	float y;
	float z;

	Vec3() : x(0), y(0), z(0) { }
	Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) { }
	Vec3(const Vec3 &v2) { x = v2.x; y = v2.y; z = v2.z; }

	float length() const {

		float vecS = x * x + y * y + z * z;
		float vecF = sqrtf(vecS);

		return vecF;
	}

	
		Vec3 inverse(Vec3 vec) {

		Vec3 invec;
		invec.x = vec.z;
		invec.z = vec.x;

		return invec;
			Vec3 inverse() {
			Vec3 inv(-x, -y, -z);
			return inv;
		}
	};

	std::ostream& operator << (std::ostream &o, const Vec3 &v) {

		return o << v.x << " " << v.y << " " << v.z;
	}

	int dot(const Vec3 &vec1, const Vec3 &vec2) {

		int vecdot = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;

		return vecdot;
	}

	int main() {

		<<<<<< < HEAD
			Vec3 vector;
		Vec3 vector1 = { 9, 8, 2 };
		Vec3 vector2 = { 1, 3, 6 };
		====== =
			Vec3 vector1 = { 2, 2, 2 };
		Vec3 vector2 = { 1, 3, 3 };
		>>>>>> > e64c077ad70fde20aab1380539085e8951f3afa8

			std::cout << "Vector1 length is " << vector1.length() << std::endl;
		std::cout << "Vector2 length is " << vector2.length() << std::endl;

		Vec3 vector3 = vector2.inverse();
		std::cout << vector3 << std::endl;

		std::cout << "Vectors' dot product is " << dot(vector1, vector2) << std::endl;

		system("pause");
		return 0;
	}

#endif

#if 0
	class Module {

	private:

		const char *name;
		int numIterations;

	public:
		Module(const char *nm, int iterations) :

			name(nm),
			numIterations(iterations)
		{}

		void update(int currentIteration) {

			if (currentIteration < numIterations) {

				std::cout << name << std::endl;
			}
		}
	};

	int main() {

		Module modules[3] = {
			Module("Input", 5),
			Module("Render", 7),
			Module("Logic", 10)

		};

		for (int i = 0; i < 10; i++) {

			std::cout << "--Iteration: " << i << std::endl;

			for (int j = 0; j < 3; j++) {

				modules[j].update(i);
			}

			std::cout << std::endl;
		}

		system("pause");
		return 0;
	}
#endif