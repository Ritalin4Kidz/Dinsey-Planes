#include "pch.h"
#include "SYDEstdafx.h"
#include "DinseyPlanes.h"
#include <Windows.h>

using namespace std;
using namespace Gdiplus;
//COLOR
struct ColourValues {
	ColourValues(int _r, int _g, int _b) { r = _r; dftr = _r; g = _g; dftg = _g; b = _b; dftb = _b; }
	int r;
	int g;
	int b;

	int dftr;
	int dftg;
	int dftb;

	void operator=(ColourValues other) { r = other.r; g = other.g; b = other.b; }
	void set(int _r, int _g, int  _b) { r = _r; dftr = _r; g = _g; dftg = _g; b = _b; dftb = _b; }

	void toDefault() { r = dftr; g = dftg; b = dftb; }
	DWORD toRGB() { return RGB(r, g, b); }
	string toRGBStr() { return to_string(r) + "," + to_string(g) + "," + to_string(b); }
};
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

ColourValues _BLACK(12, 12, 12);
ColourValues _BLUE(0, 55, 218);
ColourValues _GREEN(19,161,14);
ColourValues _AQUA (58,150,221);
ColourValues _RED(197,15,31);
ColourValues _PURPLE(136,23,152);
ColourValues _YELLOW(193,156,0);
ColourValues _WHITE(204,204,204);
ColourValues _LIGHTGREY(118,118,118);
ColourValues _DARKBLUE(59,120,255);
ColourValues _BRIGHTGREEN(22,198,12);
ColourValues _LIGHTBLUE(97,214,214);
ColourValues _BRIGHTRED(231,72,86);
ColourValues _LIGHTPURPLE(180,0,158);
ColourValues _BRIGHTYELLOW(249,241,165);
ColourValues _BRIGHTWHITE(242,242,242);

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
ColourValues _RGBLoad(string RGBstr, ColourValues rgbV)
{
	try {
		vector<string> RGBLines;
		RGBLines = Split(RGBstr, ',');
		if (RGBLines.size() == 3)
		{
			std::istringstream(RGBLines[0]) >> rgbV.r;
			std::istringstream(RGBLines[1]) >> rgbV.g;
			std::istringstream(RGBLines[2]) >> rgbV.b;
		}
	}
	catch (exception e)
	{
		rgbV.toDefault();
	}
	return rgbV;
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
			else if (FileLines[0] == "_Black")
			{
				_BLACK = _RGBLoad(FileLines[1], _BLACK);
			}
			else if (FileLines[0] == "_Blue")
			{
				_BLUE = _RGBLoad(FileLines[1], _BLUE);
			}
			else if (FileLines[0] == "_Green")
			{
				_GREEN = _RGBLoad(FileLines[1], _GREEN);
			}
			else if (FileLines[0] == "_Aqua")
			{
				_AQUA = _RGBLoad(FileLines[1], _AQUA);
			}
			else if (FileLines[0] == "_Red")
			{
				_RED = _RGBLoad(FileLines[1], _RED);
			}
			else if (FileLines[0] == "_Purple")
			{
				_PURPLE = _RGBLoad(FileLines[1], _PURPLE);
			}
			else if (FileLines[0] == "_Yellow")
			{
				_YELLOW = _RGBLoad(FileLines[1], _YELLOW);
			}
			else if (FileLines[0] == "_White")
			{
				_WHITE = _RGBLoad(FileLines[1], _WHITE);
			}
			else if (FileLines[0] == "_Lightgrey")
			{
				_LIGHTGREY = _RGBLoad(FileLines[1], _LIGHTGREY);
			}
			else if (FileLines[0] == "_Darkblue")
			{
				_DARKBLUE = _RGBLoad(FileLines[1], _DARKBLUE);
			}
			else if (FileLines[0] == "_Brightgreen")
			{
				_BRIGHTGREEN = _RGBLoad(FileLines[1], _BRIGHTGREEN);
			}
			else if (FileLines[0] == "_Lightblue")
			{
				_LIGHTBLUE = _RGBLoad(FileLines[1], _LIGHTBLUE);
			}
			else if (FileLines[0] == "_Brightred")
			{
				_BRIGHTRED = _RGBLoad(FileLines[1], _BRIGHTRED);
			}
			else if (FileLines[0] == "_Lightpurple")
			{
				_LIGHTPURPLE = _RGBLoad(FileLines[1], _LIGHTPURPLE);
			}
			else if (FileLines[0] == "_Brightyellow")
			{
				_BRIGHTYELLOW = _RGBLoad(FileLines[1], _BRIGHTYELLOW);
			}
			else if (FileLines[0] == "_Brightwhite")
			{
				_BRIGHTWHITE = _RGBLoad(FileLines[1], _BRIGHTWHITE);
			}
		}
	}
}
void Save()
{
	ofstream FileOut("EngineFiles\\Settings\\gameSettings.sc");
	//LEVELS
	FileOut << "//AUDIO" << endl;
	FileOut << "_Volume:" + to_string(Volume) << endl;
	FileOut << "//VISUALS"<< endl;
	FileOut << "_Black:" + _BLACK.toRGBStr() << endl;
	FileOut << "_Blue:" + _BLUE.toRGBStr() << endl;
	FileOut << "_Green:" + _GREEN.toRGBStr() << endl;
	FileOut << "_Aqua:" + _AQUA.toRGBStr() << endl;
	FileOut << "_Red:" + _RED.toRGBStr() << endl;
	FileOut << "_Purple:" + _PURPLE.toRGBStr() << endl;
	FileOut << "_Yellow:" + _YELLOW.toRGBStr() << endl;
	FileOut << "_White:" + _WHITE.toRGBStr() << endl;
	FileOut << "_Lightgrey:" + _LIGHTGREY.toRGBStr() << endl;
	FileOut << "_Darkblue:" + _DARKBLUE.toRGBStr() << endl;
	FileOut << "_Brightgreen:" + _BRIGHTGREEN.toRGBStr() << endl;
	FileOut << "_Lightblue:" + _LIGHTBLUE.toRGBStr() << endl;
	FileOut << "_Brightred:" + _BRIGHTRED.toRGBStr() << endl;
	FileOut << "_Lightpurple:" + _LIGHTPURPLE.toRGBStr() << endl;
	FileOut << "_Brightyellow:" + _BRIGHTYELLOW.toRGBStr() << endl;
	FileOut << "_Brightwhite:" + _BRIGHTWHITE.toRGBStr() << endl;
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
int main(int argc, char* argv[])
{
	//DINSEY PLANES SETTINGS
	Load();
	VolumeFunc();
	Save();
	//ARGUMENT SETTINGS
	for (int i = 0; i < argc; i++)
	{
		std::string arg = argv[i];
		if (arg == "--sunset")
		{
			_AQUA.set(255, 166, 106);
		}
	}
	//CONSOLE SETTINGS
	CONSOLE_SCREEN_BUFFER_INFOEX pInfo;
	pInfo.cbSize = sizeof(pInfo);
	GetConsoleScreenBufferInfoEx(hOut, &pInfo);
	pInfo.ColorTable[0] = COLORREF(_BLACK.toRGB());
	pInfo.ColorTable[1] = COLORREF(_BLUE.toRGB());
	pInfo.ColorTable[2] = COLORREF(_GREEN.toRGB());
	pInfo.ColorTable[3] = COLORREF(_AQUA.toRGB());
	pInfo.ColorTable[4] = COLORREF(_RED.toRGB());
	pInfo.ColorTable[5] = COLORREF(_PURPLE.toRGB());
	pInfo.ColorTable[6] = COLORREF(_YELLOW.toRGB());
	pInfo.ColorTable[7] = COLORREF(_WHITE.toRGB());
	pInfo.ColorTable[8] = COLORREF(_LIGHTGREY.toRGB());
	pInfo.ColorTable[9] = COLORREF(_DARKBLUE.toRGB());
	pInfo.ColorTable[10] = COLORREF(_BRIGHTGREEN.toRGB());
	pInfo.ColorTable[11] = COLORREF(_LIGHTBLUE.toRGB());
	pInfo.ColorTable[12] = COLORREF(_BRIGHTRED.toRGB());
	pInfo.ColorTable[13] = COLORREF(_LIGHTPURPLE.toRGB());
	pInfo.ColorTable[14] = COLORREF(_BRIGHTYELLOW.toRGB());
	pInfo.ColorTable[15] = COLORREF(_BRIGHTWHITE.toRGB());
	SetConsoleScreenBufferInfoEx(hOut, &pInfo);
	//SYDE ENGINE SETTINGS
	GdiplusStartup(&gdiplusToken, &startupInput, 0);
	DinseyPlanes m_Planes(astVars);
	//MinimmeTest m_mini(astVars);
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