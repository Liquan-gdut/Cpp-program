# C++ح����֪ʶС��

��л�����Ǳ�ѧ�ڵ�C++��ʦ�������Ŵ�˵�����ɬ�Ѷ��ı�����ԣ��������������������ᣬѧ��Ա�̡��ڴ�ȷʵ���������֮Ч��������˵��������ѵ�ε���ʦ���û�͸����������ѵ��ʦ�ܲ�������ѵ��....��������ʱ�䣬׼�������л�Ÿ���ʦ���϶�����ʦ�Ľ�ѧ��ʽ��������c++�ɼ������ˣ�Ҫ���ܸ��Ҷ����������Ҿ͸�л������̵�......
һ������
1���������ݵ����ַ�ʽ���ص�
��1����ֵ���ã���ʵ�ε�ֵ���Ƹ��βΣ���ʵ�θ�����ơ����໥����������ʵ�Σ����������βξֲ��ڴ档
��2�����õ��ã���ʵ�εĵ�ַ���Ƹ��βΣ���ʵ�ι���һ���ڴ桱���������ֲ�ͬ���ѣ���ʵ��ֱ�Ӳ������㣬ʵʱ�仯�������ö������ɾֲ��ڴ档
��3��ָ����ã������ϴ�ָ���ֵ���߼��ϴ�ָ�루��ַ����������������һģһ�����������ÿ�������ֱ�ۡ�
2��������������������
��1���������أ���ͬ�ĺ���������������ȴ����ͬ�ĺ������ܡ�
       ִ�л��ƣ����ݴ�����������ͣ�����������һ�����͵ĺ�����
��2��������������ִ�е�ĳ��������ʱ�����򽫲��á������ֳ�����ջ����ֱ�ӽ�����Ƕ�뵽�ô�����ʱ�ı�������Ϊȫ�ֱ�����
        ���ó��ϣ��������١������١�ִ��Ƶ�ʸߵĹ��ܴ���飬��ȥ��Ƶ������ջ��ջ������Ч���ִ��Ч�ʡ�
����������������ƣ��ࣩ
1��c++�ඨ��Ļ����ܹ�
��1������c++primer���ܽ�          
        ���������ṩ�������ͼ�������ݳ�Ա�ķ�ʽ���������ݲ��֣��Ժ�����Ա��ʽ�����˹��нӿ�
        �ඨ�壺�ṩ����ķ������壬���������ʵ���ຯ����Ա������ʵ�ֹ���
2�����캯���븴�ƹ��캯��
��1�����캯����ȫ����Ĺ��캯������һ����ͬ�Ĺ��ܣ�Ϊ������Գ�ʼ�����ԡ�
��2�����ƹ��캯�����������еĶ���������һ���µĶ���
3��ʲô�����ã�
��1�����ʶ��壺�������ᵽ������Ҳ���ԽС��������������ͬ����/����������һ���ڴ�ռ䣬����һ��������ֵ�ı䣬�������õ�ֵ���ı䡣
4�����������
��1�����壺��ϵͳ���õĸ����������+��-��*.....�����������µĹ��ܣ����������⵽��Ŀ�����Ϊ��Ӧ�ġ��ࡱʱ���������ع��ܡ�
��2�������ӣ����ء�+�����������Ǿ����ࣨMatrix��ʱ���������ع��ܣ�ÿ������Ԫ�ض����
```cpp
#include "stdafx.h"
#include <iostream>

#include <iomanip>
using namespace std;

//����������������������
//���캯�������ƹ��캯�������뺯����������
//operator+��-��<<
class Vets
{
friend ostream& operator<<(ostream &out, Vets & Vet); //��ح�������﷨û����ʱ���ǵ���ϸ��顰������Ӣ���л���
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
tempVet._vet[i] = _vet[i] + Vet._vet[i]; //��ʱ�����ֵ = ��ǰ�����ֵ + ���������ֵ
}
return tempVet;
}
Vets Vets::operator-(Vets Vet)
{
Vets tempVet;
for (int i = 0; i < 16; i++)
{
tempVet._vet[i] = _vet[i] - Vet._vet[i]; //��ʱ�����ֵ = ��ǰ�����ֵ - ���������ֵ
}
return tempVet;
}
ostream& operator<< (ostream &out, Vets & Vet){
for (int i = 0; i < 16; i++)
{
out << Vet._vet[i]<<"\t"; //ע�⣺�����Ҫ��������У���cout��β��Ҫ���ϡ�endl����
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
}```
5����Ԫ����̬��Ա
��1����Ԫ��Ϊ���ѿ���һ������ͨ�������ѿ��Է��ʱ����ڲ������г�Ա����˽�г�Ա��
        �﷨����������Ԫ�ࡢ����Ԫ������ֻ�����������У��á�friend���ؼ�����������
��2����̬��Ա�����ݡ��򷽷������ڴ���ֻ��һ���ڴ棬�����˹�����������ھ�̬�洢���򣬷����ٶȿ죬������ı�ʱ������ǣһ������ȫ����
����ָ��
1����ָ�����⣺�Ժ󿴵�ָ�����֣��Ͱ����滻�ɡ���ַ���������ǵ�ͬ�ġ�ָ���ֵ����һ����ֵַ����ͨ�����Ѱ�ҵ��������ڴ��λ�ã����ָ��ֵ     �ı����ͽС�ָ������������ϣ�ָ�벢�����ء�

�ġ�ģ��
1��ΪʲôҪ��ģ�壿
��ģ����һ�������������޹صĹ����㷨����ͨ������ģ�塱���ɶ������͵��࣬ͨ��������ģ�塱�������ò�ͬ�������͵ĺ������Ⱥ������ط�����ˣ���
2�����ࣺ����ģ�塢��ģ��
3����ô���壿�﷨
```cpp
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
/*С�᣺��Ҫ֪ʶ������⺯������ģ��ı������ã����л��ƣ�����Ⲣ����ģ��Ķ��塢����*/```

�塢��̬�ڴ����
1��c++�ڴ����⣺������ݡ�����ĵط�����ͨ����ַ����ָ�룩Ѱ�ҵ����ǡ�
 ��1�����ࣺ
��̬��Ա�洢������ž�̬��Ա��ȫ�ֱ����������ٶȿ飬ǣһ������ȫ��
�ֲ���ʱ���ݴ洢������ջ��������žֲ������������ֳ�ʱ����ʱ���ݡ�����ʱ��ַ�������ڽ������Զ��ͷš�����Ҫע�����������⣡
��̬�洢�������ݳ�������ʵ�������������ڴ�ռ䣬������ʾ���루new������ʾ�ͷţ�delete��
2����ƺ�ǳ���������ص�
    �������ƶ����С���̬�洢����Ա�������С����/ǳ���ơ��ĸ���
��1����ƣ�������ͨ��Ա��ͬʱ��Ҳ�������µġ���̬�ڴ�ռ䡱��ԭ�������¶���ġ���̬�ڴ�ռ䡱�໥������
��2��ǳ���ƣ�������ͨ��Ա��ͬʱ��û�и����µġ���̬�ڴ�ռ䡱��ԭ�������¶�������̬�ڴ�ռ䡱���������������ԭ���������ڽ�����������                      ���ᷢ������
�����̳����̬
1���̳еĻ����ܹ�
    �̳�����
    ���캯����������          //Ҫ�Ѹ���Ĺ��캯���������������൱�ڵ����˸���Ĺ��캯��
    �������³�Ա
```cpp
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
cout << "ѧ�ţ�" << _num << " " << "������" << _name << " " << "���᣺" << _address << endl;
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
}```

2����̬���麯�������麯�������
��1����̬������������̵���Ҫ�ص�֮һ����ͬ����������ͬ�����롢��ͬ�������
��2���˴��Ʋ��ļ���c++�̳����̬��

����С�᣺
1����סc++����Ļ����ܹ�
2����Ļ����ܹ�
3��c++�ڴ����
4��ģ������ü������ܹ�
5���̳еĻ����ܹ�����̬���麯�������
��ְ���ԣ�
1���������������ĸ��
�������������ü�������������������ʵ���硢���������˼ά������ʵ�����е�ʵ���������ࡱ�ĸ�����������ԡ���Ϊ������װ���൱�У�������Ǿ���ʵ�֣�ͬ���������Ժ���Ϊ��
��������������ص㣺��װ�ԣ���Ͷ���һ�������������ڱ��ʹ�õ�ʱ��Ͳ��ؿ����Ǿ������ʵ�ֵģ�ֻ��֪����ε��ýӿھ����ˣ��̳��ԣ�һ������Լ̳���һ��������Ժͷ������Ӷ�ʵ���˴���ĸ����ԡ�Ҳ����˿���Ч�ʣ���̬�ԣ�ͬһ�����������벻ͬ���࣬������ͬ������������߳���ɶ��Ե�ͬʱҲ����˿���Ч�ʡ�
2����c++����ʲô������
��ͼ�����ϵͳ��ʵ����ɾ��Ĺ��ܣ��������ݿ⡣