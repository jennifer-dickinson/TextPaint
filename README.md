# TextPaint

This is a text-based paint program that will generate a 10x10 grid by default. A user may draw lines, resize the grid, add or delete columns and rows, erase columns or rows, save the current grid to a file or load a previously saved grid.
___
**Author: Jennifer Salas**

**Created: November 30th, 2016**
___

###To compile:
```
make
```

###To run:
```
./paint.out [ num_row num_col ]
```

###Commands:
```
Help:        h
Quit:        q
Draw line:   w row_start col_start row_end col_end
Resize:      r num_rows num_cols
Add row or column:     a [r | c] pos
Delete row or column:  d [r | c] pos
Erase:       e row col
Save:        s file_name
Load:        l file_name
```

A sample save file is provided, load with ` l samplesave `.

###Other

For descriptions of individual .c files and functions, view the corresponding .h files.

