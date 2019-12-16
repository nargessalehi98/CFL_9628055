#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

//braye n>m javab nmidahad
const int n = 5, m = 8, nos = 3, noo = 1;
int A[n][m];
int Tx, Ty, Px, Py, Ta, Tb, Pa, Pb;

void matrix() {
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
            A[i][j] = 0;
}

// eshqal nashode vali else mikhanad
void first_pos() {
    Tx = 0;
    Ty = 0;
    //int num = 0;
    srand(time(NULL));
    Tx = rand() % m;   //first position of thief
    Ty = rand() % n;   //first position of thief
    A[Tx][Ty] = -1;
    printf("Tx=%d,Ty=%d\n", Tx, Ty);
    for (int i = 1; i <= nos; i++) {
        //num++;
        printf("nos=%d\n", i);
        for (int j = 0; j < noo; j++) {
            Px=0;
            Py=0;
            Px = rand() % m;   //first position of police
            Py = rand() % n;   //first position of police
            printf("Px=%d,Py=%d\n", Px, Py);
            while (1) {
                if (A[Px][Py] == 0) {
                    A[Px][Py] = i;
                    break;
                } else {
                    Px = 0;
                    Py = 0;
                    Px = rand() % m;   //first position of police
                    Py = rand() % n;  //first position of police
                    printf("else Px=%d,Py=%d\n", Px, Py);
                }
            }
        }

    }

}

void thief_move() {
    A[Tx][Ty] = 0;
    int temp1 = (rand() % 3);   //move of thief
    int temp2 = (rand() % 3);//move of thief
    if (temp1 == 0)
        Ta = 0;
    if (temp1 == 1)
        Ta = 1;
    if (temp1 == 2)
        Ta = -1;
    if (temp2 == 0)
        Tb = 0;
    if (temp2 == 1)
        Tb = 1;
    if (temp2 == 2)
        Tb = -1;
    //printf("ym=%d,xm=%d\n", Tb, Ta);
    Tx = Tx + Ta;
    Ty = Ty + Tb;
    while (1) {
        if ((Tx < m && Tx >= 0) && (Ty >= 0 && Ty < n) && A[Tx][Ty]==0) {
            A[Tx][Ty] = -1;
            break;
        } else {
            Tx = Tx - Ta;
            Ty = Ty - Tb;
            temp1 = (rand() % 3);   //move of thief
            temp2 = (rand() % 3);   //move of thief
            if (temp1 == 0)
                Ta = 0;
            if (temp1 == 1)
                Ta = 1;
            if (temp1 == 2)
                Ta = -1;
            if (temp2 == 0)
                Tb = 0;
            if (temp2 == 1)
                Tb = 1;
            if (temp2 == 2)
                Tb = -1;
            Tx = Tx + Ta;
            Ty = Ty + Tb;
            //printf("ym=%d,xm=%d\n", Tb, Ta);
        }
    }
}

void polic_move() {
    for (int k = 1; k <= nos; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (A[i][j] == k) {
                    Px = i;
                    Py = j;
                    int temp1 = (rand() % 3);   //move of police
                    int temp2 = (rand() % 3);   //move of police
                    if (temp1 == 0)
                        Pa = 0;
                    if (temp1 == 1)
                        Pa = 1;
                    if (temp1 == 2)
                        Pa = -1;
                    if (temp2 == 0)
                        Pb = 0;
                    if (temp2 == 1)
                        Pb = 1;
                    if (temp2 == 2)
                        Pb = -1;
                    Px = Px + Pa;
                    Py = Py + Pb;
                    while (1) {
                        if ((Px < m && Px >= 0) && (Py >= 0 && Py < n) && A[Px][Py]==0) {
                            A[Px][Py] = k;
                            printf("%d", k);
                            break;
                        } else {
                            Px = Px - Pa;
                            Py = Py - Pb;
                            int temp1 = (rand() % 3);   //move of police
                            int temp2 = (rand() % 3);   //move of police
                            if (temp1 == 0)
                                Pa = 0;
                            if (temp1 == 1)
                                Pa = 1;
                            if (temp1 == 2)
                                Pa = -1;
                            if (temp2 == 0)
                                Pb = 0;
                            if (temp2 == 1)
                                Pb = 1;
                            if (temp2 == 2)
                                Pb = -1;
                            Px = Px + Pa;
                            Py = Py + Pb;
                            printf("px=%d,py=%d\n", Px, Py);
                        }
                    }
                    A[Px - Pa][Py - Pb] = 0;
                }
            }
        }
    }
}
// if (A[i][j] != 0 && A[i][j] != -1)
//bishtar chap mikonad
void print() {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (A[i][j] == 0)
                printf("|   ");
            else if (A[i][j] == -1)
                printf("| T ");
            else
                printf("| D%d", A[i][j]);
        }
        printf("|\n");
    }printf("next\n");

}

int main() {
    matrix();
    first_pos();
    print();
    //sleep(1);
    //thief_move();
    //polic_move();
    //print();
    //sleep(1);
    //system("clear");
    //thief_move();
    //polic_move();
    //check_thief();
    //print();
    return 0;
}



