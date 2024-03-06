#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

int main() {
	Account a;
	a.Read();
	a.Display();
	cout << " Dollars: " << a.ConvertToDollar() << endl;
	cout << " Euros: " << a.ConvertToEuro() << endl;
	Account::Date date;
	date.Init(2024, 3, 5);
	cout << " Procent money: " << a.calculateprocent(date) << endl;
	cout << " Withdraw 100" << endl;
	a.withdraw(100);
	cout << a.toString() << endl;
	cout << " Put 300" << endl;
	a.putmoney(300);
	cout << a.toString() << endl;
	Account::Date d;
	d.Read();
	cout << "First date:";
	d.Display();cout << endl;
	Account::Date d2;
	d2.Init("2024.03.05");
	Account::Date d3;
	d3.Init(d2);
	cout << "Second date";
	d3.Display();cout << endl;
	cout << "Date after 45 days:" << endl;
	Account::Date d4 = d + 45;
	d4.Display();cout << endl;
	cout << "Date before 45 days:" << endl;
	Account::Date d5 = d - 45;
	d5.Display();cout << endl;
	cout << "date comparison:" << endl;
	if (d > d3) {
		cout << " d>d3" << endl;
	}
	if (d < d3) {
		cout << " d<d3" << endl;
	}
	if (d == d3) {
		cout << " d=d3" << endl;
	}
	cout << endl;
	if (d.isLeap()) {
		cout << "date is leap year" << endl;
	}
	else {
		cout << "date is not leap year" << endl;
	}
	cout << endl;
	cout << "days between dates:" << endl;

	cout << " d2-d=" << d2.CountOfDays(d) << endl;
	Account::Date d6 = d5;
	d6.Display();
}