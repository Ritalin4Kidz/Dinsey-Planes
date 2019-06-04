#include "pch.h"
#include "SYDEstdafx.h"
#include "DinseyPlanes.h"
#include <Windows.h>
#include "DPFunc.h"
#include "DPaint.h"

using namespace std;
using namespace Gdiplus;
//SETTINGS
DWORD VOLUME_LOW = DWORD(858993459);
DWORD VOLUME_NML = DWORD(1717986918);
DWORD VOLUME_MED = DWORD(-1717986918);
DWORD VOLUME_HIG = DWORD(-858993459);
DWORD VOLUME_OFF = DWORD(0);
//INITIALIZING VARIABLES
int windowWidth = 40;
const int windowHeight = 20;
const string dir = "BrainFiles\\";
Settings config("EngineFiles\\Settings\\configSettings.sc");
ConsoleWindow window(windowHeight);
//DRAWING SETTINGS
BackgroundClass bgVars;
Characters charVars;
Artwork artVars;
//OTHER ASSETS
AssetsClass astVars;
//DECLARE CUSTOM ASSETS HERE
CustomAsset testBmp;
CustomAsset fieldTestBmp;
COORD start = { (SHORT)0, (SHORT)0 };
static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
CustomAnimationAsset testAnimation;
//CHEATS
vector<string> cheatCodes;
static ULONG_PTR gdiplusToken;
static GdiplusStartupInput startupInput;

std::string lp_text = "Hey Guys we're playing dinsey planes";
float timeTillNextText = 0.0f;
// MAIN FUNCTION
int main(int argc, char* argv[])
{
	//CUSTOM
	//LetsPlay = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\UI\\letsplayer.bmp", 22, 20));
	//DINSEY PLANES SETTINGS
	DPFunc::Load();
	DPFunc::VolumeFunc(GlobalSettings::VolumeLVL);
	DPFunc::Save();
	//TITLES
	LPCWSTR title = L"Dinsey Planes";
	SYDECredits::_GAMETITLE = "Dinsey Planes";
	SYDECredits::_ORGANISATION = "Callum Hands \nIn Association With Freebee Games";
	bool cheating = false;
	//ARGUMENT SETTINGS
	for (int i = 0; i < argc; i++)
	{
		std::string arg = argv[i];
		if (arg == "--sunset")
		{
			DPFunc::_AQUA.set(255, 166, 106);
		}
		else if (arg == "--debug")
		{
			GlobalSettings::_SCENE = "Debug";
			GlobalSettings::debugMenu = true;
			title = L"Dinsey Planes(Debug)";
		}
		else if (arg == "--nocap")
		{
			GlobalSettings::FrameDelay_MS = 0;
		}
		else if (arg == "--fps")
		{
			GlobalSettings::framerate = true;
		}
		else if (arg == "--initfalse")
		{
			GlobalSettings::initWindow = false;
		}
		else if (arg == "--rs")
		{
			GlobalSettings::rs = true;
		}
		else if (arg == "--paint")
		{
			GlobalSettings::_SCENE = "Paint";
		}
		else if (arg == "--dinsey")
		{
			GlobalSettings::_PLANEFLAVOUR = "Dinsey";
		}
		else if (arg == "--dupty")
		{
			GlobalSettings::_PLANEFLAVOUR = "Dupty";
			title = L"Dupty Planes";
		}
		else if (arg == "--Watch_Me_Xplode")
		{
			cheating = true;
			title = L"Dinsey Planes With A Filthy Cheat";
		}
	}
	//CONSOLE SETTINGS
	DPFunc::ColourPalette(hOut, false, window);
	//SYDE ENGINE SETTINGS
	GdiplusStartup(&gdiplusToken, &startupInput, 0);
	DinseyPlanes m_Planes(astVars);
	PaintWindow m_Paint(windowWidth, windowHeight);
	DebugWindow m_Debug(astVars);
	ConsoleSYDE m_SYDECNSL;
	PauseWindow m_Pause;
	MinimmeTest m_mini(astVars);
	SetConsoleTitleW(title);
	SYDETIME deltaTime;
	deltaTime.initialise(std::chrono::high_resolution_clock::now());
	//OPENING SPLASHSCREENS
	if (GlobalSettings::rs) {
		CONSOLE_SCREEN_BUFFER_INFO SBInfo;
		GetConsoleScreenBufferInfo(hOut, &SBInfo);
		COORD removebuffer = {
			SBInfo.srWindow.Right - SBInfo.srWindow.Left + 10,
			SBInfo.srWindow.Bottom - SBInfo.srWindow.Top + 10
		};
		SetConsoleScreenBufferSize(hOut, removebuffer);
	}
	if (GlobalSettings::initWindow)
	{
		SYDEGamePlay::initialize_window(hOut, window);
	}
	SYDEGamePlay::opening_splashscreens(astVars.get_electronic_chime_file_path(), start, hOut, window, windowWidth, windowHeight, artVars);
	SYDEGamePlay::hidden_splashsceen_001(astVars.get_squish_file_path(), start, hOut, window, windowWidth, windowHeight, astVars);
	if (cheating)
	{
		GlobalSettings::_NAGASAKIBEATEN = true;
		GlobalSettings::_HIROSHIMABEATEN = true;
		GlobalSettings::_PEARLHARBOURBEATEN = true;

		GlobalSettings::_SEMICOLON_UNLOCK = true;
		GlobalSettings::_RIPPERONI_UNLOCK = true;
		GlobalSettings::_TSUBUMMER_UNLOCK = true;


	}
	//GAMEPLAY
	while (GlobalSettings::GamePlaying)
	{
		//UNIVERSAL KEYS
		if ((SYDEKeyCode::get('P')._CompareState(KEYDOWN) && GlobalSettings::PauseMode))
		{
			if (GlobalSettings::_SCENE != "Pause")
			{
				GlobalSettings::_LASTSCENE = GlobalSettings::_SCENE;
				window.setTextAtPoint(Vector2(0, 1), "Paused: Press 'P' To Continue", WHITE);
				GlobalSettings::_SCENE = "Pause";
			}
			else {
				GlobalSettings::_SCENE = GlobalSettings::_LASTSCENE;
			}
		}
		else if ((SYDEKeyCode::get(VK_BACK)._CompareState(KEYDOWN) && GlobalSettings::debugMenu))
		{
			GlobalSettings::_SCENE = "Debug";
		}
		if (GlobalSettings::_SCENE == "Debug")
		{
			window = SYDEGamePlay::play_game(&m_Debug, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}
		else if (GlobalSettings::_SCENE == "Pause")
		{
			window = SYDEGamePlay::play_game(&m_Pause, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}
		else if (GlobalSettings::_SCENE == "MiniTest")
		{
			window = SYDEGamePlay::play_game(&m_mini, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}
		else if (GlobalSettings::_SCENE == "Console")
		{
			window = SYDEGamePlay::play_game(&m_SYDECNSL, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}
		else if (GlobalSettings::_SCENE == "Paint")
		{
			window = SYDEGamePlay::play_game(&m_Paint, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}
		else {
			window = SYDEGamePlay::play_game(&m_Planes, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}

		if (GlobalSettings::letsplayer)
		{
			for (int i = 0; i < windowWidth; i++)
			{
				window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
			}
			window.setTextAtPoint(Vector2(0, 19), lp_text, BLACK_BRIGHTWHITE_BG);
			timeTillNextText += SYDEDefaults::getDeltaTime();
			if (timeTillNextText >= 5.0f)
			{
				timeTillNextText = 0;
				//CHANGE TEXT
				lp_text = DPFunc::ReturnRandomString();
			}

			//TEST
			window = GlobalSettings::m_LP.draw_asset(window, Vector2(0, 0));
		}
		if (GlobalSettings::framerate)
		{
			float fps = 1.0f / SYDEDefaults::getDeltaTime();
			GlobalSettings::m_fps.setText(std::to_string((int)fps) + "fps");
			window = GlobalSettings::m_fps.draw_ui(window);
		}
		window.writeConsole();
		SYDEFunctions::SYDESleep(GlobalSettings::FrameDelay_MS, SYDEDefaults::getDeltaTime());
	}
	system("cls");
	return NULL;
}