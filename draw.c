//
//  draw.c
//  final_project_paint
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include "draw.h"

void writeLine(canvas * board, int argc, char ** argv) {
    
    int coor[4];
    // coor[0]: x1
    // coor[1]: y1
    // coor[2]: x2
    // coor[3]: y2
    
    // Are arguments correct?
    if (argc != 5) {
        goto BROKEN;
    }
    else {
        for (int i = 1; i < argc; i++) {
            coor[i-1] = atoi(argv[i]);
        }
    }
    // Are coordinates in range?
    if (!(in_range(coor[0], coor[1], board->col, board->row) && in_range(coor[2], coor[3], board->col, board->row))){
    BROKEN:
        printf("Improper draw command.\n");
    }
    else {
        
        double theta = correctAngle(&coor[0], &coor[1], &coor[2], &coor[3]);
        
        if ( fabs(45 - theta) < .01 ) {
            draw_45(board, coor[0], coor[1], coor[2], coor[3]);
        }
        else if (fabs (90 - theta) < .01) {
            draw_90(board, coor[0], coor[1], coor[2], coor[3]);
        }
        else if ( fabs(135 - theta) < .01) {
            draw_135(board, coor[0], coor[1], coor[2], coor[3]);
        }
        else if ( fabs (0 - theta) < .01) {
            draw_180(board, coor[0], coor[1], coor[2], coor[3]);

        }

        else {
            printf("Cannot draw the line as it is not straight.\n");
            
        }
    }
    
}


double correctAngle (int *x1, int *y1, int *x2, int *y2) {
    // Check angle of line & switch directions if necessary
    double theta = atan2(*y2-*y1, *x2-*x1) * 180 / M_PI;
    
    if (theta < 0 ) {
        int tempx = *x1;
        *x1 = *x2;
        *x2 = tempx;
        
        int tempy = *y1;
        *y1 = *y2;
        *y2 = tempy;
        
        theta = atan2(*y2-*y1, *x2-*x1) * 180 / M_PI;
        
    }
    if (theta > 180) {
        theta -= 180;
    }
    
    return theta;
}

void draw_45(canvas * board, int x1, int y1, int x2, int y2) {
    // from bottom left to top right
    
    for (int x = 0; x <= x2 - x1; x++) {
        if (board->grid[x1 + x][y1 + x] != '/' && board->grid[x1 + x][y1 + x] != '*' ) {
            board->grid[x1 + x][y1 + x] = '+';
        }
        else {
            board->grid[x1 + x][y1 + x] = '/';
        }
    }
    
    displayCanvas(*board);
}
void draw_90 (canvas * board, int x1, int y1, int x2, int y2){
    // Draw vertically
    for (int y = y1; y <= y2; y++) {
        if (board->grid[x1][y] != '|' && board->grid[x1][y] != '*') {
            board->grid[x1][y] = '+';
        }
        else {
            board->grid[x1][y] = '|';
        }
    }
    displayCanvas(*board);

}
void draw_135(canvas * board, int x1, int y1, int x2, int y2) {
    // Draw diagonall from bottom right to top left
    
    for ( int x = 0; x <= x1 - x2; x++) {
        if (board->grid[x1 - x][y1 + x] != '\\' && board->grid[x1 - x][y1 + x] != '*') {
            board->grid[x1 - x][y1 + x] = '+';
        }
        else {
            board->grid[x1 - x][y1 + x] = '\\';
        }
    }
    displayCanvas(*board);
}
void draw_180 (canvas * board, int x1, int y1, int x2, int y2){
    // Draw horizontally
    for (int x = 0; x <= x2 - x1; x++) {
        if (board->grid[x1+x][y1] != '-' && board->grid[x1+x][y1] != '*') {
            board->grid[x1+x][y1]  = '+';
        }
        else {
            board->grid[x1+x][y1]  = '-';
        }
    }
    displayCanvas(*board);

}

void eraseRow (canvas *board, int pos ) {
    for (int col_index = 0; col_index < board->col; col_index++) {
        board->grid[col_index][pos] = '*';
    }
}
void eraseCol (canvas *board, int pos ) {
    for (int row_index = 0; row_index < board->row; row_index++) {
        board->grid[pos][row_index] = '*';
    }
}
