#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int month;
	int day;
	int year;

public:
	Date(string date_str);
	void print_date(string style);
	bool operator == (const Date& rhs);
};

#endif
