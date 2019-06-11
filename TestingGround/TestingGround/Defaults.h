#pragma once
#include "Vector2.h"
#include <Windows.h>
class RTWDefaults {
public:
	const static float getJumpPower() { return -3.0f; }
};

static class SYDEDefaults {
public:
	static float deltaTime;
	static void setDeltaTime(float time) { deltaTime = time; }
	static float getDeltaTime() { return deltaTime; }
	static Vector2 v2_Zero;
};

class SYDEFunctions {
public:
	static void SYDESleep(int time, float deltaTime);
};