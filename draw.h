//
//  draw.h
//  TextPaint
//
//  draw.c is responsible for modifying the contents of a canvas, drawing a line and erasign columns and rows.
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#ifndef draw_h
#define draw_h

#include <math.h>
#include <stdio.h>
#include "canvas.h"
#include "arguments.h"

void drawLine(canvas *, int, char **);
/* Summary: Takes two coordinates and attempts to draw a line on a canvas. Handles input validation
 * Parameters: canvas pointer, argument count, array of string arguments
 */

double correctAngle(int *, int *, int *, int *);
/* Summary:  Calculates the angle in degrees of a line with respect to a polar graph, switching the order if required
 * Parameters: int pointer x1, int pointer y1, int pointer x2, int pointer y2
 */

void draw45(canvas *, int, int, int);
/* Summary: Draw a line with a slope of 1 between two points
 * Parameters: canvas pointer, starting x, starting y, ending x
 */

void draw90(canvas *, int, int, int);
/* Summary: Draw a line with an undefined slope between two points
 * Parameters: canvas pointer, starting x, starting y, ending y
 */

void draw135(canvas *, int, int, int);
/* Summary: Draw a line with a slope of -1 between two points
 * Parameters: canvas pointer, starting x, starting y, ending x
 */

void draw180(canvas *, int, int, int);
/* Summary: Draw a line with a slope of 0 between two points
 * Parameters: canvas pointer, starting x, starting y, ending x
 */

void eraseCol(canvas *, int);
/* Summary: Erases the column of a canvas at a given position
 * Parameters: canvas pointer, column position
 */

void eraseRow(canvas *, int);
/* Summary: Erases the row of a canvas at a given position
 * Parameters: canvas pointer, row position
 */


#endif /* draw_h */
