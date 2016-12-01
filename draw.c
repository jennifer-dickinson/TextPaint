//
//  draw.c
//  TextPaint
//
//  To view descriptions and details for this file, view draw.h
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include "draw.h"

void drawLine(canvas *board, int argc, char **argv) {
    // Draw a line on the canvas from (x1, y1) to (x2, y2)

    int coor[4];
    // coor[0]: x1
    // coor[1]: y1
    // coor[2]: x2
    // coor[3]: y2

    // Number of arguments must equal 5
    if (argc != 5) goto BROKEN;

    // Assign 2nd to 5th arguments to coor[].
    else {
        for (int i = 1; i < argc; i++) {

            // If the parameters are not integers, skip
            if (!isPosInteger(argv[i])) goto BROKEN;
            coor[i - 1] = atoi(argv[i]);
        }
    }

    // Coordinates must be within range of the canvas grid
    if (!inRange(coor[0], coor[1], board->col, board->row)
          || !inRange(coor[2], coor[3], board->col, board->row)) {

        BROKEN:
        printf("Improper draw command.\n");
    }

    // Attempt to draw the line
    else {
        // Calculate the angle of the line
        double theta = correctAngle(&coor[0], &coor[1], &coor[2], &coor[3]);

        if (fabs(45 - theta) < .001) {
            // Slope of 1, draw a line from left to right increasing in x and y direction
            draw45(board, coor[0], coor[1], coor[2]);
        }
        else if (fabs(90 - theta) < .001) {
            // Undefined slope, draw a line x remaining static and increasing in y direction
            draw90(board, coor[0], coor[1], coor[3]);
        }
        else if (fabs(135 - theta) < .001) {
            // Slope of -1, draw a line from left to right increasing in x and decreasing in y
            draw135(board, coor[0], coor[1], coor[2]);
        }
        else if (fabs(0 - theta) < .001) {
            // Slope of 0, draw a line from left to right increasing in x and y remaining static
            draw180(board, coor[0], coor[1], coor[2]);
        }

        else {
            // The line cannot be represented by the grid, do not draw
            printf("Cannot draw the line as it is not straight.\n");
        }
    }

}


double correctAngle(int *x1, int *y1, int *x2, int *y2) {
    // Check angle of line & switch directions if necessary

    // Get degrees of the line with respect to a polar graph
    double theta = atan2(*y2 - *y1, *x2 - *x1) * 180 / M_PI;

    // If the angle is negative, switch the coordinates
    if (theta < 0) {
        int tempx = *x1;
        *x1 = *x2;
        *x2 = tempx;

        int tempy = *y1;
        *y1 = *y2;
        *y2 = tempy;

        // Calculate the new angle
        theta = atan2(*y2 - *y1, *x2 - *x1) * 180 / M_PI;

    }

    // If the angle is larger than 180 degrees, decrease by 180
    if (theta > 180) {
        theta -= 180;
    }

    return theta;
}

void draw45(canvas *board, int x1, int y1, int x2) {
    // Draw a line with a slope of 1

    for (int x = 0; x <= x2 - x1; x++) {
        // As x increases, y increases equally

        // If the cell is filled with a line of a different slope, fill with a '+'
        if (board->grid[x1 + x][y1 + x] != '/' && board->grid[x1 + x][y1 + x] != '*') {
            board->grid[x1 + x][y1 + x] = '+';
        }
        // Fill the line with a '/' to indicate a positive slope line
        else {
            board->grid[x1 + x][y1 + x] = '/';
        }
    }

    displayCanvas(*board);
}

void draw90(canvas *board, int x1, int y1, int y2) {
    // Draw a line with an undefined slope (vertical line)

    for (int y = y1; y <= y2; y++) {
        // As y increases, x remains static

        // If the cell is filled with a line of a different slope, fill with a '+'
        if (board->grid[x1][y] != '|' && board->grid[x1][y] != '*') {
            board->grid[x1][y] = '+';
        }
        // Fill the cell with a '|' to indicate a vertical line
        else {
            board->grid[x1][y] = '|';
        }
    }
    displayCanvas(*board);

}

void draw135(canvas *board, int x1, int y1, int x2) {
    // Draw a line a slope of -1

    for (int x = 0; x <= x1 - x2; x++) {
        // As x increases, y decreases equally

        // If the cell is filled with a line of a different slope, fill with a '+'
        if (board->grid[x1 - x][y1 + x] != '\\' && board->grid[x1 - x][y1 + x] != '*') {
            board->grid[x1 - x][y1 + x] = '+';
        }
        // Fill the cell with a '\' to indicate a negative slope line
        else {
            board->grid[x1 - x][y1 + x] = '\\';
        }
    }
    displayCanvas(*board);
}

void draw180(canvas *board, int x1, int y1, int x2) {
    // Draw a line with a slope of 0 (horizontal line)

    for (int x = 0; x <= x2 - x1; x++) {
        // As x increases, y remains static

        // If the cell is filled with a line of a different slope, fill with a '+'
        if (board->grid[x1 + x][y1] != '-' && board->grid[x1 + x][y1] != '*') {
            board->grid[x1 + x][y1] = '+';
        }
        // Fill the cell with a '-' to indicate a horizontal line
        else {
            board->grid[x1 + x][y1] = '-';
        }
    }
    displayCanvas(*board);

}

void eraseRow(canvas *board, int pos) {
    // Erase a row at a given position by filling with asterisks

    for (int col_index = 0; col_index < board->col; col_index++) {
        board->grid[col_index][pos] = '*';
    }
}

void eraseCol(canvas *board, int pos) {
    // Erase a column at a given position by filling with asterisks

    for (int row_index = 0; row_index < board->row; row_index++) {
        board->grid[pos][row_index] = '*';
    }
}
