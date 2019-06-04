#pragma once
#include "ConsoleWindow.h"
#include "Vector2.h"


class Artwork {
public:
	Artwork() {}
	virtual ~Artwork() {}

	ConsoleWindow draw_freebee_bee(ConsoleWindow window, int baseX, int baseY);
	ConsoleWindow draw_syde_engine_logo(ConsoleWindow window, int baseX, int baseY);

private:
};