#include "pch.h"
#include "GlobalSettings.h"
std::string GlobalSettings::_SCENE = "DinseyPlanes";
std::string GlobalSettings::_LASTSCENE = "";
std::string GlobalSettings::_LEVEL = "_Intro";
std::string GlobalSettings::_PLANEFLAVOUR = "Dinsey";

int GlobalSettings::FrameDelay_MS = 30;
bool GlobalSettings::PauseMode = false;
bool GlobalSettings::debugMenu = false;
bool GlobalSettings::initWindow = true;
bool GlobalSettings::rs = false;
bool GlobalSettings::GamePlaying = true;
bool GlobalSettings::letsplayer = false;
bool GlobalSettings::framerate = false;
int GlobalSettings::VolumeLVL = 2;

bool GlobalSettings::_PEARLHARBOURBEATEN = false;
bool GlobalSettings::_HIROSHIMABEATEN = false;
bool GlobalSettings::_NAGASAKIBEATEN = false;
bool GlobalSettings::_SEMICOLON_UNLOCK = false;
bool GlobalSettings::_TSUBUMMER_UNLOCK = false;
bool GlobalSettings::_RIPPERONI_UNLOCK = false;

LANGUAGE GlobalSettings::_GAME_LNG = ENGLISH;

SYDELabel GlobalSettings::m_fps = SYDELabel("", Vector2(35, 1), Vector2(5, 1), BRIGHTGREEN, true);;
CustomAnimationAsset GlobalSettings::m_LP;