#include "thing.h"
#include <stdio.h>
#include <stdlib.h>

board_t *allocate_board(int width, int height)
{
    board_t *board;
    int **squares;
    int row = 0; //height

    board = (board_t*)malloc(sizeof(board_t));
    squares = (int**)malloc(sizeof(int*) * height);
    while (row < height)
    {
        squares[row] = (int*)malloc(sizeof(int) * width);
        int col = 0; //width
        while(col < width)
        {
            squares[row][col] = SQUARE_BLUE;
            col++;
        }
        row++;
    }
    board->width = width;
    board->height = height;
    board->squares = squares;
    return (board);
}

void print_board(board_t *board)
{    
    int row = 0; //height

    while (row < board->height)
    {
        int col = 0; //width
        while(col < board->width)
        {
            printf("%d", board->squares[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}

board_t *make_level1(void)
{
    board_t *board;
    board = allocate_board(3, 3);

    board->squares[0][1] = 1;
    board->squares[1][1] = 1;
    board->squares[2][1] = 1;
    return (board);
}

void flip(board_t *board, int row, int col)
{
    if (board->squares[row][col] == SQUARE_BLUE)
        board->squares[row][col] = SQUARE_RED;
    else
        board->squares[row][col] = SQUARE_BLUE;
}

int main(void)
{
    board_t *board;

    board = make_level1();
    flip(board, 0, 1);
    flip(board, 2, 1);
    print_board(board);
    return(0);
}
