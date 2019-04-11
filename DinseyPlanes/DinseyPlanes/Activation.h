#pragma once
#include "pch.h"
#include <iostream>
#include "ConsoleWindow.h"
#include <math.h>
#include <time.h>
#include "Vector2.h"
#include "Board.h"
#include <stdlib.h> 
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <fstream>
#include "AI.h"
#include "Settings.h"
#include "PhysicsObject.h"
#include "RigidBody.h"
#include "BackgroundObj.h"
#include "Background.h"
#include "Characters.h"
#include "Artwork.h"
#include "AssetsClass.h"
#include "CustomAsset.h"
#include "CustomAnimationAsset.h"
#include "Defaults.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include "SYDEWindowGame.h"
using namespace std;
using namespace Gdiplus;

class Activation{
public:
	Activation() {}
	virtual ~Activation() {}

	//DRAW
	static ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight);
	static void inputVoids(int windowWidth, int windowHeight);
	static bool GetKey(char KeyCode);

private:
	static bool _setUp;
};