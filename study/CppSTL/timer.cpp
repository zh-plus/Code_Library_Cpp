//
// Created by 10578 on 11/20/2019.
//

#include <iostream>
#include <chrono>
#include <vector>

typedef std::chrono::high_resolution_clock hr_clock;

class Timer {
public:

	static void tic();

	static void print_duration() {
		std::cout << "Time elapsed: "
		          << duration.count()
		          << " microseconds" << std::endl;
	}

	static void toc();

private:
	static hr_clock::time_point start;
	static hr_clock::time_point end;
	static hr_clock::duration duration;
};

//TODO: implement Timer with static members
//hr_clock::time_point Timer::start = hr_clock::now();
//hr_clock::time_point Timer::end = hr_clock::now();
//hr_clock::time_point Timer::duration = std::chrono::duration_cast<std::chrono::microseconds>(Timer::end - Timer::start);

void Timer::tic() {
	Timer::start = hr_clock::now();
}

void Timer::toc() {
	Timer::end = hr_clock::now();
	Timer::duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	print_duration();
}

int main() {
	Timer::tic();
	std::vector<int>(1001, 1);
	Timer::toc();
}