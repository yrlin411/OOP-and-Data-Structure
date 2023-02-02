#include <cstdlib>
#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
protected:
    float volume;

public:
    Shape() { volume = 0; }
    virtual void computeVolume() = 0;
    void printVolume()
    {
        cout << volume << endl;
    }
};
class Cuboid : public Shape
{
public:
    float l,w,h;
    Cuboid(float length, float width, float height)
    {
        l = length;
        w = width;
        h = height;
    };
    float getVolume();
    virtual void computeVolume()
    {
        volume = l * w * h;
    };
};
class Pyramid : public Shape
{
public:
    float a, h;
    Pyramid(float areaOfBase,float height)
    {
        a = areaOfBase;
        h = height;
    };
    float getVolume();
    virtual void computeVolume()
    {
        volume = a * h /3;
    };
};
class Sphere : public Shape
{
public:
    float r;
    Sphere(float radius)
    {
        r = radius;
    };
    float getVolume();
    virtual void computeVolume()
    {
        volume = (4 * r * r * r * PI) / 3;
    };
};
float Cuboid::getVolume()
{
    return volume;
}

int main()
{
    float a, b, c;
    Shape *shape;

    cin >> a >> b >> c; // Enter the height and width of Rectangle
    Cuboid cub(a, b, c);

    cin >> a >> b; // Enter the bottom and height of Triangle
    Pyramid pyr(a, b);

    cin >> a; // Enter the radius of Circle
    Sphere sph(a);

    shape = &cub;
    shape->computeVolume();
    shape->printVolume();

    shape = &pyr;
    shape->computeVolume();
    shape->printVolume();

    shape = &sph;
    shape->computeVolume();
    shape->printVolume();

    return 0;
}

