#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
    virtual ~GameObject() {}
    virtual void attack() = 0;
};

#endif // GAMEOBJECT_H