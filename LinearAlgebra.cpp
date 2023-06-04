
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

struct Vector3D
{
    float x, y, z;

    Vector3D() = default;

    Vector3D(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    float& operator [](int i)
    {
        return ((&x)[i]);
    }

    const float& operator [](int i) const
    {
        return ((&x)[i]);
    }
};


int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "LinearAlgebra", Style::Fullscreen);

    Vector3D vector(4, 8, 16);

    std::cout << vector[0];
    std::cout << vector[1];
    std::cout << vector[2];

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
    }

    return 0;
}
