#pragma once
#include <string>
#include "ConsoleWindow.h"
#include "Vector2.h"
#include "SYDEUI.h"
using namespace std;

class SYDETextBox : public SYDEUI, public SYDEUIInterface {
public:
	SYDETextBox() { m_Label = ""; }
	SYDETextBox(string a_Label) { m_Label = a_Label; }
	SYDETextBox(Vector2 a_Pos, Vector2 a_Size, ColourClass txtColour);
	virtual ~SYDETextBox() {}


	ConsoleWindow draw_ui(ConsoleWindow window) override;

	void addText(string a_text) { if (m_Active) { m_Text += a_text; } }
	void removeText(int amt) { if (m_Active) { m_Text = m_Text.substr(0, m_Text.size() - amt); } }
	void setActive(bool active) { m_Active = active; }

	bool getActive() { return m_Active; }
private:
	bool m_Active = false;
	//string m_Text = "";

	Vector2 m_Size = Vector2(0, 0);
	Vector2 m_Pos = Vector2(0,0);
	ColourClass TextColour = NULLCOLOUR;

};