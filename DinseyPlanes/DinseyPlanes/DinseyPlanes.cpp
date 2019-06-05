#include "pch.h"
#include "DinseyPlanes.h"

std::string GlobalSettings::_SCENE = "DinseyPlanes";
std::string GlobalSettings::_LASTSCENE = "";
std::string GlobalSettings::_LEVEL = "_Intro";
std::string GlobalSettings::_PLANEFLAVOUR = "Dinsey";

int GlobalSettings::FrameDelay_MS = 30;
bool GlobalSettings::PauseMode = false;
bool GlobalSettings::debugMenu = false;
bool GlobalSettings::initWindow = true;
bool GlobalSettings::rs = false;
bool GlobalSettings::GamePlaying = true;
bool GlobalSettings::letsplayer = false;
bool GlobalSettings::framerate = false;
int GlobalSettings::VolumeLVL = 2;

bool GlobalSettings::_PEARLHARBOURBEATEN = false;
bool GlobalSettings::_HIROSHIMABEATEN = false;
bool GlobalSettings::_NAGASAKIBEATEN = false;
bool GlobalSettings::_SEMICOLON_UNLOCK = false;
bool GlobalSettings::_TSUBUMMER_UNLOCK = false;
bool GlobalSettings::_RIPPERONI_UNLOCK = false;

SYDELabel GlobalSettings::m_fps = SYDELabel("", Vector2(35, 1), Vector2(5, 1), BRIGHTGREEN, true);;
CustomAnimationAsset GlobalSettings::m_LP;

DebugWindow::DebugWindow(AssetsClass astVars)
{
	_Options = SYDEMenu(vector<SYDEButton> {	SYDEButton("", Vector2(0, 1), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 2), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 3), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 4), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 5), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 6), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 7), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 8), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 9), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 10), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 11), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 12), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 13), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 14), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 15), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 16), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 17), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(0, 18), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 1), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 2), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 3), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 4), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 5), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 6), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 7), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 8), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 9), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 10), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 11), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 12), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 13), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 14), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 15), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 16), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 17), Vector2(20, 1), WHITE, true),
												SYDEButton("", Vector2(20, 18), Vector2(20, 1), WHITE, true)
	});
	_Options[0].m_Label = "0";
	_Options[1].m_Label = "1";
	_Options[2].m_Label = "2";
	_Options[3].m_Label = "3";
	_Options[4].m_Label = "4";
	_Options[5].m_Label = "5";
	_Options[6].m_Label = "6";
	_Options[7].m_Label = "7";
	_Options[8].m_Label = "8";
	_Options[9].m_Label = "9";
	_Options[10].m_Label = "10";
	_Options[11].m_Label = "11";
	_Options[12].m_Label = "12";
	_Options[13].m_Label = "13";
	_Options[14].m_Label = "14";
	_Options[15].m_Label = "15";
	_Options[16].m_Label = "16";
	_Options[17].m_Label = "17";
	_Options[18].m_Label = "18";
	_Options[19].m_Label = "19";
	_Options[20].m_Label = "20";
	_Options[21].m_Label = "21";
	_Options[22].m_Label = "22";
	_Options[23].m_Label = "23";
	_Options[24].m_Label = "24";
	_Options[25].m_Label = "25";
	_Options[26].m_Label = "26";
	_Options[27].m_Label = "27";
	_Options[28].m_Label = "28";
	_Options[29].m_Label = "29";
	_Options[30].m_Label = "30";
	_Options[31].m_Label = "31";
	_Options[32].m_Label = "32";
	_Options[33].m_Label = "33";
	_Options[34].m_Label = "34";
	_Options[35].m_Label = "35";
	_Options.setActive(true);
	_Options.setPos(Vector2(0, 0));
	for (int i = 0; i < _Options.getSize(); i++)
	{
		_Options[i].setHighLight(RED);
	}
}

ConsoleWindow DebugWindow::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	for (int l = 0; l < windowWidth; l++)
	{
		for (int m = 0; m < windowHeight; m++)
		{
			window.setTextAtPoint(Vector2(l, m), " ", BLACK);
		}
	}
	_Options[0].setText("Frame Delay:" + to_string(GlobalSettings::FrameDelay_MS));
	_Options[1].setText("Pause Mode:" + to_string(GlobalSettings::PauseMode));
	_Options[2].setText("Enable Menu:" + to_string(GlobalSettings::debugMenu));
	_Options[3].setText("Pic Test");
	_Options[4].setText("Twitch Mode:" + to_string(GlobalSettings::letsplayer));
	_Options[5].setText("FPS:" + to_string(GlobalSettings::framerate));
	_Options[6].setText("Syde Console");
	_Options[7].setText("Volume:" + to_string(GlobalSettings::VolumeLVL));
	_Options[8].setText("Save Settings");
	_Options[9].setText("Load Settings");
	_Options[10].setText("Sunset");
	_Options[11].setText("Blue Sky");
	_Options[12].setText("Night Time");
	_Options[13].setText("Syde Paint");
	_Options[14].setText("Lvl:" + GlobalSettings::_LEVEL);
	_Options[15].setText("???");
	_Options[16].setText("???");
	_Options[17].setText("???");
	_Options[18].setText("???");
	_Options[19].setText("???");
	_Options[20].setText("???");
	_Options[21].setText("???");
	_Options[22].setText("???");
	_Options[23].setText("???");
	_Options[24].setText("???");
	_Options[25].setText("???");
	_Options[26].setText("Open Settings Dir");
	_Options[27].setText("Change Flavour");
	_Options[28].setText("Sound Test");
	_Options[29].setText("Unlock All");
	_Options[30].setText("Unlock None");
	_Options[31].setText("Save Game");
	_Options[32].setText("Load Game");
	_Options[33].setText("Refresh Colour");
	_Options[34].setText("Restart");
	_Options[35].setText("Play Game");

	for (int i = 0; i < windowWidth; i++)
	{
		window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
	}
	window.setTextAtPoint(Vector2(0, 19), "TAB: Select, A: Confirm", BLACK_BRIGHTWHITE_BG);

	window = _Options.draw_menu(window);

	//INPUTS
	if (SYDEKeyCode::get(VK_TAB)._CompareState(KEYDOWN))
	{
		_Options.nextSelect();
	}
	if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
	{
		if (_Options.getSelected().m_Label == "0")
		{
			GlobalSettings::FrameDelay_MS += 10;
			if (GlobalSettings::FrameDelay_MS > 200)
			{
				GlobalSettings::FrameDelay_MS = 0;
			}
		}
		else if (_Options.getSelected().m_Label == "1")
		{
			GlobalSettings::PauseMode = !GlobalSettings::PauseMode;
		}
		else if (_Options.getSelected().m_Label == "2")
		{
			GlobalSettings::debugMenu = !GlobalSettings::debugMenu;
		}
		else if (_Options.getSelected().m_Label == "3")
		{
			GlobalSettings::_SCENE = "MiniTest";
		}
		else if (_Options.getSelected().m_Label == "4")
		{
			GlobalSettings::letsplayer = !GlobalSettings::letsplayer;
		}
		else if (_Options.getSelected().m_Label == "5")
		{
			GlobalSettings::framerate = !GlobalSettings::framerate;
		}
		else if (_Options.getSelected().m_Label == "6")
		{
			GlobalSettings::_SCENE = "Console";
		}
		else if (_Options.getSelected().m_Label == "7")
		{
			GlobalSettings::VolumeLVL++;
			if (GlobalSettings::VolumeLVL >= 5)
			{
				GlobalSettings::VolumeLVL = 0;
			}
			DPFunc::VolumeFunc(GlobalSettings::VolumeLVL);
		}
		else if (_Options.getSelected().m_Label == "8")
		{
			DPFunc::Save(); //SAVE COLOUR AND VOLUME SETTINGS
		}
		else if (_Options.getSelected().m_Label == "9")
		{
			DPFunc::Load(); //LOAD COLOUR AND VOLUME SETTINGS
		}
		else if (_Options.getSelected().m_Label == "10")
		{
			DPFunc::_AQUA.set(255, 166, 106);
		}
		else if (_Options.getSelected().m_Label == "11")
		{
			DPFunc::_AQUA.set(58, 150, 221);
		}
		else if (_Options.getSelected().m_Label == "12")
		{
			DPFunc::_AQUA.set(20, 24, 82);
		}
		else if (_Options.getSelected().m_Label == "13")
		{
			GlobalSettings::_SCENE = "Paint";
		}
		else if (_Options.getSelected().m_Label == "14")
		{
			DPFunc::_GameScenes_Selection++;
			if (DPFunc::_GameScenes_Selection >= DPFunc::_GameScenes.size())
			{
				DPFunc::_GameScenes_Selection = 0;
			}
			GlobalSettings::_LEVEL = DPFunc::_GameScenes[DPFunc::_GameScenes_Selection];
		}
		else if (_Options.getSelected().m_Label == "26")
		{
			system("Start EngineFiles\\Settings");
		}
		else if (_Options.getSelected().m_Label == "27")
		{
			window.ClearWindow(true);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			GlobalSettings::GamePlaying = false;
			if (GlobalSettings::_PLANEFLAVOUR == "Dinsey")
			{
				system("DinseyPlanes --dupty --debug --rs");
			}
			if (GlobalSettings::_PLANEFLAVOUR == "Dupty")
			{
				system("DinseyPlanes --dinsey --debug --rs");
			}
		}
		else if (_Options.getSelected().m_Label == "28")
		{
			PlaySound(L"EngineFiles\\Sounds\\electronicchime.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_Options.getSelected().m_Label == "29")
		{
			GlobalSettings::_PEARLHARBOURBEATEN = true;
			GlobalSettings::_HIROSHIMABEATEN	= true;
			GlobalSettings::_NAGASAKIBEATEN		= true;
			GlobalSettings::_SEMICOLON_UNLOCK	= true;
			GlobalSettings::_TSUBUMMER_UNLOCK	= true;
			GlobalSettings::_RIPPERONI_UNLOCK	= true;
		}
		else if (_Options.getSelected().m_Label == "30")
		{
			GlobalSettings::_PEARLHARBOURBEATEN = false;
			GlobalSettings::_HIROSHIMABEATEN = false;
			GlobalSettings::_NAGASAKIBEATEN = false;
			GlobalSettings::_SEMICOLON_UNLOCK = false;
			GlobalSettings::_TSUBUMMER_UNLOCK = false;
			GlobalSettings::_RIPPERONI_UNLOCK = false;
		}
		else if (_Options.getSelected().m_Label == "31")
		{
			DPFunc::SaveGame();
		}
		else if (_Options.getSelected().m_Label == "32")
		{
			DPFunc::LoadGame();
		}
		else if (_Options.getSelected().m_Label == "33")
		{
			DPFunc::RefreshColour(window);
		}
		else if (_Options.getSelected().m_Label == "34")
		{
			//TRY FOR WHOLE REFRESH
			window.ClearWindow(true);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			GlobalSettings::GamePlaying = false;
			system("DinseyPlanes --debug --rs");
			//system("RestartDP");
		}
		else if (_Options.getSelected().m_Label == "35")
		{
			GlobalSettings::_SCENE = "DinseyPlanes";
		}
	}

	return window;
}
DinseyPlanes::DinseyPlanes(AssetsClass astVars)
{
	//GLOBAL SETTINGS
	//GlobalSettings::m_fps = SYDELabel("", Vector2(0, 1), Vector2(3, 1), BRIGHTWHITE, true);
	//ADD IN PEARL HARBOUR CUTSCENE
	m_PearlHarbour.setAsset(vector<CustomAsset> {	CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_001.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_002.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_003.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_004.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_005.bmp", 22, 20))});

	m_Explosion.setAsset(vector<CustomAsset> {		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_001.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_002.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_003.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_004.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_005.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_006.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_007.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_008.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_009.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_010.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_011.bmp", 22, 20)),
													CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\Explosion\\Scene_012.bmp", 22, 20))
	});

	m_PearlHarbour.setFrame(0);
	m_Tutorial.setAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_005.bmp", 22, 20));
	Logo.setAsset(44, 7, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\UI\\LOGO.bmp", 22, 7));

	m_Sky = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\SKY.bmp", 22, 20));
	m_Hiro = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Levels\\Hiroshima.bmp", 22, 20));
	m_Naga = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Levels\\Nagasaki.bmp", 22, 20));

	//CUTSCENES
	m_PHS001 = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\Cutscenes\\PHS001.bmp", 22, 20));
	m_PHS002 = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\Cutscenes\\PHS002.bmp", 22, 20));
	m_PHS003 = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\Cutscenes\\PHS003.bmp", 22, 20));

	m_HSS001 = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\Cutscenes\\HSS001.bmp", 22, 20));
	m_HSS002 = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\Cutscenes\\HSS002.bmp", 22, 20));

	m_Minimme = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\MinimmeDiscord\\tricksmusicr4k.bmp", 22, 20));
	m_MinimmeFoot = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\MinimmeDiscord\\Labcat.bmp", 22, 20));

	m_Dinsey = vector<CustomAsset> {	CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Dinsey\\DinseyLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Dinsey\\DinseyRight.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Dinsey\\DinseyGameLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Dinsey\\DinseyGameRight.bmp", 22, 20))
	};
	m_Dupty = vector<CustomAsset>{		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Dupty\\DuptyLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Dupty\\DuptyRight.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Dupty\\DuptyGameLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Dupty\\DuptyGameRight.bmp", 22, 20))
	};
	m_Skibber = vector<CustomAsset>{	CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Skibber\\SkibberLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Skibber\\SkibberRight.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Skibber\\SkibberGameLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Skibber\\SkibberGameRight.bmp", 22, 20)),
	};
	m_SemiColon = vector<CustomAsset>{  CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Semi-Colon\\SemiColonLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Semi-Colon\\SemiColonRight.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Semi-Colon\\SemiColonGameLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Semi-Colon\\SemiColonGameRight.bmp", 22, 20)),
	};
	m_Ripperoni = vector<CustomAsset>{	CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Ripperoni\\RipperoniLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Ripperoni\\RipperoniRight.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Ripperoni\\RipperoniGameLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Ripperoni\\RipperoniGameRight.bmp", 22, 20)),
	};
	m_Tsubummer = vector<CustomAsset>{	CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Tsubummer\\TsubummerLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Tsubummer\\TsubummerRight.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Tsubummer\\TsubummerGameLeft.bmp", 22, 20)),
										CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Tsubummer\\TsubummerGameRight.bmp", 22, 20)),
	};
	m_PearlHarbourFlyDown.setAsset(vector<CustomAsset> {	CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_006.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_007.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_008.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_009.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_010.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_011.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_012.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_013.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_014.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_015.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_016.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_017.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_018.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_019.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_020.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_021.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_022.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_023.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_024.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_025.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_026.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_027.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_028.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_029.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_030.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_031.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_032.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_033.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_034.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_035.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_036.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_037.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_038.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_039.bmp", 22, 20)),
															CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_040.bmp", 22, 20))
	});

	m_Credits.setAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_040.bmp", 22, 20));

	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_001.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_002.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_003.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_004.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_005.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_006.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_007.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_008.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_009.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_010.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_011.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_012.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_013.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_014.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_015.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_016.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_017.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_018.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_019.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_020.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_021.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_022.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_023.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_024.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_025.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_026.bmp", 5, 5)));
	m_Clouds.push_back(CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\Cloud_027.bmp", 5, 5)));

	m_Plane = CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Plane.bmp", 5, 5));
	m_Bomb  = CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Bomb.bmp", 5, 5));
	m_BoxUI = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\UI\\box_ui.bmp", 22, 20));
	
	m_DinseyPlanes_MainMenu.setAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\MainMenu.bmp", 22, 20));
	//MINIMME TEST
	_LEVELS = SYDEMenu(vector<SYDEButton> { SYDEButton("7/12/1941 Prologue", Vector2(0, 1), Vector2(20, 1), BLACK, true),
											SYDEButton("7th Dec 1941", Vector2(0, 2), Vector2(20, 1), BLACK, true),
											SYDEButton("", Vector2(0, 3), Vector2(20, 1), BLACK, true),
											SYDEButton("", Vector2(0, 4), Vector2(20, 1), BLACK, true),
											SYDEButton("", Vector2(0, 5), Vector2(20, 1), BLACK, true),
											SYDEButton("", Vector2(0, 6), Vector2(20, 1), BLACK, true),
											SYDEButton("", Vector2(0, 7), Vector2(20, 1), BLACK, true)
	});
	_LEVELS.setActive(false);
	_LEVELS.setPos(Vector2(0, 0));
	for (int i = 0; i < _LEVELS.getSize(); i++)
	{
		_LEVELS[i].setHighLight(RED);
	}

	GlobalSettings::m_LP = CustomAnimationAsset(vector<CustomAsset> {	CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_001.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_001.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_001.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_001.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_001.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_001.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_002.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_002.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_002.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_002.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_002.bmp", 22, 20)),
																		CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\LetsPlayer\\lp_002.bmp", 22, 20))
	});
	GlobalSettings::m_LP.setLooping(true);
	DPFunc::LoadGame();
}

ConsoleWindow DinseyPlanes::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	for (int l = 0; l < windowWidth; l++)
	{
		for (int m = 0; m < windowHeight; m++)
		{
			window.setTextAtPoint(Vector2(l, m), " ", WHITE_WHITE_BG);
		}
	}
	if (GlobalSettings::_LEVEL == "_PearlHarbour")
	{
		return _PearlHarbour(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_PearlHarbour_PL")
	{
		return _PearlHarbourPrologue(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Hiroshima")
	{
		return _Hiroshima(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Hiroshima_PL")
	{
		return _HiroshimaPrologue(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Nagasaki")
	{
		return _Nagasaki(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Nagasaki_PL")
	{
		return _NagasakiPrologue(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Dinsey")
	{
		return _DinseyBadDay(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Level_Select")
	{
		return _LevelSelect(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Battle_Select")
	{
		return _BattleSelect(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Battle")
	{
		return _Battle(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Intro")
	{
		return _IntroScreen(window, windowWidth, windowHeight);
	}
	if (GlobalSettings::_LEVEL == "_Credits")
	{
		return _Credits(window, windowWidth, windowHeight);
	}
	else {
		return _MainMenu(window, windowWidth, windowHeight);
	}
}

ConsoleWindow DinseyPlanes::_MainMenu(ConsoleWindow window, int windowWidth, int windowHeight)
{
	_MainMenuInputVoids();
	window = m_Sky.draw_asset(window, Vector2(0, 0));
	cloudSpawnTime += SYDEDefaults::getDeltaTime();
	//DRAW CLOUDS
	if (cloudSpawnTime > 1)
	{
		CloudsDrawn.push_back(m_Clouds[rand() % m_Clouds.size()]);
		CloudsDrawnPos.push_back(Vector2(50, rand() % 20));
		cloudSpawnTime = 0;
	}
	for (int i = 0; i < CloudsDrawn.size(); i++)
	{
		window = CloudsDrawn[i].draw_asset(window, CloudsDrawnPos[i]);
		CloudsDrawnPos[i].setX(CloudsDrawnPos[i].getX() - 1);
	}
	if (GlobalSettings::_PLANEFLAVOUR == "Dinsey")
	{
		_LEVELS[2].setText(toLevelString(GlobalSettings::_PEARLHARBOURBEATEN, (string)("6/8/1945 Prologue")));
		_LEVELS[3].setText(toLevelString(GlobalSettings::_PEARLHARBOURBEATEN, (string)("6th Aug 1945")));
		_LEVELS[4].setText(toLevelString(GlobalSettings::_HIROSHIMABEATEN, (string)("9/8/1945 Prologue")));
		_LEVELS[5].setText(toLevelString(GlobalSettings::_HIROSHIMABEATEN, (string)("9th Aug 1945")));
		_LEVELS[6].setText(toLevelString(GlobalSettings::_NAGASAKIBEATEN, (string)("Dinsey's Bad Day")));
		window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
	}
	else if (GlobalSettings::_PLANEFLAVOUR == "Dupty")
	{
		_LEVELS[0].setText(toLevelString(false, (string)("TBA")));
		_LEVELS[1].setText(toLevelString(false, (string)("TBA")));
		_LEVELS[2].setText(toLevelString(false, (string)("TBA")));
		_LEVELS[3].setText(toLevelString(false, (string)("TBA")));
		_LEVELS[4].setText(toLevelString(false, (string)("TBA")));
		_LEVELS[5].setText(toLevelString(false, (string)("TBA")));
		_LEVELS[6].setText(toLevelString(false, (string)("TBA")));
		window = m_Dupty[1].draw_asset(window, Vector2(0, 0));
	}
	// Template window.setTextAtPoint(Vector2(0, 0), "", window.determineColourAtPoint(Vector2(0,0),BLACK, true));
	// UI - Title
	window = m_DinseyPlanesLBL.draw_ui(window);
	//window.setTextAtPoint(Vector2(2, 1), "Dinsey Planes", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
	if (!_LEVELS.getActive())
	{
		LBL_Option1.setText("A. Level Select");
		LBL_Option2.setText("B. Battle Mode");
		LBL_Option3.setText("C. Credits");
		LBL_Option4.setText("Z. Quit Game");
		window = LBL_Option4.draw_ui(window);
		//window.setTextAtPoint(Vector2(0, 11), "A. Level Select", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
		//window.setTextAtPoint(Vector2(0, 12), "B. Battle Mode", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
		//window.setTextAtPoint(Vector2(0, 13), "Z. Quit Game", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
	}
	else 
	{
		LBL_Option1.setText("TAB. Select");
		LBL_Option2.setText("A. Confirm");
		LBL_Option3.setText("Z. Back");
		//window.setTextAtPoint(Vector2(0, 11), "TAB. Select", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
		//window.setTextAtPoint(Vector2(0, 12), "A. Confirm", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
		//window.setTextAtPoint(Vector2(0, 13), "Z. Back", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
	}
	window = LBL_Option1.draw_ui(window);
	window = LBL_Option2.draw_ui(window);
	window = LBL_Option3.draw_ui(window);
	window = LBL_vNumber.draw_ui(window);
	//UI - MENU
	if (_LEVELS.getActive())
	{
		window = _LEVELS.draw_menu(window);
	}
	window = unlockPopUp.draw(window);
	return window;
}

void DinseyPlanes::_MainMenuInputVoids()
{
	if (!_LEVELS.getActive())
	{
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			_LEVELS.setActive(true);
		}
		if ((SYDEKeyCode::get('B')._CompareState(KEYDOWN)))
		{
			GlobalSettings::_LEVEL = "_Battle_Select";
		}
		if ((SYDEKeyCode::get('C')._CompareState(KEYDOWN)))
		{
			GlobalSettings::_LEVEL = "_Credits";
		}
		if ((SYDEKeyCode::get('Z')._CompareState(KEYDOWN)))
		{
			DPFunc::SaveGame();
			exit(NULL);
		}
	}
	else
	{
		if (SYDEKeyCode::get(VK_TAB)._CompareState(KEYDOWN))
		{
			_LEVELS.nextSelect();
		}
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			if (_LEVELS.getSelected().m_Text == "7th Dec 1941")
			{
				GlobalSettings::_LEVEL = "_PearlHarbour";
				PearlHarbourScene = 0;
				_LEVELS.setActive(false);
			}
			else if (_LEVELS.getSelected().m_Text == "6th Aug 1945")
			{
				GlobalSettings::_LEVEL = "_Hiroshima";
				HiroshimaScene = 0;
				CloudsDrawn.clear();
				CloudsDrawnPos.clear();
				_LEVELS.setActive(false);
			}
			else if (_LEVELS.getSelected().m_Text == "9th Aug 1945")
			{
				GlobalSettings::_LEVEL = "_Nagasaki";
				NagasakiScene = 0;
				CloudsDrawn.clear();
				CloudsDrawnPos.clear();
				_LEVELS.setActive(false);
			}
			else if (_LEVELS.getSelected().m_Text == "6/8/1945 Prologue")
			{
				GlobalSettings::_LEVEL = "_Hiroshima_PL";
				Dialogue_HiroshimaScene = 0;
				_LEVELS.setActive(false);
			}
			else if (_LEVELS.getSelected().m_Text == "7/12/1941 Prologue")
			{
				GlobalSettings::_LEVEL = "_PearlHarbour_PL";
				Dialogue_PearlHarbourScene = 0;
				_LEVELS.setActive(false);
			}
			else if (_LEVELS.getSelected().m_Text == "9/8/1945 Prologue")
			{
				GlobalSettings::_LEVEL = "_Nagasaki_PL";
				Dialogue_NagasakiScene = 0;
				_LEVELS.setActive(false);
			}
			else if (_LEVELS.getSelected().m_Text == "Dinsey's Bad Day")
			{
				GlobalSettings::_LEVEL = "_Dinsey";
				DinseyScene = 0;
				IntroTimeTaken = 0;
				CloudsDrawn.clear();
				CloudsDrawnPos.clear();
				Dinsey_Pos = Vector2(1, 5);
				Ripper_Pos = Vector2(50, 5);
				Tsubummer_Pos = Vector2(50, 13);
				_LEVELS.setActive(false);
			}
			// ELSE IF FOR OTHER LEVELS
		}
		if ((SYDEKeyCode::get('Z')._CompareState(KEYDOWN)))
		{
			_LEVELS.setActive(false);
		}
	}
}

ConsoleWindow DinseyPlanes::_LevelSelect(ConsoleWindow window, int windowWidth, int windowHeight)
{
	_LevelSelectInputVoids();
	window = m_DinseyPlanes_MainMenu.draw_asset(window, Vector2(0, 0));
	// Template window.setTextAtPoint(Vector2(0, 0), "", window.determineColourAtPoint(Vector2(0,0),BLACK, true));
	// UI - Level Select
	window = m_DinseyPlanesLBL.draw_ui(window);
	//window.setTextAtPoint(Vector2(2, 1), "Dinsey Planes", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));

	window.setTextAtPoint(Vector2(0, 11), "A. 1st Sep 1939 (N/A)", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
	window.setTextAtPoint(Vector2(0, 12), "B. 7th Dec 1941", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
	window.setTextAtPoint(Vector2(0, 13), "Z. Back", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
	return window;
}

void DinseyPlanes::_LevelSelectInputVoids()
{
	if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
	{
		//_LEVEL = "_Poland"; //NOT YET IMPLEMENTED
	}
	if ((SYDEKeyCode::get('B')._CompareState(KEYDOWN)))
	{
		GlobalSettings::_LEVEL = "_PearlHarbour";
		PearlHarbourScene = 0;
	}
	if ((SYDEKeyCode::get('Z')._CompareState(KEYDOWN)))
	{
		GlobalSettings::_LEVEL = "_MainMenu";
	}
}

vector<string> DinseyPlanes::_Split(string a_String, char splitter)
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

ConsoleWindow DinseyPlanes::_PearlHarbour(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if (PearlHarbourScene == 0)
	{
		window = m_PearlHarbour.draw_asset(window, Vector2(0, 0));
		//Sleep(100);
		if (m_PearlHarbour.getFrame() >= m_PearlHarbour.getFrameSize() - 1)
		{
			m_PearlHarbour.setFrame(0);
			PearlHarbourScene++;
		}
	}
	else if (PearlHarbourScene == 1)
	{
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			PearlHarbourScene++;
		}
		window = m_Tutorial.draw_asset(window, Vector2(0, 0));
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Ripperoni[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Tonoda", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Do you remember your mission dinsous?(A)", WHITE);
		//Sleep(100);
	}
	else if (PearlHarbourScene == 2)
	{
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			PearlHarbourScene++;
		}
		window = m_Tutorial.draw_asset(window, Vector2(0, 0));
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinsous", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "I sure do Mr Tonoda!(A)", WHITE);
		//Sleep(100);
	}
	else if (PearlHarbourScene == 3)
	{
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			PearlHarbourScene++;
		}
		window = m_Tutorial.draw_asset(window, Vector2(0, 0));
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Ripperoni[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Tonoda", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Good..Good..When you're ready dinsous(A)", WHITE);
		//Sleep(100);
	}
	else if (PearlHarbourScene == 4)
	{
		if ((SYDEKeyCode::get('S')._CompareState(KEYDOWN)))
		{
			PearlHarbourScene++;
		}
		window = m_Tutorial.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tutorial: Press 'S' To Move Down", WHITE);
		//Sleep(100);
	}
	else if (PearlHarbourScene == 5)
	{
		if (m_PearlHarbourFlyDown.getFrame() == 28)
		{
			PlaySound(AssetsClass::get_explosion_file_path(), NULL, SND_FILENAME | SND_ASYNC);
		}
		window = m_PearlHarbourFlyDown.draw_asset(window, Vector2(0, 0));
		//Sleep(100);
		if (m_PearlHarbourFlyDown.getFrame() >= m_PearlHarbourFlyDown.getFrameSize() - 1)
		{
			m_PearlHarbourFlyDown.setFrame(0);
			PearlHarbourScene++;
		}
	}
	else if (PearlHarbourScene == 6)
	{
		if ((SYDEKeyCode::get('Q')._CompareState(KEYDOWN)))
		{
			PearlHarbourScene++;
			if (!GlobalSettings::_SEMICOLON_UNLOCK)
			{
				GlobalSettings::_SEMICOLON_UNLOCK = true;
				unlockPopUp.PopUp("Semi-Colon Unlocked!");
			}
		}
		window = m_Credits.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Level Complete: Press 'Q' To Return", WHITE);
		GlobalSettings::_PEARLHARBOURBEATEN = true;
		//Sleep(100);
	}
	//TO DO, ADD ANIMATION OF PLANE CRASHING INTO A HARBOUR, THEN LEVEL IS DONE
	else {
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
	}
	return window;
}

ConsoleWindow DinseyPlanes::_Hiroshima(ConsoleWindow window, int windowWidth, int windowHeight)
{
	window = m_Sky.draw_asset(window, Vector2(0, 0));
	cloudSpawnTime += SYDEDefaults::getDeltaTime();
	if (HiroshimaScene < 6)
	{
		//DRAW CLOUDS
		if (cloudSpawnTime > 1)
		{
			CloudsDrawn.push_back(m_Clouds[rand() % m_Clouds.size()]);
			CloudsDrawnPos.push_back(Vector2(50, rand() % 20));
			cloudSpawnTime = 0;
		}
		for (int i = 0; i < CloudsDrawn.size(); i++)
		{
			window = CloudsDrawn[i].draw_asset(window, CloudsDrawnPos[i]);
			CloudsDrawnPos[i].setX(CloudsDrawnPos[i].getX() - 1);
		}
		//DRAW PLANE
		window = m_Bomb.draw_asset(window, m_BombPos);
		window = m_Plane.draw_asset(window, Vector2(1, 5));
	}
	if (HiroshimaScene == 0)
	{
		IntroTimeTaken += SYDEDefaults::getDeltaTime();
		if (IntroTimeTaken >= 3)
		{
			HiroshimaScene++;
			IntroTimeTaken = 0;
		}
	}
	else if (HiroshimaScene == 1)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dupty[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Samson", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Have you reached Hiroshima yet?(A)", WHITE);
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			HiroshimaScene++;
		}
	}
	else if (HiroshimaScene == 2)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinspy", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Just arrived now boss!(A)", WHITE);
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			HiroshimaScene++;
		}
	}
	else if (HiroshimaScene == 3)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dupty[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Samson", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Excellent... Deliver the package(A)", WHITE);
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			HiroshimaScene++;
		}
	}
	else if (HiroshimaScene == 4)
	{
		window.setTextAtPoint(Vector2(0, 19), "Tutorial: Press 'B' To Use A Bomb            ", WHITE);
		if ((SYDEKeyCode::get('B')._CompareState(KEYDOWN)))
		{
			HiroshimaScene++;
		}
	}
	else if (HiroshimaScene == 5)
	{
		m_BombPos.addY(1);
		if (m_BombPos.getY() >= 22)
		{
			m_BombPos = Vector2(28, 5);
			HiroshimaScene++;
		}
	}
	else if (HiroshimaScene == 6)
	{
		window = m_Hiro.draw_asset(window, Vector2(0, 0));
		m_BombPos.addY(1);
		window = m_Bomb.draw_asset(window, m_BombPos);
		if (m_BombPos.getY() >= 18)
		{
			m_Explosion.setFrame(0);
			HiroshimaScene++;
		}
	}
	else if (HiroshimaScene == 7)
	{
		//DRAW EXPLOSION
		window = m_Hiro.draw_asset(window, Vector2(0, 0));
		window = m_Bomb.draw_asset(window, m_BombPos);
		window = m_Explosion.draw_asset(window, Vector2(0, 0));
		if (m_Explosion.getFrame() == 1)
		{
			PlaySound(AssetsClass::get_explosion_file_path(), NULL, SND_FILENAME | SND_ASYNC);
		}
		if (m_Explosion.getFrame() >= m_Explosion.getFrameSize() - 1)
		{
			HiroshimaScene++;
		}
	}
	else if (HiroshimaScene == 8)
	{
		if ((SYDEKeyCode::get('Q')._CompareState(KEYDOWN)))
		{
			HiroshimaScene++;
		}
		window = m_Credits.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Level Complete: Press 'Q' To Return", WHITE);
	}
	else if (HiroshimaScene == 9)
	{
		if (!GlobalSettings::_TSUBUMMER_UNLOCK)
		{
			GlobalSettings::_TSUBUMMER_UNLOCK = true;
			unlockPopUp.PopUp("Tsubummer Unlocked!");
		}
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
		m_Explosion.setFrame(0);
		m_BombPos = Vector2(1, 5);
		HiroshimaScene = 0;
		GlobalSettings::_HIROSHIMABEATEN = true;
	}
	//ONCE BOMB IS OFF SCREEN, PLAY AN ANIMATION.
	return window;
}

ConsoleWindow DinseyPlanes::_Nagasaki(ConsoleWindow window, int windowWidth, int windowHeight)
{
	window = m_Sky.draw_asset(window, Vector2(0, 0));
	cloudSpawnTime += SYDEDefaults::getDeltaTime();
	if (NagasakiScene < 7)
	{
		//DRAW CLOUDS
		if (cloudSpawnTime > 1)
		{
			CloudsDrawn.push_back(m_Clouds[rand() % m_Clouds.size()]);
			CloudsDrawnPos.push_back(Vector2(50, rand() % 20));
			cloudSpawnTime = 0;
		}
		for (int i = 0; i < CloudsDrawn.size(); i++)
		{
			window = CloudsDrawn[i].draw_asset(window, CloudsDrawnPos[i]);
			CloudsDrawnPos[i].setX(CloudsDrawnPos[i].getX() - 1);
		}
		//DRAW PLANE
		window = m_Bomb.draw_asset(window, m_BombPos);
		window = m_Plane.draw_asset(window, Vector2(1, 5));
	}
	if (NagasakiScene == 0)
	{
		IntroTimeTaken += SYDEDefaults::getDeltaTime();
		if (IntroTimeTaken >= 3)
		{
			NagasakiScene++;
			IntroTimeTaken = 0;
		}
	}
	else if (NagasakiScene == 1)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dupty[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Samson", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "You've done well Dinspy(A)", WHITE);
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			NagasakiScene++;
		}
	}
	else if (NagasakiScene == 2)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dupty[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Samson", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Just deliver the package to Nagasaki(A)", WHITE);
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			NagasakiScene++;
		}
	}
	else if (NagasakiScene == 3)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dupty[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Samson", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "and this will all finally be over(A)", WHITE);
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			NagasakiScene++;
		}
	}
	else if (NagasakiScene == 4)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinspy", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Aye Aye Captain(A)", WHITE);
		if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
		{
			NagasakiScene++;
		}
	}
	else if (NagasakiScene == 5)
	{
		//window.setTextAtPoint(Vector2(0, 19), "Tutorial: Press 'B' To Use A Bomb            ", WHITE);
		if ((SYDEKeyCode::get('B')._CompareState(KEYDOWN)))
		{
			NagasakiScene++;
		}
	}
	else if (NagasakiScene == 6)
	{
		m_BombPos.addY(1);
		if (m_BombPos.getY() >= 22)
		{
			m_BombPos = Vector2(28, 5);
			NagasakiScene++;
		}
	}
	else if (NagasakiScene == 7)
	{
		window = m_Naga.draw_asset(window, Vector2(0, 0));
		m_BombPos.addY(1);
		window = m_Bomb.draw_asset(window, m_BombPos);
		if (m_BombPos.getY() >= 18)
		{
			m_Explosion.setFrame(0);
			NagasakiScene++;
		}
	}
	else if (NagasakiScene == 8)
	{
		//DRAW EXPLOSION
		window = m_Naga.draw_asset(window, Vector2(0, 0));
		window = m_Bomb.draw_asset(window, m_BombPos);
		window = m_Explosion.draw_asset(window, Vector2(0, 0));
		if (m_Explosion.getFrame() == 1)
		{
			PlaySound(AssetsClass::get_explosion_file_path(), NULL, SND_FILENAME | SND_ASYNC);
		}
		if (m_Explosion.getFrame() >= m_Explosion.getFrameSize() - 1)
		{
			NagasakiScene++;
		}
	}
	else if (NagasakiScene == 9)
	{
		if ((SYDEKeyCode::get('Q')._CompareState(KEYDOWN)))
		{
			NagasakiScene++;
		}
		window = m_Credits.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Level Complete: Press 'Q' To Return", WHITE);
	}
	else if (NagasakiScene == 10)
	{
		if (!GlobalSettings::_RIPPERONI_UNLOCK)
		{
			GlobalSettings::_RIPPERONI_UNLOCK = true;
			unlockPopUp.PopUp("Ripperoni Unlocked!");
		}
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
		m_Explosion.setFrame(0);
		m_BombPos = Vector2(1, 5);
		NagasakiScene = 0;
		GlobalSettings::_NAGASAKIBEATEN = true;
	}
	//ONCE BOMB IS OFF SCREEN, PLAY AN ANIMATION.
	return window;
}

ConsoleWindow DinseyPlanes::_PearlHarbourPrologue(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if (SYDEKeyCode::get('A')._CompareState(KEYDOWN) || SYDEKeyCode::get(VK_SPACE)._CompareState(KEYDOWN))
	{
		Dialogue_PearlHarbourScene++;
	}
	switch (Dialogue_PearlHarbourScene)
	{
	case 0:
		window = m_PHS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Purplous: Sir... The Americans....", BLACK_BRIGHTWHITE_BG);
		break;
	case 1:
		window = m_PHS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Purplous: They've threatened war with us", BLACK_BRIGHTWHITE_BG);
		break;
	case 2:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: Hmmmm...", BLACK_BRIGHTWHITE_BG);
		break;
	case 3:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: I see...", BLACK_BRIGHTWHITE_BG);
		break;
	case 4:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: This is most troubling", BLACK_BRIGHTWHITE_BG);
		break;
	case 5:
		window = m_PHS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Purplous: What ever should we do sir?", BLACK_BRIGHTWHITE_BG);
		break;
	case 6:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: Do not worry, I have a plan", BLACK_BRIGHTWHITE_BG);
		break;
	case 7:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: DINSOUS!", BLACK_BRIGHTWHITE_BG);
		break;
	case 8:
		window = m_PHS003.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dinsous: I'm here sir, what is it?", BLACK_BRIGHTWHITE_BG);
		break;
	case 9:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: I have a job for you", BLACK_BRIGHTWHITE_BG);
		break;
	default:
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
		break;
	}
	return window;
}

ConsoleWindow DinseyPlanes::_HiroshimaPrologue(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if (SYDEKeyCode::get('A')._CompareState(KEYDOWN) || SYDEKeyCode::get(VK_SPACE)._CompareState(KEYDOWN))
	{
		Dialogue_HiroshimaScene++;
	}
	switch (Dialogue_HiroshimaScene)
	{
	case 0:
		window = m_HSS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Samson: It's been nearly 4 years", BLACK_BRIGHTWHITE_BG);
		break;
	case 1:
		window = m_HSS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Samson: But today....", BLACK_BRIGHTWHITE_BG);
		break;
	case 2:
		window = m_HSS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Samson: TODAY WE FIGHT BACK!", BLACK_BRIGHTWHITE_BG);
		break;
	case 3:
		window = m_HSS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Samson: WE LIVE IN FEAR NO MORE!", BLACK_BRIGHTWHITE_BG);
		break;
	case 4:
		window = m_HSS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Samson: DINSPY!", BLACK_BRIGHTWHITE_BG);
		break;
	case 5:
		window = m_HSS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dinspy: YES SIR!", BLACK_BRIGHTWHITE_BG);
		break;
	case 6:
		window = m_HSS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Samson: Prepare your luggage", BLACK_BRIGHTWHITE_BG);
		break;
	case 7:
		window = m_HSS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Samson: You're going to Japan", BLACK_BRIGHTWHITE_BG);
		break;
	default:
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
		break;
	}
	return window;
}

ConsoleWindow DinseyPlanes::_NagasakiPrologue(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if (SYDEKeyCode::get('A')._CompareState(KEYDOWN) || SYDEKeyCode::get(VK_SPACE)._CompareState(KEYDOWN))
	{
		Dialogue_NagasakiScene++;
	}
	switch (Dialogue_NagasakiScene)
	{
	case 0:
		window = m_PHS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Purplous: Sir, our country is wounded", BLACK_BRIGHTWHITE_BG);
		break;
	case 1:
		window = m_PHS001.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Purplous: we must surrender to the US", BLACK_BRIGHTWHITE_BG);
		break;
	case 2:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: NEVER!!!", BLACK_BRIGHTWHITE_BG);
		break;
	case 3:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: I'D RATHER WE ALL DIE!!", BLACK_BRIGHTWHITE_BG);
		break;
	case 4:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		break;
	case 5:
		window = m_PHS002.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tonoda: Do you hear something?", BLACK_BRIGHTWHITE_BG);
		break;
	default:
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
		break;
	}
	return window;
}

ConsoleWindow DinseyPlanes::_DinseyBadDay(ConsoleWindow window, int windowWidth, int windowHeight)
{
	window = m_Sky.draw_asset(window, Vector2(0, 0));
	cloudSpawnTime += SYDEDefaults::getDeltaTime();
	if (DinseyScene < 9)
	{
		if (SYDEKeyCode::get('W')._CompareState(KEY) && Dinsey_Pos.getY() > 1)
		{
			Dinsey_Pos.addY(-1);
		}
		if (SYDEKeyCode::get('S')._CompareState(KEY) && Dinsey_Pos.getY() < 15)
		{
			Dinsey_Pos.addY(1);
		}
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
	}
	if (DinseyScene < 20)
	{
		//DRAW CLOUDS
		if (cloudSpawnTime > 1)
		{
			CloudsDrawn.push_back(m_Clouds[rand() % m_Clouds.size()]);
			CloudsDrawnPos.push_back(Vector2(50, rand() % 20));
			cloudSpawnTime = 0;
		}
		for (int i = 0; i < CloudsDrawn.size(); i++)
		{
			window = CloudsDrawn[i].draw_asset(window, CloudsDrawnPos[i]);
			CloudsDrawnPos[i].setX(CloudsDrawnPos[i].getX() - 1);
		}
	}
	if (DinseyScene == 0)
	{
		IntroTimeTaken += SYDEDefaults::getDeltaTime();
		if (IntroTimeTaken >= 3)
		{
			DinseyScene++;
			IntroTimeTaken = 0;
		}
	}
	else if (DinseyScene == 1)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dupty[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dupty", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Hey Dinsey, what you up to bud?(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 2)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinsey", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Not much Dupty, just chilling(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 3)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinsey", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Cruising in the sky, no worries(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 4)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinsey", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Why? what's up mr Dups?(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 5)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dupty[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dupty", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Minimme's doing a signing!!(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 6)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dupty[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dupty", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Meet me at westfield(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 7)
	{
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinsey", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Oh heck yeah, i'll meet you there(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 8)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		Tsubummer_Pos.addX(-1);
		Ripper_Pos.addX(-1);
		if (Ripper_Pos.getX() == 32)
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 9)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		if (Dinsey_Pos.getY() > 5)
		{
			Dinsey_Pos.addY(-1);
		}
		else if(Dinsey_Pos.getY() < 5)
		{
			Dinsey_Pos.addY(1);
		}
		if (Dinsey_Pos.getY() == 5)
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 10)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Ripperoni[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(30, 6), "Ripperoni", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "well...well...well...(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 11)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Ripperoni[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(30, 6), "Ripperoni", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "if isn't dins..stupid(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 12)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Tsubummer[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(30, 6), "Tsubummer", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "hehe. that's a good one boss(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 13)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinsey", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "It's dinsey ripper...(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 14)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Ripperoni[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(30, 6), "Ripperoni", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "WHAT DID YOU JUST CALL ME?(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 15)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Ripperoni[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(30, 6), "Ripperoni", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Tsu, you're excused, i've got this(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 16)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[3].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Tsubummer[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(30, 6), "Tsubummer", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "no worries boss(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 17)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Tsubummer[2].draw_asset(window, Tsubummer_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		Tsubummer_Pos.addX(1);
		if (Tsubummer_Pos.getX() >= 50) {
			DinseyScene++;
		}
	}
	else if (DinseyScene == 18)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		Ripper_Pos.addY(1);
		Dinsey_Pos.addY(1);
		if (Dinsey_Pos.getY() >= 14) {
			DinseyScene++;
			IntroCountDown = 3.5f;
			m_Explosion.setFrame(0);
		}
	}
	else if (DinseyScene == 19)
	{
		window = m_Ripperoni[3].draw_asset(window, Ripper_Pos);
		window = m_Dinsey[2].draw_asset(window, Dinsey_Pos);
		if (IntroCountDown >= 0)
		{
			window.setTextAtPoint(Vector2(21, 10), to_string((int)IntroCountDown), window.determineColourAtPoint(Vector2(21, 10), BLACK, true));
			IntroCountDown -= SYDEDefaults::getDeltaTime();
		}
		else if (Dinsey_Pos.getX() < Ripper_Pos.getX()) {
			Dinsey_Pos.addX(1);
			Ripper_Pos.addX(-1);
		}
		if (Dinsey_Pos.getX() >= Ripper_Pos.getX())
		{
			if (m_Explosion.getFrame() == 1)
			{
				PlaySound(AssetsClass::get_explosion_file_path(), NULL, SND_FILENAME | SND_ASYNC);
			}
			window = m_Explosion.draw_asset(window, Vector2(0, 0));
			if (m_Explosion.getFrame() >= m_Explosion.getFrameSize() - 1)
			{
				DinseyScene++;
			}
		}
	}
	else if (DinseyScene == 20)
	{
		window = m_Credits.draw_asset(window, Vector2(0, 0));
		window = m_BoxUI.draw_asset(window, Vector2(0, 0));
		window = m_Dinsey[3].draw_asset(window, Vector2(32, 1));
		window.setTextAtPoint(Vector2(32, 6), "Dinsey", WHITE);
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "ow.......(A)", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 21)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_Dupty[0].draw_asset(window, Vector2(-6, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dupty: DINSEY!, YOU'RE OK! (A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 22)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_Dupty[0].draw_asset(window, Vector2(-6, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dupty: You were in a coma for 2 weeks!(A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}

	else if (DinseyScene == 23)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dinsey: 2 Weeks? Oh no! that means... (A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 24)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dinsey: I MISSED MINIMME! NOOOOO! (A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}

	else if (DinseyScene == 25)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_Minimme.draw_asset(window, Vector2(1, 1));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Minimme: Don't be so sure (A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}

	else if (DinseyScene == 26)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dinsey: Minimme? Is it really you?(A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}

	else if (DinseyScene == 27)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_MinimmeFoot.draw_asset(window, Vector2(1, 1));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Minimme: Yes, take a look at my foot(A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}

	else if (DinseyScene == 28)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dinsey: Hooray!!!!! wait.... (A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 29)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", WHITE_BRIGHTWHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 19), "Dinsey: Why the hospital visit?(A)", BLACK_BRIGHTWHITE_BG);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else if (DinseyScene == 30)
	{
		for (int i = 0; i < windowWidth; i++)
		{
			for (int j = 0; j < windowHeight; j++)
			{
				window.setTextAtPoint(Vector2(i, j), " ", BLACK);
			}
		}
		window.setTextAtPoint(Vector2(17, 10), "The End", WHITE);
		if (SYDEKeyCode::get('A')._CompareState(KEYDOWN))
		{
			DinseyScene++;
		}
	}
	else {
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
		Dinsey_Pos = Vector2(1, 5);
		DinseyScene = 0;
	}
	return window;
}

ConsoleWindow DinseyPlanes::_Credits(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if ((SYDEKeyCode::get('Z')._CompareState(KEYDOWN)))
	{
		GlobalSettings::_LEVEL = "_MainMenu";
	}
	for (int l = 0; l < windowWidth; l++)
	{
		for (int m = 0; m < windowHeight; m++)
		{
			window.setTextAtPoint(Vector2(l, m), " ", WHITE);
		}
	}
	for (int m = 0; m < windowWidth; m++)
	{
		window.setTextAtPoint(Vector2(m, 19), " ", BLACK_BRIGHTWHITE_BG);
	}
	window.setTextAtPoint(Vector2(0, 1), "SYDE Engine Created By Callum Hands", BRIGHTWHITE);
	window.setTextAtPoint(Vector2(0, 2), "Dinsey Planes Created By Callum Hands", BRIGHTWHITE);
	window.setTextAtPoint(Vector2(0, 3), "ritalin4kidz.github.io", BRIGHTWHITE);
	window.setTextAtPoint(Vector2(0, 4), "Music: ", BRIGHTWHITE);
	window.setTextAtPoint(Vector2(0, 5), "Additional Art: Tricksmusic, Labcat", BRIGHTWHITE);
	window.setTextAtPoint(Vector2(0, 6), " ", BRIGHTWHITE);
	window = Disclaimer.draw_ui(window);
	window.setTextAtPoint(Vector2(0, 19), "Press 'Z' to go back...", BLACK_BRIGHTWHITE_BG);
	return window;
}

ConsoleWindow DinseyPlanes::_BattleSelect(ConsoleWindow window, int windowWidth, int windowHeight)
{
	for (int l = 0; l < windowWidth; l++)
	{
		for (int m = 0; m < windowHeight; m++)
		{
			window.setTextAtPoint(Vector2(l, m), " ", BRIGHTWHITE_AQUA_BG);
		}
	}
	switch (char1_choice)
	{
	case 0:
		if (player1stats)
		{
			window = m_Dinsey[2].draw_asset(window, Vector2(3, 5));
			window.setTextAtPoint(Vector2(0, 11), "Speed-------", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(0, 12), "Defence", BLACK_YELLOW_BG);
			window.setTextAtPoint(Vector2(0, 13), "Attack------", BLACK_BRIGHTGREEN_BG);
		}
		else
		{
			window = m_Dinsey[0].draw_asset(window, Vector2(-6, 0));
		}
		window.setTextAtPoint(Vector2(0, 18), "Dinsey", BLACK_BRIGHTWHITE_BG);
		break;
	case 1:
		if (player1stats)
		{
			window = m_Dupty[2].draw_asset(window, Vector2(3, 5));
			window.setTextAtPoint(Vector2(0, 11), "Speed-", BLACK_RED_BG);
			window.setTextAtPoint(Vector2(0, 12), "Defence-------", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(0, 13), "Attack------", BLACK_BRIGHTGREEN_BG);
		}
		else
		{
			window = m_Dupty[0].draw_asset(window, Vector2(-6, 0));
		}
		window.setTextAtPoint(Vector2(0, 18), "Dupty", BLACK_BRIGHTWHITE_BG);
		break;
	case 2:
		if (player1stats)
		{
			window = m_Skibber[2].draw_asset(window, Vector2(3, 5));
			window.setTextAtPoint(Vector2(0, 11), "Speed---------", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(0, 12), "Defence---", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(0, 13), "Attack", BLACK_YELLOW_BG);
		}
		else
		{
			window = m_Skibber[0].draw_asset(window, Vector2(-6, 0));
		}
		window.setTextAtPoint(Vector2(0, 18), "Skibber", BLACK_BRIGHTWHITE_BG);
		break;
	case 3:
		if (GlobalSettings::_SEMICOLON_UNLOCK)
		{
			if (player1stats)
			{
				window = m_SemiColon[2].draw_asset(window, Vector2(3, 5));
				window.setTextAtPoint(Vector2(0, 11), "Speed", BLACK_RED_BG);
				window.setTextAtPoint(Vector2(0, 12), "Defence------", BLACK_BRIGHTGREEN_BG);
				window.setTextAtPoint(Vector2(0, 13), "Attack-------", BLACK_BRIGHTGREEN_BG);
			}
			else
			{
				window = m_SemiColon[0].draw_asset(window, Vector2(-6, 0));
			}
			window.setTextAtPoint(Vector2(0, 18), "Semi-Colon", BLACK_BRIGHTWHITE_BG);
			break;
		}
		char1_choice++;
	case 4:
		if (GlobalSettings::_RIPPERONI_UNLOCK)
		{
			if (player1stats)
			{
				window = m_Ripperoni[2].draw_asset(window, Vector2(3, 5));
				window.setTextAtPoint(Vector2(0, 11), "Speed--------", BLACK_BRIGHTGREEN_BG);
				window.setTextAtPoint(Vector2(0, 12), "Defen", BLACK_RED_BG);
				window.setTextAtPoint(Vector2(0, 13), "Attack-----", BLACK_BRIGHTGREEN_BG);
			}
			else
			{
				window = m_Ripperoni[0].draw_asset(window, Vector2(-6, 0));
			}
			window.setTextAtPoint(Vector2(0, 18), "Ripperoni", BLACK_BRIGHTWHITE_BG);
			break;
		}
		char1_choice++;
	case 5:
		if (GlobalSettings::_TSUBUMMER_UNLOCK)
		{
			if (player1stats)
			{
				window = m_Tsubummer[2].draw_asset(window, Vector2(3, 5));
				window.setTextAtPoint(Vector2(0, 11), "Speed---------", BLACK_BRIGHTGREEN_BG);
				window.setTextAtPoint(Vector2(0, 12), "Def", BLACK_RED_BG);
				window.setTextAtPoint(Vector2(0, 13), "Attack--------", BLACK_BRIGHTGREEN_BG);
			}
			else
			{
				window = m_Tsubummer[0].draw_asset(window, Vector2(-6, 0));
			}
			window.setTextAtPoint(Vector2(0, 18), "Tsubummer", BLACK_BRIGHTWHITE_BG);
			break;
		}
		char1_choice++;
	default:
		if (player1stats)
		{
			window = m_Dinsey[2].draw_asset(window, Vector2(3, 5));
			window.setTextAtPoint(Vector2(0, 11), "Speed-------", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(0, 12), "Defence", BLACK_YELLOW_BG);
			window.setTextAtPoint(Vector2(0, 13), "Attack------", BLACK_BRIGHTGREEN_BG);
		}
		else
		{
			window = m_Dinsey[0].draw_asset(window, Vector2(-6, 0));
		}
		window.setTextAtPoint(Vector2(0, 18), "Dinsey", BLACK_BRIGHTWHITE_BG);
		char1_choice = 0;
		break;
	}
	switch (char2_choice)
	{
	case 0:
		if (player2stats)
		{
			window = m_Dinsey[3].draw_asset(window, Vector2(29, 5));
			window.setTextAtPoint(Vector2(28, 11), "-------Speed", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(33, 12), "Defence", BLACK_YELLOW_BG);
			window.setTextAtPoint(Vector2(28, 13), "------Attack", BLACK_BRIGHTGREEN_BG);
		}
		else
		{
			window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
		}
		window.setTextAtPoint(Vector2(34, 18), "Dinsey", WHITE);
		break;
	case 1:
		if (player2stats)
		{
			window = m_Dupty[3].draw_asset(window, Vector2(29, 5));
			window.setTextAtPoint(Vector2(34, 11), "-Speed", BLACK_RED_BG);
			window.setTextAtPoint(Vector2(26, 12), "-------Defence", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(28, 13), "------Attack", BLACK_BRIGHTGREEN_BG);
		}
		else
		{
			window = m_Dupty[1].draw_asset(window, Vector2(0, 0));
		}
		window.setTextAtPoint(Vector2(35, 18), "Dupty", WHITE);
		break;
	case 2:
		if (player2stats)
		{
			window = m_Skibber[3].draw_asset(window, Vector2(29, 5));
			window.setTextAtPoint(Vector2(26, 11), "---------Speed", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(30, 12), "---Defence", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(34, 13), "Attack", BLACK_YELLOW_BG);
		}
		else
		{
			window = m_Skibber[1].draw_asset(window, Vector2(0, 0));
		}
		window.setTextAtPoint(Vector2(33, 18), "Skibber", WHITE);
		break;
	case 3:
		if (GlobalSettings::_SEMICOLON_UNLOCK)
		{
			if (player2stats)
			{
				window = m_SemiColon[3].draw_asset(window, Vector2(26, 5));
				window.setTextAtPoint(Vector2(35, 11), "Speed", BLACK_RED_BG);
				window.setTextAtPoint(Vector2(27, 12), "------Defence", BLACK_BRIGHTGREEN_BG);
				window.setTextAtPoint(Vector2(27, 13), "-------Attack", BLACK_BRIGHTGREEN_BG);
			}
			else
			{
				window = m_SemiColon[1].draw_asset(window, Vector2(0, 0));
			}
			window.setTextAtPoint(Vector2(30, 18), "Semi-Colon", WHITE);
			break;
		}
		char2_choice++;
	case 4:
		if (GlobalSettings::_RIPPERONI_UNLOCK)
		{
			if (player2stats)
			{
				window = m_Ripperoni[3].draw_asset(window, Vector2(29, 5));
				window.setTextAtPoint(Vector2(27, 11), "--------Speed", BLACK_BRIGHTGREEN_BG);
				window.setTextAtPoint(Vector2(35, 12), "Defen", BLACK_RED_BG);
				window.setTextAtPoint(Vector2(29, 13), "-----Attack", BLACK_BRIGHTGREEN_BG);
			}
			else
			{
				window = m_Ripperoni[1].draw_asset(window, Vector2(0, 0));
			}
			window.setTextAtPoint(Vector2(31, 18), "Ripperoni", WHITE);
			break;
		}
		char2_choice++;
	case 5:
		if (GlobalSettings::_TSUBUMMER_UNLOCK)
		{
			if (player2stats)
			{
				window = m_Tsubummer[3].draw_asset(window, Vector2(29, 5));
				window.setTextAtPoint(Vector2(26, 11), "---------Speed", BLACK_BRIGHTGREEN_BG);
				window.setTextAtPoint(Vector2(37, 12), "Def", BLACK_RED_BG);
				window.setTextAtPoint(Vector2(26, 13),  "--------Attack", BLACK_BRIGHTGREEN_BG);
			}
			else
			{
				window = m_Tsubummer[1].draw_asset(window, Vector2(0, 0));
			}
			window.setTextAtPoint(Vector2(31, 18), "Tsubummer", WHITE);
			break;
		}
		char2_choice++;
	default:
		if (player2stats)
		{
			window = m_Dinsey[3].draw_asset(window, Vector2(37, 5));
			window.setTextAtPoint(Vector2(28, 11), "-------Speed", BLACK_BRIGHTGREEN_BG);
			window.setTextAtPoint(Vector2(33, 12), "Defence", BLACK_YELLOW_BG);
			window.setTextAtPoint(Vector2(28, 13), "------Attack", BLACK_BRIGHTGREEN_BG);
		}
		else
		{
			window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
		}
		window.setTextAtPoint(Vector2(34, 18), "Dinsey", WHITE);
		char2_choice = 0;
		break;
	}
	window.setTextAtPoint(Vector2(0, 19), "<-A,D->", BLACK_BRIGHTWHITE_BG);
	window.setTextAtPoint(Vector2(15, 19), "Space: Play", BLACK_AQUA_BG);
	window.setTextAtPoint(Vector2(17, 18), "Z: Back", BLACK_AQUA_BG);
	window.setTextAtPoint(Vector2(14, 1), "Plane Select", BLACK_BRIGHTWHITE_BG);
	window.setTextAtPoint(Vector2(33, 19), "<-J,L->", WHITE);
	//KEY INPUT
	player1stats = SYDEKeyCode::get('S')._CompareState(KEY);
	player2stats = SYDEKeyCode::get('K')._CompareState(KEY);
	if ((SYDEKeyCode::get('A')._CompareState(KEYDOWN)))
	{
		char1_choice--;
		if (char1_choice < 0)
		{
			char1_choice = 5;
		}
		switch (char1_choice)
		{
			case 5:
				if (GlobalSettings::_TSUBUMMER_UNLOCK)
					break;
				char1_choice--;
			case 4:
				if (GlobalSettings::_RIPPERONI_UNLOCK)
					break;
				char1_choice--;
			case 3:
				if (GlobalSettings::_SEMICOLON_UNLOCK)
					break;
				char1_choice--;
			default:
				break;
		}
	}
	if ((SYDEKeyCode::get('D')._CompareState(KEYDOWN)))
	{
		char1_choice++;
		if (char1_choice > 5)
		{
			char1_choice = 0;
		}
	}
	if ((SYDEKeyCode::get('J')._CompareState(KEYDOWN)))
	{
		char2_choice--;
		if (char2_choice < 0)
		{
			char2_choice = 5;
		}
		switch (char2_choice)
		{
			case 5:
				if (GlobalSettings::_TSUBUMMER_UNLOCK)
					break;
				char2_choice--;
			case 4:
				if (GlobalSettings::_RIPPERONI_UNLOCK)
					break;
				char2_choice--;
			case 3:
				if (GlobalSettings::_SEMICOLON_UNLOCK)
					break;
				char2_choice--;
			default:
				break;
		}
	}
	if ((SYDEKeyCode::get('L')._CompareState(KEYDOWN)))
	{
		char2_choice++;
		if (char2_choice > 5)
		{
			char2_choice = 0;
		}
	}
	if ((SYDEKeyCode::get('Z')._CompareState(KEYDOWN)))
	{
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
	}
	if ((SYDEKeyCode::get(VK_SPACE)._CompareState(KEYDOWN)))
	{
		GlobalSettings::_LEVEL = "_Battle";
		switch (char1_choice)
		{
		case 0:
			Player1Plane = m_Dinsey[2];
			break;
		case 1:
			Player1Plane = m_Dupty[2];
			break;
		case 2:
			Player1Plane = m_Skibber[2];
			break;
		case 3:
			Player1Plane = m_SemiColon[2];
			break;
		case 4:
			Player1Plane = m_Ripperoni[2];
			break;
		case 5:
			Player1Plane = m_Tsubummer[2];
			break;
		default:
			Player1Plane = m_Dinsey[2];
			break;
		}
		switch (char2_choice)
		{
		case 0:
			Player2Plane = m_Dinsey[3];
			break;
		case 1:
			Player2Plane = m_Dupty[3];
			break;
		case 2:
			Player2Plane = m_Skibber[3];
			break;
		case 3:
			Player2Plane = m_SemiColon[3];
			break;
		case 4:
			Player2Plane = m_Ripperoni[3];
			break;
		case 5:
			Player2Plane = m_Tsubummer[3];
			break;
		default:
			Player2Plane = m_Dinsey[3];
			break;
		}
		//RESET
		IntroCountDown = 3.5f;
		m_Explosion.setFrame(0);
		Play1Pos = Vector2(0, 14);
		Play2Pos = Vector2(32, 14);
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
		BattleScene = 0;
	}

	return window;
}

ConsoleWindow DinseyPlanes::_Battle(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if (BattleScene == 0)
	{
		window = m_Sky.draw_asset(window, Vector2(0, 0));
		cloudSpawnTime += SYDEDefaults::getDeltaTime();
		//DRAW CLOUDS
		if (cloudSpawnTime > 1)
		{
			CloudsDrawn.push_back(m_Clouds[rand() % m_Clouds.size()]);
			CloudsDrawnPos.push_back(Vector2(50, rand() % 20));
			cloudSpawnTime = 0;
		}
		for (int i = 0; i < CloudsDrawn.size(); i++)
		{
			window = CloudsDrawn[i].draw_asset(window, CloudsDrawnPos[i]);
			CloudsDrawnPos[i].setX(CloudsDrawnPos[i].getX() - 1);
		}
		if (IntroCountDown >= 0)
		{
			window.setTextAtPoint(Vector2(21, 10), to_string((int)IntroCountDown), window.determineColourAtPoint(Vector2(21, 10), BLACK, true));
			IntroCountDown -= SYDEDefaults::getDeltaTime();
		}
		else if (Play1Pos.getX() < Play2Pos.getX()) {
			Play1Pos.addX(1);
			Play2Pos.addX(-1);
		}
		window = Player1Plane.draw_asset(window, Play1Pos);
		window = Player2Plane.draw_asset(window, Play2Pos);
		if (Play1Pos.getX() >= Play2Pos.getX())
		{
			if (m_Explosion.getFrame() == 1)
			{
				PlaySound(AssetsClass::get_explosion_file_path(), NULL, SND_FILENAME | SND_ASYNC);
			}
			window = m_Explosion.draw_asset(window, Vector2(0, 0));
			if (m_Explosion.getFrame() >= m_Explosion.getFrameSize() - 1)
			{
				BattleScene++;
			}
		}
	}
	if (BattleScene == 1)
	{
		if ((SYDEKeyCode::get('Q')._CompareState(KEYDOWN)))
		{
			BattleScene++;
		}
		window = m_Credits.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Draw: Press 'Q' To Return", WHITE);
	}
	if (BattleScene == 2)
	{
		GlobalSettings::_LEVEL = "_Battle_Select";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
	}
	return window;
}

ConsoleWindow DinseyPlanes::_IntroScreen(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if (init)
	{
		//MASSIVE TO DO: GET ACTUAL MUSIC FOR THIS
		PlaySound(L"EngineFiles\\Sounds\\Music\\placeholder.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		init = false;
	}
	window = m_Sky.draw_asset(window, Vector2(0, 0));
	cloudSpawnTime += SYDEDefaults::getDeltaTime();
	InverseTime += SYDEDefaults::getDeltaTime();
	if (introFlash)
	{
		FlashTime += SYDEDefaults::getDeltaTime();
	}
	window = m_Dinsey[2].draw_asset(window, Vector2(0, 13 - direction));
	window = m_Tsubummer[2].draw_asset(window, Vector2(8, 13 + direction));
	window = m_Dupty[2].draw_asset(window, Vector2(16, 13 - direction));
	window = m_Skibber[2].draw_asset(window, Vector2(24, 13 + direction));
	window = m_Ripperoni[2].draw_asset(window, Vector2(32, 13 - direction));

	if (InverseTime >= InverseMax)
	{
		direction = -direction;
		InverseTime = 0;
		showStart = !showStart;
	}
	if (FlashTime >= FlashMaxTime)
	{
		GlobalSettings::_LEVEL = "_MainMenu";
		CloudsDrawn.clear();
		CloudsDrawnPos.clear();
	}
	//DRAW CLOUDS
	if (cloudSpawnTime > 1)
	{
		CloudsDrawn.push_back(m_Clouds[rand() % m_Clouds.size()]);
		CloudsDrawnPos.push_back(Vector2(50, rand() % 20));
		cloudSpawnTime = 0;
	}
	for (int i = 0; i < CloudsDrawn.size(); i++)
	{
		window = CloudsDrawn[i].draw_asset(window, CloudsDrawnPos[i]);
		CloudsDrawnPos[i].setX(CloudsDrawnPos[i].getX() - 1);
	}
	window = Logo.draw_asset(window, Vector2(2, 1));
	window.setTextAtPoint(Vector2(0, 1), " " + GlobalSettings::_PLANEFLAVOUR + " ", RED_BRIGHTWHITE_BG);
	if (showStart)
	{
		window = m_Start.draw_ui(window);
	}
	if ((SYDEKeyCode::get(VK_SPACE)._CompareState(KEYDOWN)) && !introFlash)
	{
		introFlash = true;
		InverseMax = 0.1f;
		PlaySound(NULL, NULL, SND_FILENAME);
	}
	return window;
}

bool DinseyPlanes::GetKey(char KeyCode)
{
	return GetAsyncKeyState(KeyCode) && 0x8000;
}

ConsoleWindow MainMenuPopUp::draw(ConsoleWindow window)
{
	if (TimeTaken < TimeShown) {
		window = PopUpBox.draw_ui(window);
		TimeTaken += SYDEDefaults::getDeltaTime();
	}
	return window;
}

void MainMenuPopUp::PopUp(string a_Text)
{
	PopUpBox.setText(a_Text);
	TimeTaken = 0;
}

MinimmeTest::MinimmeTest(AssetsClass astVars)
{
	m_Mini.setAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\MinimmeDiscord\\minimme.bmp", 22, 20));
}

ConsoleWindow MinimmeTest::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	//testing mini
	for (int i = 0; i < windowWidth; i++)
	{
		for (int ii = 0; ii < windowHeight; ii++)
		{
			window.setTextAtPoint(Vector2(i, ii), " ", AQUA_AQUA_BG);
		}
	}
	window = m_Mini.draw_asset(window, Vector2(0, 0));
	return window;
}

ConsoleWindow PauseWindow::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	return window;
}

ConsoleWindow ConsoleSYDE::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	m_TextDelay += SYDEDefaults::getDeltaTime();
	if (SYDEKeyCode::get(VK_RETURN)._CompareState(KEYDOWN))
	{
		_cmd.setText(_CmdLine.m_Text);
		_cmds.setText(exec(_CmdLine.m_Text));
		_CmdLine.removeText(_CmdLine.m_Text.size());
	}
	else if (SYDEKeyCode::get(VK_LEFT)._CompareState(KEYDOWN))
	{
		_CmdLine.removeText(1);
	}
	else if (m_TextDelay > 0.05f && !SYDEKeyCode::get(VK_LEFT)._CompareState(KEY))
	{
		_CmdLine.addText(SYDEKeyCode::KeysDown());
		m_TextDelay = 0;
	}
	window = _cmd.draw_ui(window);
	window = _cmds.draw_ui(window);
	window = _CmdLine.draw_ui(window);
	return window;
}

std::string ConsoleSYDE::exec(std::string cmd)
{
	std::string Error = "";
	// NO VALUE CHANGES IN HERE, JUST CHECKING SHIT
	if (cmd == DPFunc::_Commands[0])
	{
		return "test thing works";
	}
	if (cmd == DPFunc::_Commands[1])
	{
		if (GlobalSettings::_LASTSCENE != "")
		{
			return GlobalSettings::_LASTSCENE;
		}
		Error = "SL001: LastScene is non existant";
	}
	if (cmd == DPFunc::_Commands[2])
	{
		if (GlobalSettings::letsplayer)
		{
			return "Letsplayer == true";
		}
		else {
			return "Letsplayer == false";
		}
	}
	if (cmd == DPFunc::_Commands[3])
	{
		try {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			GlobalSettings::GamePlaying = false;
			system("DinseyPlanes --debug --rs");
		}
		catch (exception e) {
			Error = e.what();
		}
	}
	if (Error == "")
	{
		Error = "Unable to find command: " + cmd + ". " +  DPFunc::FindCommand(cmd);
	}
	return "Error: " + Error;
}
