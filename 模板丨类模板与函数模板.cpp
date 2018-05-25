#include "stdafx.h"
#include <iostream>

#include <iomanip>
using namespace std;

//��ģ�����������͡������Ͳ������룻
//���ԣ�ͨ�ö����ά���飻���������졢���ƹ��졢������print��const�������������ʽ���

template<typename Ty1, int m, int n>class Matrix{
private:
	Ty1 a[m][n];
public:
	Matrix(){};
	Matrix(Matrix &Mat);
	~Matrix(){ cout << "Object is drop��" << endl; };
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
}//�����Ա����������Ҫ����/�����Ͳ����������ʱ����ǰ׺�Ƿ���Ҫ��ԭ����һ��������Ҫ������ģ���Ա������������У������ⶨ��ĳ�Ա����������Ҫ����ģ��ǰ׺��

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

/*С�᣺��Ҫ֪ʶ������⺯������ģ��ı������ã����л��ƣ�����Ⲣ����ģ��Ķ��塢����*/
