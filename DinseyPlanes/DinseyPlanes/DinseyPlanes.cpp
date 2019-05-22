#include "pch.h"
#include "DinseyPlanes.h"

DinseyPlanes::DinseyPlanes(AssetsClass astVars)
{
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

	m_Sky = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\SKY.bmp", 22, 20));
	m_Hiro = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Levels\\Hiroshima.bmp", 22, 20));

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

	m_Plane = CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Plane.bmp", 5, 5));
	m_Bomb  = CustomAsset(10, 5, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Planes_ETC\\Bomb.bmp", 5, 5));

	m_DinseyPlanes_MainMenu.setAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\MainMenu.bmp", 22, 20));
	_LEVELS = SYDEMenu(vector<SYDEButton> { SYDEButton("7th Dec 1941", Vector2(0, 1), Vector2(20, 1), BLACK, true),
											SYDEButton("", Vector2(0, 2), Vector2(20, 1), BLACK, true),
											SYDEButton("", Vector2(0, 3), Vector2(20, 1), BLACK, true)
	});
	_LEVELS.setActive(false);
	_LEVELS.setPos(Vector2(0, 0));
	for (int i = 0; i < _LEVELS.getSize(); i++)
	{
		_LEVELS[i].setHighLight(RED);
	}
	_Load();
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

	if (_LEVEL == "_PearlHarbour")
	{
		return _PearlHarbour(window, windowWidth, windowHeight);
	}
	if (_LEVEL == "_Hiroshima")
	{
		return _Hiroshima(window, windowWidth, windowHeight);
	}
	if (_LEVEL == "_Nagasaki")
	{
		return _Nagasaki(window, windowWidth, windowHeight);
	}
	if (_LEVEL == "_Level_Select")
	{
		return _LevelSelect(window, windowWidth, windowHeight);
	}
	if (_LEVEL == "_Battle_Select")
	{
		return _BattleSelect(window, windowWidth, windowHeight);
	}
	if (_LEVEL == "_Battle")
	{
		return _Battle(window, windowWidth, windowHeight);
	}
	else {
		return _MainMenu(window, windowWidth, windowHeight);
	}
}

ConsoleWindow DinseyPlanes::_MainMenu(ConsoleWindow window, int windowWidth, int windowHeight)
{
	_LEVELS[1].setText(toLevelString(_PEARLHARBOURBEATEN, (string)("6th Aug 1945")));
	_LEVELS[2].setText(toLevelString(_HIROSHIMABEATEN, (string)("9th Aug 1945")));
	_MainMenuInputVoids();
	window = m_DinseyPlanes_MainMenu.draw_asset(window, Vector2(0, 0));
	// Template window.setTextAtPoint(Vector2(0, 0), "", window.determineColourAtPoint(Vector2(0,0),BLACK, true));
	// UI - Title
	window.setTextAtPoint(Vector2(2, 1), "Dinsey Planes", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));

	if (!_LEVELS.getActive())
	{
		window.setTextAtPoint(Vector2(0, 11), "A. Level Select", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
		window.setTextAtPoint(Vector2(0, 12), "B. Battle Mode", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
		window.setTextAtPoint(Vector2(0, 13), "Z. Quit Game", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
	}
	else 
	{
		window.setTextAtPoint(Vector2(0, 11), "TAB. Select", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
		window.setTextAtPoint(Vector2(0, 12), "A. Confirm", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
		window.setTextAtPoint(Vector2(0, 13), "Z. Back", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
	}

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
			_LEVEL = "_Battle_Select";
		}
		if ((SYDEKeyCode::get('Z')._CompareState(KEYDOWN)))
		{
			_Save();
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
				_LEVEL = "_PearlHarbour";
				PearlHarbourScene = 0;
				_LEVELS.setActive(false);
			}
			else if (_LEVELS.getSelected().m_Text == "6th Aug 1945")
			{
				_LEVEL = "_Hiroshima";
				HiroshimaScene = 0;
				CloudsDrawn.clear();
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
	window.setTextAtPoint(Vector2(2, 1), "Dinsey Planes", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));

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
		_LEVEL = "_PearlHarbour";
		PearlHarbourScene = 0;
	}
	if ((SYDEKeyCode::get('Z')._CompareState(KEYDOWN)))
	{
		_LEVEL = "_MainMenu";
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

void DinseyPlanes::_Load()
{
	ifstream File("EngineFiles\\Settings\\dp_Saves.sc", ios::binary | ios::in);
	if (File.is_open())
	{
		string line;
		vector<string> FileLines;
		while (getline(File, line, '\n'))
		{
			FileLines = _Split(line, ':');
			if (FileLines[0] == "_PEARLHARBOURBEATEN")
			{
				std::istringstream(FileLines[1]) >> _PEARLHARBOURBEATEN;
			}
			if (FileLines[0] == "_HIROSHIMABEATEN")
			{
				std::istringstream(FileLines[1]) >> _HIROSHIMABEATEN;
			}
			if (FileLines[0] == "_SEMICOLON_UNLOCK")
			{
				std::istringstream(FileLines[1]) >> _SEMICOLON_UNLOCK;
			}
			if (FileLines[0] == "_TSUBUMMER_UNLOCK")
			{
				std::istringstream(FileLines[1]) >> _TSUBUMMER_UNLOCK;
			}
			if (FileLines[0] == "_RIPPERONI_UNLOCK")
			{
				std::istringstream(FileLines[1]) >> _RIPPERONI_UNLOCK;
			}
		}
	}
}

void DinseyPlanes::_Save()
{
	ofstream FileOut("EngineFiles\\Settings\\dp_Saves.sc");
	//LEVELS
	FileOut << "_PEARLHARBOURBEATEN:" + to_string(_PEARLHARBOURBEATEN) << endl;
	FileOut << "_HIROSHIMABEATEN:" + to_string(_HIROSHIMABEATEN) << endl;
	//CHARACTERS
	FileOut << "_SEMICOLON_UNLOCK:" + to_string(_SEMICOLON_UNLOCK) << endl;
	FileOut << "_TSUBUMMER_UNLOCK:" + to_string(_TSUBUMMER_UNLOCK) << endl;
	FileOut << "_RIPPERONI_UNLOCK:" + to_string(_RIPPERONI_UNLOCK) << endl;
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
	else if (PearlHarbourScene == 2)
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
	else if (PearlHarbourScene == 3)
	{
		if ((SYDEKeyCode::get('Q')._CompareState(KEYDOWN)))
		{
			PearlHarbourScene++;
			if (!_SEMICOLON_UNLOCK)
			{
				_SEMICOLON_UNLOCK = true;
				unlockPopUp.PopUp("Semi-Colon Unlocked!");
			}
		}
		window = m_Credits.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Level Complete: Press 'Q' To Return", WHITE);
		_PEARLHARBOURBEATEN = true;
		//Sleep(100);
	}
	//TO DO, ADD ANIMATION OF PLANE CRASHING INTO A HARBOUR, THEN LEVEL IS DONE
	else {
		_LEVEL = "_MainMenu";
	}
	return window;
}

ConsoleWindow DinseyPlanes::_Hiroshima(ConsoleWindow window, int windowWidth, int windowHeight)
{
	window = m_Sky.draw_asset(window, Vector2(0, 0));
	cloudSpawnTime += SYDEDefaults::getDeltaTime();
	if (HiroshimaScene == 0)
	{
		IntroTimeTaken += SYDEDefaults::getDeltaTime();
		if (IntroTimeTaken >= 3)
		{
			HiroshimaScene++;
			IntroTimeTaken = 0;
		}
	}
	if (HiroshimaScene < 3)
	{
		//DRAW CLOUDS
		if (cloudSpawnTime > 1)
		{
			CloudsDrawn.push_back(m_Clouds[rand() % m_Clouds.size()]);
			CloudsDrawnPos.push_back(Vector2(50,rand()%20));
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
	if (HiroshimaScene == 1)
	{
		window.setTextAtPoint(Vector2(0, 19), "Tutorial: Press 'B' To Use A Bomb            ", WHITE);
		if ((SYDEKeyCode::get('B')._CompareState(KEYDOWN)))
		{
			HiroshimaScene++;
		}
	}
	if (HiroshimaScene == 2)
	{
		m_BombPos.addY(1);
		if (m_BombPos.getY() >= 22)
		{
			m_BombPos = Vector2(28, 5);
			HiroshimaScene++;
		}
	}
	if (HiroshimaScene == 3)
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
	if (HiroshimaScene == 4)
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
	if (HiroshimaScene == 5)
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
	if (HiroshimaScene == 6)
	{
		if (!_TSUBUMMER_UNLOCK)
		{
			_TSUBUMMER_UNLOCK = true;
			unlockPopUp.PopUp("Tsubummer Unlocked!");
		}
		_LEVEL = "_MainMenu";
		m_Explosion.setFrame(0);
		m_BombPos = Vector2(1, 5);
		HiroshimaScene = 0;
	}
	//ONCE BOMB IS OFF SCREEN, PLAY AN ANIMATION.
	return window;
}

ConsoleWindow DinseyPlanes::_Nagasaki(ConsoleWindow window, int windowWidth, int windowHeight)
{
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
		window = m_Dinsey[0].draw_asset(window, Vector2(-6, 0));
		window.setTextAtPoint(Vector2(0, 18), "Dinsey", BLACK_BRIGHTWHITE_BG);
		break;
	case 1:
		window = m_Dupty[0].draw_asset(window, Vector2(-6, 0));
		window.setTextAtPoint(Vector2(0, 18), "Dupty", BLACK_BRIGHTWHITE_BG);
		break;
	case 2:
		window = m_Skibber[0].draw_asset(window, Vector2(-6, 0));
		window.setTextAtPoint(Vector2(0, 18), "Skibber", BLACK_BRIGHTWHITE_BG);
		break;
	case 3:
		if (_SEMICOLON_UNLOCK)
		{
			window = m_SemiColon[0].draw_asset(window, Vector2(-6, 0));
			window.setTextAtPoint(Vector2(0, 18), "Semi-Colon", BLACK_BRIGHTWHITE_BG);
			break;
		}
		char1_choice++;
	case 4:
		if (_RIPPERONI_UNLOCK)
		{
			window = m_Ripperoni[0].draw_asset(window, Vector2(-6, 0));
			window.setTextAtPoint(Vector2(0, 18), "Ripperoni", BLACK_BRIGHTWHITE_BG);
			break;
		}
		char1_choice++;
	case 5:
		if (_TSUBUMMER_UNLOCK)
		{
			window = m_Tsubummer[0].draw_asset(window, Vector2(-6, 0));
			window.setTextAtPoint(Vector2(0, 18), "Tsubummer", BLACK_BRIGHTWHITE_BG);
			break;
		}
		char1_choice++;
	default:
		window = m_Dinsey[0].draw_asset(window, Vector2(-6, 0));
		window.setTextAtPoint(Vector2(0, 18), "Dinsey", BLACK_BRIGHTWHITE_BG);
		char1_choice = 0;
		break;
	}
	switch (char2_choice)
	{
	case 0:
		window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
		window.setTextAtPoint(Vector2(34, 18), "Dinsey", WHITE);
		break;
	case 1:
		window = m_Dupty[1].draw_asset(window, Vector2(0, 0));
		window.setTextAtPoint(Vector2(35, 18), "Dupty", WHITE);
		break;
	case 2:
		window = m_Skibber[1].draw_asset(window, Vector2(0, 0));
		window.setTextAtPoint(Vector2(33, 18), "Skibber", WHITE);
		break;
	case 3:
		if (_SEMICOLON_UNLOCK)
		{
			window = m_SemiColon[1].draw_asset(window, Vector2(0, 0));
			window.setTextAtPoint(Vector2(30, 18), "Semi-Colon", WHITE);
			break;
		}
		char2_choice++;
	case 4:
		if (_RIPPERONI_UNLOCK)
		{
			window = m_Ripperoni[1].draw_asset(window, Vector2(0, 0));
			window.setTextAtPoint(Vector2(31, 18), "Ripperoni", WHITE);
			break;
		}
		char2_choice++;
	case 5:
		if (_TSUBUMMER_UNLOCK)
		{
			window = m_Tsubummer[1].draw_asset(window, Vector2(0, 0));
			window.setTextAtPoint(Vector2(31, 18), "Tsubummer", WHITE);
			break;
		}
		char2_choice++;
	default:
		window = m_Dinsey[1].draw_asset(window, Vector2(0, 0));
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
				if (_TSUBUMMER_UNLOCK)
					break;
				char1_choice--;
			case 4:
				if (_RIPPERONI_UNLOCK)
					break;
				char1_choice--;
			case 3:
				if (_SEMICOLON_UNLOCK)
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
				if (_TSUBUMMER_UNLOCK)
					break;
				char2_choice--;
			case 4:
				if (_RIPPERONI_UNLOCK)
					break;
				char2_choice--;
			case 3:
				if (_SEMICOLON_UNLOCK)
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
		_LEVEL = "_MainMenu";
	}
	if ((SYDEKeyCode::get(VK_SPACE)._CompareState(KEYDOWN)))
	{
		_LEVEL = "_Battle";
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
		_LEVEL = "_Battle_Select";
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
