#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
    this->_rows = this->_columns = 0;
    this->_matrix = nullptr;
}


S21Matrix::S21Matrix(int rows, int columns) {
    if (rows <= 0 && columns <= 0) {
        throw "Invalid error";
    }
    this->_rows = rows;
    this->_columns = columns;
    this->create_matrix();
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            this->_matrix[i][j] = 0;
        }
    }
}



void S21Matrix::create_matrix() {
    this->_matrix = new double* [_rows];
    for (int i = 0; i < _rows; i++) {
        this->_matrix[i] = new double[_columns];
    }
}

void S21Matrix::copy_matrix(const S21Matrix& other) {
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_columns; j++) {
            this->_matrix[i][j] = other->_matrix[i][j];
        }
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
    this->_rows = other->_rows;
    this->_columns = other->_columns;
    this->create_matrix();
    this->copy_matrix(other)
}

S21Matrix::~S21Matrix() {
    for (int i = 0; i < this->_rows; i++) {
        delete [] _matrix[i];
    }
    delete [] _matrix;
    this->_rows = this->_columns = 0;
}


void S21Matrix::output_matrix() {
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->columns_; j++) {
                std::cout << matrix_[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        throw  std::exception() "Matrix is empty";  // need class exceptions
    }

}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (&other != this) {

        this->copy_matrix(other);
    }
    else {
        this->~S21Matrix;
    }
    return *this;
}

void S21Matrix::get_rows() {
    return this->_rows;
}
void S21Matrix::get_columns() {
    return this->_columns;
}

void S21Matrix::set_rows(int rows) {
    if (rows <= 0) {
        throw "";
    }
    if (this->_rows > 0) {
        
    }

}

void S21Matrix::set_columns(int columns) {

}

int main(void) {
    /* S21Matrix s; */
    /* try { */
    /*     s.output_matrix(); */
    /* } */
    /* catch (const char *err) { */
         /* std::cout <<   err << std::endl; */
    /* } */

    return 0;
}
