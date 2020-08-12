#ifndef Treatment_H
#define Treatment_H
#include "Intervention.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>
using namespace std;

class Treatment : public Intervention
{
private:
	string Address;
public:
	Treatment() :Intervention() 
	{
		Address = "";
	}
	Treatment(const Treatment &y) :Intervention(y)
	{
		Address = y.Address;
	}
	Treatment(Time yTimee, Date yDatee, int yInterventionNumber, string ylocation, string yAddress):Intervention(yTimee, yDatee, yInterventionNumber,   ylocation)
	{
		Address = yAddress;
	}

	void display()const
	{
		Intervention::display();
		cout << "Address: " << Address << endl;

	}
};
#endif
