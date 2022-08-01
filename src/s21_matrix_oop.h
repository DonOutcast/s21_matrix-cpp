#ifndef SRC_S21_MATRIX_OOP_H
#define SRC_S21_MATRIX_OOP_H
#include <iostream>
#include <exception>

class S21Matrix {
    private:
    int rows_;
    int columns_;
    double **matrix_;
    public:
    S21Matrix();
    S21Matrix(int rows, int columns);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();
    void create_matrix();
    void copy_matrix();
    void get_columns();
    void get_rows();
    void set_columns();
    void set_rows();
    void output_matrix();

     S21Matrix& operator=(const S21Matrix& other);
};


#endif  // SRC_S21_MATRIX_OOP_H
