
#include "stdafx.h"
#include <iostream>

#include <iomanip>
using namespace std;

//类声明、属性声明：数组
//构造函数、复制构造函数、输入函数声明定义
//operator+、-、<<
class Vets
{
	friend ostream& operator<<(ostream &out, Vets & Vet);	//马虎丨当发现语法没错误时，记得仔细检查“符号中英文切换”
public:
	Vets(){};
	~Vets(){};
	Vets(Vets &Vet);
	void inputData();
	Vets operator+ (Vets Vet);
	Vets operator- (Vets Vet);
	
private:
	int _vet[16];
};

Vets::Vets(Vets &Vet){
	for (int i = 0; i < 16; i++)
	{
		_vet[i] = Vet._vet[i];
	}
}
void Vets::inputData()
{
	for (int i = 0; i < 16; i++)
	{
		cin >> _vet[i];
	}
}

Vets Vets::operator+(Vets Vet)
{
	Vets tempVet;
	for (int i = 0; i < 16; i++)
	{
		tempVet._vet[i] = _vet[i] + Vet._vet[i];	//临时对象的值 = 当前对象的值 + 参数对象的值
	}
	return tempVet;
}
Vets Vets::operator-(Vets Vet)
{
	Vets tempVet;
	for (int i = 0; i < 16; i++)
	{
		tempVet._vet[i] = _vet[i] - Vet._vet[i];	//临时对象的值 = 当前对象的值 - 参数对象的值
	}
	return tempVet;
}
ostream& operator<< (ostream &out, Vets & Vet){
	for (int i = 0; i < 16; i++)
	{
		out << Vet._vet[i]<<"\t";				//注意：如果想要输出不换行，则cout结尾不要加上“endl”；
		if ((i + 1) % 4 == 0){ cout << "\n"; }
	}
	return out;
}

//测试程序
void main(){
	Vets Vet1;
	Vets Vet2;
	Vets Vet3;
	Vets Vet4;
	cout << "请输入16位数，作为Vet1矩阵的值："<<endl;
	Vet1.inputData();
	cout << "请输入16位数，作为Vet2矩阵的值：" << endl;
	Vet2.inputData();
	Vet3 = Vet1 + Vet2;
	Vet4 = Vet1 - Vet2;
	cout << "Vet1 + Vet2的值：" << endl;
	cout << Vet3 << endl;
	cout << "Vet1 - Vet2的值：" << endl;
	cout << Vet4<<endl;
}
