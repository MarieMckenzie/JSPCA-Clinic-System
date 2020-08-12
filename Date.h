#ifndef Date_H
#define Date_H
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int Day;
	int Month;
	int Year;
public:
	void setDay(int day) {
		Day = day;
	}
	int getDay()const {
		return Day;
	}
	void setMonth(int month) {
		Month = month;
	}
	int getMonth()const {
		return Month;
	}
	void setYear(int year) {
		Year = year;
	}
	int getYear()const {
		return Year;
	}
	void display()const {
		cout << getDay() << "/" << getMonth() << "/" << getYear();
	}
	Date(int day, int month, int year) {
		this->Day = day;
		this->Month = month;
		this->Year = year;
	}
	Date(const Date &d) {
		Day = d.Day;
		Month = d.Month;
		Year = d.Year;
	}
	Date() {
		Day = 0;
		Month = 0;
		Year = 0;
	}
};
#endif
//display
//copy
//primary
//default