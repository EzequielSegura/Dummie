#ifndef COLLIDER_H
#define COLLIDER_H

#include <vector>
#include <cmath>
#include <graphics.h>


class Collider 
{
private:
    float x;
    float y;
    float width;
    float height;

public:
    Collider(float x, float y, float width, float height) : x(x), y(y), width(width), height(height){};

    bool checkCollision(const Collider& otherCollider) const;
    static void checkCollisions(const std::vector<Collider>& colliders);
    void drawCollider(int r, int g, int b);
    void setPosition(int newX, int newY);
    void setSize(int newWidth, int newHeight);
};
#endif 
