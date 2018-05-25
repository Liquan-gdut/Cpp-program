// 20180426generalPractice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//思路：新建日（包含时、分，构造函数赋值日）、
//月（包含日）、
//年（包含月、输出函数）类，
//测试：实例化新建对象日、月、年，输入值，赋值给每个对象的属性，调用年的输出函数

class Day{
private:
	int _day;
	int _hour;
	int _minu;
public:
	Day(int day=1, int hour=0, int minu=0) :_day(day), _hour(hour), _minu(minu){}
	int getDay(){
		return _day;
	}
	int getTime(){
		
		return (_hour, _minu);
	}
	~Day(){ cout << "Day对象已被释放" << "\n"; };
};
class Month{
private:
	int _month;
public:
				//此处需要给Day传入实参？？？
	Month(int month=1) :_month(month){}
	int getMonth(){
		return _month;
	}
	~Month(){ cout << "Month对象已被释放" << "\n"; };
};
class Year{
private:
	int _year;
public:
	
	Year(int year=2018) :_year(year){}
	int getYear(){
		return _year;
	}
	~Year(){ cout << "Year对象已被释放" << "\n"; };
};
class Date
{
public:
	Day _Day;
	Month _Month;
	Year _Year;
	Date(int year, int month, int day, int hour, int mimu) :_Day(day,hour,mimu ),_Month(month),_Year(year){}
	void print(){
		cout << "Today is: " << _Year.getYear() << "年" << _Month.getMonth() << "月" << _Day.getDay() << "日" << _Day.getTime() << endl;			//注意：无法直接访问子对象的私有属性，必须通过子对象的“公有函数”进行获取！
	}
	~Date(){ cout << "Date对象已被释放" << "\n"; };
};
/*测试程序*/
void main(){
	int year, month, day, hour, minu;
	cout << "please input the date:" << "\n";
	cin >> year >> month >> day >> hour >> minu;
/*	Day _Day(day,hour,minu);
	Month _Month(month);
	Year _Year(year);*/
	Date _Date(year, month, day, hour, minu);
	_Date.print();
}

/*bug：无法给类对象传参，都是默认参数；变量无法拼接*/
