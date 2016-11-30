//
//  saveload.h
//  final_project_paint
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#ifndef saveload_h
#define saveload_h

#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"

void saveCanvas(canvas *, char *);
/* Summary: Save the current status of the grid to a file
 * Parameters: canvas pointer, file name
 */

void loadCanvas(canvas *, char *);
/* Summary: Load a previously saved grid and overwrite the currently displayed grid
 * Parameters: canvas pointer, file name
 */

#endif /* saveload_h */
