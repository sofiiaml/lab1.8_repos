//Account.cpp
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

void Account::setLastname(string lastname) {
	this->lastname = lastname;
}
void Account::withdraw(double money) {
	if (money <= this->money) {
		this->money -= money;
	}
	else {
		cout << "Not enough money" << endl;
	}
}
void Account::putmoney(double money) {
	this->money += money;
}
double Account::calculateprocent(Date date) {
	this->procent = 0.01 * date.CountOfDays(this->date);
	return money * procent;
}
double Account::ConvertToDollar() {
	return money / 38.45;
}
double Account::ConvertToEuro() {
	return money / 41.78;
}
string Account::toString() {
	string res = to_string((int)money) + " hrn. " + to_string((int)(money * 100) % 100) + " kop. ";
	return res;
}
void Account::Init(string lastname, string number, Date date, double procent, double money) {
	this->lastname = lastname;
	this->number = number;
	this->date = date;
	this->procent = procent;
	this->money = money;
}
void Account::Read()
{
	string lastname, number;
	Date date;
	double procent, money;
	cout << "Input account data:" << endl;
	cout << " Lastname: "; cin >> lastname;
	cout << " Number: "; cin >> number;
	date.Read();
	cout << " Procent = ";cin >> procent;
	cout << " Money = "; cin >> money;
	Init(lastname, number, date, procent, money);
}
void Account::Display()
{
	cout << endl;
	cout << " Lastname: " << lastname;
	cout << " Number: " << number;
	date.Display();
	cout << " Procent = " << procent << endl;
	cout << " Money = " << money << endl;
}

int Account::Date::getYear() { return year; }
int Account::Date::getMonth() { return month; }
int Account::Date::getDay() { return day; }

bool Account::Date::isLeap() {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
Account::Date Account::Date::operator+(int days) {
	Date d;
	d.year = year;
	d.month = month;
	d.day = day;
	int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (days > 0) {
		if (d.month == 13) {
			d.month = 1;
			d.year++;
		}
		if (d.day == amount[d.month - 1]) {

			d.month++;
			d.day = 1;
		}
		d.day++;
		days--;
	}
	return d;
}
Account::Date Account::Date::operator-(int days) {
	Date d;
	d.year = year;
	d.month = month;
	d.day = day;
	int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (days > 0) {


		if (d.day == 0) {

			d.day = amount[(d.month + 10) % 12];
			d.month--;
		}
		if (d.month == 0) {
			d.month = 12;
			d.year--;
		}
		d.day--;
		days--;
	}
	return d;
}
Account::Date& Account::Date::operator=(Date date) {
	year = date.year;
	month = date.month;
	day = date.day;
	return *this;
}
bool Account::Date::operator==(Date date) {
	return year == date.year && month == date.month && day == date.day;
}
bool Account::Date::operator<(Date date) {
	if (year < date.year) {
		return true;
	}
	else if (year == date.year) {
		if (month < date.month) {
			return true;
		}
		else if (month == date.month) {
			if (day < date.day) {
				return true;
			}
		}
	}
	return false;
}
bool Account::Date::operator>(Date date) {
	return date < *this;
}
int Account::Date::CountOfDays(Date date) {
	int days = 0;
	int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (*this > date) {
		while (!(*this == date)) {
			if (date.day == amount[month - 1]) {
				date.day = 1;
				date.month++;
			}
			if (date.month == 12) {
				date.year++;
				date.month = 1;
			}
			days++;
			date.day++;
		}
	}
	else {
		return 0;
	}
	/*else {
		return date.CountOfDays(*this)
	}*/
	return days;
}
void Account::Date::Init(Date date) {
	year = date.year;
	month = date.month;
	day = date.day;

}
void Account::Date::Init(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
void Account::Date::Init(string date) {
	year = stoi(date.substr(0, 4));
	month = stoi(date.substr(5, 2));
	day = stoi(date.substr(8, 2));
}
void Account::Date::Read()
{
	unsigned int year, month, day;
	cout << "Input date:" << endl;
	cout << " Year = "; cin >> year;
	cout << " Month = "; cin >> month;
	cout << " Day = "; cin >> day;
	Init(year, month, day);
}
void Account::Date::Display()
{
	cout << endl;
	cout << " Year = " << year << endl;
	cout << " Month = " << month << endl;
	cout << " Day = " << day << endl;
}