#include <collider.h>

bool Collider::checkCollision(const Collider& otherCollider) const {
    return (x < otherCollider.x + otherCollider.width &&
            x + width > otherCollider.x &&
            y < otherCollider.y + otherCollider.height &&
            y + height > otherCollider.y);
}

void Collider::checkCollisions(const std::vector<Collider>& colliders) {
    for (size_t i = 0; i < colliders.size(); ++i) {
        for (size_t j = i + 1; j < colliders.size(); ++j) {
            if (colliders[i].checkCollision(colliders[j])) {
                //std::cout << "Colisión entre Collider " << i + 1 << " y Collider " << j + 1 << std::endl;
            }
        }
    }
}

void Collider::drawCollider(int r, int g, int b) {
    for (int i = x; i < x + width; ++i) {
        pixel(i, y, r,g,b);  // Dibuja el borde superior
        pixel(i, y + height - 1, r,g,b);  // Dibuja el borde inferior
    }
    for (int i = y; i < y + height; ++i) {
        pixel(x, i, r,g,b);  // Dibuja el borde izquierdo
        pixel(x + width - 1, i, r,g,b); // Dibuja el borde derecho
    }
}

void Collider::setPosition(int newX, int newY) {
    x=newX;
    y=newY;
}

void Collider::setSize(int newWidth, int newHeight) {
    width=newWidth;
    height=newHeight;
}