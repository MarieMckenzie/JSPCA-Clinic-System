#ifndef Intervention_H
#define Intervention_H
#include "Time.h"
#include <iostream>
#include <string>
using namespace std;

class Intervention {
private:
	Date Datee;
	Time Timee;
	int InterventionNumber;
	string Location;
public:
	void setDate(Date date) {
		Datee = date;
	}
	Date getDate()const {
		return Datee;
	}
	void setTime(Time time) {
		Timee = time;
	}
	Time getTime()const {
		return Timee;
	}
	void setInterNum(int number) {
		InterventionNumber = number;
	}
	int getInterNum()const {
		return InterventionNumber;
	}
	void setLocation(string location) {
		Location = location;
	}
	string getLocation()const {
		return Location;
	}
	Intervention(Time time, Date date, int number,string location) :Timee(time) {
		this->InterventionNumber = number;
		this->Location = location;
	}
	Intervention(const Intervention & i) :Timee(i.getTime()){
		InterventionNumber = i.InterventionNumber;
		Location = i.Location;
	}
	Intervention() :Timee(), Datee() {
		InterventionNumber = 0;
		Location = "";

	}

	virtual void display()const {
		cout <<getInterNum();
		cout << getLocation();
		Timee.display();
		Datee.display();
	}

};
#endif
