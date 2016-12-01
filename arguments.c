//
//  arguments.c
//  TextPaint
//
//  To view descriptions and details for this file, view arguments.h
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include "arguments.h"

bool inRange(int x, int y, int x_lim, int y_lim) {
    // Check if two points are within range of a grid
    return !(x < 0 || x > x_lim - 1 || y < 0 || y > y_lim - 1);
}

void getArgs(int *argc, char ***argv) {
    // Read a line of user input and split into number of arguments and a string array of arguments

    // Generate placeholders for information
    char *line = NULL; // To store the substring
    char **arguments = (char **) malloc(sizeof(char *)); // To store multiple substrings
    int argCount = 0; // Count the number of strings

    // Length of input string
    unsigned long length = 0;

    // Placeholder for bool logic
    char lastChar = ' ';

    //start of a new substring, end of last substring
    bool newArg, endArg;

    // starting position of substring, length of substring, index of string
    int startPos = 0, argLen = 0, index = 0;

    // Get the string of user input
    getline(&line, &length, stdin);

    // Get the actual length of the string
    length = strlen(line);

    for (index = 0; index < length; index++) {

        // Is the current character the start of an substring?
        newArg = (!isspace(line[index]) && isspace(lastChar));

        // Is the current character the end of an substring?
        endArg = (isspace(line[index]) && !isspace(lastChar)) || (!isspace(lastChar) && index + 1 == length);

        if (newArg) {
            // Mark the starting position of the argument in the string
            startPos = index;
        }
        if (endArg) {
            // Mark the length the argument
            argLen = index - startPos;

            // Increase string array size
            arguments = (char **) realloc(arguments, (argCount + 1) * sizeof(char *));

            // Allocate memory for string
            arguments[argCount] = (char *) malloc((argLen) * sizeof(char));

            // Copy argument to string
            strncpy(arguments[argCount], &line[startPos], (argLen));

            // Fixed glitch where string would sometimes include garbage
            arguments[argCount][argLen] = '\0';

            // Increment number of arguments count
            argCount += 1;
        }

        // Keep record of the last character
        lastChar = line[index];
    }

    // Point the parameters to argument array and argument count
    *argv = arguments;
    *argc = argCount;
}

void freeArgs(int *argc, char **argv) {
    // Free the memory the argument array and reset argument to zero

    for (int i = 0; i < *argc; i++) {
        // Free strings
        free(argv[i]);
    }
    // Free string array
    free(argv);

    // Reset argument count
    *argc = 0;

}

bool isPosInteger(char *string) {
    // Check if a string is a positive integer

    for (int index = 0; index < strlen(string); index++) {

        // Is the current character not a number [0-9]?
        if (!isdigit(string[index]))
            return false;
    }
    return true;
}
