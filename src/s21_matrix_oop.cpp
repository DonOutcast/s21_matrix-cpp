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
    // for (int i = 0; i < rows_; i++) {
    //     for (int j = 0; j < columns_; j++) {
    //         this->matrix_[i][j] = 0;
    //     }
    // }
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
    this->matrix_ = new double* [rows_]();  // default 0
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[columns_]();  // default 0
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
    if (this->matrix_ != nullptr) {
     for (int i = 0; i < this->rows_; i++) {
        delete [] matrix_[i];
    }
    delete [] matrix_;
    this->matrix_ = nullptr;
    this->rows_ = this->columns_ = 0;
    }
   
}

void S21Matrix::generarion_numbers() {
    for (int i = 0, count = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->columns_; j++) {
            this->matrix_[i][j] = count++;

        }
    }
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

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
    S21Matrix operand_a(*this);
    operand_a.sum_matrix(other);
    return operand_a;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
    S21Matrix operand_a(*this);
    operand_a.sub_matrix(other);
    return operand_a;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix operand_a(*this);
    operand_a.mul_matrix(other);
    return operand_a;
}

S21Matrix S21Matrix::operator*(const double num) {
    S21Matrix result(*this);
    result.mul_number(num);
    return result;
}


bool S21Matrix::operator==(const S21Matrix& other) {
    return this->eq_matrix(other);
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
    this->sum_matrix(other);
    return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
    this->sub_matrix(other);
    return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
    this->mul_matrix(other);
    return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
    this->mul_number(num);
    return *this;
}

double& S21Matrix::operator()(int i, int j) {
    if (i >= this->rows_ || j >= this->columns_ || i < 0 || j < 0) {
        throw std::out_of_range("Incorrect index!"); 
    }
    return this->matrix_[i][j];
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
    S21Matrix temp(rows, this->columns_);
    int min_rows = (rows < this->rows_) ? rows : this->rows_;
    
    for (int i = 0; i < min_rows; i++) {
        for (int j = 0; j < this->columns_; j++) {
            temp.matrix_[i][j] = this->matrix_[i][j];
        }
    }
    this->clear_matrix();
    *this = temp;
    
}

void S21Matrix::set_columns(int columns) {
    if (columns <= 0) {
        throw std::length_error("Rows is less or equal 0");
    }
    S21Matrix temp(this->rows_, columns);
    if (columns < this->columns_) {
            this->columns_ = columns;
        }
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->columns_; j++) {
                temp.matrix_[i][j] = this->matrix_[i][j];
            }
        }
        *this = temp;

}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool result = true;
    if (this->matrix_ == nullptr && other.matrix_ == nullptr) {
        throw std::length_error("Two matrixs is empty!!");
    }
    else if (this->rows_ < 0  || other.rows_ < 0 ) {
        throw std::runtime_error("Are you shure man ??");
    } else if (this->rows_ != other.rows_ || this->columns_ != other.columns_) {
        throw std::runtime_error("Comone eq");
    } else {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->columns_; j++) {
                if (std::fabs(this->matrix_[i][j] - this->matrix_[i][j]) > 1e-07)
                    result = false;
            }
        } 
    }    
    return result;
}


void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (this->matrix_ == nullptr && other.matrix_ == nullptr) {
    throw std::length_error("Two matrixs is empty!!");
  } 
  else if (this->rows_ != other.rows_ || this->columns_ != other.columns_) {
      throw std::length_error("Incorrect size of matrixs");
} else {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->columns_; j++) {
          this->matrix_[i][j] += other.matrix_[i][j];
        }
      }
    }
  
}


void S21Matrix::sub_matrix(const S21Matrix& other) {
 if (this->matrix_ == nullptr && other.matrix_ == nullptr) {
    throw std::length_error("Two matrixs is empty!!");
  } 
  else if (this->rows_ != other.rows_ || this->columns_ != other.columns_) {
      throw std::length_error("Incorrect size of matrixs");
} else {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->columns_; j++) {
          this->matrix_[i][j] -= other.matrix_[i][j];
        }
      }
    }

}

void S21Matrix::mul_number(const double num) {
    if (this->matrix_ == nullptr) {
        throw std::length_error("Two matrixs is empty!!");
    } else {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->columns_; j++) {
                this->matrix_[i][j] *= num;
            }
        }
    }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
    if (!this->matrix_ || !other.matrix_) {
        throw std::length_error("Two matrixs is empty!!");
    } else if (this->columns_ != other.rows_) {
        throw std::runtime_error("Incorrect size of rows or columns");
    } 
        S21Matrix result(this->rows_, other.columns_);
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < other.columns_; j++) {
                for (int k = 0; k < this->columns_; k++) {
                    result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
                
            }
        }
    }
    *this = result;
}


void S21Matrix::cut_matrix(S21Matrix& result, int rows_A, int columns_A) {
  for (int i = 0, a = 0; i < this->rows_; i++) {
    if (columns_A != i) {
      for (int j = 0, b = 0; j < this->rows_; j++) {
        if (rows_A != j) {
          result.matrix_[a][b] = this->matrix_[i][j];
          b++;
        }
      }
      a++;
    }
  }
}


double  S21Matrix::determinant() {
  double result = 0;
  if (!this->matrix_) {
      throw std::length_error("Matrix is empty d");
  } else {
    if (this->rows_ == this->columns_) {
      if (this->rows_ == 1) result = this->matrix_[0][0];
      if (this->rows_ == 2) {
        result = (this->matrix_[0][0] * this->matrix_[1][1]) -
                  (this->matrix_[0][1] * this->matrix_[1][0]);
      }
      if (this->rows_ > 2) {
         double tmp = 0; 
        for (int i = 0; i < this->rows_; i++) {
          S21Matrix minor(this->rows_ - 1, this->columns_ -1);
          cut_matrix(minor, 0, i);
          result = minor.determinant();
          tmp += this->matrix_[i][0] * pow(-1, i) * result;
          result = tmp;
        }
      }
    } else {
      throw std::runtime_error("Error with size");
    }
  }
  return result;
}

S21Matrix S21Matrix::transpose() {
  if (!this->matrix_) {
     throw std::length_error("Matrixs is empty!!");
  } 
    S21Matrix result(this->columns_, this->rows_);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->columns_; j++) {
        result.matrix_[j][i] = this->matrix_[i][j];
      }
    
  }

  return result;
}


S21Matrix S21Matrix::calc_complements() {
  if (this->matrix_ == nullptr) {
      throw std::length_error("Matrix is empty! c");
  }
  if (this->columns_ != this->rows_) {
      throw std::length_error("Error in len of matrix");
  } 
      S21Matrix result(this->rows_, this->columns_);
      S21Matrix determ(this->rows_ - 1, this->columns_ - 1);
        double temp = 0;
        for (int i = 0; i < this->rows_; i++) {
          for (int j = 0; j < this->columns_; j++) {
            this->cut_matrix(determ, j, i);
            temp = determ.determinant();
            result.matrix_[i][j] = pow(-1, i + j) * temp;
            
        }
        }
  return result;
}


S21Matrix S21Matrix::inverse_matrix() {
    S21Matrix tmp(3,3);
    S21Matrix tmp1(3,3);
  if (!this->matrix_) {
    throw std::length_error("Matrix is empty");
  } else {
    if (this->rows_ != this->columns_) {
    throw std::runtime_error("Man are you shure???");
  } else {
    double determ = 0;

    determ =this->determinant();
    if (std::fabs(determ) > 1e-7) {
      tmp = this->calc_complements();
      tmp1 = tmp.transpose();
      tmp1.mul_number( 1 / determ);
    } else {
      throw std::length_error("Your determ is 0!!!!");
    }
  }
  }
  return tmp1;
}

// int main(void) {
//     S21Matrix a(3, 3);
//     S21Matrix b(3, 3);
//     a.generarion_numbers();
//     b.generarion_numbers();
//     std::cout << "Matrix A: " << std::endl;
//     a.output_matrix();
//     std::cout << "Matrix B: " << std::endl;
//     b.output_matrix();
//     std::cout << "Matrix A new: " << std::endl;
//     a(0, 0) = 1;
//     a.output_matrix();
//     return 0;
// }
