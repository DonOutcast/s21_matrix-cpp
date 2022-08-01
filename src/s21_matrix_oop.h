#ifndef SRC_S21_MATRIX_OOP_H
#define SRC_S21_MATRIX_OOP_H
#include <iostream>
#include <exception>

class S21Matrix {
    private:
    int _rows;
    int _columns;
    double **_matrix;
    public:
    S21Matrix();
    ~S21Matrix();
    output_natrix();
};


#endif  // SRC_S21_MATRIX_OOP_H
