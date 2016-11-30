//
//  commands.h
//  final_project_paint
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
void read_command(int, char**, canvas *);
void quit(canvas *);
void print_help();
void mainCommand(char, int, char**, canvas *);

#endif /* commands_h */
