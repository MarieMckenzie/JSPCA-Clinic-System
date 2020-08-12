#ifndef Client_H
#define Client_H
#include "Animal.h"
#include <iostream>
#include <string>

void makeAppointment(string fname, string lname, int contactnum, string paymentoption, Animal animaldescription);
using namespace std;

class Client
{
private:
	string Fname;
	string Lname;
	int ContactNum;
	string PaymentOption;
	Animal AnimalDescription;
public:
	void makeAppointment(string fname, string lname, int contactnum, string paymentoption, Animal animaldescription)
	{
		cout << getFname()<<endl;
		cout << getLname() << endl;
		cout << getContactNum() << endl;
		cout << getPaymentOption() << endl;
		AnimalDescription.display();
	}
	void setFname(string fname) {
		Fname = fname;
	}
	string getFname()const {
		return Fname;
	}
	void setLname(string lname) {
		Lname = lname;
	}
	string getLname()const {
		return Lname;
	}
	void setContactNum(int contactnum) {
		ContactNum = contactnum;
	}
	int getContactNum()const {
		return ContactNum;
	}
	void setPaymentOption(string paymentoption) {
		PaymentOption = paymentoption;
	}
	string getPaymentOption()const {
		return PaymentOption;
	}

	void setAnimalDescription(Animal animaldescription) {
		AnimalDescription=animaldescription;
	}
	Animal getAnimalDescription()const {
		return AnimalDescription;
	}
	
	void display()const {
		cout << getFname() << "\n" << getLname() << "\n" << getContactNum() << "\n" << getPaymentOption() << "\n";
			AnimalDescription.display();
	}
	Client(string fname, string lname, int contactnum, string paymentoption, Animal animaldescription):AnimalDescription(animaldescription) {
		this->Fname = fname;
		this->Lname = lname;
		this->ContactNum = contactnum;
		this->PaymentOption = paymentoption;
	}
	Client(const Client & c):AnimalDescription(c.getAnimalDescription())
	{
		Fname=c.Fname;
		Lname=c.Lname;
		ContactNum=c.ContactNum;
		PaymentOption=c.PaymentOption;
	}

	Client():AnimalDescription() {
		Fname = "";
		Lname = "";
		ContactNum = 0;
		PaymentOption = "";
	}
};
#endif


