// TestingGround.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

__interface IAction {
public:

	void actionVoid();
};

class MainAction : public IAction {
public:
	MainAction() {}
	virtual ~MainAction() {}
	void actionVoid() override;
};

class SecAction : public IAction {
public:
	SecAction() {}
	virtual ~SecAction() {}
	void actionVoid() override;
};

class MainActionClass {
public:
	MainActionClass() { }
	virtual ~MainActionClass() {}

	void DoAction(IAction &action);
private:
};


int main()
{
	MainAction m;
	MainActionClass mC;
	SecAction s;
	mC.DoAction(m);
	mC.DoAction(s);
}

void MainActionClass::DoAction(IAction &action)
{
	action.actionVoid();
}

void MainAction::actionVoid()
{
	std::cout << "Hello World!\n";
}

void SecAction::actionVoid()
{
	std::cout << "This is an action test\n";
}
