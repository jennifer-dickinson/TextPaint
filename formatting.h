//
//  formatting.h
//  final_project_paint
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


bool assert_formatting(int, int);

bool in_range(int, int, int, int);

void get_args(int *, char ***);

void free_args(int *, char **);

bool isPosInteger(char *);

#endif /* formatting_h */
