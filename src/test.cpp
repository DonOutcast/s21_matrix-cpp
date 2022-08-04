#include "s21_matrix_oop.h"
#include <gtest/gtest.h>

TEST(Test, eq_matrix) {
    S21Matrix A(3,3);
    S21Matrix B(3,3);
    A.generarion_numbers();
    B.generarion_numbers();
    if (A == B) {
        EXPECT_EQ(1, 1);
        ASSERT_TRUE(1);
    }
}

TEST(Test, not_eq_matrix) {
    S21Matrix A;
    S21Matrix B;
    EXPECT_THROW(A == B, std::length_error);
}

TEST(Test, get_rows) {
    S21Matrix A(3,3);
    EXPECT_EQ(3, A.get_rows());
}

TEST(Test, get_columns) {
    S21Matrix A(3,3);
    EXPECT_EQ(3, A.get_columns());
}

TEST(Test, set_rows) {
    S21Matrix A(3,3);
    A.set_rows(4);
    EXPECT_EQ(4, A.get_rows());
}

TEST(Test, set_rows_less_0) {
    S21Matrix A(3,3);
    EXPECT_THROW(A.set_rows(-1), std::length_error);
}

TEST(Test, set_columns) {
    S21Matrix A(3,3);
    A.set_columns(7);
    EXPECT_EQ(7, A.get_columns());
}

TEST(Test, set_columns_less_0) {
    S21Matrix A(3,3);
    EXPECT_THROW(A.set_columns(-1), std::length_error);
}

TEST(Test, get_columns_3) {
    S21Matrix A(3,3);
    EXPECT_EQ(3, A.get_columns());
}

TEST(Test, get_rows_5) {
    S21Matrix A(5,2);
    EXPECT_EQ(5, A.get_rows());
}

TEST(Test, constructor_0) {
    S21Matrix A;
    EXPECT_EQ(0, A.get_rows());
    EXPECT_EQ(0, A.get_columns());
}

TEST(Test, constructor_4_4) {
    S21Matrix A(4,4);
    EXPECT_EQ(4, A.get_columns());
    EXPECT_EQ(4, A.get_rows());
}

TEST(Test, constructor_from_other) {
    S21Matrix A(3,4);
    S21Matrix B(A);
    EXPECT_EQ(3, B.get_rows());
    EXPECT_EQ(4, B.get_columns());
    EXPECT_EQ(1, A == B);
}

TEST(Test, constructor_move) {
    S21Matrix A(5,5);
    S21Matrix B(std::move(A));
    EXPECT_EQ(5, B.get_rows());
    EXPECT_EQ(5, B.get_columns());
    EXPECT_EQ(0, A.get_rows());
    EXPECT_EQ(0, A.get_columns());
}

TEST(Test, set_rows_test) {
    S21Matrix A(8,5);
    A.generarion_numbers();
    A.set_rows(3);
    EXPECT_EQ(3, A.get_rows());
}

TEST(Test, set_columns_test) {
    S21Matrix A(3,6);
    A.generarion_numbers();
    A.set_columns(2);
    EXPECT_EQ(2 , A.get_columns());
}

TEST(Test, set_rows_throw) {
    S21Matrix A;
    EXPECT_THROW(A.set_rows(0), std::length_error);
}

TEST(Test, set_columns_throw) {
    S21Matrix A;
    EXPECT_THROW(A.set_columns(0), std::length_error);
}

TEST(Test, plus_operator) {
    S21Matrix A(3,4);
    S21Matrix B(3,4);
    B(0, 0) = 2;
    B(0, 1) = 4;
    B(0, 2) = 6;
    B(0, 3) = 2;
    B(1, 0) = 10;
    B(1, 1) = 12;
    B(1, 2) = 95;
    B(1, 3) = 94;
    B(2, 0) = 18;
    B(2, 1) = 94;
    B(2, 2) = 22;
    B(2, 3) = 98;
    A = B + B;
    EXPECT_EQ(1, A == B);
}   

TEST(Test, plus_with_eq) {
    S21Matrix A(3,4);
    S21Matrix B(3,4);
    B(0, 0) = 2;
    B(0, 1) = 4;
    B(0, 2) = 6;
    B(0, 3) = 2;
    B(1, 0) = 10;
    B(1, 1) = 12;
    B(1, 2) = 95;
    B(1, 3) = 94;
    B(2, 0) = 18;
    B(2, 1) = 94;
    B(2, 2) = 22;
    B(2, 3) = 98;
    A += B;
    EXPECT_EQ(1, A == B);
}

TEST(Test, plus_throw) {
    S21Matrix A(3,5);
    S21Matrix B(5,4);
    EXPECT_THROW(A + B, std::length_error);
}

TEST(Test, minus_operator) {
    S21Matrix A(3,4);
    S21Matrix B(3,4);
    B(0, 0) = 2;
    B(0, 1) = 4;
    B(0, 2) = 6;
    B(0, 3) = 2;
    B(1, 0) = 10;
    B(1, 1) = 12;
    B(1, 2) = 95;
    B(1, 3) = 94;
    B(2, 0) = 18;
    B(2, 1) = 94;
    B(2, 2) = 22;
    B(2, 3) = 98;
    A = B - B;
    EXPECT_EQ(1, A == B);
}

TEST(Test, minus_operator_with_eq) {
    S21Matrix A(3,4);
    S21Matrix B(3,4);
    B(0, 0) = 2;
    B(0, 1) = 4;
    B(0, 2) = 6;
    B(0, 3) = 2;
    B(1, 0) = 10;
    B(1, 1) = 12;
    B(1, 2) = 95;
    B(1, 3) = 94;
    B(2, 0) = 18;
    B(2, 1) = 94;
    B(2, 2) = 22;
    B(2, 3) = 98;
    A -= B;
    EXPECT_EQ(1, A == B);
}

TEST(Test, minus_operator_throw) {
    S21Matrix A(3,5);
    S21Matrix B(5,4);
    EXPECT_THROW(A - B, std::length_error);
}

TEST(Test, mul_operator_num) {
    S21Matrix A(3,4);
    S21Matrix B(3,4);
    B(0, 0) = 2;
    B(0, 1) = 4;
    B(0, 2) = 6;
    B(0, 3) = 2;
    B(1, 0) = 10;
    B(1, 1) = 12;
    B(1, 2) = 95;
    B(1, 3) = 94;
    B(2, 0) = 18;
    B(2, 1) = 94;
    B(2, 2) = 22;
    B(2, 3) = 98;
    A = B * 5;
    EXPECT_EQ(1, A == B);
}

TEST(Test, mul_operator_num_with_eq) {
    S21Matrix A(3,4);
    S21Matrix B(3,4);
    B(0, 0) = 2;
    B(0, 1) = 4;
    B(0, 2) = 6;
    B(0, 3) = 2;
    B(1, 0) = 10;
    B(1, 1) = 12;
    B(1, 2) = 95;
    B(1, 3) = 94;
    B(2, 0) = 18;
    B(2, 1) = 94;
    B(2, 2) = 22;
    B(2, 3) = 98;
    A *= 5;
    EXPECT_EQ(1, A == B);
}

TEST(Test, mul_matrix_test) {
    S21Matrix A(3,1);
    A.generarion_numbers();
    S21Matrix B(3,3);
    B.generarion_numbers();
    
    S21Matrix C(3,1);
    
    C =  B * A;
    
    EXPECT_EQ(1, C == A);
}

TEST(Test, mul_matrix_with_eq) {
    S21Matrix A(3,1);
    A.generarion_numbers();
    S21Matrix B(3,3);
    B.generarion_numbers();
    
    S21Matrix C(3,1);
    B *= A;
    EXPECT_EQ(1, C == B);
}


TEST(Test, mul_matrix_throw) {
    S21Matrix A(3,1);
    S21Matrix B(3,3);
    EXPECT_THROW(A * B, std::runtime_error);
}

TEST(Test, operation_func) {
    S21Matrix A(3,3);
    A.operator()(0, 0) = 5;
    EXPECT_EQ(5, A.operator()(0, 0));
}

TEST(Test, operation_func_throw) {
    S21Matrix A(3,2);
    EXPECT_THROW(A.operator()(-1,0), std::out_of_range);
    EXPECT_THROW(A.operator()(5,0), std::out_of_range);
}

TEST(Test, determ_testing) {
    S21Matrix A(3, 3);
    A.operator()(0, 0) = 8;
    A.operator()(0, 1) = 2;
    A.operator()(0, 2) = 4;
    A.operator()(1, 0) = 4;
    A.operator()(1, 1) = 6;
    A.operator()(1, 2) = 6;
    A.operator()(2, 0) = 4;
    A.operator()(2, 1) = 8;
    A.operator()(2, 2) = 8;
    EXPECT_EQ(16, A.determinant());
}

TEST(Test, trans) {
    S21Matrix A(3, 4);
    A.operator()(0, 0) = 1;
    A.operator()(0, 1) = 2;
    A.operator()(0, 2) = 3;
    A.operator()(0, 3) = 4;
    A.operator()(1, 0) = 5;
    A.operator()(1, 1) = 6;
    A.operator()(1, 2) = 7;
    A.operator()(1, 3) = 8;
    A.operator()(2, 0) = 9;
    A.operator()(2, 1) = 10;
    A.operator()(2, 2) = 11;
    A.operator()(2, 3) = 12;
    S21Matrix B(3,4);
    B = A.transpose();
    EXPECT_EQ(4, B.get_rows());
    EXPECT_EQ(3, B.get_columns());

}

TEST(Test, inverst_test) {
    S21Matrix result(3,3);
    result(0, 0) = 0;
    result(0, 1) = 1;
    result(0, 2) = -0.75;
    result(1, 0) = -0.5;
    result(1, 1) = 3;
    result(1, 2) = -2;
    result(2, 0) = 0.5;
    result(2, 1) = -3.5;
    result(2, 2) = 2.5;

    S21Matrix result_inverse(3,3);

    S21Matrix R(3, 3);
    R.operator()(0, 0) = 8;
    R.operator()(0, 1) = 2;
    R.operator()(0, 2) = 4;
    R.operator()(1, 0) = 4;
    R.operator()(1, 1) = 6;
    R.operator()(1, 2) = 6;
    R.operator()(2, 0) = 4;
    R.operator()(2, 1) = 8;
    R.operator()(2, 2) = 8;
    
    result_inverse = R.inverse_matrix();
    EXPECT_EQ(1, result == result_inverse);
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
