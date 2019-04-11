#pragma once
#include "TextItem.h"
#include "RigidBody.h"
#include <string>
#include "Vector2.h"
using namespace std;
class PhysicsObject : public RigidBody {
public:
	PhysicsObject(string id, Vector2 pos, bool kinematic, float weight) { setKinematic(kinematic); setID(id); setPosition(pos); setWeight(weight); }
	PhysicsObject(string id, Vector2 pos, bool kinematic, float weight, bool solidBottom) { setKinematic(kinematic); setID(id); setPosition(pos); setWeight(weight); setSolidity(solidBottom); }
	virtual ~PhysicsObject() {}

private:
};