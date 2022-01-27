#include "Date.h"
#include "DocGia.h"

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getMonth() {
	return month;
}

void Date::setDay(int day) {
	this->day = day;
}

void Date::setMonth(int month) {
	this->month = month;
}

void Date::setYear(int year) {
	this->year = year;
}

int Date::DaysInMonth(int mm, int yy) {
    switch (mm)
    {
    case 2:
        if ((yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0)) {
            return 29;
        }
        return 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

// đếm số ngày của năm
int Date::dayOfTheYear() {
	int count = 0;
	for (int i = 1; i < month; i++) {
		count = count + DaysInMonth(i, year);
	}
	return count + day;
}

int Date::daysInYear(int yy) {
	if ((yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0)) {
		return 366;
	}
	return 365;
}

int Date::differentDays(Date d) {
	if (year == d.year) {
		return abs(dayOfTheYear() - d.dayOfTheYear());
	}


	if (year < d.year) {
		int kq = daysInYear(year) - dayOfTheYear() + d.dayOfTheYear();
		if (d.year - year == 1) {
			return kq;
		}
		for (int i = year + 1; i < d.year; i++) {
			kq = kq + daysInYear(i);
		}
		return kq;
	}

	int kq = daysInYear(d.year) - d.dayOfTheYear() + dayOfTheYear();
	if (year - d.year == 1) {
		return kq;
	}
	for (int i = d.year + 1; i < year; i++) {
		kq = kq + daysInYear(i);
	}
	return kq;
}

void Date::input() {
	do
	{
		cout << "\t - Ngay: ";
		string sday;
		do
		{
			getline(cin, sday);
			if (!La_So_Nguyen(sday)) {
				cout << "Nhap sai! Moi ban nhap lai: ";
			}
		} while (!La_So_Nguyen(sday));
		day = stoi(sday);


		cout << "\t - Thang: ";
		string smonth;
		do
		{
			getline(cin, smonth);
			if (!La_So_Nguyen(smonth)) {
				cout << "Nhap sai! Moi ban nhap lai: ";
			}
		} while (!La_So_Nguyen(smonth));
		month = stoi(smonth);

		cout << "\t - Nam: ";
		string syear;
		do
		{
			getline(cin, syear);
			if (!La_So_Nguyen(syear)) {
				cout << "Nhap sai! Moi ban nhap lai: ";
			}
		} while (!La_So_Nguyen(syear));
		year = stoi(syear);

		if (year > 2021 || year < 0 || 0 >= month || month > 12 || day > DaysInMonth(month, year) || day <= 0) {
			cout << "Ngay khong hop le! Moi ban nhap lai: " << endl;
		}
	} while (year > 2021 || year < 0 || 0 >= month || month > 12 || day > DaysInMonth(month, year) || day <= 0);
}

void Date::display() {
	cout << day << "/" << month << "/" << year;
}

string Date::writeInFile() {
	string strday = to_string(this->day);
	string strmonth = to_string(this->month);
	string stryear = to_string(this->year);
	string s = strday + " " + strmonth + " " + stryear;
	return s;
}

string Date::displayFromFile() {
	string strday = to_string(this->day);
	string strmonth = to_string(this->month);
	string stryear = to_string(this->year);
	string s = strday + "/" + strmonth + "/" + stryear;
	return s;
}

Date::~Date() {

}