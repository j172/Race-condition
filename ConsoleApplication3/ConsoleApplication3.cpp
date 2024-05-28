// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>

int counter = 100000;
std::mutex mtx;

void incrementCounter() {
	for (int i = 0; i < 100000; ++i) {
		std::lock_guard<std::mutex> lock(mtx);
		counter++;
	}
}

void decrementCounter() {
	for (int i = 0; i < 100000; ++i) {
		std::lock_guard<std::mutex> lock(mtx);
		counter--;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::thread t1(incrementCounter);
	std::thread t2(decrementCounter);

	t1.join();
	t2.join();

	std::cout << "Final counter value: " << counter << std::endl;

	return 0;
}

