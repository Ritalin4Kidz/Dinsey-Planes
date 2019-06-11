#pragma once
#include "PhysicsObject.h"
class Trap : public RigidBody {
public:
	Trap(string id, Vector2 pos, float weight) { setKinematic(false); setID(id); setPosition(pos); setWeight(weight); }
	virtual ~Trap() {}
private:

};