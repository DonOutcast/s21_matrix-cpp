#ifndef SRC_S21_MATRIX_OOP_H
#define SRC_S21_MATRIX_OOP_H
#include <iostream>
#include <stdexcept>
#include <cmath>
 
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
    void clear_matrix();
    void bring_to_zero();
    void copy_matrix(const S21Matrix& other);
    int get_columns();
    int get_rows();
    void set_columns(int columns);
    void set_rows(int rows);
    void output_matrix();
    void generarion_numbers();


    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();
    S21Matrix calc_complements();
    void cut_matrix(S21Matrix& result, int rows_A, int columns_A);
    double determinant();
    S21Matrix inverse_matrix();

    S21Matrix& operator=(const S21Matrix& other);
    bool operator==(const S21Matrix& other);
    S21Matrix operator+=(const S21Matrix& other);
    S21Matrix operator-=(const S21Matrix& other);
    S21Matrix operator*=(const S21Matrix& other);
    S21Matrix operator+(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other);
    double& operator()(int i, int j);

};


#endif  // SRC_S21_MATRIX_OOP_H
