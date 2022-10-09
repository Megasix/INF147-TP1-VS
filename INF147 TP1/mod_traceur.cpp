#include "mod_traceur.h"

void TRACEUR_initialiser_fenetre()
{
	initwindow(DIM_LARGEUR, DIM_HAUTEUR);
}

void TRACEUR_ligne(int x_1, int y_1, int x_2, int y_2){
    setcolor(WHITE);
    line(x_1, y_1, x_2, y_2);
    setcolor(LIGHTCYAN);
    circle(x_1, y_1, R_FAISCEAU);
    circle(x_2, y_2, R_FAISCEAU);

    if(x_2-x_1==0 && y_2-y_1!=0){
        line(x_1, y_1+R_FAISCEAU, x_2, y_2+R_FAISCEAU);
        line(x_1, y_1-R_FAISCEAU, x_2, y_2-R_FAISCEAU);
    }else if (x_2-x_1!=0 && y_2-y_1==0){
        line(x_1+R_FAISCEAU, y_1, x_2+R_FAISCEAU, y_2);
        line(x_1-R_FAISCEAU, y_1, x_2-R_FAISCEAU, y_2);
    }else{

    }
}