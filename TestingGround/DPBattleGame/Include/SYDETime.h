#pragma once

#include <chrono>

class SYDETIME {
public:
	 void initialise(std::chrono::high_resolution_clock::time_point time);
	 float getDeltaTime() { return deltaTime; }
	 void refreshTime();
private:
	std::chrono::high_resolution_clock::time_point timeprev;
	float deltaTime;
};
