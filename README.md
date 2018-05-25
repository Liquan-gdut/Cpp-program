# C++丨基础知识小结
> 摘要：1、函数；2、类的理解；3、指针的理解；4、模板；5、内存理解；6、继承与多态

> `鸣谢：` 感谢下我们本学期的C++老师，把这门传说中最粗涩难懂的编程语言，讲得如此让我们心领神会，学完对编程、内存确实有提纲挈领之效，我室友说比他们培训课的老师讲得还透彻（想问培训老师能不能退培训费....）。过段时间，准备发封感谢信给老师，肯定下老师的教学方式，过几天c++成绩出来了，要是能给我多点分数，那我就感谢得再深刻点......<br>
### 一、函数<br>
#### 1、参数传递的三种方式及特点<br>
（1）传值调用：将实参的值复制给形参，“实形隔离机制”，相互独立，保护实参，但会生成形参局部内存。<br>
（2）引用调用：将实参的地址复制给形参，“实形共用一个内存”，就是名字不同而已，即实参直接参与运算，实时变化，但不用额外生成局部内存。<br>
（3）指针调用：物理上传指针的值，逻辑上传指针（地址），本质上与引用一模一样，不过引用看起来更直观。<br>
#### 2、函数重载与内联函数<br>
（1）函数重载：相同的函数名，具有相似却不相同的函数功能。<br>
       执行机制：根据传入参数的类型，决定调用哪一种类型的函数。<br>
（2）内联函数：当执行到某内联函数时，程序将不用“保护现场、入栈”，直接将代码嵌入到该处，此时的变量将变为全局变量。<br>
        适用场合：代码量少、变量少、执行频率高的功能代码块，免去“频繁的入栈出栈”，有效提高执行效率。<br>
### 二、面向对象程序设计（类）<br>
#### 1、c++类定义的基本架构<br>
（1）来自c++primer的总结          <br>
        类声明：提供了类的蓝图，以数据成员的方式描述了数据部分，以函数成员方式描述了公有接口<br>
        类定义：提供了类的方法定义，描述了如何实现类函数成员，具体实现过程<br>
#### 2、构造函数与复制构造函数<br>
（1）构造函数：全世界的构造函数都有一个共同的功能，为类的属性初始化属性。<br>
（2）复制构造函数：拷贝现有的对象来生成一个新的对象。<br>
#### 3、什么叫引用？<br>
（1）本质定义：上面有提到，引用也可以叫“别名”，多个不同变量/对象名共享一个内存空间，其中一个变量的值改变，所有引用的值都改变。<br>
#### 4、运算符重载<br>
（1）含义：给系统内置的各种运算符“+、-、*.....”重新载入新的功能，当运算符检测到“目标对象”为对应的“类”时，触发重载功能。<br>
（2）举栗子：重载“+”，当传入是矩阵类（Matrix）时，触发重载功能：每个矩阵元素都相加<br>
```cpp<br>
#include "stdafx.h"
#include <iostream>

#include <iomanip>
using namespace std;

//类声明、属性声明：数组
//构造函数、复制构造函数、输入函数声明定义
//operator+、-、<<
class Vets
{
friend ostream& operator<<(ostream &out, Vets & Vet); //马虎丨当发现语法没错误时，记得仔细检查“符号中英文切换”
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
tempVet._vet[i] = _vet[i] + Vet._vet[i]; //临时对象的值 = 当前对象的值 + 参数对象的值
}
return tempVet;
}
Vets Vets::operator-(Vets Vet)
{
Vets tempVet;
for (int i = 0; i < 16; i++)
{
tempVet._vet[i] = _vet[i] - Vet._vet[i]; //临时对象的值 = 当前对象的值 - 参数对象的值
}
return tempVet;
}
ostream& operator<< (ostream &out, Vets & Vet){
for (int i = 0; i < 16; i++)
{
out << Vet._vet[i]<<"\t"; //注意：如果想要输出不换行，则cout结尾不要加上“endl”；
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
}```<br>
```
#### 5、友元、静态成员<br>
（1）友元：为朋友开启一个特殊通道，朋友可以访问本类内部的所有成员包括私有成员。<br>
        语法：可以是友元类、或友元函数，只需在类声明中，用“friend”关键字声明即可<br>
（2）静态成员：数据、或方法。在内存中只有一份内存，所有人共享它，存放在静态存储区域，访问速度快，但当其改变时，将“牵一发而动全身”。<br>
### 三、指针<br>
#### 1、对指针的理解：以后看到指针两字，就把它替换成“地址”，两者是等同的。指针的值就是一个地址值，可通过这个寻找到数据在内存的位置；存放指针值     的变量就叫“指针变量”，综上，指针并不神秘。<br>

### 四、模板<br>
#### 1、为什么要用模板？<br>
答：模板是一处与数据类型无关的功能算法，可通过”类模板”生成多种类型的类，通过“函数模板”生成适用不同数据类型的函数（比函数重载方便多了）、<br>
#### 2、分类：函数模板、类模板<br>
#### 3、怎么定义？语法<br>
```cpp<br>
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
/*小结：重要知识：①理解函数、类模板的本质作用，运行机制；②理解并熟练模板的定义、调用*/```<br>
```
### 五、动态内存管理<br>
#### 1、c++内存的理解：存放数据、代码的地方，可通过地址（或指针）寻找到它们。<br>
 （1）分类：<br>
静态成员存储区：存放静态成员、全局变量，访问速度块，牵一发而动全身<br>
局部临时数据存储区（堆栈区）：存放局部变量、保护现场时存临时数据、存临时地址，生命期结束后，自动释放。灵活，但要注意作用域问题！<br>
动态存储区：根据程序运行实际情况而申请的内存空间，必须显示申请（new）、显示释放（delete）<br>
#### 2、深复制和浅复制区别及特点<br>
       当被复制对象有“动态存储区成员”，才有“深复制/浅复制”的概念
（1）深复制：复制普通成员的同时，也复制了新的“动态内存空间”，原对象与新对象的“动态内存空间”相互独立。<br>
（2）浅复制：复制普通成员的同时，没有复制新的“动态内存空间”，原对象与新对象共享“动态内存空间”，这种情况常常在原对象生命期结束，析构后，                      将会发生错误。<br>
### 六、继承与多态<br>
#### 1、继承的基本架构<br>
    继承声明
    构造函数声明定义          //要把父类的构造函数都包含进来，相当于调用了父类的构造函数
    可增加新成员
    
```cpp<br>
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
cout << "学号：" << _num << " " << "姓名：" << _name << " " << "宿舍：" << _address << endl;
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
}```<br>
```
#### 2、多态、虚函数、纯虚函数的理解<br>
（1）多态：是面向对象编程的重要特点之一。相同函数名、不同的输入、不同的输出。<br>
（2）此处移步文件![“c++继承与多态.md”](https://github.com/Liquan-gdut/Cpp-program/blob/master/c%2B%2B%E7%BB%A7%E6%89%BF%E4%B8%8E%E5%A4%9A%E6%80%81.md)<br>

### 整体小结：<br>
       1、记住c++程序的基本架构
       2、类的基本架构
       3、c++内存机制
       4、模板的作用及基本架构
       5、继承的基本架构、多态与虚函数的理解
### 求职面试：<br>
#### 1、如何理解面向对象的概念？<br>
       答：面向对象就是让计算机世界更贴近我们现实世界、贴近人类的思维。把现实世界中的实体抽象出“类”的概念，将数据属性、行为方法封装在类当中，对象就是具体实现，同样具有属性和行为。
       面向对象有三个特点：封装性：类和对象一旦建立，我们在编程使用的时候就不必考虑是具体如何实现的，只需知道如何调用接口就行了；继承性：一个类可以继承另一个类的属性和方法，从而实现了代码的复用性、也提高了开发效率；多态性：同一函数名，输入不同的类，产生不同的输出结果，提高程序可读性的同时也提高了开发效率。
#### 2、用c++做过什么东西？<br>
       答：图书管理系统，实现增删查改功能，连接数据库。
