#pragma once
#include <vector>
#include "ConsoleWindow.h"

using namespace std;

class CustomAsset {
public:
	CustomAsset() {}
	CustomAsset(int width, int height, vector<ColourClass> colour_array) { setAsset(width, height, colour_array); }

	virtual ~CustomAsset() {}

	void operator=(CustomAsset other);

	ConsoleWindow draw_asset(ConsoleWindow window, Vector2 point);
	void setAsset(int width, int height, vector<ColourClass> colourClassArray);
	void setAsset(vector<vector<TextItem>> asset) { AssetVector = asset; }

private:
	vector<vector<TextItem>> AssetVector;

};