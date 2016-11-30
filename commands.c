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

    canvas board = createCanvas(row, col);

    displayCanvas(board);

    do {
        printf("Enter your command: ");
        get_args(&promptArgsC, &promptArgs);
        read_command(promptArgsC, promptArgs, &board);
        free_args(&promptArgsC, promptArgs);
    }
    while (true);
}

void read_command(int argc, char **argv, canvas *board) {
    char command;
    command = (strlen(argv[0]) > 1) ? ' ' : argv[0][0];
    mainCommand(command, argc, argv, board);

}

void mainCommand(char command, int argc, char **argv, canvas *board) {
    switch (command) {
        case 'h':
        case 'H':
            print_help();
            break;

        case 'q':
        case 'Q':
            quit(board);
            break;

        case 'w':
        case 'W':
            writeLine(board, argc, argv);
            break;

        case 'r':
        case 'R':
            if (argc == 3 && isPosInteger(argv[1]) && (isPosInteger(argv[1])) && atoi(argv[1]) > 0 &&
                atoi(argv[2]) > 0) {
                resize(board, atoi(argv[1]), atoi(argv[2]));
                displayCanvas(*board);
            }
            else {
                printf("Improper resize command.\n");
            }
            break;

        case 'a':
        case 'A':

            if (argc == 3 && strlen(argv[1]) == 1 && (isPosInteger(argv[2])) && atoi(argv[2]) >= 0) {
                switch (argv[1][0]) {
                    case 'r':
                    case 'R':
                        if (atoi(argv[2]) > board->row) goto IAD;
                        addRow(board, atoi(argv[2]));
                        displayCanvas(*board);
                        break;
                    case 'c':
                    case 'C':
                        if (atoi(argv[2]) > board->col) goto IAD;
                        addCol(board, atoi(argv[2]));
                        displayCanvas(*board);
                        break;

                    default:
                    IAD:
                        printf("Improper add command.\n");
                        break;
                }
            }
            else {
                goto IAD;
            }

            break;

        case 'd':
        case 'D':
            if (strlen(argv[1]) == 1) {
                switch (argv[1][0]) {
                    case 'r':
                    case 'R':
                        if (atoi(argv[2]) >= board->row || atoi(argv[2]) < 0 || !isPosInteger(argv[2])) goto IDC;
                        delRow(board, atoi(argv[2]));
                        displayCanvas(*board);
                        break;
                    case 'c':
                    case 'C':
                        if (atoi(argv[2]) >= board->col || atoi(argv[2]) < 0 || !isPosInteger(argv[2])) goto IDC;
                        delCol(board, atoi(argv[2]));
                        displayCanvas(*board);
                        break;

                    default:
                    IDC:
                        printf("Improper delete command.\n");
                        break;
                }
            }
            break;

        case 'e':
        case 'E':
            if (argc == 3 & strlen(argv[1]) == 1) {

                switch (argv[1][0]) {
                    case 'c':
                    case 'C':
                        if (atoi(argv[2]) >= board->col || atoi(argv[2]) < 0) goto IEC;

                        eraseCol(board, atoi(argv[2]));
                        displayCanvas(*board);
                        break;
                    case 'r':
                    case 'R':
                        if (atoi(argv[2]) >= board->row || atoi(argv[2]) < 0) goto IEC;

                        eraseRow(board, atoi(argv[2]));
                        displayCanvas(*board);
                        break;
                    default:
                    IEC:
                        printf("Improper erase command.\n");
                        break;
                }
            }
            break;

        case 's':
        case 'S':
            if (argc == 2) {
                saveCanvas(board, argv[1]);
            }
            else {
                printf("Improper save command or file could not be created.\n");

            }
            break;

        case 'l':
        case 'L':
            if (argc == 2) {
                loadCanvas(board, argv[1]);
            }
            else {
                printf("Improper save command or file could not be opened.\n");
            }
            break;

        default:
            printf("Unrecognized command. Type h for help.\n");
            break;
    }
}

void quit(canvas *board) {
    freeCanvas(board);
    exit(0);
}

void print_help() {

    printf("Commands:\n");
    printf("    Help: h\n");
    printf("    Quit: q\n");
    printf("    Draw line: w row_start col_start row_end col_end\n");
    printf("    Resize: r num_rows num_cols\n");
    printf("    Add row or column: a [r | c] pos\n");
    printf("    Delete row or column: d [r | c] pos\n");
    printf("    Erase: e row col\n");
    printf("    Save: s file_name\n");
    printf("    Load: l file_name\n");
}
