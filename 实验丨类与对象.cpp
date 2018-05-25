#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//类声明，属性声明
//构造函数、复制构造函数、print函数、析构函数声明(定义)
//函数定义
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
	cout << _name << "已被释放" << endl;
}

void Students::print(){
	cout << "学号：" << _num << "  " << "姓名：" << _name << "  " << "宿舍：" << _address << endl;
}

//继承student，生成UniStudent
class aStudent:public Students
{
private:
	string _sch;
public:
	aStudent(string num, string name, string _address, string sch) : Students(num, name, _address){ _sch = sch; };
	~aStudent();
	void print(){
		Students::print();
		cout << "学校：" << _sch << endl;
	}
};



//测试程序
void main(){
	Students student1("3115002441", "李权", "东一415");
	Students student2(student1);
	aStudent stu3("3115002441", "李权", "东一415","广工");
	student1.print();
	student2.print();
	stu3.print();

}