# TextPaint

___
#####Author: Jennifer Salas
___
#####Created: November 30th, 2016

This is a text-based paint program that will generage a 10x10 grid by default. A user may draw lines, resize the grid, add or delete columns and rows, erase columns or rows, save the current grid to a file or load a previously saved grid.

To run:
* ./paint.out [ num_rows num_columns ]

To compile:
* make

Commands:
* Help:        h
* Quit:        q
* Draw line:   w row_start col_start row_end col_end
* Resize:      r num_rows num_cols
* Add row or column:     a [r | c] pos
* Delete row or column:  d [r | c] pos
* Erase:       e row col
* Save:        s file_name
* Load:        l file_name

For descriptions of c files and functions, view the corresponding .h files.