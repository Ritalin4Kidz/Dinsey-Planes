#include "pch.h"
#include "DPaint.h"

PaintWindow::PaintWindow(int windowWidth, int windowHeight)
{
	m_CursorPoint = Vector2(10, 5);
	for (int l = 0; l < windowWidth; l++)
	{
		for (int m = 0; m < windowHeight; m++)
		{
			m_PaintingArray.push_back(GAME_RTW_PIXEL(Vector2(l, m)));
		}
	}
}

void PaintWindow::setPaintArrayAtPoint(Vector2 aPoint, ColourClass colour)
{
	for (int i = 0; i < m_PaintingArray.size(); i++)
	{
		if (m_PaintingArray[i].getPoint() == aPoint) {
			m_PaintingArray[i].setColour(colour);
			return;
		}
	}
}

ConsoleWindow PaintWindow::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	if (SYDEKeyCode::get('W')._CompareState(KEY)) {
		m_CursorPoint.addYSafe(-1, 1, windowHeight - 2);
	}
	if (SYDEKeyCode::get('A')._CompareState(KEY)) {
		m_CursorPoint.addXSafe(-2, 0, windowWidth - 2);
	}
	if (SYDEKeyCode::get('S')._CompareState(KEY)) {
		m_CursorPoint.addYSafe(1, 1, windowHeight - 2);
	}
	if (SYDEKeyCode::get('D')._CompareState(KEY)) {
		m_CursorPoint.addXSafe(2, 0, windowWidth - 2);
	}
	if (SYDEKeyCode::get('P')._CompareState(KEY)) {
		setPaintArrayAtPoint(m_CursorPoint, m_PaintColour);
		setPaintArrayAtPoint(Vector2(m_CursorPoint.getX() + 1, m_CursorPoint.getY()), m_PaintColour);
	}
	if (SYDEKeyCode::get('C')._CompareState(KEYDOWN)) {
		colourcode++;
			if (colourcode >= m_paintColours.size()) {
				colourcode = 0;
			}
		m_PaintColour = m_paintColours[colourcode];
	}

	for (int l = 0; l < windowWidth; l++)
	{
		for (int m = 0; m < windowHeight; m++)
		{
			window.setTextAtPoint(Vector2(l, m), " ", WHITE_WHITE_BG);
		}
	}
	for (int i = 0; i < m_PaintingArray.size(); i++)
	{
		window.setTextAtPoint(m_PaintingArray[i].getPoint(), " ", m_PaintingArray[i].getColour());
	}
	// CURSOR
	window.setTextAtPoint(m_CursorPoint, " ", DARKBLUE_DARKBLUE_BG);
	window.setTextAtPoint(Vector2(m_CursorPoint.getX() + 1, m_CursorPoint.getY()), " ", DARKBLUE_DARKBLUE_BG);
	// UI
	for (int i = 0; i < windowWidth; i++)
	{
		window.setTextAtPoint(Vector2(i, windowHeight - 1), " ", BRIGHTWHITE_BRIGHTWHITE_BG);
	}
	if (m_PaintColour == NULLCOLOUR)
	{
		window.setTextAtPoint(Vector2(0, windowHeight - 1), "-", BLACK_BRIGHTWHITE_BG);
		window.setTextAtPoint(Vector2(1, windowHeight - 1), "-", BLACK_BRIGHTWHITE_BG);
	}
	else {
		window.setTextAtPoint(Vector2(0, windowHeight - 1), " ", m_PaintColour);
		window.setTextAtPoint(Vector2(1, windowHeight - 1), " ", m_PaintColour);
	}
	window.setTextAtPoint(Vector2(2, windowHeight - 1), "P:Paint,C:Colour,WASD:Move", BLACK_BRIGHTWHITE_BG);
	return window;
}
GAME_PIXEL::GAME_PIXEL()
{
	m_color = NULLCOLOUR;
	m_point = Vector2(0, 0);
}

GAME_PIXEL::GAME_PIXEL(Vector2 a_Point)
{
	m_color = NULLCOLOUR;
	m_point = a_Point;
}