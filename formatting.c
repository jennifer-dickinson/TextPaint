//
//  formatting.c
//  final_project_paint
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include "formatting.h"

bool in_range(int x, int y, int x_lim, int y_lim) {
    return !(x < 0 || x > x_lim - 1 || y < 0 || y > y_lim - 1);
}

void get_args(int *argc, char ***argv) {
    char *line = NULL;
    unsigned long length = 0;
    char lastchar = ' ';
    int start = 0, i = 0;
    bool newArg, endArg;

    char **arguments = (char **) malloc(sizeof(char *));
    int arg_count = 0;


    getline(&line, &length, stdin);

    length = strlen(line);

    for (i = 0; i < length; i++) {
        newArg = (!isspace(line[i]) && isspace(lastchar));
        endArg = (isspace(line[i]) && !isspace(lastchar)) || (!isspace(lastchar) && i + 1 == length);

        if (newArg) {
            start = i;
        }
        if (endArg) {

            // Increase string array size
            arguments = (char **) realloc(arguments, (arg_count + 1) * sizeof(char *));

            // Allocate memory for string
            arguments[arg_count] = (char *) malloc((i - start + 1) * sizeof(char));

            // Copy argument to string
            strncpy(arguments[arg_count], &line[start], (i - start));

            // Increment number of arguments count
            arg_count += 1;
        }
        lastchar = line[i];
    }
//    for (i = 0; i < arg_count; i++) {
//        printf("%d: %s\n", i, arguments[i]);
//    }
    *argv = arguments;
    *argc = arg_count;
}

void free_args(int *argc, char **argv) {
    for (int i = 0; i < *argc; i++) {
        free(argv[i]);
    }
    free(argv);

    *argc = 0;

}

bool isPosInteger(char *string) {
    for (int index = 0; index < strlen(string); index++) {
        if (!isdigit(string[index]))
            return false;
    }
    return true;
}
