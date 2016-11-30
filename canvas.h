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
    int row; // number of rows for the canvas
    int col; // number of columns for the canvas
    char **grid; // pointer to a multidimensional array representing a grid
} canvas;

canvas createCanvas(int, int);
/* Summary: Generates an empty grid representing a canvas
 * Parameters: Row, Column
 * Return: Canvas object containing variables for row, column, and a multidimensional array representing a grid
 */

void freeCanvas(canvas *);
/* Summary: Free memory from multidimensional array within canvas struct
 * Parameters: canvas pointer
 */

void displayCanvas(canvas);
/* Summary: Print the elements of a multidimensional arra within the canvas struct to console
 * Parameters: canvas object
 */

void addRow(canvas *, int);
/* Summary: Adds a row to a canvas at a given position
 * Parameters: canvas object, position of insertion
 */

void addCol(canvas *, int);
/* Summary: Adds a column to a canvas at a given position
 *
 * Parameters: canvas object, position of insertion
 */

void delRow(canvas *, int);
/* Summary: Deletes a row from a canvas at a given position
 * Parameters: canvas object, position of deletion
 */

void delCol(canvas *, int);
/* Summary: Deletes a column from a canvas at a given position
 * Parameters: canvas object, position of deletion
 */

void resize(canvas *, int, int);
/* Summary: Resizes a canvas to any combination of columns and rows
 * Parameters: canvas object, number of columns, number of rows
 */


#endif /* canvas_h */
