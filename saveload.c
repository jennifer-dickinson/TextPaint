//
//  saveload.c
//  final_project_paint
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include "saveload.h"


void saveCanvas( canvas * board, char * filename) {
    // Open file
    FILE *outFile = NULL;
    
    outFile = fopen(filename, "w");
    
    if (outFile == NULL) {
        printf("Failed to open file: %s\n", filename);
    }
    else {
        
        // Write to file

        fprintf(outFile, "Columns: %d Rows: %d\n", board->col, board->row);
        
        for (int col_index = 0; col_index < board->col; col_index++) {
            for (int row_index = 0; row_index < board->row; row_index++) {
                fprintf(outFile, "%c ", board->grid[col_index][row_index]);
            }
            fprintf(outFile, "\n");
        }
        
        // Close file

        fclose(outFile);
    }
    
    
    
}

void loadCanvas ( canvas * board, char * filename) {
    // Open file
    FILE * inFile = NULL;
    inFile = fopen(filename, "r");
    if (inFile == NULL) {
        printf("Failed to open file: %s\n", filename);
    }
    else {
        // Read file
        int col = 0;
        int row = 0;
        fscanf(inFile, "Columns: %d Rows: %d ", &col, &row);
        
        printf("Columns: %d Rows: %d\n", board->col, board->row);
        
        // Resize canvas
        resize(board, col, row);
        printf("resized\n");
        
        // Fill canvas with characters
        for (int col_index = 0; col_index < board->col; col_index++) {
            for (int row_index = 0; row_index < board->row; row_index++) {
                fscanf(inFile, " %c ", &board->grid[col_index][row_index]);
            }
        }
        
        // Close file
        fclose(inFile);
        
        // Display Canvas
        displayCanvas(*board);
    }
}
