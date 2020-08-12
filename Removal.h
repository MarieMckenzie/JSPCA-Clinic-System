#ifndef Removal_H
#define Removal_H
#include "Intervention.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>
using namespace std;

class Removal : public Intervention
{
private:
	string Address;
	string Outcome;

public:
	Removal() :Intervention() {
		Address = "";
		Outcome = "";
	}
	void setAddress(string address) {
		Address = address;
	}

	string getAddress()const {
		return Address;
	}

	void setOutcome(string outcome) {
		Outcome = outcome;
	}
	string getOutcome()const {
		return Outcome;
	}
	Removal(const Removal &d) :Intervention(d)
	{
		Address = d.Address;
		Outcome = d.Outcome;
	}
	Removal(Time dTimee, Date dDatee, int dInterventionNumber,string dLocation, string dAddress, string dOutcome) :Intervention(dTimee, dDatee, dInterventionNumber,dLocation)
	{
		Address = dAddress;
		Outcome = dOutcome;
	}

	void display()const
	{
		Intervention::display();
		cout << "Address: " << Address << endl;
		cout << "Outcome: " << Outcome << endl;

	}

};
#endif
