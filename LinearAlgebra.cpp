
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector3D.h"

using namespace sf;

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
