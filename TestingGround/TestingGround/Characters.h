#pragma once
#include "ConsoleWindow.h"

class Characters {
public:
	Characters() {}
	virtual ~Characters() {}

	//FIRST APPEARANCE, OPENING CUTSCENE
	ConsoleWindow draw_truck_syde_001(ConsoleWindow window, Vector2 point);
	ConsoleWindow draw_girl_diptio_park(ConsoleWindow window, Vector2 point);

	//FIRST APPEARANCE, BREAK_ROOM_001
	ConsoleWindow draw_player(ConsoleWindow window, Vector2 point, ColourClass Clothes1, ColourClass Clothes2, ColourClass Accessory, ColourClass Skin, string lookAngle, string charName);
	ConsoleWindow draw_player_wireframe(ConsoleWindow window, Vector2 point, ColourClass Clothes1, ColourClass Clothes2, ColourClass Accessory, ColourClass Skin, string lookAngle, string charName);
private:
};