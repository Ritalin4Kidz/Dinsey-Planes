// TestingGround.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

__interface IAction {
public:

	void actionVoid();
};

class PlaceHolders {
public:
	static void NullFunction();
};
class MainAction : public IAction {
public:
	MainAction() {}
	virtual ~MainAction() {}
	void actionVoid() override;
};

class SecAction : public IAction {
public:
	SecAction() { m_f = PlaceHolders::NullFunction; }
	SecAction(void(*f)()) { m_f = f; }
	virtual ~SecAction() {}
	void actionVoid() override;
private:
	void(*m_f)();
};

class MainActionClass {
public:
	MainActionClass() { }
	virtual ~MainActionClass() {}

	void DoAction(IAction &action);
private:

};

void testVoid()
{
	std::cout << "this is a test project!\n";
}

void testVoid2()
{
	std::cout << "this is not a test project!\n";
}

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
	m_f();
}

void PlaceHolders::NullFunction()
{
}
