#include "date.h"
#include <sstream>

Date::Date(string date_str){
	string month_str, day_str, year_str;
	
	stringstream ss(date_str);
	
	getline(ss, month_str, '/');
	getline(ss, day_str, '/');
	getline(ss, year_str);
	
	istringstream ss1(month_str);
	ss1 >> month;
	
	istringstream ss2(day_str);
	ss2 >> day;
	
	istringstream ss3(year_str);
	ss3 >> year;
}

void Date::print_date(string style){
	string month_names[] = {
		"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};
	
	if (style == "Month D, YYYY"){
		cout << month << "/" << day << "/" << year << endl;
	}
	else{
		cout << month_names[month] << " " << day << ", " << year << endl;
	}
}

bool Date::operator==(const Date& rhs){
	return (month == rhs.month &&
		day == rhs.day &&
		year == rhs.year);
}
