#include "PlayerCharacter.h"

void PlayerCharacter::attack() {
    std::cout << "PlayerCharacter attacking!" << std::endl;
}

void PlayerCharacter::draw() {
    std::cout << "Drawing Renderable" << std::endl;
    attack(); // Dodatkowe wywołanie metody attack() po zrealizowaniu rysowania
}

namespace gutils {
    void handleGameObject(GameObject* obj) {
        std::cout << "Rendering GameObject" << std::endl;
        obj->attack();
    }

    void handleRenderable(Renderable* obj) {
        obj->draw();
    }
}
