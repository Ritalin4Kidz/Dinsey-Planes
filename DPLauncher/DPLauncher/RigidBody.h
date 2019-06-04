#pragma once
#include <vector>
#include <string>
#include "Vector2.h"
#include "ConsoleWindow.h"
using namespace std;
class RigidBody {
public:
	RigidBody() {}
	RigidBody(Vector2 pos, float Weight, bool kinemat) { m_pos = pos; m_Weight = Weight; m_Kinematic = kinemat; }
	virtual ~RigidBody() {}

	void gravity(vector<RigidBody> rigidbodyArray);
	void gravityChildren(vector<RigidBody> rigidbodyArray, vector<RigidBody> children);
	bool checkArrayForHit(vector<RigidBody> rbArr);

	bool operator==(RigidBody rb);
	bool operator!=(RigidBody rb);

	void setKinematic(bool a_val) { m_Kinematic = a_val; }
	void setWeight(float a_val) { m_Weight = a_val; }
	void setPosition(Vector2 a_val) { m_pos = a_val; }
	void setID(string a_ID) { id = a_ID; }

	float getSpeed() { return m_Speed; }
	void setSpeed(float a_speed) { m_Speed = a_speed; }

	void setTrap(bool a_Val) { m_isTrap = a_Val; }
	void setTrigger(bool a_Val, string m_triggerVal) { m_isTrigger = a_Val; levelTrigger = m_triggerVal; }
	void setSolidity(bool a_Val) { m_solidBottom = a_Val; }
	void setInteract(bool a_Val) { m_isInteractable = a_Val; }
	void setInteractString(string a_val) { interactTrigger = a_val; }
	void setNewStartPos(Vector2 newPos) { startPos = newPos; }
	void setColour(ColourClass a_col) { m_colour = a_col; }
	void setParentPos(Vector2 a_Pos) { parent_Pos = a_Pos; differenceFromOrigin = Vector2(parent_Pos.getX() - m_pos.getX(),parent_Pos.getY() - m_pos.getY()); }
	void setConstantSpeed(bool a_Constant, float speed) { constantspeed = a_Constant; constantSpeedFloat = speed; }

	bool getIsTrap() { return m_isTrap; }
	bool getIsTrigger() { return m_isTrigger; }
	bool getSolidity() { return m_solidBottom; }
	bool getInteract() { return m_isInteractable; }
	string getTriggerLevel() { return levelTrigger; }
	string getInteractString() { return interactTrigger; }
	Vector2 getNewStartPos() {return startPos;}
	Vector2 getPos() { return m_pos; }
	ColourClass getColour() { return m_colour; }
	Vector2 getParentPos() { return parent_Pos; }
	Vector2 getDifference() { return differenceFromOrigin; }

	void setTag(string a_tag) { tag = a_tag; }
	string getTag() { return tag; }
private:
	ColourClass m_colour;
	bool m_Kinematic = false;
	float m_Weight = 1.0f;
	bool m_isTrap = false;
	bool m_isTrigger = false;
	bool m_isInteractable = false;
	string levelTrigger = "";
	string interactTrigger = "";
	bool m_solidBottom = false;
	bool constantspeed = false;
	float constantSpeedFloat = 0.0f;
	float m_Speed = 0.0f;
	string id = "";
	Vector2 startPos;
	Vector2 m_pos;
	Vector2 parent_Pos;
	Vector2 differenceFromOrigin;
	string tag = "";
};