#ifndef Time_H
#define Time_H
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
	int Hour;
	int Minute;
public:
	void setHour(int hour) {
		Hour = hour;
	}
	int getHour()const {
		return Hour;
	}
	void setMinute(int minute) {
		Minute = minute;
	}
	int getMinute()const {
		return Hour;
	}
	void display()const {
		cout << getHour ()<< ":" << getMinute();
	}
	Time(int hour, int minute) {
		this->Hour = hour;
		this->Minute = minute;
	}
	Time() {
		Hour = 0;
		Minute = 0;
}
};
#endif
//display
//copy
//primary
//default