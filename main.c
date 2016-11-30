//
//  main.c
//  TextPaint
//
//  For a detailed description of TextPaint, view README.md
//
//  Created by Jennifer Salas on 11/28/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "canvas.h"
#include "commands.h"
#include "draw.h"
#include "arguments.h"

void checkArgs(int argc, const char *argv[], int *row, int *col);

int main(int argc, const char *argv[]) {
    int row, col;

    // Check that the commandline arguments are valid
    checkArgs(argc, argv, &row, &col);

    // Run the program
    runTextPaint(row, col);

    return 0;

}

void checkArgs(int argc, const char *argv[], int *row, int *col) {
    // Validate arguments provided through the command line before aunching

    // If no arguments are provided, generate the default 10x10 grid.
    if (argc == 1) {
        *row = 10;
        *col = 10;
        printf("Making default board of %d X %d.\n", *row, *col);
    }
    // If the incorrect number of arguments are provided, alert the user and quit.
    else if (argc != 3) {
        printf("Wrong number of command line arguements entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        exit(0);
    }

    else {

        int args = 0;

        // Check that the first argument is an integer greater than or equal to 1
        args = sscanf(argv[1], " %d", row);

        if (args < 1) {
            printf("The number of rows is not an integer.\n");
        }
        else if (*row < 1) {
            printf("The number of rows is less than 1.\n");
            exit(0);
        }

        // Check that the second argument is an integer greater than or equal to one
        args = sscanf(argv[2], " %d", col);

        if (args < 1) {
            printf("The number of columns is not an integer.\n");
            exit(0);
        }
        else if (*col < 1) {
            printf("The number of columns is less than 1.\n");
            exit(0);
        }
    }
}

