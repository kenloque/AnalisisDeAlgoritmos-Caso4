#include "point.h"

class List{
    public:
        Point* firstFrom;
        Point* firstTo;

        List(){
            firstFrom = firstTo = NULL;
        }

        void add(Point* pFrom, Point* pTo){
            Point* auxFrom = firstFrom;
            Point* auxTo = firstTo;
            firstFrom = pFrom;
            firstTo = pTo;
            pFrom->next = auxFrom;
            pTo->next = auxTo;
        }

        void print(){
            Point* auxFrom = firstFrom;
            Point* auxTo = firstTo;
            while(auxFrom != NULL && auxTo != NULL){
                cout<< "[(" << auxFrom->x << "," << auxFrom->y << "),(" << auxTo->x << "," << auxTo->y << ")]" << endl;
                auxFrom = auxFrom->next;
                auxTo = auxTo->next;
            }
        }
};