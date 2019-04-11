#pragma once
#include <string>
#include <vector>

using namespace std;
enum TextState {
	TEXTNONE,
	TEXTCHANGED,
	TEXTENTER
};

enum ButtonState {
	BUTTONNONE,
	BUTTONCLICKED
};

__interface SYDEUIInterface
{
	virtual ConsoleWindow draw_ui(ConsoleWindow window) {}
};

class SYDEUI
{
public:
	bool _CompareTextState(TextState m_State) { return m_State == m_TxtState; }
	bool _CompareButtonState(ButtonState m_State) { return m_State == m_BtnState; }
	void _CheckState() {
		if (m_Text == m_LastText)
		{
			m_TxtState = TEXTNONE;
		}
		else {
			m_TxtState = TEXTCHANGED;
		}
		m_LastText = m_Text;
	}
	void _Enter()
	{
		m_TxtState = TEXTENTER;
	}
	string m_Text = "";
	string m_Label = "";
protected:
	TextState m_TxtState = TEXTNONE;
	ButtonState m_BtnState = BUTTONNONE;
	string m_LastText = "";
};