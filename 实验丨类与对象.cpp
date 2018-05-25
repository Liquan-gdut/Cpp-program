#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//����������������
//���캯�������ƹ��캯����print������������������(����)
//��������
class Students{
private:
	string _num;
	string _name;
	string _address;

public:
	Students(string num, string name, string _address);
	Students(Students & student);
	void print();
	~Students();
};


Students::Students(string num, string name, string address) :_num(num), _name(name), _address(address){}
Students::Students(Students & student) : _num(student._num), _name(student._name), _address(student._address){}
Students::~Students(){
	cout << _name << "�ѱ��ͷ�" << endl;
}

void Students::print(){
	cout << "ѧ�ţ�" << _num << "  " << "������" << _name << "  " << "���᣺" << _address << endl;
}

//�̳�student������UniStudent
class aStudent:public Students
{
private:
	string _sch;
public:
	aStudent(string num, string name, string _address, string sch) : Students(num, name, _address){ _sch = sch; };
	~aStudent();
	void print(){
		Students::print();
		cout << "ѧУ��" << _sch << endl;
	}
};



//���Գ���
void main(){
	Students student1("3115002441", "��Ȩ", "��һ415");
	Students student2(student1);
	aStudent stu3("3115002441", "��Ȩ", "��һ415","�㹤");
	student1.print();
	student2.print();
	stu3.print();

}