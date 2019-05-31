#include "pch.h"
#include "DPFunc.h"
DWORD DPFunc::VOLUME_LOW = DWORD(858993459);
DWORD DPFunc::VOLUME_NML = DWORD(1717986918);
DWORD DPFunc::VOLUME_MED = DWORD(-1717986918);
DWORD DPFunc::VOLUME_HIG = DWORD(-858993459);
DWORD DPFunc::VOLUME_OFF = DWORD(0);

ColourValues DPFunc::_BLACK = ColourValues(12, 12, 12);
ColourValues DPFunc::_BLUE = ColourValues(0, 55, 218);
ColourValues DPFunc::_GREEN = ColourValues(19, 161, 14);
ColourValues DPFunc::_AQUA = ColourValues(58, 150, 221);
ColourValues DPFunc::_RED = ColourValues(197, 15, 31);
ColourValues DPFunc::_PURPLE = ColourValues(136, 23, 152);
ColourValues DPFunc::_YELLOW = ColourValues(193, 156, 0);
ColourValues DPFunc::_WHITE = ColourValues(204, 204, 204);
ColourValues DPFunc::_LIGHTGREY = ColourValues(118, 118, 118);
ColourValues DPFunc::_DARKBLUE = ColourValues(59, 120, 255);
ColourValues DPFunc::_BRIGHTGREEN = ColourValues(22, 198, 12);
ColourValues DPFunc::_LIGHTBLUE = ColourValues(97, 214, 214);
ColourValues DPFunc::_BRIGHTRED = ColourValues(231, 72, 86);
ColourValues DPFunc::_LIGHTPURPLE = ColourValues(180, 0, 158);
ColourValues DPFunc::_BRIGHTYELLOW = ColourValues(249, 241, 165);
ColourValues DPFunc::_BRIGHTWHITE = ColourValues(242, 242, 242);

std::string DPFunc::ReturnRandomString()
{
	int rNum = rand() % 93;
	switch (rNum)
	{
	case 0:
		return "jimmyjamesxx, ty for the sub";
	case 1:
		return "that was pretty cool lmao";
	case 2:
		return "well...didn't expect that";
	case 3:
		return "so as i was saying before";
	case 4:
		return "micron ty for the follow";
	case 5:
		return "ummmm.....";
	case 6:
		return "what was i saying?...";
	case 7:
		return "xx_SPY006 ty for the sub";
	case 8:
		return "i tried mangos for the first time";
	case 9:
		return "i don't really like them";
	case 10:
		return "i might play league later";
	case 11:
		return "r4k ty for the cheeky sub";
	case 12:
		return "sometimes i get lonely..";
	case 13:
		return "andrew ty for the follow";
	case 14:
		return "holy s***balls dude!";
	case 15:
		return "sorry about any swears everyone";
	case 16:
		return "this is a family friendly stream";
	case 17:
		return "where my mods at in chat?";
	case 18:
		return "evil_guy43 ty for the sub";
	case 19:
		return "i know only 20 people are watching but";
	case 20:
		return "oh damn did you guys see that?";
	case 21:
		return "who would make a plane based game?";
	case 22:
		return "did you guys read the news lately?";
	case 23:
		return "this is my 125th stream in a row btw";
	case 24:
		return "i might play black ops 4 later";
	case 25:
		return "turns out drugs cure disease";
	case 26:
		return "turns out the pm is crooked";
	case 27:
		return "turns out brexit isn't american";
	case 28:
		return "turns out frank black is white";
	case 29:
		return "turns out barry white is black";
	case 30:
		return "turns out soylent green is people";
	case 31:
		return "turns out star wars is bad lmao";
	case 32:
		return "MUM!!! WHERE'S MY TENDIES?!!";
	case 33:
		return "MUM!!! WHERE'S MY REDBULL?!!";
	case 34:
		return "F*** wtf just happened there?";
	case 35:
		return "dinsey planes is a terrible name";
	case 36:
		return "i'm still waiting on dinsey cars";
	case 37:
		return "DinseyFan ty for the sub";
	case 38:
		return "stop telling me to review planes";
	case 39:
		return "REEEEEEEEEEEEEEEE!!!!!!";
	case 40:
		return "ty for the support. keeps my lights on";
	case 41:
		return "pls donate $5 to the charity of me";
	case 42:
		return "donate to my patreon, $20 a month";
	case 43:
		return "donate to my minecraft server btw";
	case 44:
		return "i've been looking for work lately";
	case 45:
		return "every job i find online sucks ass";
	case 46:
		return "mum threatened to kick me out last night";
	case 47:
		return "i had a date yesterday, was s***";
	case 48:
		return "kongamon thanks for the sub man";
	case 49:
		return "so i went to the doctor the other day";
	case 50:
		return "anyways, that's how i lost my license";
	case 51:
		return "this game is actually pretty fun";
	case 52:
		return "this game is actually pretty bad";
	case 53:
		return "why would the dev add that in?";
	case 54:
		return "lmao i'm not really paying attention";
	case 55:
		return "how do i even play this game?";
	case 56:
		return "ok jimmyjamesxx see you later";
	case 57:
		return "kratosfanboy ty for the sub";
	case 58:
		return "apparently avocado is a fruit";
	case 59:
		return "i can't believe fantano gave it a 6";
	case 60:
		return "i can't believe fantano gave it a 10";
	case 61:
		return "i just realised this is the wrong game";
	case 62:
		return "mods ban that d*** in chat";
	case 63:
		return "i got involved in this mlm yesterday";
	case 64:
		return "hey anyone wanna buy 10 cases of amway?";
	case 65:
		return "FaZe turned down my job application :(";
	case 66:
		return "Oh............ok.......";
	case 67:
		return "F*** THIS BULLS*** MAN...HOLY S***!!!";
	case 68:
		return "555-3567-1235 call me ladies ;)";
	case 69:
		return "that was a surprise to say the least";
	case 70:
		return "f*** im so random XD";
	case 71:
		return "i'll be doing a giveaway at 40k subs";
	case 72:
		return "i won't be able to stream tomorrow";
	case 73:
		return "mum's angry because my room isn't clean";
	case 74:
		return "who's up for a gym sesh tonight?";
	case 75:
		return "follow me on twitter @maxiyyou";
	case 76:
		return "honestly i don't like this game";
	case 77:
		return "honestly i love to play this game";
	case 78:
		return "i've been diagnosed with boredom";
	case 79:
		return "anyone in chat listen to death grips?";
	case 80:
		return "mbv_loveless thanks for the sub";
	case 81:
		return "are there any ladies in chat?";
	case 82:
		return "dude, not funny, get off my stream";
	case 83:
		return "someone end me from this existence";
	case 84:
		return "life is cruel and unfair.....";
	case 85:
		return "F*** THIS GAME IS OVERRATED TRASH!";
	case 86:
		return "why did i want to play this game?";
	case 87:
		return "who wants to see my chug a beer?";
	case 88:
		return "got my grandad's funeral saturday";
	case 90:
		return "where's my redbull?....";
	case 91:
		return "are some of you unsubbing & resubbing?";
	case 92:
		return "i want to sleep soon.....";
	default:
		return "OK... that was weird";
		break;
	}
}

std::string DPFunc::FindCommand(std::string cmd)
{
	std::string cmdRtn = "";
	for (int i = 0; i < _Commands.size(); i++)
	{
		if (_Commands[i][0] == cmd[0])
		{
			cmdRtn += _Commands[i] + ",";
		}
	}
	if (cmdRtn == "")
	{
		return "No possible commands found";
	}
	return "Possible Commands: " + cmdRtn;
}

void DPFunc::VolumeFunc(int volume)
{
	switch (volume)
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
		volume = 2;
		break;
	}
}

ColourValues DPFunc::_RGBLoad(std::string RGBstr, ColourValues rgbV)
{
	try {
		std::vector<std::string> RGBLines;
		RGBLines = Split(RGBstr, ',');
		if (RGBLines.size() == 3)
		{
			std::istringstream(RGBLines[0]) >> rgbV.r;
			std::istringstream(RGBLines[1]) >> rgbV.g;
			std::istringstream(RGBLines[2]) >> rgbV.b;
		}
	}
	catch (std::exception e)
	{
		rgbV.toDefault();
	}
	return rgbV;
}

void DPFunc::Load()
{
	std::ifstream File("EngineFiles\\Settings\\gameSettings.sc", std::ios::binary | std::ios::in);
	if (File.is_open())
	{
		std::string line;
		std::vector<std::string> FileLines;
		while (getline(File, line, '\n'))
		{
			FileLines = Split(line, ':');
			if (FileLines[0] == "_Volume")
			{
				std::istringstream(FileLines[1]) >> GlobalSettings::VolumeLVL;
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

void DPFunc::Save()
{
	ofstream FileOut("EngineFiles\\Settings\\gameSettings.sc");
	//LEVELS
	FileOut << "//AUDIO" << endl;
	FileOut << "_Volume:" + std::to_string(GlobalSettings::VolumeLVL) << endl;
	FileOut << "//VISUALS" << endl;
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

void DPFunc::LoadGame()
{
	ifstream File("EngineFiles\\Settings\\dp_Saves.sc", ios::binary | ios::in);
	if (File.is_open())
	{
		string line;
		vector<string> FileLines;
		while (getline(File, line, '\n'))
		{
			FileLines = Split(line, ':');
			if (FileLines[0] == "_PEARLHARBOURBEATEN")
			{
				std::istringstream(FileLines[1]) >> GlobalSettings::_PEARLHARBOURBEATEN;
			}
			if (FileLines[0] == "_HIROSHIMABEATEN")
			{
				std::istringstream(FileLines[1]) >> GlobalSettings::_HIROSHIMABEATEN;
			}
			if (FileLines[0] == "_NAGASAKIBEATEN")
			{
				std::istringstream(FileLines[1]) >> GlobalSettings::_NAGASAKIBEATEN;
			}
			if (FileLines[0] == "_SEMICOLON_UNLOCK")
			{
				std::istringstream(FileLines[1]) >> GlobalSettings::_SEMICOLON_UNLOCK;
			}
			if (FileLines[0] == "_TSUBUMMER_UNLOCK")
			{
				std::istringstream(FileLines[1]) >> GlobalSettings::_TSUBUMMER_UNLOCK;
			}
			if (FileLines[0] == "_RIPPERONI_UNLOCK")
			{
				std::istringstream(FileLines[1]) >> GlobalSettings::_RIPPERONI_UNLOCK;
			}
		}
	}
}

void DPFunc::SaveGame()
{
	ofstream FileOut("EngineFiles\\Settings\\dp_Saves.sc");
	//LEVELS
	FileOut << "_PEARLHARBOURBEATEN:" + to_string(GlobalSettings::_PEARLHARBOURBEATEN) << endl;
	FileOut << "_HIROSHIMABEATEN:" + to_string(GlobalSettings::_HIROSHIMABEATEN) << endl;
	FileOut << "_NAGASAKIBEATEN:" + to_string(GlobalSettings::_NAGASAKIBEATEN) << endl;
	//CHARACTERS
	FileOut << "_SEMICOLON_UNLOCK:" + to_string(GlobalSettings::_SEMICOLON_UNLOCK) << endl;
	FileOut << "_TSUBUMMER_UNLOCK:" + to_string(GlobalSettings::_TSUBUMMER_UNLOCK) << endl;
	FileOut << "_RIPPERONI_UNLOCK:" + to_string(GlobalSettings::_RIPPERONI_UNLOCK) << endl;
}

void DPFunc::RefreshColour(ConsoleWindow window)
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	DPFunc::ColourPalette(GetStdHandle(STD_OUTPUT_HANDLE), true, window);
}

void DPFunc::ColourPalette(HANDLE hOut, bool initRS, ConsoleWindow window)
{
	CONSOLE_SCREEN_BUFFER_INFOEX pInfo;
	pInfo.cbSize = sizeof(pInfo);
	GetConsoleScreenBufferInfoEx(hOut, &pInfo);
	pInfo.ColorTable[0] = COLORREF(DPFunc::_BLACK.toRGB());
	pInfo.ColorTable[1] = COLORREF(DPFunc::_BLUE.toRGB());
	pInfo.ColorTable[2] = COLORREF(DPFunc::_GREEN.toRGB());
	pInfo.ColorTable[3] = COLORREF(DPFunc::_AQUA.toRGB());
	pInfo.ColorTable[4] = COLORREF(DPFunc::_RED.toRGB());
	pInfo.ColorTable[5] = COLORREF(DPFunc::_PURPLE.toRGB());
	pInfo.ColorTable[6] = COLORREF(DPFunc::_YELLOW.toRGB());
	pInfo.ColorTable[7] = COLORREF(DPFunc::_WHITE.toRGB());
	pInfo.ColorTable[8] = COLORREF(DPFunc::_LIGHTGREY.toRGB());
	pInfo.ColorTable[9] = COLORREF(DPFunc::_DARKBLUE.toRGB());
	pInfo.ColorTable[10] = COLORREF(DPFunc::_BRIGHTGREEN.toRGB());
	pInfo.ColorTable[11] = COLORREF(DPFunc::_LIGHTBLUE.toRGB());
	pInfo.ColorTable[12] = COLORREF(DPFunc::_BRIGHTRED.toRGB());
	pInfo.ColorTable[13] = COLORREF(DPFunc::_LIGHTPURPLE.toRGB());
	pInfo.ColorTable[14] = COLORREF(DPFunc::_BRIGHTYELLOW.toRGB());
	pInfo.ColorTable[15] = COLORREF(DPFunc::_BRIGHTWHITE.toRGB());
	SetConsoleScreenBufferInfoEx(hOut, &pInfo);
	if (initRS)
	{
		CONSOLE_SCREEN_BUFFER_INFO SBInfo;
		GetConsoleScreenBufferInfo(hOut, &SBInfo);
		COORD removebuffer = {
			SBInfo.srWindow.Right - SBInfo.srWindow.Left + 10,
			SBInfo.srWindow.Bottom - SBInfo.srWindow.Top + 10
		};
		SetConsoleScreenBufferSize(hOut, removebuffer);
		SYDEGamePlay::initialize_window(hOut, window);
	}
}

std::vector<std::string> DPFunc::Split(std::string a_String, char splitter)
{
	int arraySize = 1;
	for (int i = 0; i < a_String.length(); i++)
	{
		if (a_String[i] == splitter)
		{
			arraySize++;
		}
	}
	std::vector<std::string> splitString(arraySize);
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

std::vector<std::string> DPFunc::_Commands = {
	"TEST",
	"SCENELAST",
	"LP",
	"DPRS"
};