#pragma once
#include <string>
#include "ConsoleWindow.h"
#include "Vector2.h"
#include "SYDEUI.h"
#include "SYDEButton.h"
#include <vector>

using namespace std;

class SYDEMenu {
public:
	SYDEMenu() {}
	SYDEMenu(vector<SYDEButton> _ITEMS) { m_Items = _ITEMS; m_Items[0]._HIGHLIGHT(true); }
	virtual ~SYDEMenu() {}

	ConsoleWindow draw_menu(ConsoleWindow window);
	void setActive(bool _ACTV) { m_Active = _ACTV; }
	bool getActive() { return m_Active; }

	SYDEButton& operator[](int i) { return m_Items[i]; }

	void prevSelect();
	void nextSelect();
	void hiLight();

	int getSize() { return m_Items.size(); }
	int getSelectedNumber() { return selectionNumber; }
	SYDEButton& getSelected() { return m_Items[selectionNumber]; }
	void setPos(Vector2 newPos) { m_Pos = newPos; }
private:
	vector<SYDEButton> m_Items;
	Vector2 m_Pos = Vector2(0, 0);

	bool m_Active = false;

	int selectionNumber = 0;
};