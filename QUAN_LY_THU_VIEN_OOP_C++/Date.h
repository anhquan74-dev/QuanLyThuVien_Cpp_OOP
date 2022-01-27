#pragma once
#include<string>
#include<iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:

	Date();
	Date(int day, int month, int year);

	int getMonth();
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int DaysInMonth(int mm, int yy);

	int dayOfTheYear();
	int daysInYear(int yy);
	int differentDays(Date d);

	void input();
	void display();

	string writeInFile();
	string displayFromFile();

	~Date();
};

