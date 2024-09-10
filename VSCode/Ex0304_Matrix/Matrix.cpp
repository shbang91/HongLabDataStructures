#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{
	// TODO:
	num_rows_ = num_rows;
	num_cols_ = num_cols;
	values_ = new float[num_rows * num_cols];
	for (int i(0); i < num_rows_ * num_cols_; i++)
	{
		values_[i] = 0.0f;
	}
}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix& b)
{
	// TODO:
	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;
	values_ = new float[num_rows_ * num_cols_];
	memcpy(values_, b.values_, sizeof(float) * num_rows_ * num_cols_);
}

Matrix::~Matrix()
{
	// TODO:
	if (values_)
		delete[] values_;
}

void Matrix::SetValue(int row, int col, float value)
{
	// values_[TODO] = value;
	values_[num_cols_ * row + col] = value;
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	return values_[num_cols_ * row + col];
}

Matrix Matrix::Transpose()
{
	Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

	// TODO:
	for (int i(0); i < num_rows_; i++)
	{
		for (int j(0); j < num_cols_; j++)
		{
			temp.values_[temp.num_cols_ * j + i] = values_[num_cols_ * i + j];
		}
	}

	return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Matrix temp(num_rows_, num_cols_);

	// TODO:
	for (int i(0); i < num_rows_; i++)
	{
		for (int j(0); j < num_cols_; j++)
		{
			temp.values_[num_cols_ * i + j] = values_[num_cols_ * i + j] + b.values_[num_cols_ * i + j];
		}
	}

	return temp;
}

void Matrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}
