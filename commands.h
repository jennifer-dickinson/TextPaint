//
//  commands.h
//  TextPaint
//
//  This file is responsible for displaying the grid to the console, requesting user commands, performing commands,
//  and quitting the program
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#ifndef commands_h
#define commands_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canvas.h"
#include "draw.h"
#include "saveload.h"

void runTextPaint(int, int);
/* Summary: This is the main part of the program. It displays the image of the canvas grid and accepts command from user
 * Parameters: row, column
 */

void readCommand(int, char **, canvas *);
/* Summary: Reads user input to modify, save, load, or display a canvas, or quit the program.
 * Parameters: number of arguments, list of arguments, canvas pointer.
 */

void quit(canvas *);
/* Summary: Frees memory allocated for the canvas grid and exits the program.
 * Parameters: canvas pointer
 */

void printHelp();
/* Summary: displays all valid user commands
 */


#endif /* commands_h */
