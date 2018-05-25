
#include "stdafx.h"
#include <iostream>

#include <iomanip>
using namespace std;

//����������������������
//���캯�������ƹ��캯�������뺯����������
//operator+��-��<<
class Vets
{
	friend ostream& operator<<(ostream &out, Vets & Vet);	//��ح�������﷨û����ʱ���ǵ���ϸ��顰������Ӣ���л���
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
		tempVet._vet[i] = _vet[i] + Vet._vet[i];	//��ʱ�����ֵ = ��ǰ�����ֵ + ���������ֵ
	}
	return tempVet;
}
Vets Vets::operator-(Vets Vet)
{
	Vets tempVet;
	for (int i = 0; i < 16; i++)
	{
		tempVet._vet[i] = _vet[i] - Vet._vet[i];	//��ʱ�����ֵ = ��ǰ�����ֵ - ���������ֵ
	}
	return tempVet;
}
ostream& operator<< (ostream &out, Vets & Vet){
	for (int i = 0; i < 16; i++)
	{
		out << Vet._vet[i]<<"\t";				//ע�⣺�����Ҫ��������У���cout��β��Ҫ���ϡ�endl����
		if ((i + 1) % 4 == 0){ cout << "\n"; }
	}
	return out;
}

//���Գ���
void main(){
	Vets Vet1;
	Vets Vet2;
	Vets Vet3;
	Vets Vet4;
	cout << "������16λ������ΪVet1�����ֵ��"<<endl;
	Vet1.inputData();
	cout << "������16λ������ΪVet2�����ֵ��" << endl;
	Vet2.inputData();
	Vet3 = Vet1 + Vet2;
	Vet4 = Vet1 - Vet2;
	cout << "Vet1 + Vet2��ֵ��" << endl;
	cout << Vet3 << endl;
	cout << "Vet1 - Vet2��ֵ��" << endl;
	cout << Vet4<<endl;
}
