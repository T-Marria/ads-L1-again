#include "pch.h"
#include "../ads-L1 again/Matrix.h"
#include "../ads-L1 again/Matrix.cpp"
#include "../ads-L1 again/Functions.cpp"

TEST(Matrix, Constructor) {
	Matrix a;
	EXPECT_EQ(0, a.GetRows());
	EXPECT_EQ(0, a.GetCols());
}

TEST(Matrix, Constructor_Parametric) {
	Matrix a(2, 3);
	EXPECT_EQ(2, a.GetRows());
	EXPECT_EQ(3, a.GetCols());
}

TEST(Matrix, Constructor_Copy) {
	Matrix a(2, 2);
	a(0, 0) = 1;
	a(0, 1) = 2;
	a(1, 0) = 3;
	a(1, 1) = 4;
	Matrix b = a;
	EXPECT_EQ(a(0, 0), b(0, 0));
	EXPECT_EQ(a(0, 1), b(0, 1));
	EXPECT_EQ(a(1, 0), b(1, 0));
	EXPECT_EQ(a(1, 1), b(1, 1));
}

TEST(Matrix, Methods_GetSizes) {
	Matrix a(2, 3);
	EXPECT_EQ(2, a.GetRows());
	EXPECT_EQ(3, a.GetCols());
}

TEST(Matrix, Operator_Brackets) {
	Matrix a(2, 2);
	a(0, 0) = 2;
	EXPECT_EQ(2, a(0, 0));
}

TEST(Matrix, Operator_Brackets_Exception) {
	Matrix a(2, 2);
	EXPECT_THROW(a(2, 3), const char*);
}

TEST(Matrix, Operator_Plus_Exception) {
	Matrix a(2, 2);
	Matrix b(3, 3);
	EXPECT_THROW(a + b, const char*);
}

TEST(Matrix, Operator_Minus_Exception) {
	Matrix a(2, 2);
	Matrix b(3, 3);
	EXPECT_THROW(a - b, const char*);
}

TEST(Matrix, Operator_Multiplication_Exception) {
	Matrix a(2, 2);
	Matrix b(3, 3);
	EXPECT_THROW(a * b, const char*);
}

TEST(Matrix, Operator_ScalarMultiplication) {
	Matrix a(2, 2);
	Matrix b(2, 2);
	a(0, 1) = 4;
	b = a * 2;
	EXPECT_EQ(8, b(0, 1));
}
TEST(Matrix, Operator_ScalarDivision) {
	Matrix a(2, 2);
	Matrix b(2, 2);
	a(0, 1) = 4;
	b = a / 2;
	EXPECT_EQ(2, b(0, 1));
}

TEST(Matrix, Method_Trace) {
	Matrix a(2, 2);
	a(0, 0) = 1;
	a(0, 1) = 2;
	a(1, 0) = 3;
	a(1, 1) = 4;
	EXPECT_EQ(5, a.tr());
}