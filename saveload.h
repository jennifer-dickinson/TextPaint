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

void saveCanvas( canvas *, char *);
void loadCanvas( canvas *, char *);

#endif /* saveload_h */
