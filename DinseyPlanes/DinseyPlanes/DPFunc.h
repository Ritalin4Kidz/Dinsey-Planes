#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <istream>
#include <sstream>
#include "SYDEstdafx.h"
#include "GlobalSettings.h"
struct DialogueClass {
	DialogueClass(LANGUAGE a_Lng)
	{
		if (a_Lng == PLANE)
		{
			string_mission_dinsous = " *ENGINE NOISES* (A)";
			string_sure_tonoda = " *ENGINE NOISES* (A)";
			string_when_ready_dinsous = " *ENGINE NOISES* (A)";
			string_hiroshima_reached = " *ENGINE NOISES* (A)";
			string_just_reached = " *ENGINE NOISES* (A)";
			string_deliver_package = " *ENGINE NOISES* (A)";
			string_done_well_dinspy = " *ENGINE NOISES* (A)";
			string_just_deliver = " *ENGINE NOISES* (A)";
			string_all_over = " *ENGINE NOISES* (A)";
			string_aye_aye = " *ENGINE NOISES* (A)";
			string_the_americans = " *ENGINE NOISES* (A)";
			string_war_threat = " *ENGINE NOISES* (A)";
			string_hmmmm = " *ENGINE NOISES* (A)";
			string_i_see = " *ENGINE NOISES* (A)";
			string_most_troubling = " *ENGINE NOISES* (A)";
			string_what_shall_we_do = " *ENGINE NOISES* (A)";
			string_i_have_plan = " *ENGINE NOISES* (A)";
			string_dinsous_shout = " *LOUD ENGINE NOISES* (A)";
			string_im_here_sir = " *ENGINE NOISES* (A)";
			string_job_for_you = " *ENGINE NOISES* (A)";
			string_nearly_years = " *ENGINE NOISES* (A)";
			string_but_today = " *ENGINE NOISES* (A)";
			string_fight_back = " *ENGINE NOISES* (A)";
			string_no_more_fear = " *ENGINE NOISES* (A)";
			string_dinspy_shout = " *LOUD ENGINE NOISES* (A)";
			string_yes_sir = " *ENGINE NOISES* (A)";
			string_prepare_luggage = " *ENGINE NOISES* (A)";
			string_going_japan = " *ENGINE NOISES* (A)";
			string_sir_country_wound = " *ENGINE NOISES* (A)";
			string_surrender_neccesary = " *ENGINE NOISES* (A)";
			string_never = " *ENGINE NOISES* (A)";
			string_rather_die = " *ENGINE NOISES* (A)";
			string_hear_something = " *COAWRDLY ENGINE NOISES* (A)";
			string_what_up_to = " *ENGINE NOISES* (A)";
			string_just_chill = " *ENGINE NOISES* (A)";
			string_cruising_in_sky = " *ENGINE NOISES* (A)";
			string_what_up_dups = " *ENGINE NOISES* (A)";
			string_minimme_signing = " *ENGINE NOISES* (A)";
			string_meet_westfield = " *ENGINE NOISES* (A)";
			string_ill_meet_you_there = " *ENGINE NOISES* (A)";
			string_well_x3 = " *ENGINE NOISES* (A)";
			string_if_it_isnt = " *ENGINE NOISES* (A)";
			string_hehe_good_one = " *ENGINE NOISES* (A)";
			string_its_dinsey = " *ENGINE NOISES* (A)";
			string_what_just_call = " *ANGRY ENGINE NOISES* (A)";
			string_excused_tsu = " *ENGINE NOISES* (A)";
			string_no_worries = " *ENGINE NOISES* (A)";
			string_ow = " *ENGINE NOISES* (A)";
			string_dinsey_ok = " *ENGINE NOISES* (A)";
			string_2_week = " *ENGINE NOISES* (A)";
			string_missed_mini = " *ENGINE NOISES* (A)";
			string_noooooo = " *ENGINE NOISES* (A)";
			string_dont_be_sure = " *ENGINE NOISES* (A)";
			string_is_it_really = " *ENGINE NOISES* (A)";
			string_confirmation = " *ENGINE NOISES* (A)";
			string_hooray = " *ENGINE NOISES* (A)";
			string_realisation = " *CONCERNED ENGINE NOISES* (A)";
		}
	}

	//MISSION 1 Dialogue
	//DO YOU REMEMBER YOUR MISSION DINSOUS
	std::string string_mission_dinsous = "Do you remember your mission dinsous?(A)";
	//I SURE DO MR TONODA
	std::string string_sure_tonoda = "I sure do Mr Tonoda!(A)";
	//GOOD...GOOD...WHEN YOU'RE READY
	std::string string_when_ready_dinsous = "Good..Good..When you're ready dinsous(A)";

	//MISSION 2 Dialogue
	//YOU REACHED HIROSHIMA YET?
	std::string string_hiroshima_reached = "Have you reached Hiroshima yet?(A)";
	//JUST REACHED NOW
	std::string string_just_reached = "Just arrived now boss!(A)";
	//DELIVER THE PACKAGE
	std::string string_deliver_package = "Excellent... Deliver the package(A)";

	//MISSION 3 Dialogue
	//YOU'VE DONE WELL DINSPY
	std::string string_done_well_dinspy = "You've done well Dinspy(A)";
	//JUST DELIVER THE PACKAGE TO NAGASAKI
	std::string string_just_deliver = "Just deliver the package to Nagasaki(A)";
	//THIS WILL FINALLY BE OVER
	std::string string_all_over = "and this will all finally be over(A)";
	//AYE AYE CAPTAIN
	std::string string_aye_aye = "Aye Aye Captain(A)";

	//DIALOGUE 1
	std::string string_the_americans = ": Sir... The Americans....";
	std::string string_war_threat = ": They've threatened war with us";
	std::string string_hmmmm = ": Hmmmm...";
	std::string string_i_see = ": I see...";
	std::string string_most_troubling = ": This is most troubling";
	std::string string_what_shall_we_do = ": What ever should we do sir?";
	std::string string_i_have_plan = ": Do not worry, I have a plan";
	std::string string_dinsous_shout = ": DINSOUS!";
	std::string string_im_here_sir = ": I'm here sir, what is it?";
	std::string string_job_for_you = ": I have a job for you";

	//DIALOGUE 2
	std::string string_nearly_years = ": It's been nearly 4 years";
	std::string string_but_today = ": But today....";
	std::string string_fight_back = ": TODAY WE FIGHT BACK!";
	std::string string_no_more_fear = ": WE LIVE IN FEAR NO MORE!";
	std::string string_dinspy_shout = ": DINSPY!";
	std::string string_yes_sir = ": YES SIR!";
	std::string string_prepare_luggage = ": Prepare your luggage";
	std::string string_going_japan = ": You're going to Japan";

	//DIALOGUE 3
	std::string string_sir_country_wound = ": Sir, our country is wounded";
	std::string string_surrender_neccesary = ": we must surrender to the US";
	std::string string_never = ": NEVER!!!";
	std::string string_rather_die = ": I'D RATHER WE ALL DIE!!";
	std::string string_hear_something = ": Do you hear something?";

	//DINSEY's BAD DAY PART 1
	std::string string_what_up_to = "Hey Dinsey, what you up to bud?(A)";
	std::string string_just_chill = "Not much Dupty, just chilling(A)";
	std::string string_cruising_in_sky = "Cruising in the sky, no worries(A)";
	std::string string_what_up_dups = "Why? what's up mr Dups?(A)";
	std::string string_minimme_signing = "Minimme's doing a signing!!(A)";
	std::string string_meet_westfield = "Meet me at westfield(A)";
	std::string string_ill_meet_you_there = "Oh heck yeah, i'll meet you there(A)";
	std::string string_well_x3 = "well...well...well...(A)";
	std::string string_if_it_isnt = "if isn't dins..stupid(A)";
	std::string string_hehe_good_one = "hehe. that's a good one boss(A)";
	std::string string_its_dinsey = "It's dinsey ripper...(A)";
	std::string string_what_just_call = "WHAT DID YOU JUST CALL ME?(A)";
	std::string string_excused_tsu = "Tsu, you're excused, i've got this(A)";
	std::string string_no_worries = "no worries boss(A)";
	std::string string_ow = "ow.......(A)";

	//DINSEY's BAD DAY PART 2
	std::string string_dinsey_ok = ": DINSEY!, YOU'RE OK! (A)";
	std::string string_2_week = ": You were in a coma for 2 weeks!(A)";
	std::string string_missed_mini = ": 2 Weeks? Oh no! that means... (A)";
	std::string string_noooooo = ": I MISSED MINIMME! NOOOOO! (A)";
	std::string string_dont_be_sure = ": Don't be so sure (A)";
	std::string string_is_it_really = ": Minimme? Is it really you?(A)";
	std::string string_confirmation = ": Yes, take a look at my foot(A)";
	std::string string_hooray = ": Hooray!!!!! wait.... (A)";
	std::string string_realisation = ": Why the hospital visit?(A)";

	//CHARACTERS
	//Purplous
	std::string string_purplous = "Purplous";
	//TONODA
	std::string string_tonoda = "Tonoda";
	//SAMSON
	std::string string_samson = "Samson";
	//DINSPY
	std::string string_dinspy = "Dinspy";
	//DINSOUS
	std::string string_dinsous = "Dinsous";
	//DUPTY
	std::string string_dupty = "Dupty";
	//DINSEY
	std::string string_dinsey = "Dinsey";
	//RIPPERONI
	std::string string_ripperoni = "Ripperoni";
	//TSUBUMMER
	std::string string_tsubummer = "Tsubummer";
	//SKIBBER
	std::string string_skibber = "Skibber";
	//SEMICOLON
	std::string string_semicolon = "Semi-Colon";
	//MINIMME
	std::string string_minimme = "Minimme";

	//ETC
	std::string string_q_to_return = "Level Complete: Press 'Q' To Return";
	std::string bomb_tutorial = "Tutorial: Press 'B' To Use A Bomb            ";
	std::string string_draw = "Draw: Press 'Q' To Return";
	std::string the_end = "The End";

};

struct ColourValues {
	ColourValues(int _r, int _g, int _b) { r = _r; dftr = _r; g = _g; dftg = _g; b = _b; dftb = _b; }
	int r;
	int g;
	int b;

	int dftr;
	int dftg;
	int dftb;

	void operator=(ColourValues other) { r = other.r; g = other.g; b = other.b; }
	void set(int _r, int _g, int  _b) { r = _r; dftr = _r; g = _g; dftg = _g; b = _b; dftb = _b; }

	void toDefault() { r = dftr; g = dftg; b = dftb; }
	DWORD toRGB() { return RGB(r, g, b); }
	std::string toRGBStr() { return std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b); }
};
//FUNC AND CONST
class DPFunc {
public:
	static std::string ReturnRandomString();
	static std::vector<std::string> _Commands;
	static std::vector<std::string> _GameScenes;
	static int _GameScenes_Selection;

	static std::string FindCommand(std::string cmd);
	static void VolumeFunc(int volume);

	static DWORD VOLUME_LOW;
	static DWORD VOLUME_NML;
	static DWORD VOLUME_MED;
	static DWORD VOLUME_HIG;
	static DWORD VOLUME_OFF;

	static ColourValues _BLACK;
	static ColourValues _BLUE;
	static ColourValues _GREEN;
	static ColourValues _AQUA;
	static ColourValues _RED;
	static ColourValues _PURPLE;
	static ColourValues _YELLOW;
	static ColourValues _WHITE;
	static ColourValues _LIGHTGREY;
	static ColourValues _DARKBLUE;
	static ColourValues _BRIGHTGREEN;
	static ColourValues _LIGHTBLUE;
	static ColourValues _BRIGHTRED;
	static ColourValues _LIGHTPURPLE;
	static ColourValues _BRIGHTYELLOW;
	static ColourValues _BRIGHTWHITE;

	static ColourValues _RGBLoad(std::string RGBstr, ColourValues rgbV);

	static void Load();
	static void Save();

	static void LoadGame();
	static void SaveGame();

	static void RefreshColour(ConsoleWindow window);

	static void ColourPalette(HANDLE hOut, bool initRS, ConsoleWindow window);

	static std::vector<std::string> Split(std::string a_String, char splitter);
};