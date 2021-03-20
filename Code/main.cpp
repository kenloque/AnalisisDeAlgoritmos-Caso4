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
    double inicioX = 0;															//--> 1
    double inicioY = 0;															//--> 1						3 +

    for(int i=0; i<10; i++){													//--> 1 + (3...				19 +
        int distX = pWidth-inicioX;												//--> 2
		int distY = pHeight-inicioY;											//--> 2
		int reduccionX = (distX*4)/100;											//--> 3
		int reduccionY = (distY*4)/100;											//--> 3
		int divRellenoX = (reduccionX*25)/100;									//--> 3
		int divRellenoY = (reduccionY*25)/100;									//--> 3

        createPointsDerechos(initialPoints, pWidth, pHeight, inicioX, inicioY);	//--> 5						14 +
        for(int i=0;i<3;i++){													//--> 4				N=3							
            pLines->add(initialPoints[i],initialPoints[i+1]);					//--> 5
			//Agrega el relleno de este cuadro
			if(i%2 == 0){														//--> 1						50 +		
				(initialPoints[i+1])->y+=(divRellenoY);							//--> 6
				pLines->add(initialPoints[i], initialPoints[i+1]);				//--> 5
				(initialPoints[i+1])->y+=(divRellenoY);							//--> 6
				pLines->add(initialPoints[i], initialPoints[i+1]);				//--> 5
				(initialPoints[i+1])->y+=(divRellenoY);							//--> 6
				pLines->add(initialPoints[i], initialPoints[i+1]);				//--> 5
				(initialPoints[i+1])->y+=(divRellenoY);							//--> 6
				pLines->add(initialPoints[i], initialPoints[i+1]);				//--> 5
				(initialPoints[i+1])->y-=(4*divRellenoY);						//--> 5
			}else{
				(initialPoints[i+1])->x+=(divRellenoX);							//--> 6						49 +
				pLines->add(initialPoints[i], initialPoints[i+1]);				//--> 5
				(initialPoints[i+1])->x+=(divRellenoX);							//--> 6
				pLines->add(initialPoints[i], initialPoints[i+1]);				//--> 5
				(initialPoints[i+1])->x+=(divRellenoX);							//--> 6
				pLines->add(initialPoints[i], initialPoints[i+1]);				//--> 5
				(initialPoints[i+1])->x+=(divRellenoX);							//--> 6
				pLines->add(initialPoints[i], initialPoints[i+1]);				//--> 5
				(initialPoints[i+1])->x-=(4*divRellenoX);						//--> 5
			}
        }
        pLines->add(initialPoints[4],initialPoints[1]);							//--> 4						41 +		
        (initialPoints[1])->x+=(divRellenoX);									//--> 4
        pLines->add(initialPoints[4], initialPoints[1]);						//--> 4
		(initialPoints[1])->x+=(divRellenoX);									//--> 4
		pLines->add(initialPoints[4], initialPoints[1]);						//--> 4
		(initialPoints[1])->x+=(divRellenoX);									//--> 4
		pLines->add(initialPoints[4], initialPoints[1]);						//--> 4
		(initialPoints[1])->x+=(divRellenoX);									//--> 4
		pLines->add(initialPoints[4], initialPoints[1]);						//--> 4
		(initialPoints[1])->x-=(4*divRellenoX);									//--> 5

        int auxInicioX = inicioX + reduccionX;									//--> 2						8 + 9 + 1 +
		int auxInicioY = inicioY + reduccionY;									//--> 2
		int auxAncho = pWidth - reduccionX;										//--> 2
		int auxAlto = pHeight - reduccionY;										//--> 2

        createPointsTorcidos(nextPoints, pWidth, pHeight, inicioX, inicioY, auxInicioX, auxInicioY, auxAncho, auxAlto);	//--> 9
        for(int i=0;i<3;i++){													//--> 1+(3 +..				8 +
            pLines->add(nextPoints[i],nextPoints[i+1]);							//--> 5)*N
			//Agrega el relleno de este cuadro
			          
        }
        pLines->add(nextPoints[4],nextPoints[1]);								//--> 4						4 +
        

        inicioX = auxInicioX;													//--> 1						4 +
		inicioY = auxInicioY;													//--> 1
	    pWidth = auxAncho;														//--> 1
		pHeight = auxAlto;														//--> 1
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
