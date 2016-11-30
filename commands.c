//
//  commands.c
//  final_project_paint
//
//  Created by Jennifer Salas on 11/29/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include "commands.h"

void runTextPaint(int row, int col) {

    int promptArgsC = 0;
    char **promptArgs = NULL;

    // Generate a canvas object
    canvas board = createCanvas(row, col);

    // Display the canvas grid
    displayCanvas(board);

    // Ignore any infinite loop warnings (We want this)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    do {
        // Prompt user for input
        printf("Enter your command: ");

        // Get user number of arguments and an arguments array
        get_args(&promptArgsC, &promptArgs);

        // Read and execute command
        read_command(promptArgsC, promptArgs, &board);

        // Clear memory for  number of arguments and arguments array
        free_args(&promptArgsC, promptArgs);
    }
    while (true); // Continue indefinitely. Will end with user input of 'q' in read_command
#pragma clang diagnostic pop
}

void read_command(int argc, char **argv, canvas *board) {

    // If the first argument is longer than a single character, skip
    if (strlen(argv[0]) > 1) goto UNRECOGNIZED;

    // Use first argument as the command
    char command = argv[0][0];

    switch (command) {
        // Show help dialogue
        case 'h':
        case 'H':
            // If more than one argument, skip
            if (argc != 1) goto UNRECOGNIZED;
            print_help();
            break;

        // Quit program
        case 'q':
        case 'Q':
            // If more than one argument, skip
            if (argc != 1) goto UNRECOGNIZED;
            quit(board);
            break;

        // Draw a line
        case 'w':
        case 'W':
            // Input validation is handled by drawLine();
            drawLine(board, argc, argv);
            break;

        // Resize canvas grid
        case 'r':
        case 'R':
            // Argument count  must equal 3
            // Second and third arguments must be integers greater than 0 to modify number of columns and rows
            if (argc != 3 || !isPosInteger(argv[1]) || !isPosInteger(argv[2]) || atoi(argv[1]) <= 0 ||
                atoi(argv[2]) <= 0) {
                printf("Improper resize command.\n");
                break;
            }

            resize(board, atoi(argv[1]), atoi(argv[2]));
            displayCanvas(*board);
            break;

        // Add a column or row
        case 'a':
        case 'A':
            // Argument count must be 3
            // Second argument must be a single character to modify column or row
            // Third argument must be a positive integer
            if (argc != 3 || strlen(argv[1]) != 1 || !isPosInteger(argv[2])) goto IAD;

            // Check second argument to modify column or row
            switch (argv[1][0]) {

                // Add a column at given position
                case 'c':
                case 'C':

                    // If requested column position is out of range, skip to improper command
                    if (atoi(argv[2]) > board->col) goto IAD;
                    addCol(board, atoi(argv[2]));
                    displayCanvas(*board);
                    break;

                // Add a row at given position
                case 'r':
                case 'R':

                    // If requested column position is out of range, skip to improper command
                    if (atoi(argv[2]) > board->row) goto IAD;
                    addRow(board, atoi(argv[2]));
                    displayCanvas(*board);
                    break;

                // Second command is not recognized
                default:
                IAD:
                    printf("Improper add command.\n");
                    break;
            }
            break;

        // Delete a column or row
        case 'd':
        case 'D':
            // Argument count must be three
            // Second argument must be a single character to modify column or row
            // Third argument must be a positive integer
            if (argc != 3 || strlen(argv[1]) != 1 || !isPosInteger(argv[2])) goto IDC;

            // Check second argument to modify column or row
            switch (argv[1][0]) {

                // Delete a column at a given position
                case 'c':
                case 'C':
                    // If requested column position is out of range, skip
                    if (atoi(argv[2]) >= board->col) goto IDC;
                    delCol(board, atoi(argv[2]));
                    displayCanvas(*board);
                    break;

                // Delete a row at a given position
                case 'r':
                case 'R':
                    // If requested row position is out of range, skip
                    if (atoi(argv[2]) >= board->row) goto IDC;
                    delRow(board, atoi(argv[2]));
                    displayCanvas(*board);
                    break;

                // Second command is not recognized
                default:
                IDC:
                    printf("Improper delete command.\n");
                    break;
            }
            break;

        // Erase a column or row
        case 'e':
        case 'E':

            // Argument count must be three
            // Second argument must be a single character
            // Third argument must be a positive integer
            if (argc != 3 || strlen(argv[1]) != 1 || !isPosInteger(argv[2])) goto IEC;

            // Use second argument to modify column or row
            switch (argv[1][0]) {

                // Erase column at a given position
                case 'c':
                case 'C':
                    // If requested column is out of range, skip
                    if (atoi(argv[2]) >= board->col) goto IEC;

                    eraseCol(board, atoi(argv[2]));
                    displayCanvas(*board);
                    break;

                // Erase row at a given position
                case 'r':
                case 'R':

                    // If requested row is out of range, skip
                    if (atoi(argv[2]) >= board->row) goto IEC;

                    eraseRow(board, atoi(argv[2]));
                    displayCanvas(*board);
                    break;

                // Second command is not recognized
                default:
                IEC:
                    printf("Improper erase command.\n");
                    break;
            }
            break;

        // Save to file
        case 's':
        case 'S':

            // Argument count must equal two
            if (argc == 2) {
                saveCanvas(board, argv[1]);
            }
            else {
                printf("Improper save command or file could not be created.\n");
            }
            break;

        // Load a file
        case 'l':
        case 'L':

            // Argument count must equal two
            if (argc == 2) {
                loadCanvas(board, argv[1]);
            }
            else {
                printf("Improper save command or file could not be opened.\n");
            }
            break;

        // Commands are not recognized
        default:
        UNRECOGNIZED:
            printf("Unrecognized command. Type h for help.\n");
            break;
    }
}

void quit(canvas *board) {
    // Free canvas grid memory
    freeCanvas(board);

    // Exit program
    exit(0);
}

void print_help() {
    // Print out the list of commands to the console

    printf("Commands:\n");
    printf("    Help:        h\n");
    printf("    Quit:        q\n");
    printf("    Draw line:   w row_start col_start row_end col_end\n");
    printf("    Resize:      r num_rows num_cols\n");
    printf("    Add row or column:     a [r | c] pos\n");
    printf("    Delete row or column:  d [r | c] pos\n");
    printf("    Erase:       e row col\n");
    printf("    Save:        s file_name\n");
    printf("    Load:        l file_name\n");
}
