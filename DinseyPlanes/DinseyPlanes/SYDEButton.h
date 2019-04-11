#pragma once
#include <string>
#include "ConsoleWindow.h"
#include "Vector2.h"
#include "SYDEUI.h"
#include "SYDEWindowGame.h"

class SYDEButton : public SYDEUI, public SYDEUIInterface {
public:
	SYDEButton() { m_Label = ""; }
	SYDEButton(string a_text, Vector2 a_Pos, Vector2 a_Size, ColourClass txtColour, bool _TRANSPARENTBG);
	virtual ~SYDEButton() {}

	ConsoleWindow draw_ui(ConsoleWindow window) override;

	void addText(string a_text) { m_Text += a_text; }
	void setText(string a_text) { m_Text = a_text; }
	void removeText(int amt) { m_Text = m_Text.substr(0, m_Text.size() - amt); }

	void _WrapText(bool _WRAP) { _WRAPTEXT = _WRAP; }
	void _HIGHLIGHT(bool _HILGHT) { _HIGHLIGHTED = _HILGHT; }
	void setHighLight(ColourClass _COLR) { HiLightColour = _COLR; }

	void ButtonPress() { m_BtnState = BUTTONCLICKED; }

	SYDEButton& operator=(SYDEButton other);

	void setActive(bool active) { m_Active = active; }
	bool getActive() { return m_Active; }
private:

	bool m_Active = false;

	bool _WRAPTEXT = false;
	bool _TRANSPARENT = false;
	bool _HIGHLIGHTED = false;
	Vector2 m_Size = Vector2(0, 0);
	Vector2 m_Pos = Vector2(0, 0);
	ColourClass TextColour = NULLCOLOUR;
	ColourClass HiLightColour = NULLCOLOUR;
};