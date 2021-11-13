#pragma once
#include <iostream>
class Matrix {
private:
	int rows, columns;
	double** data;

public:
	Matrix();
	Matrix(int rows, int columns);
	Matrix(Matrix& rhs);
	~Matrix();
	int GetRows() const;
	int GetCols() const;
	double& operator () (int i, int j);
	/*Matrix& operator = (Matrix& rhs);*/
	Matrix operator + (Matrix& rhs);
	Matrix operator - (Matrix& rhs);
	Matrix operator * (Matrix& rhs);
	Matrix operator * (double h);
	Matrix operator / (double h);
	friend Matrix operator * (double h, Matrix matrix);
	friend Matrix operator / (double h, Matrix matrix);
	double tr();

	void EnterMatrix();
	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
};
