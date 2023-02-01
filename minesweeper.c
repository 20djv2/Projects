#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define MINES 10

//grids as local variables
char answerGrid[SIZE][SIZE];    //hidden solution
int visibleTile[SIZE][SIZE];    //visible/revealed tiles

//initialize the game
void gameStart() {
    srand(2); //randomly distribute mines

    //clear grid before each game
    for(int i=0; i<SIZE; i++){   
        for(int j=0; j<SIZE; j++){
            answerGrid[i][j] = '0';
            visibleTile[i][j] = 0;
        }
    }

    //check surrounding tiles for mines
    int x, y;
    for (int i = 0; i < 10;){
        x = rand() % SIZE;
        y = rand() % SIZE;

        if(answerGrid[x][y] !='M'){
            answerGrid[x][y] = 'M';
            i++;

            if(x < 9 && y > 0 && answerGrid[x+1][y-1]!='M') //checking the tile one up and one to the right
                answerGrid[x+1][y-1] += 1;

            if(x < 9 && answerGrid[x+1][y] != 'M') //checking tile to the right
                answerGrid[x+1][y] += 1;

            if(x < 9 && y < 9 && answerGrid[x+1][y+1] != 'M') //checking bottom right
                answerGrid[x+1][y+1] += 1;

            if(x > 0 && y > 0 && answerGrid[x-1][y-1]!='M') //checking the tile one up and one to the left
                answerGrid[x-1][y-1] += 1;

            if(x > 0 && answerGrid[x-1][y] != 'M') //checking tile to the left
                answerGrid[x-1][y] += 1;

            if(x > 0 && y < 9 && answerGrid[x-1][y+1] != 'M') //checking bottom left
                answerGrid[x-1][y+1] += 1;

            if(y < 9 && answerGrid[x][y+1] !='M') //down
                answerGrid[x][y+1] += 1;

            if(y > 0 && answerGrid[x][y-1] !='M') //up
                answerGrid[x][y-1] += 1;
        }
    }
} //end gameStart()

//flag helpe function, for printGrid function
void flag(int row, int col) {
    if(visibleTile[row][col] == 0)
        visibleTile[row][col] = 2;
}

//for loop to go through each row and print
void printGrid() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(visibleTile[i][j]==1) //visible tiles
                printf("%c  ", answerGrid[i][j]);

            else if (visibleTile[i][j]==2)  //flagged, marked as f
                printf("F  ");

            else
                printf("*  ");  //not revealed
        }
        printf("\n");
    }
}//end printGrid()

//recursive function to check surrounding boxes
int check(int row, int col)
{
    if(visibleTile[row][col] == 0)
    {
        visibleTile[row][col]=1; //means the square is set to be visible
        if(answerGrid[row][col] == '0' &&  visibleTile[row][col] != 'F')
        {
            if (row < 9)
                {check (row + 1, col); } //right
            if (row > 0)
                {check (row - 1, col); } //left
            if (col < 9)
                {check (row, col + 1); } //down
            if (col > 0)
                {check (row, col - 1); } //up
            if (row < 9 && col < 9)
                {check (row + 1, col + 1); } //bottom right
            if (row > 0 && col > 0)
                {check (row - 1, col - 1); } //top left
            if (row < 9 && col > 0)
                {check (row + 1, col - 1); } //bottom left
            if (row > 0 && col < 9)
                {check (row - 1, col + 1); } //top right
        }
    }
    return answerGrid[row][col] != 'M';
}

// recursive function to reveal large sections at a time
void reveal(int row, int col) {
    if(playGrid[row][col] != '*')
        return;

    //reveal the tile, only continue w adjacents if it = 0
    playGrid[row][col] = answerGrid[row][col];
    if(playGrid[row][col] != '0')
        return;

    //call reveal on all adjacent tiles
    for(int i = row - 1; i < row + 2; i++)
        if(i >= 0 && i < SIZE)
            for(int j = col - 1; j < col + 2; j++)
                if(j >= 0 && j < SIZE && !(i == row && j == col))
                    reveal(i, j);
}

//function to check through tiles, checks if they've all been made visible, are flags, numbers, or empty
int checkWin()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(visibleTile[i][j] == 0 && answerGrid[i][j] != 'M')
            {
                return 0;
            }
        }
    }
    printf("Congratulations! You win!");
    return 1;
}

//main function
int main() {
    char c; //command
    int row, col;

    gameStart();

    while(!checkWin()) {
        printGrid();

        printf("Enter \'c\' for check cell, \'f\' for flag cell.\nEnter command & cell row col: ");
        scanf("%c %d %d",&c,&row,&col);
        printf("\n\n");

        if(c == 'c') {
            if(check(row, col) == 0) {
                printGrid();
                printf("You hit a mine, game over.");
                break;
            }
        }
        else if (c == 'f')
            flag(row, col);
    }//end while
    return 0;
}//end main

