#include <iostream>
#include <fstream>
#include <cassert>

#include "vector2d.h"

using namespace std;

int main(int argn, char const* argv[])
{
    assert(argn == 2);

    ifstream file(argv[1]);
    assert(file.is_open());

    Vector2D size;
    Vector2D currP;
    Vector2D currV;
    double time;

    file >> size >> currP >> currV >> time;

    file.close();

    while (time > 0.0f) {
        Vector2D path = currV * time;
        Vector2D tP = currP + path;

        Vector2D intersect;
        bool isIntersectX = false;
        bool isIntersectY = false;
        double timePath = time;

        if (tP.x <= 0) {
            isIntersectX = true;
            intersect.x = 0;
        }
        else if (tP.x >= size.x) {
            isIntersectX = true;
            intersect.x = size.x;
        }

        if (tP.y <= 0) {
            isIntersectY = true;
            intersect.y = 0;
        }
        else if (tP.y >= size.y) {
            isIntersectY = true;
            intersect.y = size.y;
        }

        if (isIntersectX || isIntersectY) {
            Vector2D timeToIntersect;
            timeToIntersect.x = (intersect.x - currP.x) / currV.x;
            timeToIntersect.y = (intersect.y - currP.y) / currV.y;
            if (isIntersectX && isIntersectY) {
                if (timeToIntersect.x > timeToIntersect.y) {
                    isIntersectX = false;
                }
                else {
                    isIntersectY = false;
                }
            }
            if (isIntersectX) {
                timePath = timeToIntersect.x;
                double dy = timePath * currV.y;
                intersect.y = currP.y + dy;
            }
            else if (isIntersectY) {
                timePath = timeToIntersect.y;
                double dx = timePath * currV.x;
                intersect.x = currP.x + dx;
            }
            currP = intersect;
        }
        else {
            timePath = path.getLength() / currV.getLength();
            currP = tP;
        }

        time -= timePath;
        if (isIntersectX) {
            currV.x *= -1;
        }
        if (isIntersectY) {
            currV.y *= -1;
        }
    }

    std::cout << currP;

    return 0;
}
