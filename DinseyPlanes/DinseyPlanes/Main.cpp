#include "pch.h"
#include "SYDEstdafx.h"
#include "DinseyPlanes.h"
#include <Windows.h>

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

int Volume = 2;

vector<string> Split(string a_String, char splitter)
{
	int arraySize = 1;
	for (int i = 0; i < a_String.length(); i++)
	{
		if (a_String[i] == splitter)
		{
			arraySize++;
		}
	}
	vector<string> splitString(arraySize);
	int arrayNo = 0;
	while (arrayNo < arraySize - 1)
	{
		for (int i = 0; i < a_String.length(); i++)
		{
			if (a_String[i] == splitter)
			{
				splitString[arrayNo] = a_String.substr(0, i);
				a_String = a_String.substr(i + 1, a_String.length() - i);
				arrayNo++;
				break;
			}
		}
	}
	splitString[arraySize - 1] = a_String;
	return splitString;
}

void Load()
{
	ifstream File("EngineFiles\\Settings\\gameSettings.sc", ios::binary | ios::in);
	if (File.is_open())
	{
		string line;
		vector<string> FileLines;
		while (getline(File, line, '\n'))
		{
			FileLines = Split(line, ':');
			if (FileLines[0] == "_Volume")
			{
				std::istringstream(FileLines[1]) >> Volume;
			}
		}
	}
}
void Save()
{
	ofstream FileOut("EngineFiles\\Settings\\gameSettings.sc");
	//LEVELS
	FileOut << "_Volume:" + to_string(Volume) << endl;
}
void VolumeFunc()
{
	switch(Volume)
	{
	case 0:
		waveOutSetVolume(0, VOLUME_OFF);
		break;
	case 1:
		waveOutSetVolume(0, VOLUME_LOW);
		break;
	case 2:
		waveOutSetVolume(0, VOLUME_NML);
		break;
	case 3:
		waveOutSetVolume(0, VOLUME_MED);
		break;
	case 4:
		waveOutSetVolume(0, VOLUME_HIG);
		break;
	default:
		waveOutSetVolume(0, VOLUME_NML);
		Volume = 2;
		break;
	}
}

// MAIN FUNCTION
int main()
{
	//DINSEY PLANES SETTINGS
	Load();
	VolumeFunc();
	Save();
	//SYDE ENGINE SETTINGS
	GdiplusStartup(&gdiplusToken, &startupInput, 0);
	DinseyPlanes m_Planes(astVars);
	LPCWSTR title = L"Dinsey Planes";
	SYDECredits::_GAMETITLE = "Dinsey Planes";
	SYDECredits::_ORGANISATION = "Callum Hands \nIn Association With Freebee Games";
	SetConsoleTitleW(title);
	SYDETIME deltaTime;
	deltaTime.initialise(std::chrono::high_resolution_clock::now());
	//OPENING SPLASHSCREENS
	SYDEGamePlay::initialize_window(hOut, window);
	SYDEGamePlay::opening_splashscreens(astVars.get_electronic_chime_file_path(), start, hOut, window, windowWidth, windowHeight, artVars);
	SYDEGamePlay::hidden_splashsceen_001(astVars.get_squish_file_path(), start, hOut, window, windowWidth, windowHeight, astVars);
	//GAMEPLAY
	while (true)
	{
		window = SYDEGamePlay::play_game(&m_Planes, start, hOut, window, windowWidth, windowHeight, deltaTime);
		window.writeConsole();
		SYDEFunctions::SYDESleep(30, SYDEDefaults::getDeltaTime());
	}
}