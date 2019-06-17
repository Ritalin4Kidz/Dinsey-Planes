#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h> 
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include "SYDEstdafx.h"
#include <sstream>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
//COLOUR
enum LANGUAGE {
	ENGLISH = 'E',
	PLANE = 'P'
};
class GlobalSettings {
public:
	static std::string _SCENE;
	static std::string _LASTSCENE;
	static std::string _LEVEL;
	static std::string FillStr;
	static std::string _PLANEFLAVOUR;

	static int FrameDelay_MS;
	static int VolumeLVL;

	static bool PauseMode;
	static bool debugMenu;
	static bool initWindow;
	static bool rs;
	static bool GamePlaying;
	static bool letsplayer;
	static bool framerate;

	// Unlocks
	static bool _PEARLHARBOURBEATEN;
	static bool _HIROSHIMABEATEN;
	static bool _NAGASAKIBEATEN;
	//CHARACTER UNLOCKS
	static bool _SEMICOLON_UNLOCK;
	static bool _TSUBUMMER_UNLOCK;
	static bool _RIPPERONI_UNLOCK;

	static enum LANGUAGE _GAME_LNG;

	static SYDELabel m_fps;
	static CustomAnimationAsset m_LP;
};