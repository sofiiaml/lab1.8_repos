#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	string lastname;
	string number;
	double procent;
	double money;
public:
	class Date {
		unsigned int year;
		unsigned int month;
		unsigned int day;
	public:
		int getYear();
		int getMonth();
		int getDay();
		bool isLeap();
		Date operator+(int days);
		Date operator-(int days);
		Date& operator=(Date date);
		bool operator==(Date date);
		bool operator<(Date date);
		bool operator>(Date date);
		int CountOfDays(Date date);
		void Init(Date date);
		void Init(unsigned int year, unsigned int month, unsigned int day);
		void Init(string date);
		void Read();
		void Display();
	};
	double getMoney() { return money; }
	void setLastname(string lastname);
	void withdraw(double money);
	void putmoney(double money);
	double calculateprocent(Date date);
	double ConvertToDollar();
	double ConvertToEuro();
	string toString();
	void Init(string lastname, string number, Date date, double procent, double money);
	void Read();
	void Display();
private:
	Date date;
};