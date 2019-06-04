#include "pch.h"
#include "SYDEstdafx.h"
#include <Windows.h>
#include <string>
#include <vector>

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
	Launcher();
	~Launcher() {}
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:
	SYDEMenu m_Options;
};

Launcher::Launcher()
{
	m_Options = SYDEMenu(vector<SYDEButton>{
		SYDEButton("Download Latest", Vector2(0, 2), Vector2(20, 1), WHITE, true),
		SYDEButton("Play Game", Vector2(0, 3), Vector2(20, 1), WHITE, true),
	});
	m_Options.setActive(true);
	m_Options.setPos(Vector2(0, 0));
	m_Options[0].m_Label = "0";
	m_Options[1].m_Label = "1";
	for (int i = 0; i < m_Options.getSize(); i++)
	{
		m_Options[i].setHighLight(RED);
	}
}

ConsoleWindow Launcher::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	for (int i = 0; i < windowWidth; i++)
	{
		for (int j = 0; j < windowHeight; j++)
		{
			window.setTextAtPoint(Vector2(i, j), " ", BLACK);
		}
	}
	if (SYDEKeyCode::get(VK_TAB)._CompareState(KEYDOWN))
	{
		m_Options.nextSelect();
	}
	window = m_Options.draw_menu(window);
	if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
	{
		if (m_Options.getSelected().m_Label == "0")
		{
			system("start Download https://github.com/Ritalin4Kidz/Dinsey-Planes/releases/latest/download/DinseyPlanes.zip");
		}
		else if (m_Options.getSelected().m_Label == "1")
		{
			system("cd Extract && start DinseyPlanes");
			//system("start DinseyPlanes");
			exit(NULL);
		}
	}
	window.setTextAtPoint(Vector2(0, 1), " Dinsey Planes Launcher ", RED_BRIGHTWHITE_BG);
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
		window.writeConsole();
		SYDEFunctions::SYDESleep(30, SYDEDefaults::getDeltaTime());
	}
	system("cls");
	return NULL;
}
