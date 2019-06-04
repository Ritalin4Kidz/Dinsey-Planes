#include "pch.h"
#include "SYDEstdafx.h"
#include <Windows.h>

using namespace std;
using namespace Gdiplus;
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
COORD start = { (SHORT)0, (SHORT)0 };
static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
CustomAnimationAsset testAnimation;
//CHEATS
vector<string> cheatCodes;
static ULONG_PTR gdiplusToken;
static GdiplusStartupInput startupInput;

class Launcher : public SYDEWindowGame {
public:
	Launcher() {}
	~Launcher() {}
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:
};

ConsoleWindow Launcher::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{

	return window;
}
// MAIN FUNCTION
int main(int argc, char* argv[])
{
	//TITLES
	LPCWSTR title = L"DPLauncher";
	SYDECredits::_GAMETITLE = "DPLauncher";
	SYDECredits::_ORGANISATION = "Callum Hands \nIn Association With Freebee Games";
	//CONSOLE SETTINGS
	//SYDE ENGINE SETTINGS
	GdiplusStartup(&gdiplusToken, &startupInput, 0);
	SetConsoleTitleW(title);
	SYDETIME deltaTime;
	Launcher m_Launcher;
	deltaTime.initialise(std::chrono::high_resolution_clock::now());
	SYDEGamePlay::initialize_window(hOut, window);
	SYDEGamePlay::opening_splashscreens(astVars.get_electronic_chime_file_path(), start, hOut, window, windowWidth, windowHeight, artVars);
	//GAMEPLAY
	while (true)
	{
			window = SYDEGamePlay::play_game(&m_Launcher, start, hOut, window, windowWidth, windowHeight, deltaTime);
	}
	system("cls");
	return NULL;
}
