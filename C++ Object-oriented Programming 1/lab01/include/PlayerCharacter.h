#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "GameObject.h"
#include "Renderable.h"
#include <iostream>

class PlayerCharacter : public GameObject, public Renderable {
public:
    void attack() override;
    void draw() override;
};

namespace gutils {
    void handleGameObject(GameObject* obj);
    void handleRenderable(Renderable* obj);
}

#endif // PLAYERCHARACTER_H
