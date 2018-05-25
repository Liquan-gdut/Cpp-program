#include "stdafx.h"
#include <iostream>

#include <iomanip>
using namespace std;

//类模板声明：类型、非类型参数输入；
//属性：通用定义二维数组；方法：构造、复制构造、析构；print的const函数，按矩阵格式输出

template<typename Ty1, int m, int n>class Matrix{
private:
	Ty1 a[m][n];
public:
	Matrix(){};
	Matrix(Matrix &Mat);
	~Matrix(){ cout << "Object is drop！" << endl; };
	void inputData();
	void print()const;
	Matrix operator + (Matrix& mat);
};

template<typename Ty1, int m, int n>Matrix<Ty1, m, n> Matrix<Ty1, m, n>::operator + (Matrix<Ty1, m, n>& mat){
	Matrix<Ty1, m, n> temp;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp.a[m][n]=a[m][n] + mat.a[m][n];
		}
	}
	return temp;
}

template<typename Ty1, int m, int n>Matrix<Ty1,m,n>::Matrix(Matrix &Mat){
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[m][n] = Mat.a[m][n];
		}
	}
}//如果成员函数，不需要类型/非类型参数，定义的时候，类前缀是否需要跟原的类一样？？答：要。在类模板成员函数定义过程中，在类外定义的成员函数，均需要加上模板前缀！

template<typename Ty1, int m, int n>void Matrix<Ty1, m, n>::inputData(){
	cout << "please enter 16 number:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}
template<typename Ty1, int m, int n>void Matrix<Ty1, m, n>::print()const{
	cout << "You enter the value as:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
		}
		cout << "\n";
	}
}
//Test program
void main(){
	Matrix<int, 4, 4> Mat1;
	Matrix<int, 4, 4> Mat2;
	Matrix<int, 4, 4> Mat5;
	Matrix<float, 4, 4> Mat3;
	Matrix<double, 4, 4> Mat4;
	Mat5 = Mat1 + Mat2;
	Mat1.inputData();
	Mat1.print();
	Mat2.inputData();
	Mat2.print();
	Mat5.print();
	Mat3.inputData();
	Mat3.print();
}

/*小结：重要知识：①理解函数、类模板的本质作用，运行机制；②理解并熟练模板的定义、调用*/
