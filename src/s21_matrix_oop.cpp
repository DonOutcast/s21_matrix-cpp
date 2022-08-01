#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
    this->bring_to_zero();
}

S21Matrix::S21Matrix(int rows, int columns) {
    if (rows <= 0 && columns <= 0) {
        throw std::runtime_error("Rows and Columns equal 0!!!!");
    }
    this->rows_ = rows;
    this->columns_ = columns;
    this->create_matrix();
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns_; j++) {
            this->matrix_[i][j] = 0;
        }
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
    this->copy_matrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    this->bring_to_zero();
    this->copy_matrix(other);
    other.clear_matrix();
}

void S21Matrix::bring_to_zero() {
    this->rows_ = this->columns_ = 0;
    this->matrix_ = nullptr;  
}

void S21Matrix::create_matrix() {
    this->matrix_ = new double* [rows_];
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[columns_];
    }
}

void S21Matrix::copy_matrix(const S21Matrix& other) {
    this->rows_ = other.rows_;
    this->columns_ = other.columns_;
    this->create_matrix();
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->columns_; j++) {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
    }
}



S21Matrix::~S21Matrix() {
    this->clear_matrix();
}

void S21Matrix::clear_matrix() {
        for (int i = 0; i < this->rows_; i++) {
        delete [] matrix_[i];
    }
    delete [] matrix_;
    this->rows_ = this->columns_ = 0;
}

void S21Matrix::output_matrix() {
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->columns_; j++) {
                std::cout << matrix_[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Hello)" << std::endl;
        // throw  std::exception();  // need class e
    }

}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (this->matrix_ == nullptr) {
        this->copy_matrix(other);
    }
    else {
        this->clear_matrix();
        this->copy_matrix(other);
    }

    return *this;
}

int S21Matrix::get_rows() {
    return this->rows_;
}
int S21Matrix::get_columns() {
    return this->columns_;
}

void S21Matrix::set_rows(int rows) {
    if (rows <= 0) {
        throw std::length_error("Rows is less or equal 0");
    }
    if (this->rows_ > 0) {
        S21Matrix temp(rows, this->columns_);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < this->columns_; j++) {
                temp.matrix_[i][j] = this->matrix_[i][j];
            }
        }
        *this = temp;
    }

}

void S21Matrix::set_columns(int columns) {
    if (columns <= 0) {
        throw std::length_error("Rows is less or equal 0");
    }

}

bol eq_matrix(const S21Matrix& other) {
    result = true;
    if (A && B && A->columns > 0 && A->columns == B->columns && A->rows == B->rows) {
        for (int i = 0; i < A->rows && ret != FAILURE; i++) {
            for (int j = 0; j < A->columns && ret != FAILURE; j++) {
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07)
                    result = false;
            }
        }
    } else {
        result = false;
    }
    return ret;
}

// int check_square(matrix_t *A) {
//   int output = 0;
//   if (A->rows == A->columns) {
//     output = 1;
//   }
//   return output;
// }

// int check_matrix(matrix_t *matrix) {
//   int result = INCORRECT_MATRIX;
//   if ((matrix != NULL) && (matrix->matrix != NULL) && (matrix->rows > 0) &&
//       (matrix->columns > 0)) {
//     result = OK;
//   }
//   return result;
// }

// void s21_remove_matrix(matrix_t *A) {
//   for (int i = 0; i < A->rows; i++) {
//     free(A->matrix[i]);
//   }
//   free(A->matrix);
// }

// int s21_create_matrix(int rows, int columns, matrix_t *result) {
//   int output = OK;
//   if (rows <= 0 || columns <= 0) {
//     output = INCORRECT_MATRIX;
//   }
//   result->rows = rows;
//   result->columns = columns;
//   result->matrix = (double **)malloc(
//       rows * sizeof(double *));  // add malloc faile after using a malloc
//   for (int i = 0; i < rows; i++) {
//     result->matrix[i] = (double *)malloc(columns * sizeof(double));
//   }

//   return output;
// }




// int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
//   int output = OK;
//   if (check_matrix(A) && check_matrix(B)) {
//     output = INCORRECT_MATRIX;
//   } else {
//     if (A->rows != B->rows || A->columns != B->columns) {
//       output = ERROR;
//     } else {
//       s21_create_matrix(A->rows, B->columns, result);
//       for (int i = 0; i < A->rows; i++) {
//         for (int j = 0; j < A->columns; j++) {
//           result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
//         }
//       }
//     }
//   }

//   return output;
// }

// int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
//   int output = OK;
//   if (check_matrix(A) && check_matrix(B)) {
//     output = INCORRECT_MATRIX;
//   } else {
//     if (A->rows != B->rows || A->columns != B->columns) {
//       output = ERROR;
//     } else {
//       s21_create_matrix(A->rows, B->columns, result);
//       for (int i = 0; i < A->rows; i++) {
//         for (int j = 0; j < B->columns; j++) {
//           result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
//         }
//       }
//     }
//   }

//   return output;
// }

// int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
//   int output = OK;
//   if (check_matrix(A)) {
//     output = INCORRECT_MATRIX;
//   } else {
//     s21_create_matrix(A->rows, A->columns, result);
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         result->matrix[i][j] = A->matrix[i][j] * number;
//       }
//     }
//   }
//   return output;
// }
// int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
//     int ret_val = 0;
//     if (!A || !B || !result || !A->matrix || !B->matrix) {
//         ret_val = 1;
//     } else if (A->columns != B->rows || A->rows != B->columns || A->columns <= 0 || B->columns <= 0) {
//         ret_val = 2;
//     } else {
//         s21_create_matrix(A->rows, B->columns, result);
//         for (int i = 0; i < result->rows; i++) {
//             for (int j = 0; j < result->columns; j++) {
//                 long double res = 0;
//                 for (int k = 0; k < A->columns; k++)
//                     res += A->matrix[i][k] * B->matrix[k][j];
//                 result->matrix[i][j] = (double)res;
//             }
//         }
//     }
//     return ret_val;
// }





// int s21_transpose(matrix_t *A, matrix_t *result) {
//   int output = OK;
//   if (check_matrix(A)) {
//     output = ERROR;
//   } else {
//     s21_create_matrix(A->columns, A->rows, result);
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         result->matrix[j][i] = A->matrix[i][j];
//       }
//     }
//   }

//   return output;
// }

// int s21_determinant(matrix_t *A, double *determ) {
//   int output = OK;
//   double tmp = 0;
//   if (check_matrix(A)) {
//     output = ERROR;
//   } else {
//     if (check_square(A)) {
//       if (A->rows == 1) *determ = A->matrix[0][0];
//       if (A->rows == 2) {
//         *determ = (A->matrix[0][0] * A->matrix[1][1]) -
//                   (A->matrix[0][1] * A->matrix[1][0]);
//       }
//       if (A->rows > 2) {
//         for (int i = 0; i < A->rows; i++) {
//           matrix_t decrMatrix;
//           cut_matrix(A, 0, i, &decrMatrix);
//           s21_determinant(&decrMatrix, determ);
//           tmp += A->matrix[i][0] * pow(-1, i) * (*determ);
//           s21_remove_matrix(&decrMatrix);
//           *determ = tmp;
//         }
//       }
//     } else {
//       *determ = NAN;
//       output = ERROR;
//     }
//   }

//   return output;
// }

// void cut_matrix(matrix_t *A, int rows_A, int columns_A, matrix_t *tmp) {
//   s21_create_matrix(A->rows - 1, A->columns - 1, tmp);
//   for (int i = 0, a = 0; i < A->rows; i++) {
//     if (columns_A != i) {
//       for (int j = 0, b = 0; j < A->rows; j++) {
//         if (rows_A != j) {
//           tmp->matrix[a][b] = A->matrix[i][j];
//           b++;
//         }
//       }
//       a++;
//     }
//   }
// }

// int s21_calc_complements(matrix_t *A, matrix_t *result) {
//   double determ = 0;
//   int output = OK;
//   matrix_t tmp;
//   if (A->columns != A->rows) {
//     output = ERROR;
//   } else {
//     if (check_matrix(A)) {
//       output = INCORRECT_MATRIX;
//     } else {
//       s21_create_matrix(A->rows, A->columns, result);
//       if (check_square(A)) {
//         for (int i = 0; i < A->rows; i++) {
//           for (int j = 0; j < A->columns; j++) {
//             cut_matrix(A, j, i, &tmp);
//             s21_determinant(&tmp, &determ);
//             result->matrix[i][j] = pow(-1, i + j) * determ;
//             s21_remove_matrix(&tmp);
//           }
//         }
//       }
//     }
//   }

//   return output;
// }

// int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
//   int output = OK;
//   if (check_matrix(A)) {
//     output = INCORRECT_MATRIX;
//   } else {
//     if (A->rows != A->columns) {
//     output = ERROR;
//   } else {
//     double determ = 0;
//     matrix_t tmp;
//     matrix_t tmp1;
//     s21_determinant(A, &determ);
//     if (fabs(determ) > 1e-7) {
//       s21_calc_complements(A, &tmp);
//       s21_transpose(&tmp, &tmp1);
//       s21_remove_matrix(&tmp);
//       s21_mult_number(&tmp1, 1 / determ, result);
//       s21_remove_matrix(&tmp1);
//     } else {
//       output = INCORRECT_MATRIX;
//     }
//   }
//   }
//   return output;
// }




int main(void) {
    // S21Matrix a(10, 10);
    // S21Matrix b(a);
    // std::cout << "Matrix A: " << std::endl;
    // a.output_matrix();
    // std::cout << "Matrix B: " << std::endl;
    // b.output_matrix();
    // a = b;
    // std::cout << "Matrix A new: " << std::endl;
    // a.output_matrix();
    return 0;
}
