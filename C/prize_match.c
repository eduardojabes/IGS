#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 5

typedef enum { false, true } bool;

// Slot constructor
int **create_slot()
{
    int** slot = malloc (LINHAS * sizeof(int*));
    for (int line = 0; line < LINHAS; line++){
        slot[line] = malloc(COLUNAS * sizeof(int));
        
        printf("Insira os valores da linha %d:\n", (line + 1));
        
        for (int col = 0; col < COLUNAS; col++){
            scanf("%d", &slot[line][col]);
        }
    }
 return (slot);
}

int main (void)
{
int prize[LINHAS][COLUNAS] = {{1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}};
bool win = false;
while (win == false)
{
printf ("Iniciando um novo jogo!\n");
int **slot = create_slot();
win = true;
    for (int lines = 0; lines < LINHAS; lines++){
        for (int cols = 0; cols < COLUNAS; cols++){
           if (slot[lines][cols] != prize[lines][cols])
            {
               win = false;
            }
        }
        free(slot[lines]);
    }
    free(slot);
}

printf ("Ganhou!\n");
system("pause");
return (0);
}