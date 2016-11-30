//
//  main.c
//  final_project_paint
//
//  Created by Jennifer Salas on 11/28/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "canvas.h"
#include "commands.h"
#include "draw.h"
#include "formatting.h"

void checkArgs (int argc, const char * argv[], int * row, int * col);

int main(int argc, const char * argv[]) {
    int row, col;
    
    int promptArgsC = 0;
    char ** promptArgs = NULL;
    
    checkArgs(argc, argv, &row, &col);
    
    canvas board = createCanvas(row, col);
    
    displayCanvas(board);

    do {
        printf("Enter your command: ");
        get_args(&promptArgsC, &promptArgs);
        read_command(promptArgsC, promptArgs, &board);
        free_args(&promptArgsC, promptArgs);
    }
    while (true);
    
    
    return 0;

}

void checkArgs (int argc, const char * argv[], int * row, int * col) {
    if ( argc == 1 ) {
        *row = 10;
        *col = 10;
        printf("Making default board of %d X %d.\n", *row, *col);
    }
    else if (argc != 3) {
        printf("Wrong number of command line arguements entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        exit(0);
    }
    else {
        int args = 0;
        
        args = sscanf(argv[1], " %d", row);
        
        if (args < 1) {
            printf("The number of rows is not an integer.\n");
            }
        else if ( *row < 1) {
            printf("The number of rows is less than 1.\n");
            exit(0);
        }
        
        args = sscanf(argv[2], " %d", col);
        
        if (args < 1) {
            printf("The number of columns is not an integer.\n");
            exit(0);
        }
        else if ( *col < 1) {
            printf("The number of columns is less than 1.\n");
            exit(0);
        }
    }
}

