//
//  canvas.c
//  final_project_paint
//
//  Created by Jennifer Salas on 11/28/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//


#include "canvas.h"

canvas createCanvas(int rows, int columns) {
    canvas board;
    board.row = rows;
    board.col = columns;

    // Allocate memory for columns
    board.grid = (char **) malloc(columns * sizeof(char *));

    for (int i = 0; i < columns; i++) {

        // Allocate memory for rows
        board.grid[i] = (char *) malloc(rows * sizeof(char));

        for (int j = 0; j < rows; j++) {

            // Fill with asterisks
            board.grid[i][j] = '*';
        }
    }
    return board;
}

void freeCanvas(canvas *board) {

    int col = board->col;

    for (int i = 0; i < col; i++) {
        free(board->grid[i]);
    }
    free(board->grid);
}

void displayCanvas(canvas board) {
    int col_index = 0, row_index = 0;

    for (row_index = board.row - 1; row_index + 1 > 0; row_index--) {

        // Print the row numbers
        printf("%2d", row_index);

        for (col_index = 0; col_index < board.col; col_index++) {
            // Print contents of cell
            printf("%2c", board.grid[col_index][row_index]);
        }

        printf("\n");
    }

    printf("%2s", "");

    for (row_index = 0; row_index < board.col; row_index++) {

        // Print the column numbers
        printf("%2d", row_index);
    }
    printf("\n");
}

void addRow(canvas *board, int pos) {
    // Increase number of rows
    board->row += 1;

    int col_index, row_index;


    // Allocate memory
    for (col_index = 0; col_index < board->col; col_index++) {
        board->grid[col_index] = (char *) realloc(board->grid[col_index], board->row * sizeof(char));
    }

    // Move rows over
    for (col_index = 0; col_index < board->col; col_index++) {
        for (row_index = board->row; row_index > pos; row_index--) {
            board->grid[col_index][row_index - 1] = board->grid[col_index][row_index - 2];
        }
    }

    // Fill new row
    for (col_index = 0; col_index < board->col; col_index++) {
        board->grid[col_index][pos] = '*';
    }
}

void addCol(canvas *board, int pos) {

    // Increase number of col
    board->col += 1;

    int col_index, row_index;

    // Allocate memory for new column
    board->grid = (char **) realloc(board->grid, board->col * sizeof(char *));
    board->grid[board->col - 1] = (char *) malloc(board->row * sizeof(char));

    // Move columns
    for (col_index = board->col; col_index - 1 > pos; col_index--) {
        for (row_index = 0; row_index < board->row; row_index++) {

            board->grid[col_index - 1][row_index] = board->grid[col_index - 2][row_index];
        }
    }

    // Fill new row
    for (int row_index = 0; row_index < board->row; row_index++) {
        board->grid[pos][row_index] = '*';
    }

}

void delRow(canvas *board, int pos) {
    int col_index, row_index;

    board->row -= 1;

    if (pos >= board->row) {
        pos = board->row;
    }

    for (col_index = 0; col_index < board->col; col_index++) {

        // Move rows
        for (row_index = pos; row_index < board->row; row_index++) {
            board->grid[col_index][row_index] = board->grid[col_index][row_index + 1];
        }

        // Reallocate memory
        board->grid[col_index] = (char *) realloc(board->grid[col_index], board->row * sizeof(char));
    }
}

void delCol(canvas *board, int pos) {
    int col_index, row_index;

    if (pos >= board->col) {
        pos = board->col - 1;
    }

    board->col -= 1;

    // Move columns
    for (col_index = pos; col_index < board->col; col_index++) {
        for (row_index = 0; row_index < board->row; row_index++) {
            board->grid[col_index][row_index] = board->grid[col_index + 1][row_index];
        }
    }

    // Reallocate memory
    board->grid = (char **) realloc(board->grid, board->col * sizeof(char *));
}

void resize(canvas *board, int cols, int rows) {
    int index;
    if (rows > board->row) {
        for (index = board->row; index < rows; index++) {
            addRow(board, board->row);
        }
    }
    else if (rows < board->row) {
        for (index = board->row; index > rows; index--) {
            delRow(board, board->row);
        }
    }

    if (cols > board->col) {
        for (index = board->col; index < cols; index++) {
            addCol(board, board->col);
        }
    }
    else if (cols < board->col) {
        for (index = board->col; index > cols; index--) {
            delCol(board, board->col);
        }
    }

//    displayCanvas(*board);
}
