//
//  canvas.c
//  TextPaint
//
//  To view descriptions and details for this file, view canvas.h
//
//  Created by Jennifer Salas on 11/28/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//


#include "canvas.h"

canvas createCanvas(int rows, int columns) {
    // Create a new canvas by assigning its number of rows, columns, and generating a grid.

    canvas board;
    board.row = rows;
    board.col = columns;

    // Allocate memory for columns
    board.grid = (char **) malloc(columns * sizeof(char *));

    for (int col_index = 0; col_index < columns; col_index++) {

        // Allocate memory for rows
        board.grid[col_index] = (char *) malloc(rows * sizeof(char));

        for (int row_index = 0; row_index < rows; row_index++) {

            // Fill with asterisks
            board.grid[col_index][row_index] = '*';
        }
    }
    return board;
}

void freeCanvas(canvas *board) {
    // Deallocate memory for the canvas grid

    int col = board->col;

    // Free memory for 2nd level of grid
    for (int col_index = 0; col_index < col; col_index++) {
        free(board->grid[col_index]);
    }

    // Free memory for 1st level of grid
    free(board->grid);
}

void displayCanvas(canvas board) {
    // Display the canvas grid to stdout.

    for (int row_index = board.row - 1; row_index + 1 > 0; row_index--) {

        // Print the row numbers
        printf("%2d", row_index);

        for (int col_index = 0; col_index < board.col; col_index++) {
            // Print cell contents
            printf("%2c", board.grid[col_index][row_index]);
        }

        printf("\n");
    }

    printf("%2s", "");

    for (int row_index = 0; row_index < board.col; row_index++) {

        // Print the column numbers
        printf("%2d", row_index);
    }
    printf("\n");
}

void addRow(canvas *board, int pos) {
    // Add a row to a canvas grid at indicated position

    // Increase number of rows
    board->row += 1;

    // Allocate memory for the new row
    for (int col_index = 0; col_index < board->col; col_index++) {
        board->grid[col_index] = (char *) realloc(board->grid[col_index], board->row * sizeof(char));
    }

    // Move rows over if necessary
    for (int col_index = 0; col_index < board->col; col_index++) {
        for (int row_index = board->row; row_index > pos; row_index--) {
            board->grid[col_index][row_index - 1] = board->grid[col_index][row_index - 2];
        }
    }

    // Fill new row with asterisks
    for (int col_index = 0; col_index < board->col; col_index++) {
        board->grid[col_index][pos] = '*';
    }
}

void addCol(canvas *board, int pos) {
    // Add a column to canvas grid at indicated position

    // Increase number of columns
    board->col += 1;

    // Allocate memory for the new column
    board->grid = (char **) realloc(board->grid, board->col * sizeof(char *));
    board->grid[board->col - 1] = (char *) malloc(board->row * sizeof(char));

    // Move columns if necessary
    for (int col_index = board->col; col_index - 1 > pos; col_index--) {
        for (int row_index = 0; row_index < board->row; row_index++) {

            board->grid[col_index - 1][row_index] = board->grid[col_index - 2][row_index];
        }
    }

    // Fill new column with asterisks
    for (int row_index = 0; row_index < board->row; row_index++) {
        board->grid[pos][row_index] = '*';
    }

}

void delRow(canvas *board, int pos) {
    // Delete row in canvas grid at indicated position

    int col_index, row_index;

    // Decrease rows by one
    board->row -= 1;

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
    // Delete row in canvas grid at indicated position

    int col_index, row_index;

    // Decrease number of columns by 1
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
    // Resize canvas grid to indicated number of rows and columns

    int index;

    // If new number of rows is larger, add rows
    if (rows > board->row) {
        for (index = board->row; index < rows; index++) {
            addRow(board, board->row);
        }
    }

        // If new number of rows is smaller, delete rows
    else if (rows < board->row) {
        for (index = board->row; index > rows; index--) {
            delRow(board, board->row);
        }
    }

    // If new number of columns is larger, add columns
    if (cols > board->col) {
        for (index = board->col; index < cols; index++) {
            addCol(board, board->col);
        }
    }

        // If new number of columns is smaller, delete columns
    else if (cols < board->col) {
        for (index = board->col; index > cols; index--) {
            delCol(board, board->col);
        }
    }
}
