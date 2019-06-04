#pragma once
#include <vector>
#include "ConsoleWindow.h"
#include "CustomAsset.h"
#include <windows.h>

using namespace std;

class CustomAnimationAsset {
public:
	CustomAnimationAsset() {}
	CustomAnimationAsset(vector<CustomAsset> frames) { setAsset(frames); }

	virtual ~CustomAnimationAsset() {}

	void operator=(CustomAnimationAsset other);
	void resetAnimation() { frame_number = 0; }

	void setFrame(int aFrameNo);
	int getFrame() { return frame_number; }
	int getFrameSize() { return m_Frames.size(); }

	void setLooping(bool aLoop) { m_looping = aLoop; }
	void toggleLooping() { m_looping = !m_looping; }

	bool getLooping() { return m_looping; }

	void setPaused(bool aPause) { m_paused = aPause; }
	void togglePaused() { m_paused = !m_paused; }

	bool getPaused() { return m_paused; }

	ConsoleWindow draw_asset(ConsoleWindow window, Vector2 point);
	void setAsset(vector<CustomAsset> frames);

private:
	vector<CustomAsset> m_Frames;
	int frame_number = 0;
	bool m_looping = false;
	bool m_paused = false;
};