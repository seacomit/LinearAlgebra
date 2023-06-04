
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

    Vector3D& operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3D& operator /=(float s)
    {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3D& operator +=(const Vector3D& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }

    Vector3D& operator -=(const Vector3D& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return (*this);
    }
};

inline Vector3D operator +(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline Vector3D operator *(const Vector3D& v, float s)
{
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D& v, float s)
{
    s = 1.0F / s;
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

// Negation not subtraction.
inline Vector3D operator -(const Vector3D& v)
{
    return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude(const Vector3D& v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D& v)
{
    return (v / Magnitude(v));
}

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
