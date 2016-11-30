//
//  draw.h
//  final_project_paint
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#ifndef draw_h
#define draw_h

#include <math.h>
#include <stdio.h>
#include "canvas.h"
#include "formatting.h"

void writeLine(canvas *, int, char **); // Validate line
double correctAngle(int *, int *, int *, int *); // Check if line is at 45, 90, 135 or 180 degrees
void draw_45(canvas *, int, int, int, int); // Draw a line at 45 degrees counter-clockwise
void draw_90(canvas *, int, int, int, int); // Draw a line at 90 degrees counter-clockwise
void draw_135(canvas *, int, int, int, int); // Draw a line at 135 degrees counter-clockwise
void draw_180(canvas *, int, int, int, int); // Draw a line at 180 degrees counter-clockwise
void eraseRow(canvas *, int);

void eraseCol(canvas *, int);

#endif /* draw_h */
