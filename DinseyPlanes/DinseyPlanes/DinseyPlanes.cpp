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

	m_PearlHarbour.setFrame(0);

	m_Tutorial.setAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Animations\\PearlHarbour\\Scene_005.bmp", 22, 20));

	m_Sky = CustomAsset(44, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\DinseyPlanes\\Clouds\\SKY.bmp", 22, 20)),

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
		window.setTextAtPoint(Vector2(0, 12), "A. Level Select", window.determineColourAtPoint(Vector2(2, 1), BLACK, true));
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
		if ((SYDEKeyCode::get('Z')._CompareState(KEYDOWN)))
		{
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

ConsoleWindow DinseyPlanes::_PearlHarbour(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if (PearlHarbourScene == 0)
	{
		window = m_PearlHarbour.draw_asset(window, Vector2(0, 0));
		Sleep(100);
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
		Sleep(100);
	}
	else if (PearlHarbourScene == 2)
	{
		if (m_PearlHarbourFlyDown.getFrame() == 28)
		{
			PlaySound(AssetsClass::get_explosion_file_path(), NULL, SND_FILENAME | SND_ASYNC);
		}
		window = m_PearlHarbourFlyDown.draw_asset(window, Vector2(0, 0));
		Sleep(100);
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
		}
		window = m_Credits.draw_asset(window, Vector2(0, 0));
		for (int i = 0; i < windowWidth; i++)
		{
			window.setTextAtPoint(Vector2(i, 19), " ", BLACK);
		}
		window.setTextAtPoint(Vector2(0, 19), "Level Complete: Press 'Q' To Return", WHITE);
		_PEARLHARBOURBEATEN = true;
		Sleep(100);
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
	if (HiroshimaScene < 2)
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

	}
	if (HiroshimaScene == 1)
	{
		window.setTextAtPoint(Vector2(0, 19), "Tutorial: Press 'B' To Use A Bomb", WHITE);
	}
	//ONCE BOMB IS OFF SCREEN, PLAY AN ANIMATION.
	return window;
}

ConsoleWindow DinseyPlanes::_Nagasaki(ConsoleWindow window, int windowWidth, int windowHeight)
{
	return window;
}

bool DinseyPlanes::GetKey(char KeyCode)
{
	return GetAsyncKeyState(KeyCode) && 0x8000;
}
