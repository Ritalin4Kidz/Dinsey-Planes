#pragma once
#include <string>
#include "ConsoleWindow.h"
#include "Vector2.h"
#include "SYDEUI.h"

class SYDELabel : public SYDEUI, public SYDEUIInterface {
public:
	SYDELabel() { m_Label = ""; }
	SYDELabel(string a_text, Vector2 a_Pos, Vector2 a_Size, ColourClass txtColour, bool _TRANSPARENTBG);
	virtual ~SYDELabel() {}

	ConsoleWindow draw_ui(ConsoleWindow window) override;

	void addText(string a_text) { m_Text += a_text; }
	void setText(string a_text) { m_Text = a_text; }
	void removeText(int amt) {m_Text = m_Text.substr(0, m_Text.size() - amt);}

	void _WrapText(bool _WRAP) { _WRAPTEXT = _WRAP; }

private:
	bool _WRAPTEXT = false;
	bool _TRANSPARENT = false;
	Vector2 m_Size = Vector2(0, 0);
	Vector2 m_Pos = Vector2(0, 0);
	ColourClass TextColour = NULLCOLOUR;

};
