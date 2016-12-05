//
//  saveload.c
//  TextPaint
//
//  To view descriptions and details for this file, view saveload.h
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include "saveload.h"


void saveCanvas(canvas *board, char *filename) {
    // Save the current grid to a readable file

    // Open file
    FILE *outFile = NULL;
    outFile = fopen(filename, "w");

    // Check if the file has been opened
    if (outFile == NULL) {
        printf("Failed to open file: %s\n", filename);
    } else {

        // Write number of rows and columns
        fprintf(outFile, "Row: %d Col: %d\n", board->row, board->col);

        // Write the grid
        for (int row_index = board->row - 1; row_index + 1 > 0; row_index--) {
            for (int col_index = 0; col_index < board->col; col_index++) {
                fprintf(outFile, "%c ", board->grid[col_index][row_index]);
            }
            fprintf(outFile, "\n");
        }

        // Close file
        fclose(outFile);
    }


}

void loadCanvas(canvas *board, char *filename) {

    // Open file
    FILE *inFile = NULL;
    inFile = fopen(filename, "r");

    // Check if file has been opened
    if (inFile == NULL) {
        printf("Failed to open file: %s\n", filename);
    } else {
        // Read file
        int col = 0;
        int row = 0;

        // Get the number of rows and columns
        fscanf(inFile, "Row: %d Col: %d ", &row, &col);

        // Resize canvas
        resize(board, col, row);

        // Fill canvas with characters
        for (int row_index = row - 1; row_index + 1 > 0; row_index--) {
            for (int col_index = 0; col_index < col; col_index++) {
                fscanf(inFile, "%c ", &board->grid[col_index][row_index]);
            }
            fscanf(inFile, "\n");
        }

        // Close file
        fclose(inFile);
    }
}
