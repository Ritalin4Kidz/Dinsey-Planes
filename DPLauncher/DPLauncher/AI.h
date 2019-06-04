#pragma once
#include "Vector2.h"
#include <string>
#include "ConsoleWindow.h"
#include <vector>
using namespace std;
class AI {
public:
	AI(string filename) { m_filename = filename; }
	virtual ~AI() {}

	Vector2 bestMove(string board);

	bool existingMove(string board, Vector2 move);

	void addWinMove(string board, Vector2 move);

	vector<string> returnBoard(int index);
	vector<string> returnWinningMove(int index);

	int getBrainSize();
private:
	string m_filename;
};