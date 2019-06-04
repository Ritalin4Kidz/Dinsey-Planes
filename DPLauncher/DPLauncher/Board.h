#pragma once
#include "BoardPiece.h"
#include <vector>

using namespace std;
class Board {
public:
	Board(vector<BoardPiece> boardpieces, int targetValue, int a_maxTurns) { m_board = boardpieces; m_targetValue = targetValue; maxTurns = a_maxTurns; }
	virtual ~Board() {}

	bool checkWinner(string user);
	void setOccupier(int index, string occupier) { m_board[index].setOccupier(occupier); }
	string getOccupier(int index) { m_board[index].getOccupier(); }

	vector<BoardPiece> getBoard() { return m_board; }
	bool pieceExists(Vector2 pos);
	BoardPiece getPieceAt(Vector2 pos);
	void setOccupierAt(Vector2 pos, string occupier);

	void setValueAt(Vector2 pos, int value);
	int getMaxTurns() { return maxTurns; }
private:
	int m_targetValue;
	int maxTurns;
	vector<BoardPiece> m_board;
};