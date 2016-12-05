//
//  arguments.h
//  TextPaint
//
//  arguments.c is responsible for capturing and parsing user input into readable formats for other functions
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#ifndef formatting_h
#define formatting_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool inRange(int, int, int, int);

/* Summary: Check if a point is within range of a grid
 * Parameters: x1, y1, grid columns, grid rows
 */
void getArgs(int *, char ***);

/* Summary: Get a user input line and split into number of arguments and a string array of arguments
 * Parameters: pointer to number of arguments, pointer to a string array of arguments
 */

void freeArgs(int *, char **);
/* Summary: Reset an argument count to 0 and free memory for a string array of arguments
 * Parameters: pointer to number of arguments, pointer to a string array of arguments
 */

bool isPosInteger(char *);
/* Summary: Check if a string is a positive integer
 * Parameters: string
 */

#endif /* formatting_h */
