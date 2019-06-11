#include "pch.h"
#include "SYDEstdafx.h"
#include <Windows.h>
#include <string>
#include <vector>
#include <math.h>
#include "json.hpp"
using json = nlohmann::json;
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
string SCENE = "Launcher";

class GLOBAL {
public:
	static string gs_GameFlavour;

	static bool gs_Debug;
	static bool gs_FPSCounter;
	static bool gs_NoCap;

	static string toX(bool setting);
	static string toArguments();

	static void nextFlavor();

private:
	static vector<string> Flavours;
	static int _flavNum;
};

vector<string> GLOBAL::Flavours = {
	"dinsey",
	"dupty"
};
string GLOBAL::gs_GameFlavour = "dinsey";

bool GLOBAL::gs_Debug = false;
bool GLOBAL::gs_FPSCounter = false;
bool GLOBAL::gs_NoCap = false;

int GLOBAL::_flavNum = 0;

class Launcher : public SYDEWindowGame {
public:
	Launcher();
	~Launcher() {}
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
	string on_off_str(bool aBool) { if (aBool) return "On"; else return "Off"; }
private:
	SYDEMenu m_Options;
	bool m_BackupSaves = true;
	vector<CustomAsset> bgArr;
	CustomAsset bg;
};

class ReleaseNotes : public SYDEWindowGame {
public:
	ReleaseNotes() { RefresherNotes(); }
	~ReleaseNotes() {}

	void RefresherNotes();
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:
	SYDELabel m_Notes = SYDELabel(" ",Vector2(0,1), Vector2(40,18), BRIGHTWHITE, false);
	vector<SYDELabel> m_Labels;
};

class LaunchOptions : public SYDEWindowGame {
public:
	LaunchOptions();
	~LaunchOptions() {}

	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:
	SYDEMenu m_LaunchOptions;
};

Launcher::Launcher()
{
	m_Options = SYDEMenu(vector<SYDEButton>{
		SYDEButton("Back Up Saves: " + on_off_str(m_BackupSaves), Vector2(0, 15), Vector2(20, 1), BLACK, true),
		SYDEButton("Download Latest", Vector2(0, 16), Vector2(20, 1), BLACK, true),
		SYDEButton("Play Game", Vector2(0, 17), Vector2(20, 1), BLACK, true),
		SYDEButton("Play Game Debug", Vector2(0, 18), Vector2(20, 1), BLACK, true),
			SYDEButton("Launch Options", Vector2(0, 13), Vector2(20, 1), BLACK, true),
			SYDEButton("Release Notes", Vector2(0, 14), Vector2(20, 1), BLACK, true)
	});
	m_Options.setActive(true);
	m_Options.setPos(Vector2(0, 0));
	m_Options[0].m_Label = "0";
	m_Options[1].m_Label = "1";
	m_Options[2].m_Label = "2";
	m_Options[3].m_Label = "3";
	m_Options[4].m_Label = "LaunchOptions";
	m_Options[5].m_Label = "Notes";
	for (int i = 0; i < m_Options.getSize(); i++)
	{
		m_Options[i].setHighLight(RED);
	}
	//TODO, CREATE A RNADOM BG FOR EVERY LOAD
	bgArr = vector<CustomAsset>{	CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\pearl_bg.bmp", 22, 20)),
									CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\dp_bg.bmp", 22, 20)),
									CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\action_bg.bmp", 22, 20)),
	};
	srand(time(NULL));
	int bgChoice = rand() % bgArr.size();
	bg = bgArr[bgChoice];
}

ConsoleWindow Launcher::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	window = bg.draw_asset(window, Vector2(0, 0));
	if (SYDEKeyCode::get(VK_TAB)._CompareState(KEYDOWN))
	{
		m_Options.nextSelect();
	}
	window = m_Options.draw_menu(window);
	if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
	{
		if (m_Options.getSelected().m_Label == "Notes")
		{
			SCENE = "Release";
		}
		if (m_Options.getSelected().m_Label == "LaunchOptions")
		{
			SCENE = "LaunchOptions";
		}
		if (m_Options.getSelected().m_Label == "0")
		{
			m_BackupSaves = !m_BackupSaves;
			m_Options[0].setText("Back Up Saves: " + on_off_str(m_BackupSaves));
		}
		if (m_Options.getSelected().m_Label == "1")
		{
			if (m_BackupSaves)
			{
				system("start BackupSaves");
			}
			system("start Download https://github.com/Ritalin4Kidz/Dinsey-Planes/releases/latest/download/DinseyPlanes.zip");
			exit(NULL);
		}
		else if (m_Options.getSelected().m_Label == "2")
		{
			if (m_BackupSaves)
			{
				system("start ReloadSaves");
			}
			string arg = "cd Extract && start DinseyPlanes" + GLOBAL::toArguments();
			char *cstr = new char[arg.size() + 1];
			arg.copy(cstr, arg.size() + 1);
			cstr[arg.size()] = '\0';
			system(cstr);
			//system("start DinseyPlanes");
			exit(NULL);
		}
		else if (m_Options.getSelected().m_Label == "3")
		{
			if (m_BackupSaves)
			{
				system("start ReloadSaves");
			}
			system("cd Extract && start debugMode");
			//system("start DinseyPlanes");
			exit(NULL);
		}
	}
	window.setTextAtPoint(Vector2(0, 19), "TAB: Next Option, A: Select Option           ", BLACK_BRIGHTWHITE_BG);
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
	LaunchOptions m_LOptions;
	ReleaseNotes m_ReleaseNotes;
	deltaTime.initialise(std::chrono::high_resolution_clock::now());
	SYDEGamePlay::initialize_window(hOut, window);
	for (int i = 0; i < windowWidth; i++)
	{
		for (int j = 0; j < windowHeight; j++)
		{
			window.setTextAtPoint(Vector2(i, j), " ", BRIGHTWHITE_BRIGHTWHITE_BG);
		}
	}
	SYDEGamePlay::activate_bySplashscreen(astVars.get_electronic_chime_file_path(), start, hOut, window, windowWidth, windowHeight, artVars);
	//GAMEPLAY
	while (true)
	{
		if (SCENE == "Launcher")
		{
			window = SYDEGamePlay::play_game(&m_Launcher, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}
		if (SCENE == "LaunchOptions")
		{
			window = SYDEGamePlay::play_game(&m_LOptions, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}
		if (SCENE == "Release")
		{
			window = SYDEGamePlay::play_game(&m_ReleaseNotes, start, hOut, window, windowWidth, windowHeight, deltaTime);
		}
		window.writeConsole();
		SYDEFunctions::SYDESleep(30, SYDEDefaults::getDeltaTime());
	}
	system("cls");
	return NULL;
}

void ReleaseNotes::RefresherNotes()
{
	//Get Release Notes
	try {
		system("start ReleaseNotes");
		std::ifstream ifs{ "EngineFiles\\Settings\\releaseNotes.json" };
		json release_notes = json::parse(ifs);
		string notes = release_notes["body"];
		string temp = "";
		m_Labels.clear();
		m_Labels.push_back(SYDELabel("", Vector2(0, 1), Vector2(40, 1), WHITE, true));
		int m_LabelNo = 0;
		for (int i = 0; i < notes.size(); i++)
		{
			if (notes[i] != '\r' && notes[i] != '\n')
			{
				temp += notes[i];
				m_Labels[m_LabelNo].setText(temp);
				if (temp.size() == 40)
				{
					m_LabelNo++;
					m_Labels.push_back(SYDELabel("", Vector2(0, m_LabelNo + 1), Vector2(40, 1), WHITE, true));
					temp = "";
				}
			}
			else
			{
				m_LabelNo++;
				m_Labels.push_back(SYDELabel("", Vector2(0, m_LabelNo + 1), Vector2(40, 1), WHITE, true));
				temp = "";
				i++;
			}
		}
	}
	catch (exception e)
	{
		m_Notes.setText("Error getting notes: ");
		m_Notes.addText(e.what());
	}
}

ConsoleWindow ReleaseNotes::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	for (int i = 0; i < windowWidth; i++)
	{
		for (int j = 0; j < windowHeight; j++)
		{
			window.setTextAtPoint(Vector2(i, j), " ", BLACK);
		}
	}
	if (m_Labels.size() == 0)
	{
		window = m_Notes.draw_ui(window);
	}
	
	else{
		for (int i = 0; i < m_Labels.size(); i++)
		{
			window = m_Labels[i].draw_ui(window);
		}
	}
	window.setTextAtPoint(Vector2(0, 19), "Press Z To Go Back, R To Refresh", BRIGHTWHITE);
	if (SYDEKeyCode::get('Z')._CompareState(KEYDOWN))
	{
		SCENE = "Launcher";
	}
	if (SYDEKeyCode::get('R')._CompareState(KEYDOWN))
	{
		RefresherNotes();
	}
	return window;
}

LaunchOptions::LaunchOptions()
{
	m_LaunchOptions = SYDEMenu(vector<SYDEButton>{
			SYDEButton("Debug: ", Vector2(0, 1), Vector2(20, 1), WHITE, true),
			SYDEButton("Flavour: ", Vector2(0, 2), Vector2(20, 1), WHITE, true),
			SYDEButton("Framerate: ", Vector2(0, 3), Vector2(20, 1), WHITE, true),
			SYDEButton("No FPS Cap: ", Vector2(0, 4), Vector2(20, 1), WHITE, true),
			SYDEButton("Back", Vector2(0, 5), Vector2(20, 1), WHITE, true)
	});
	m_LaunchOptions[0].m_Label = "0";
	m_LaunchOptions[1].m_Label = "1";
	m_LaunchOptions[2].m_Label = "2";
	m_LaunchOptions[3].m_Label = "3";
	m_LaunchOptions[4].m_Label = "4";

	for (int i = 0; i < m_LaunchOptions.getSize(); i++)
	{
		m_LaunchOptions[i].setHighLight(RED);
	}
}

ConsoleWindow LaunchOptions::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
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
		m_LaunchOptions.nextSelect();
	}
	m_LaunchOptions[0].setText("Debug: " + GLOBAL::toX(GLOBAL::gs_Debug));
	m_LaunchOptions[1].setText("Flavour: " + GLOBAL::gs_GameFlavour);
	m_LaunchOptions[2].setText("Framerate: " + GLOBAL::toX(GLOBAL::gs_FPSCounter));
	m_LaunchOptions[3].setText("No FPS Cap: " + GLOBAL::toX(GLOBAL::gs_NoCap));

	if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
	{
		if (m_LaunchOptions.getSelected().m_Label == "0")
		{
			GLOBAL::gs_Debug = !GLOBAL::gs_Debug;
		}
		if (m_LaunchOptions.getSelected().m_Label == "1")
		{
			GLOBAL::nextFlavor();
		}
		if (m_LaunchOptions.getSelected().m_Label == "2")
		{
			GLOBAL::gs_FPSCounter = !GLOBAL::gs_FPSCounter;
		}
		if (m_LaunchOptions.getSelected().m_Label == "3")
		{
			GLOBAL::gs_NoCap = !GLOBAL::gs_NoCap;
		}
		if (m_LaunchOptions.getSelected().m_Label == "4")
		{
			SCENE = "Launcher";
		}
	}
	window = m_LaunchOptions.draw_menu(window);
	window.setTextAtPoint(Vector2(0, 19), "TAB: Next Option, A: Select Option                      ", BRIGHTWHITE);
	return window;
}

string GLOBAL::toX(bool setting)
{
	if (setting)
	{
		return "X";
	}
	return " ";
}

string GLOBAL::toArguments()
{
	string temp = " ";
	if (gs_Debug)
	{
		temp += "--debug ";
	}
	if (gs_FPSCounter)
	{
		temp += "--fps ";
	}
	if (gs_NoCap)
	{
		temp += "--nocap ";
	}
	temp += "--" + gs_GameFlavour;
	return temp;
}

void GLOBAL::nextFlavor()
{
	_flavNum++;
	if (_flavNum >= Flavours.size())
	{
		_flavNum = 0;
	}
	gs_GameFlavour = Flavours[_flavNum];
}
