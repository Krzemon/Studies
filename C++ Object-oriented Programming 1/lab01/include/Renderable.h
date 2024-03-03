#ifndef RENDERABLE_H
#define RENDERABLE_H

class Renderable {
public:
    virtual ~Renderable() {}
    virtual void draw() = 0;
};

#endif // RENDERABLE_H