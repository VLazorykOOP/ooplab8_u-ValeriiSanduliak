#pragma once
#include<iostream>
using std::ostream;
using std::istream;
template<typename T>
class Matrix {
private:
	T** data;
	int rows;
	int cols;
public:
	Matrix() : rows(0), cols(0) ,data(nullptr){}
	Matrix(int rows, int cols) : rows(rows), cols(cols) 
	{
		data = new T * [rows];
		for (int i = 0; i < rows; i++) 
		{
			data[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
	{
		data = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < cols; j++) 
			{
				data[i][j] = other.data[i][j];
			}
		}
	}
	~Matrix()
	{
		for(int i=0;i<rows;i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
	Matrix& operator=(const Matrix& other) {
		if (this != &other) {
			for (int i = 0; i < rows; i++)
			{
				delete[] data[i];
			}
			delete[] data;
			rows = other.rows;
			cols = other.cols;
			data = new T * [rows];
			for (int i = 0; i < rows; i++)
			{
				data[i] = new T[cols];
			}
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					data[i][j] = other.data[i][j];
				}
			}

		}
		else
		  return *this;
	}

	T* operator[](int i)
	{
		if (i < 0 || i >= rows)
		{
			std::cout << "Index out of range"<<std::endl;
		}
		return data[i];
	}
	Matrix operator+(const Matrix& other)
	{
		Matrix res(*this);
		res += other;
		return res;
	}
	Matrix& operator+=(const Matrix& other)
	{
		if (rows != other.rows || cols != other.cols)
		{
			std::cout << "Error matrix must have same size";
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
			   data[i][j] += other.data[i][j];
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, Matrix& m)
	{
		out << "Matrix [" << m.rows << "," << m.cols << "]" << std::endl;
		for (int i = 0; i < m.rows; i++,out<<std::endl) 
		{
			for (int j = 0; j < m.cols; j++) 
			{
				out << m.data[i][j] << " ";
			}
		}
		return out;
	}
	friend istream& operator>>(istream& in, Matrix& m)
	{
		if (m.rows == 0 && m.cols == 0)
		{
			std::cout << "Input rows,cols: ";
			std::cin >> m.rows >> m.cols;
			m.data = new T * [m.rows];
			for (int i = 0; i < m.rows; i++) {
				m.data[i] = new T[m.cols];
			}
			std::cout << "Input matrix [" << m.rows << "," << m.cols << "]" << std::endl;
			for (int i = 0; i < m.rows; i++)
			{
				for (int j = 0; j < m.cols; j++)
				{
					std::cin >> m.data[i][j];
				}
			}
		}
		else
		{
			std::cout << "Input matrix [" << m.rows << "," << m.cols << "]" << std::endl;
			for (int i = 0; i < m.rows; i++)
			{
				for (int j = 0; j < m.cols; j++)
				{
					std::cin >> m.data[i][j];
				}
			}
		}
		return in;
	}
};

void Task3()
{
	std::cout << "-------------------------" << std::endl;
	std::cout << "Test template class Matrix:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "Matrix<int>:"<<std::endl;
	Matrix<int> intMatrix(2,3);
	std::cout << "---------------------" << std::endl;
	std::cout << "Test cin,cout:" << std::endl;
	std::cin >> intMatrix;
	std::cout << intMatrix;
	std::cout << "---------------------" << std::endl;
	std::cout << "Test operator +" << std::endl;
	Matrix<int>intMatrixd(intMatrix);
	intMatrixd = intMatrixd + intMatrix;
	std::cout << intMatrixd;
	std::cout << "---------------------" << std::endl;
	std::cout << "Test operator +=" << std::endl;
	Matrix<int>intMatrixdd(intMatrixd);
	intMatrixdd += intMatrix;
	std::cout << intMatrixdd;
	std::cout << "---------------------" << std::endl;
	std::cout << "Test operator =" << std::endl;
	Matrix<int>intMe;
	intMe = intMatrix;
	std::cout << intMe;
	std::cout << "---------------------" << std::endl;
	std::cout << "End test!!!" << std::endl;
}