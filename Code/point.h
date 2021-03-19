#include <iostream>

using namespace std;

class Point{
    public:
        double x;
        double y;
        Point* next;

        Point(double pX, double pY){
            x = pX;
            y = pY;
            next = NULL;
        } 
};