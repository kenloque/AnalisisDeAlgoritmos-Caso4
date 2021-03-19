#include "list.h"

void createPoints(Point* points[], double pWidth, double pHeight);
void draw(double pWidth, double pHeight, List* pLines);

int main(){
    double width = 10;
    double height = 30;

    List* linesList = new List();
    draw(width,height,linesList);
    linesList->print();

    return 0;
}

void draw(double pWidth, double pHeight, List* pLines){
    Point* initialPoints[4];
    Point* nextPoints[4];
    createPoints(initialPoints, pWidth, pHeight);

    // Desarrollo aun no escrito en codigo

    pLines->add(initialPoints[0],initialPoints[1]);
}



void createPoints(Point* points[], double pWidth, double pHeight){
    points[0] = new Point(0,0);
    points[1] = new Point(0,pHeight);
    points[2] = new Point(pWidth,pHeight);
    points[3] = new Point(pWidth,0);
}