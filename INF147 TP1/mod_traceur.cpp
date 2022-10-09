#include "mod_traceur.h"
#include "mod_math.h"

void TRACEUR_initialiser_fenetre()
{
	initwindow(DIM_LARGEUR, DIM_HAUTEUR);
}

void TRACEUR_ligne(int x_1, int y_1, int x_2, int y_2){
    int delta_x = (int) MATH_valeur_absolue((double)x_1-x_2);
    int delta_y = (int) MATH_valeur_absolue((double)y_1-y_2);


    setcolor(WHITE);
    line(x_1, y_1, x_2, y_2);
    setcolor(LIGHTCYAN);
    circle(x_1, y_1, R_FAISCEAU);
    circle(x_2, y_2, R_FAISCEAU);

    if(delta_x==0 && delta_y!=0){
        line(x_1, y_1+R_FAISCEAU, x_2, y_2+R_FAISCEAU);
        line(x_1, y_1-R_FAISCEAU, x_2, y_2-R_FAISCEAU);
    }else if (delta_x!=0 && delta_y==0){
        line(x_1+R_FAISCEAU, y_1, x_2+R_FAISCEAU, y_2);
        line(x_1-R_FAISCEAU, y_1, x_2-R_FAISCEAU, y_2);
    }else{
        double angle = MATH_atan((double) (delta_y)/(delta_x));
        int dplc_x = (int) MATH_cos(angle)*R_FAISCEAU;
        int dplc_y = (int) MATH_sin(angle)*R_FAISCEAU;
        if(y_1>y_2){
            line(x_1+dplc_x, y_1+dplc_y, x_2+dplc_x, y_2+dplc_y);
            line(x_1-dplc_x, y_1-dplc_y, x_2-dplc_x, y_2-dplc_y);
        } else {
            line(x_1+dplc_x, y_1-dplc_y, x_2+dplc_x, y_2-dplc_y);
            line(x_1-dplc_x, y_1+dplc_y, x_2-dplc_x, y_2+dplc_y);
        }
    }
}