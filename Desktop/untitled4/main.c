#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 9
#define ROW_BLOCK_SIZE 4
#define COL_BLOCK_SIZE 8
int map[2*SIZE+1][2*SIZE+1];
int players[2][2];
char players_pawn[2] = {'x', 'o'};

char visual_map[4*SIZE+1][8*SIZE+1];


void print();
void add_block_at(int i,int j);
void init_table();
void add_pawn(int player,int i, int j);
void remove_pawn(int i, int j);

int main() {
    init_table();
    add_block_at(3,2);
    add_pawn(0,3,1);
    add_pawn(1,2,3);
    remove_pawn(2,3);
    print();
}

void add_pawn(int player,int i, int j)
{
    if(player==0)
 visual_map[i*4+1-3][j*8+1-5]='x';
    if(player==1)
        visual_map[i*4+1-3][j*8+1-5]='o';
}


void remove_pawn(int i, int j)
{

    visual_map[i*4+1-3][j*8+1-5]=' ';
}

void add_block_at(int i, int j)
{
    map[i][j] = 1;
    if(i%2 == 0 && j%2 == 1)
    {
        i/=2;
        j/=2;
        i*=ROW_BLOCK_SIZE;
        j*=COL_BLOCK_SIZE;
        int jj;
        for(jj=j+1;jj<j+8;jj++)
            visual_map[i][jj] = '-';
    }
    else if(i%2 == 1 && j%2 == 0)
    {
        i/=2;
        j/=2;
        i*=ROW_BLOCK_SIZE;
        j*=COL_BLOCK_SIZE;
        int ii;
        for(ii=i+1;ii<i+4;ii++)
            visual_map[ii][j] = '|';
    }
}

void init_table()
{
    for(int i = 0; i <= ROW_BLOCK_SIZE*SIZE; i++)
    {
        for(int j=0;j<=COL_BLOCK_SIZE*SIZE;j++)
        {
            if(j%COL_BLOCK_SIZE == 0 && i%ROW_BLOCK_SIZE == 0)
                visual_map[i][j] = '+';

            else if(i%ROW_BLOCK_SIZE == 0)
            {
                if(j % 2 == 0)
                    visual_map[i][j] = '*';
                else
                    visual_map[i][j] = ' ';
            }
            else if(j%COL_BLOCK_SIZE == 0)
            {
                visual_map[i][j] = '*';
            }

            else
                visual_map[i][j] = ' ';
        }
    }
}
void print()
{
    for(int i = 0; i <= ROW_BLOCK_SIZE*SIZE; i++) {
        for (int j = 0; j <= COL_BLOCK_SIZE * SIZE; j++) {
            printf("%c", visual_map[i][j]);
        }
        printf("\n");
    }
}
