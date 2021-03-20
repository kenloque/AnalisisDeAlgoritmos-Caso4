#include "list.h"

void createPointsDerechos(Point* points[], double pWidth, double pHeight, double pInicioX, double pInicioY);
void createPointsTorcidos(Point* nextPoints[], double pWidth, double pHeight, double inicioX, double inicioY, double auxInicioX, double auxInicioY, double auxAncho, double auxAlto);
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
    double inicioX = 0;
    double inicioY = 0;

    for(int i=0; i<10; i++){
        int distX = pWidth-inicioX;
		int distY = pHeight-inicioY;
		int reduccionX = (distX*4)/100;
		int reduccionY = (distY*4)/100;
		int divRellenoX = (reduccionX*25)/100;
		int divRellenoY = (reduccionY*25)/100;

        createPointsDerechos(initialPoints, pWidth, pHeight, inicioX, inicioY);
        for(int i=0;i<3;i++){
            pLines->add(initialPoints[i],initialPoints[i+1]);
			//Agrega el relleno de este cuadro
			if(i%2 == 0){
				(initialPoints[i+1])->y+=(divRellenoY);
				pLines->add(initialPoints[i], initialPoints[i+1]);
				(initialPoints[i+1])->y+=(divRellenoY);
				pLines->add(initialPoints[i], initialPoints[i+1];
				(initialPoints[i+1])->y+=(divRellenoY);
				pLines->add(initialPoints[i], initialPoints[i+1]);
				(initialPoints[i+1])->y+=(divRellenoY);
				pLines->add(initialPoints[i], initialPoints[i+1]);
				(initialPoints[i+1])->y-=(4*divRellenoY);
			}else{
				(initialPoints[i+1])->x+=(divRellenoX);
				pLines->add(initialPoints[i], initialPoints[i+1]);
				(initialPoints[i+1])->x+=(divRellenoX);
				pLines->add(initialPoints[i], initialPoints[i+1]);
				(initialPoints[i+1])->x+=(divRellenoX);
				pLines->add(initialPoints[i], initialPoints[i+1]);
				(initialPoints[i+1])->x+=(divRellenoX);
				pLines->add(initialPoints[i], initialPoints[i+1]);
				(initialPoints[i+1])->x-=(4*divRellenoX);
			}
        }
        pLines->add(initialPoints[4],initialPoints[1]);
        (initialPoints[1])->x+=(divRellenoX);
        pLines->add(initialPoints[4], initialPoints[1]);
		(initialPoints[1])->x+=(divRellenoX);
		pLines->add(initialPoints[4], initialPoints[1]);
		(initialPoints[1])->x+=(divRellenoX);
		pLines->add(initialPoints[4], initialPoints[1]);
		(initialPoints[1])->x+=(divRellenoX);
		pLines->add(initialPoints[4], initialPoints[1]);
		(initialPoints[1])->x-=(4*divRellenoX);

        int auxInicioX = inicioX + reduccionX;
		int auxInicioY = inicioY + reduccionY;
		int auxAncho = pWidth - reduccionX;
		int auxAlto = pHeight - reduccionY;

        createPointsTorcidos(nextPoints, pWidth, pHeight, inicioX, inicioY, auxInicioX, auxInicioY, auxAncho, auxAlto);
        for(int i=0;i<3;i++){
            pLines->add(nextPoints[i],nextPoints[i+1]);
			//Agrega el relleno de este cuadro
			          
        }
        pLines->add(nextPoints[4],nextPoints[1]);
        

        inicioX = auxInicioX;
		inicioY = auxInicioY;
	    pWidth = auxAncho;
		pHeight = auxAlto;
    }
}


void createPointsDerechos(Point* points[], double pWidth, double pHeight, double pInicioX, double pInicioY){
    points[0] = new Point(pInicioX,pInicioY);
    points[1] = new Point(pInicioX,pHeight);
    points[2] = new Point(pWidth,pHeight);
    points[3] = new Point(pWidth,pInicioY);
}

void createPointsTorcidos(Point* points[], double pWidth, double pHeight, double inicioX, double inicioY, double auxInicioX, double auxInicioY, double auxAncho, double auxAlto){
    points[0] = new Point(auxInicioX,inicioY);
    points[1] = new Point(inicioX,auxAlto);
    points[2] = new Point(auxAncho,pHeight);
    points[3] = new Point(pWidth,auxInicioY);
}
