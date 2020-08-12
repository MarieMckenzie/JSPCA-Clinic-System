#ifndef Animal_H
#define Animal_H
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
	string Type;
	string Breed;
	string Gender;
	int Age;
	string ReasonForVisit;
	string ClinicVisit;
	Date IntendedDay;
	string Location;

public:
	void setType(string type) {
		Type = type;
	}
	string getType()const {
		return Type;
	}
	void setBreed(string breed) {
		Breed = breed;
	}
	string getBreed()const {
		return Breed;
	}
	void setGender(string gender) {
		Gender = gender;
	}
	string getGender() const{
		return Gender;
	}

	void setAge(int age) {
		Age = age;
	}
	int getAge()const {
		return Age;
	}
	void setReasonForVisit(string reasonforvisit) {
		ReasonForVisit = reasonforvisit;
	}
	string getReasonForVisit()const {
		return ReasonForVisit;
	}
	void setClincVisit(string clinicvisit) {
		ClinicVisit = clinicvisit;
	}
	string getClinicVisit()const {
		return ClinicVisit;
	}
	void setIntenDay(Date intendedday) {
		IntendedDay = intendedday;
	}
	Date getIntenDay()const {
		return IntendedDay;
	}
	void display()const {
		Date d;
		cout << getType()<<"\n" << getBreed()<<"\n"<<getGender() << "\n" << getAge() << "\n" << getReasonForVisit() << "\n" <<getClinicVisit() << "\n";
			d.display();
	}
	Animal(string type, string breed, string gender, int age, string reasonforvisit, string clinicvisit, Date intendedday) :IntendedDay(intendedday){
		this->Type = type;
		this->Breed = breed;
		this->Gender = gender;
		this->Age = age;
		this->ReasonForVisit = reasonforvisit;
		this->ClinicVisit = clinicvisit;
	}
	Animal(const Animal & a):IntendedDay(a.getIntenDay()){
		Type = a.Type;
		Breed = a.Breed;
		Gender = a.Gender;
		Age = a.Age;
		ReasonForVisit = a.ReasonForVisit;
		ClinicVisit = a.ClinicVisit;
	}
	Animal() :IntendedDay(){
		Type = "";
		Breed = "";
		Gender="";
		Age = 0;
		ReasonForVisit = "";
		ClinicVisit = "";
	}
};
#endif

