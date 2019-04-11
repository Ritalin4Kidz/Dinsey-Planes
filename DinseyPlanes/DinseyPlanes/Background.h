#pragma once
#include "ConsoleWindow.h"
#include "BackgroundObj.h"
class BackgroundClass {
public:
	BackgroundClass() {}
	virtual ~BackgroundClass() {}
	//DRAW FUNCTIONS
	ConsoleWindow draw_diptio_park_cutscene_bg(ConsoleWindow window, int windowWidth, int windowHeight);

	vector<BackgroundObj> draw_break_room_001(vector<BackgroundObj> bgArr, int windowWidth, int windowHeight);
	vector<BackgroundObj> draw_break_room_002(vector<BackgroundObj> bgArr, int windowWidth, int windowHeight);
	vector<BackgroundObj> draw_holding_cell(vector<BackgroundObj> bgArr, int windowWidth, int windowHeight);

private:
};