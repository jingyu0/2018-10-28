#include<iostream>
#include<stdio.h>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && isleap(_year) == 1)
			return 29;
		else
			return monthArray[month];
	}
	int isleap(int _year)
	{
		return _year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0;
	}
	Date(int year = 2019, int month = 1, int day = 1)
	{
		if (year > 0 &&
			month > 0 && month <13 &&
			day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}
	}
	Date(const Date &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (*this != d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	inline bool operator==(const Date& d)const
	{
		return (_year == d._year)
			&& (_month == d._month)
			&& (_day == d._day);
	}

	inline bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
	inline bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year&&_month > d._month)
			return true;
		else if (_year == d._year&&_month == d._month&&_day > d._day)
			return true;
		else
			return false;
	}
	inline bool operator<(const Date& d)const
	{
		return !((*this>d) || (*this == d));
	}
	inline bool operator>=(const Date& d)const
	{
		return !(*this < d);
	}
	inline bool operator<=(const Date& d)const
	{
		return !(*this >d);
	}

	//d1+10
	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;
	}
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator-(int day)const
	{
		/*Date ret(*this);
		while (ret._day <= day)
		{
		day = day - ret._day;
		if (ret._month == 1)
		{
		ret._month = 13;
		ret._year--;
		}
		ret._month--;
		ret._day = GetMonthDay(ret._year, ret._month);
		}
		ret._day -= day;
		return ret;*/
		Date ret(*this);
		ret -= day;
		return ret;
	}
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	//后置
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	//前置
	Date operator++(int)
	{
		/*if (++_day > GetMonthDay(_year, _month))
		{
		_month++;
		if (_month == 13)
		{
		_year++;
		_month = 1;
		_day = 1;
		}
		_day--;
		_day -= GetMonthDay(_year, _month);
		}
		return *this;*/
		Date ret(*this);
		*this += 1;
		return ret;
	}
	Date operator--(int)
	{
		/*if (--_day == 0)
		{
		_month--;
		if (_month == 0)
		{
		_year--;
		_month = 12;
		}
		_day = GetMonthDay(_year, _month);
		}
		return *this;*/
		Date ret(*this);
		*this -= 1;;
		return ret;
	}

	//d1-d2
	int operator-(const Date &d)
	{
		int day = 0;
		int flag = 1;
		Date min = d;
		Date max = *this;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		while (min != max)
		{
			++day;
			++min;
		}
		return flag*day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	~Date()
	{

	}
private:
	int _year;
	int _month;
	int _day;
};

void test()
{
	Date d1(2018, 3, 31);
	Date d2(2018, 8, 31);
	d1++;
	d1.Print();
}
int main()
{
	test();
	system("pause");
	return 0;
}