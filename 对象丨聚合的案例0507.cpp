// 20180426generalPractice.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//˼·���½��գ�����ʱ���֣����캯����ֵ�գ���
//�£������գ���
//�꣨�����¡�����������࣬
//���ԣ�ʵ�����½������ա��¡��꣬����ֵ����ֵ��ÿ����������ԣ���������������

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
	~Day(){ cout << "Day�����ѱ��ͷ�" << "\n"; };
};
class Month{
private:
	int _month;
public:
				//�˴���Ҫ��Day����ʵ�Σ�����
	Month(int month=1) :_month(month){}
	int getMonth(){
		return _month;
	}
	~Month(){ cout << "Month�����ѱ��ͷ�" << "\n"; };
};
class Year{
private:
	int _year;
public:
	
	Year(int year=2018) :_year(year){}
	int getYear(){
		return _year;
	}
	~Year(){ cout << "Year�����ѱ��ͷ�" << "\n"; };
};
class Date
{
public:
	Day _Day;
	Month _Month;
	Year _Year;
	Date(int year, int month, int day, int hour, int mimu) :_Day(day,hour,mimu ),_Month(month),_Year(year){}
	void print(){
		cout << "Today is: " << _Year.getYear() << "��" << _Month.getMonth() << "��" << _Day.getDay() << "��" << _Day.getTime() << endl;			//ע�⣺�޷�ֱ�ӷ����Ӷ����˽�����ԣ�����ͨ���Ӷ���ġ����к��������л�ȡ��
	}
	~Date(){ cout << "Date�����ѱ��ͷ�" << "\n"; };
};
/*���Գ���*/
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

/*bug���޷�������󴫲Σ�����Ĭ�ϲ����������޷�ƴ��*/
