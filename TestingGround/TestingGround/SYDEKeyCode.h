#pragma once
#include "SYDEKey.h"
#include <vector>
#include <string>
class SYDEKeyCode {
public:
	static std::string KeysDown();
	static std::vector<SYDEKey> KeyCodes;
	static SYDEKey get(char KeyCode);
	static SYDEKey A; //0
	static SYDEKey B; //1
	static SYDEKey C; //2
	static SYDEKey D; //3
	static SYDEKey E; //4
	static SYDEKey F; //5
	static SYDEKey G; //6
	static SYDEKey H; //7
	static SYDEKey I; //8
	static SYDEKey J; //9
	static SYDEKey K; //10
	static SYDEKey L; //11
	static SYDEKey M; //12
	static SYDEKey N; //13
	static SYDEKey O; //14
	static SYDEKey P; //15
	static SYDEKey Q; //16
	static SYDEKey R; //17
	static SYDEKey S; //18
	static SYDEKey T; //19
	static SYDEKey U; //20
	static SYDEKey V; //21
	static SYDEKey W; //22
	static SYDEKey X; //23
	static SYDEKey Y; //24
	static SYDEKey Z; //25
	//Other Keys
	static SYDEKey Return;
	static SYDEKey Backspace;
	static SYDEKey Space;
	static SYDEKey ArrowLeft;
	static SYDEKey ArrowRight;
	static SYDEKey ArrowUp;
	static SYDEKey ArrowDown;
	static SYDEKey LeftShift;
	static SYDEKey RightShift;
	static SYDEKey LeftTab;
};