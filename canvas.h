//
//  canvas.h
//  final_project_paint
//
//  Created by Jennifer Salas on 11/28/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#ifndef canvas_h
#define canvas_h

#include <stdio.h>
#include <stdlib.h>


typedef struct canvas_struct {
    int row;
    int col;
    char ** grid;
} canvas;

canvas createCanvas (int, int);
void freeCanvas (canvas *);
void displayCanvas (canvas);
void addRow (canvas *, int);
void addCol (canvas *, int);
void delRow (canvas *, int);
void delCol (canvas *, int);
void resize (canvas *, int, int);

#endif /* canvas_h */
