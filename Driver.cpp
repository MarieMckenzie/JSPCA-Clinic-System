#include <Windows.h>
#include <conio.h>
#include "Client.h"
#include "Treatment.h"
#include "Removal.h"
#include "Animal.h"
#include "Date.h"
#include "Time.h"
#include "Intervention.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#define KEY_SPACE 32//ASCII Function key
#define KEY_X 88//ASCII Function key


using namespace std;

void veterinarianMenu();
void removalMenu();
void addVet();
void updateVet();
void viewSingleVet();
void viewAllVet();
void deleteFuncVet();
void addReq();
void updateReq();
void viewReq();
void viewAllReq();
void deleteReq();
void reports();
void clinicReports();
void removeReports();
void locationReport();
void visitReport();
void animalReport();
void remLocationReport();
void reqDateReport();
void outcomeReport();
void loading();


int main()
{
	cout << "Press the SPACE BAR twice to move to the main menu otherwise press X to exit" << endl;
	char key = getchar();
	int value = key;
	cout << value << endl;
	system("pause");
	system("cls");


	switch (getchar()) {//ASCII Function
	case KEY_SPACE:
	int menu;
	do {
		system("Color 0A");//Color for window
		cout << "<<<<<<<<<<<<<<<<<    MAIN MENU OPTION    >>>>>>>>>>>>>>>>>>>>\n\n" << endl;
		cout << "Select your option\n" << endl;
		cout << "1. Veterinarian Clinic Visit" << "\n" << "2. Removal Request\n3. Reports\n4. Exit\n" << endl;
		cout << ">> ";
		cin >> menu;
		loading();
		system("cls");


		switch (menu) {
		case 1:
			veterinarianMenu();
			break;
		case 2:
			removalMenu();
			break;
		case 3:
			reports();
			break;
		case 4:
			cout << "Exiting:" << endl;
			exit(0);
			break;
		default:
			cout << "Error, please enter a valid option." << endl;//Allows the user to select a corresponding option
			system("pause");
			system("cls");
		}
	} while (menu != 3);
	system("Pause");
	break;


			case KEY_X:
	cout << "Exiting";
	cout << "Good Bye" << endl;
	break;
	}//end of Asci code
	

}

void veterinarianMenu() {//This method displays the Vet Clinic menu
	//veterinarianmenu:
	int vmenu;
	do {
		system("Color 3E");
		cout << "Veterinarian Clinic Visit Menu\n" << endl;
		cout << "Select from the option below" << endl;
		cout << "1. Add" << endl;
		cout << "2. Update" << endl;
		cout << "3. View Single" << endl;
		cout << "4. View All" << endl;
		cout << "5. Delete" << endl;
		cout << "6. Back" << endl;
		cout << "7. Exit" << endl;
		cout << ">> ";
		cin >> vmenu;
		loading();
		if (vmenu == 1) {
			addVet();
		}
		else if (vmenu == 2) {
			updateVet();
		}
		else if (vmenu == 3) {
			viewSingleVet();
		}
		else if (vmenu == 4) {
			viewAllVet();
		}
		else if (vmenu == 5) {
			deleteFuncVet();
		}
		else if (vmenu == 6) {
		}
		else if (vmenu == 7) {
			exit(0);
		}
		else {
			cout << "Error, please enter a valid option" << endl;
			system("pause");
			system("cls");
		}

	} while (vmenu != 6);

}
void removalMenu() {//This method displays the removal menu
	//removalmenu:
	int rmenu;
	do {
		system("Color 1E");
		cout << "Removal Request Menu\n" << endl;
		cout << "Select from the option below" << endl;
		cout << "1. Add" << endl;
		cout << "2. Update" << endl;
		cout << "3. View Single" << endl;
		cout << "4. View All" << endl;
		cout << "5. Delete" << endl;
		cout << "6. Back" << endl;
		cout << "7. Exit" << endl;
		cout << ">> ";
		cin >> rmenu;
		system("cls");
		loading();
		if (rmenu == 1) {
			addReq();
		}
		else if (rmenu == 2) {
			updateReq();
		}
		else if (rmenu == 3) {
			viewReq();
		}
		else if (rmenu == 4) {
			viewAllReq();
		}
		else if (rmenu == 5) {
			deleteReq();
		}
		else if (rmenu == 6) {

		}
		else if (rmenu == 7) {
			exit(0);
		}
		else {
			cout << "Error, please select a valid option" << endl;
			system("pause");
			system("cls");
		}
	} while (rmenu != 6);
}
void addVet() {//This method adds a Vet Clinic record
	Client c;
	Animal a;
	Date add1;
	int contactnum;
	string paymentoption;
	string fname;
	string lname;
	string breed;
	string type;
	string gender;
	int age;
	string reason;
	string clinicvisit;
	//Date intendedday;
	int day1;
	int month1;
	int year1;
	int emptyfile = 0;
	int check = 0;
	ifstream checkifnull;
	checkifnull.open("client.txt", ios::in);
	checkifnull >> fname >> lname >> contactnum >> paymentoption >> type >> breed >> age >> gender;
	checkifnull.ignore();
	getline(checkifnull, reason);
	if (fname == "") {
		emptyfile = 1;
	}
	checkifnull.close();
	cout << "Please enter the client's name" << endl << ">> ";
	cin >> fname >> lname;
	c.setFname(fname);
	c.setLname(lname);
	cout << "Please Enter a Contact number" << endl << ">> ";
	cin >> contactnum;
	c.setContactNum(contactnum);
	do {
		cout << "Please select a Payment Option: (Cash/Credit)" << endl << ">> ";
		cin >> paymentoption;
		if (paymentoption.compare("Cash") && paymentoption.compare("Credit") && paymentoption.compare("cash") && paymentoption.compare("credit")) {
			cout << "Please select a valid payment option\n" << ">> ";
		}
		else {
			check = 1;
		}
	} while (check == 0);
	c.setPaymentOption(paymentoption);
	cout << "Enter the type of Animal" << endl << ">> ";
	cin >> type;
	a.setType(type);
	cout << "Enter the breed of " << type << endl << ">> ";
	cin >> breed;
	a.setBreed(breed);
	cout << "Select a gender Male or Female" << endl << ">> ";
	cin >> gender;
	check = 0;
	do {
		if (gender.compare("Male") && gender.compare("Female") && gender.compare("male") && gender.compare("female") && gender.compare("m") && gender.compare("f") && gender.compare("M") && gender.compare("F")) {
			cout << "Please enter a gender.\n";
			cin >> gender;
		}
		else {
			check = 1;
		}
	} while (check != 1);

	a.setGender(gender);
	cout << "Enter the age of the " << type << endl << ">> ";
	cin >> age;
	a.setAge(age);
	cout << "What is the reason for the visit?" << endl << ">> ";
	//cin >> reason;
	cin.ignore();
	std::getline(std::cin, reason);
	a.setReasonForVisit(reason);
	do {
		cout << "Clinic visit location (Caymanas/Winchester)" << endl << ">> ";
		//cin.ignore();
		getline(cin, clinicvisit);
		a.setClincVisit(clinicvisit);
	} while (clinicvisit.compare("Caymanas") && clinicvisit.compare("Winchester"));
	cout << "\nWhen is the intended day (DD MM YYYY)?" << endl << ">> ";
	cin >> day1 >> month1 >> year1;
	add1.setDay(day1);
	add1.setMonth(month1);
	add1.setYear(year1);
	//c.display();
	//a.display();
	//add1.display();
	ofstream adding;
	adding.open("client.txt", ios::app);
	if (adding.is_open()) {
		if (emptyfile == 0) {
			adding << endl << fname << " " << lname << " " << contactnum << " " << paymentoption << " " << type << " " << breed << " " << age << " " << gender << " " << day1 << "/ " << month1 << " /" << year1 << endl << reason << endl << clinicvisit;
			adding.close();
			system("cls");
		}
		else {
			adding << fname << " " << lname << " " << contactnum << " " << paymentoption << " " << type << " " << breed << " " << age << " " << gender << " " << day1 << "/ " << month1 << " /" << year1 << endl << reason << endl << clinicvisit;
			adding.close();
			system("cls");
		}
	}
	else {
		cout << "The file could not be opened." << endl;
		system("pause");
		system("cls");
	}
}
void updateVet() {//This updates delects a Vet Clinic record
	Client cc;
	Animal aa;
	int contactnum;
	string paymentoption;
	string fname;
	string lname;
	string searchfname;
	string searchlname;
	string breed;
	string type;
	string gender;
	int age;
	string reason;
	int tempcontactnum;
	string temppaymentoption;
	string tempfname;
	string templname;
	string tempbreed;
	string temptype;
	string tempgender;
	int tempage;
	string tempreason;
	int day;
	int month;
	int year;
	int tempday;
	int tempyear;
	int tempmonth;
	string clinicvisit;
	string tempvisit;
	ifstream viewing;
	int found = 0;
	int check = 0;
	cout << "Enter the Name of the Client" << endl << ">> ";
	cin >> searchfname >> searchlname;
	cc.setFname(searchfname);
	cc.setLname(searchlname);
	system("cls");
	viewing.open("client.txt", ios::in);
	if (viewing.is_open()) {
		while (!viewing.eof()) {
			viewing >> fname >> lname >> contactnum >> paymentoption >> type >> breed >> age >> gender >> day >> month >> year;
			viewing.ignore();
			getline(viewing, reason);
			getline(viewing, clinicvisit);
			if (!searchfname.compare(fname) && !searchlname.compare(lname)) {
				found = 1;
				cout << "Client found, please re enter the updated information." << endl;
				cout << "Please enter the client's name" << endl << ">> ";
				cin >> fname >> lname;
				cc.setFname(fname);
				cc.setLname(lname);
				cout << "Please Enter a Contact number" << endl << ">> ";
				cin >> contactnum;
				cc.setContactNum(contactnum);
				do {
					cout << "Please select a Payment Option: (Cash/Credit)" << endl << ">> ";
					cin >> paymentoption;
					if (paymentoption.compare("Cash") && paymentoption.compare("Credit") && paymentoption.compare("cash") && paymentoption.compare("credit")) {
						cout << "Please select a valid payment option\n" << ">> ";
					}
					else {
						check = 1;
					}
				} while (check == 0);
				cc.setPaymentOption(paymentoption);
				cout << "Enter the type of Animal" << endl << ">> ";
				cin >> type;
				aa.setType(type);
				cout << "Enter the breed of " << type << endl << ">> ";
				cin >> breed;
				aa.setBreed(breed);
				cout << "Select a gender Male or Female" << endl << ">> ";
				cin >> gender;
				check = 0;
				do {
					if (gender.compare("Male") && gender.compare("Female") && gender.compare("male") && gender.compare("female") && gender.compare("m") && gender.compare("f") && gender.compare("M") && gender.compare("F")) {
						cout << "Please enter a gender.\n";
						cin >> gender;
					}
					else {
						check = 1;
					}
				} while (check != 1);

				aa.setGender(gender);
				cout << "Enter the age of the " << type << endl << ">> ";
				cin >> age;
				aa.setAge(age);
				cout << "What is the reason for the visit?" << endl << ">> ";
				cin.ignore();
				std::getline(std::cin, reason);
				aa.setReasonForVisit(reason);
				do {
					cout << "Enter the clinic Location (Caymanas/Winchester)" << endl << ">> ";
					getline(cin, clinicvisit);
				} while (clinicvisit.compare("Caymanas") && clinicvisit.compare("Winchester"));
				cout << "Enter the intended visit date (DD MM YYYY)" << endl << ">> ";
				cin >> day >> month >> year;
				ifstream search;
				ofstream write;
				search.open("client.txt", ios::in);
				if (search.is_open()) {
					write.open("temp.txt", ios::out);
					while (!search.eof()) {
						search >> tempfname >> templname >> tempcontactnum >> temppaymentoption >> temptype >> tempbreed >> tempage >> tempgender >> tempday >> tempmonth >> tempyear;
						search.ignore();
						getline(search, tempreason);
						getline(search, tempvisit);
						if (!searchfname.compare(tempfname) && !searchlname.compare(templname)) {
							write << "\n" << fname << " " << lname << " " << contactnum << " " << paymentoption << " " << type << " " << breed << " " << age << " " << gender << " " << day << " " << month << " " << year << endl << reason << endl << clinicvisit;
						}
						else {
							write << "\n" << tempfname << " " << templname << " " << tempcontactnum << " " << temppaymentoption << " " << temptype << " " << tempbreed << " " << tempage << " " << tempgender << " " << tempday << " " << tempmonth << " " << tempyear << endl << tempreason << endl << tempvisit;
						}
					}
				}

				else {
					cout << "Unable to open file." << endl;
				}
				search.close();
				write.close();
				search.open("temp.txt", ios::in);
				if (search.is_open()) {
					write.open("client.txt", ios::out);
					while (!search.eof()) {
						search >> tempfname >> templname >> tempcontactnum >> temppaymentoption >> temptype >> tempbreed >> tempage >> tempgender >> tempday >> tempmonth >> tempyear;
						search.ignore();
						getline(search, tempreason);
						getline(search, tempvisit);
						write << "\n" << tempfname << " " << templname << " " << tempcontactnum << " " << temppaymentoption << " " << temptype << " " << tempbreed << " " << tempage << " " << tempgender << " " << tempday << " " << tempmonth << " " << tempyear << endl << tempreason << endl << tempvisit;
					}
					cout << "\n\nUpdate Complete.\n\n";
				}
				else {
					cout << "Unable to open file." << endl;
				}
			}
			else {

			}
		};
		if (found == 0) {
			cout << "No client found." << endl;
		}
		viewing.close();
		system("pause");
		system("cls");
	}
}
void viewSingleVet() {//This method views a Vet Clinic record
	int contactnum;
	string paymentoption;
	string fname;
	string lname;
	string searchfname;
	string searchlname;
	string breed;
	string type;
	string gender;
	int age;
	string reason;
	ifstream viewing;
	int found = 0;
	int day;
	int month;
	int year;
	string clinicvisit;
	cout << "Enter the Name of the Client" << endl << ">> ";
	cin >> searchfname >> searchlname;
	system("cls");
	viewing.open("client.txt", ios::in);
	if (viewing.is_open()) {
		while (!viewing.eof()) {
			viewing >> fname >> lname >> contactnum >> paymentoption >> type >> breed >> age >> gender >> day >> month>> year;
			viewing.ignore();
			getline(viewing, reason);
			getline(viewing, clinicvisit);
			if (!searchfname.compare(fname) && !searchlname.compare(lname)) {
				cout << "First Name: " << fname << endl << "Last Name: " << lname << endl << "Contact Number: ";
				cout << contactnum << endl << "Payment Option: " << paymentoption << endl << "Type of Animal: ";
				cout << type << endl << "Breed of " << type << ": " << breed << endl << "Age of " << type << ": ";
				cout << age << endl << "Gender: " << gender << endl << "Reason for Visit: " << reason << endl;
				cout << "Clinic visit Location: " << clinicvisit << endl;
				cout << "Intended date of visit: " << day << "/" << month << "/" << year << endl;
				cout << "\n\n";
				found = 1;
			}
			else {

			}
		};
		if (found == 0) {
			cout << "No client found." << endl;
		}
		viewing.close();
		system("pause");
		system("cls");
	}
}
void viewAllVet() {//This method views all Vet Clinic records
	int contactnum;
	string paymentoption;
	string fname;
	string lname;
	string breed;
	string type;
	string gender;
	int age;
	string reason;
	ifstream viewing;
	int day;
	int month;
	int year;
	string clinicvisit;
	int count = 0;

	viewing.open("client.txt", ios::in);
	if (viewing.is_open()) {
		while (!viewing.eof()) {
			count += 1;
			viewing >> fname >> lname >> contactnum >> paymentoption >> type >> breed >> age >> gender >> day >> month >> year;
			viewing.ignore();
			getline(viewing, reason);
			//viewing.ignore();
			getline(viewing, clinicvisit);
			if (fname == "") {
				cout << "No records." << endl;
			}
			else {
				cout << "Client No. " << count << ": " << endl;
				cout << "First Name: " << fname << endl << "Last Name: " << lname << endl << "Contact Number: ";
				cout << contactnum << endl << "Payment Option: " << paymentoption << endl << "Type of Animal: ";
				cout << type << endl << "Breed of " << type << ": " << breed << endl << "Age of " << type << ": ";
				cout << age << endl << "Gender: " << gender << endl << "Reason for Visit: " << reason << endl;
				cout << "Intended date of visit: " << day << "/" << month << "/" << year << endl;
				cout << "Clinic visit Location: " << clinicvisit << endl;
				cout << "\n\n";
			}
		};
		viewing.close();
		system("pause");
		system("cls");
	}
	else {
		cout << "the file could not be opened." << endl;
		system("pause");
		system("cls");
	}
}
void deleteFuncVet() {//This method deletes a Vet Clinic record
	Client c;
	Animal a;
	int contactnum;
	string paymentoption;
	string fname;
	string lname;
	string searchfname;
	string searchlname;
	string breed;
	string type;
	string gender;
	int age;
	string reason;
	int tempcontactnum;
	string temppaymentoption;
	string tempfname;
	string templname;
	string tempbreed;
	string temptype;
	string tempgender;
	int tempage;
	string tempreason;
	ifstream viewing;
	int found = 0;
	int check = 0;

	cout << "Enter the Name of the Client" << endl << ">> ";
	cin >> searchfname >> searchlname;
	system("cls");
	viewing.open("client.txt", ios::in);
	if (viewing.is_open()) {
		while (!viewing.eof()) {
			viewing >> fname >> lname >> contactnum >> paymentoption >> type >> breed >> age >> gender;
			viewing.ignore();
			getline(viewing, reason);
			if (!searchfname.compare(fname) && !searchlname.compare(lname)) {
				found = 1;
				cout << "Client found.\n";
				ifstream search;
				ofstream write;
				search.open("client.txt", ios::in);
				if (search.is_open()) {
					write.open("temp.txt", ios::out);
					while (!search.eof()) {
						search >> tempfname >> templname >> tempcontactnum >> temppaymentoption >> temptype >> tempbreed >> tempage >> tempgender;
						search.ignore();
						getline(search, tempreason);
						if (!searchfname.compare(tempfname) && !searchlname.compare(templname)) {
						}
						else {
							write << "\n" << tempfname << " " << templname << " " << tempcontactnum << " " << temppaymentoption << " " << temptype << " " << tempbreed << " " << tempage << " " << tempgender << endl << tempreason;
						}
					}
				}

				else {
					cout << "Unable to open file." << endl;
				}
				search.close();
				write.close();
				search.open("temp.txt", ios::in);
				if (search.is_open()) {
					write.open("client.txt", ios::out);
					while (!search.eof()) {
						search >> tempfname >> templname >> tempcontactnum >> temppaymentoption >> temptype >> tempbreed >> tempage >> tempgender;
						search.ignore();
						getline(search, tempreason);
						write << "\n" << tempfname << " " << templname << " " << tempcontactnum << " " << temppaymentoption << " " << temptype << " " << tempbreed << " " << tempage << " " << tempgender << endl << tempreason;
					}
					cout << "\n\nDelete Complete.\n\n";
				}
				else {
					cout << "Unable to open file." << endl;
				}
			}
		}
	}
	else {
		cout << "Unable to open file." << endl;
	}
	if (found == 0) {
		cout << "Client not found.\n\n";
	}
	system("pause");
	system("cls");
	viewing.close();
}
void addReq() {//This method adds a request
	system("cls");
	Date remdate;
	Time remtime;
	Removal r;
	Intervention i;
	string location;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int interventionnum;
	int emptyfile = 0;
	string outcome = "Pending";
	string type;
	string address;
	ifstream checkifnull;
	checkifnull.open("removal.txt", ios::in);
	checkifnull >> day >> month >> year >> interventionnum;
	checkifnull.ignore();

	getline(checkifnull, address);
	if (day == NULL) {
		emptyfile = 1;
	}
	checkifnull.close();
	do {
		cout << "Is this a Removal or an Intervention?" << endl << ">> ";
		cin >> type;
	} while (type.compare("Removal") && type.compare("Intervention") && type.compare("removal") && type.compare("intervention"));
	cout << "Please enter the address of the " << type << endl << ">> ";
	cin.ignore();
	std::getline(std::cin, address);
	cout << "Please enter the date of the appointment (DD MM YYYY)" << endl << ">> ";
	cin >> day >> month >> year;
	remdate.setDay(day);
	remdate.setMonth(month);
	remdate.setYear(year);
	cout << "Please enter the time for the appointment (HH MM)" << endl << ">> ";
	cin >> hour >> minute;
	cout << "Please enter an intervention number" << endl << ">> ";
	cin >> interventionnum;
	do {
		cout << "Please enter the location (Winchester/Caymanas)" << endl << ">> ";
		cin >> location;
	} while (location.compare("Winchester") && location.compare("Caymanas"));
	i.setInterNum(interventionnum);
	ofstream adding;
	adding.open("removal.txt", ios::app);
	if (adding.is_open()) {
		if (emptyfile == 0) {
			adding << "\n" << type << " " << day << " " << month << " " << year << " " << hour << " " << minute << " " << interventionnum << " " << outcome << " " << location << endl << address;
			adding.close();
			system("cls");
		}
		else {
			adding << type << " " << day << " " << month << " " << year << " " << hour << " " << minute << " " << interventionnum << " " << outcome << " " << location << endl << address;
			adding.close();
			system("cls");
		}

	}
	else {
		cout << "The file could not be opened." << endl;
		system("pause");
		system("cls");
	}
}
void updateReq() {//This method updates a request entered
	Date remdate;
	Time remtime;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int interventionnum;
	int found = 0;
	int searchnum;
	int tempday;
	int tempmonth;
	int tempyear;
	int tempnum;
	int temphour;
	int tempminute;
	string outcome;
	string tempoutcome;
	string type;
	string tempaddress;
	string address;
	string location;
	string templocation;
	ifstream viewing;;
	ifstream search;
	ofstream write;
	cout << "Enter the intervention number" << endl << ">> ";
	cin >> searchnum;
	viewing.open("removal.txt", ios::in);
	if (viewing.is_open()) {
		while (!viewing.eof()) {
			viewing >> type >> day >> month >> year >> hour >> minute >> interventionnum >> outcome >> location;
			viewing.ignore();
			getline(viewing, address);
			if (searchnum == interventionnum) {
				found = 1;
				cout << "Appointment found.\nPlease enter the updated information" << endl;
				cout << "Please enter the Address of the removal" << endl << ">> ";
				cin.ignore();
				std::getline(std::cin, address);
				cout << "Please enter the date of the appointment (DD MM YYYY)" << endl << ">> ";
				cin >> day >> month >> year;
				cout << "Please enter the time of the appointment (HH MM)" << endl << ">> ";
				cin >> hour >> minute;
				cout << "Please enter an intervention number" << endl << ">> ";
				cin >> interventionnum;
				do {
					cout << "What was the outcome? (Adoption/Euthanized/Pending)" << endl << ">> ";
					cin >> outcome;
				} while (outcome.compare("Euthanized") && outcome.compare("Adoption") && outcome.compare("Pending"));
				do {
					cout << "Enter the location (Winchester/Caymanas)" << endl << ">> ";
					cin >> location;
				} while (location.compare("Winchester") && location.compare("Caymanas"));
				search.open("removal.txt", ios::in);
				if (search.is_open()) {
					write.open("temp.txt", ios::out);
					if (write.is_open()) {
						while (!search.eof()) {
							search >> type >> tempday >> tempmonth >> tempyear >> temphour >> tempminute >> tempnum >> tempoutcome >> templocation;
							search.ignore();
							getline(search, tempaddress);
							if (tempnum == searchnum) {
								write << "\n" << type << " " << day << " " << month << " " << year << " " << hour << " " << minute << " " << interventionnum << " " << outcome << " " << location << endl << address;
							}
							else {
								write << "\n" << type << " " << tempday << " " << tempmonth << " " << tempyear << " " << temphour << " " << tempminute << " " << tempnum << " " << tempoutcome << " " << templocation << endl << tempaddress;
							}
						}
					}
					else {
						cout << "Could not open file." << endl;
					}

				}
				else {
					cout << "Could not open file." << endl;
				}
				search.close();
				write.close();
				search.open("temp.txt", ios::in);
				if (search.is_open()) {
					write.open("removal.txt", ios::out);
					if (write.is_open()) {
						while (!search.eof()) {
							search >> type >> tempday >> tempmonth >> tempyear >> temphour >> tempminute >> tempnum >> tempoutcome >> templocation;
							search.ignore();
							getline(search, tempaddress);
							if (tempnum == searchnum) {
								write << "\n" << type << " " << day << " " << month << " " << year << " " << hour << " " << minute << " " << interventionnum << " " << outcome << " " << location << endl << address;
							}
							else {
								write << "\n" << type << " " << tempday << " " << tempmonth << " " << tempyear << " " << temphour << " " << tempminute << " " << tempnum << " " << tempoutcome << " " << templocation << endl << tempaddress;
							}
						}
						cout << "\n\nUpdate Complete\n\n";
					}
					else {
						cout << "Could not open file." << endl;
					}
				}
				else {
					cout << "Could not open file." << endl;
				}
				search.close();
				write.close();
			}
		}
	}
	else {
		cout << "The file could not be opened" << endl;
	}
	if (found == 0) {
		cout << "No appointment found." << endl;
	}
	system("pause");
	system("cls");
	viewing.close();
}
void viewReq() {//This method views a single request
	Date remdate;
	Time remtime;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int interventionnum;
	int searchnum;
	int count = 0;
	ifstream viewing;
	string address;
	int found = 0;
	string type;
	string outcome;
	string location;
	cout << "Enter the Intervention number" << endl << ">> ";
	cin >> searchnum;
	viewing.open("removal.txt", ios::in);
	if (viewing.is_open()) {
		while (!viewing.eof()) {
			viewing >> type >> day >> month >> year >> hour >> minute >> interventionnum >> outcome >> location;
			viewing.ignore();
			getline(viewing, address);
			if (interventionnum == searchnum) {
				found = 1;
				cout << "Appointment found." << endl;
				cout << "Type of appointment: " << type << endl;
				cout << "Date: " << day << "/" << month << "/" << year << endl;
				cout << "Time: " << hour << ":" << minute << endl;
				cout << "Intervention Number: " << interventionnum << endl;
				cout << "Address: " << address << endl;
				cout << "Outcome: " << outcome << endl;
				cout << "Location: " << location << endl;
				cout << "\n\n";
			}
		}
		if (found == 0) {
			cout << "Appointment not found." << endl;
		}
	}
	else {
		cout << "Could not open file." << endl;

	}
	system("pause");
	system("cls");
	viewing.close();
}
void viewAllReq() {//This method views all requests made
	Date remdate;
	Time remtime;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int interventionnum;
	int count = 0;
	string outcome;
	string location;
	string type;
	string address;
	ifstream viewing;
	viewing.open("removal.txt", ios::in);
	if (viewing.is_open()) {
		while (!viewing.eof()) {
			count += 1;
			viewing >> type >> day >> month >> year >> hour >> minute >> interventionnum >> outcome >> location;
			viewing.ignore();
			getline(viewing, address);
			if (type == "") {
				cout << "No records." << endl;
			}
			else {
				cout << "Entry No. " << count << endl;
				cout << "Type of appointment: " << type << endl;
				cout << "Date: " << day << "/" << month << "/" << year << endl;
				cout << "Time: " << hour << ":" << minute << endl;
				cout << "Intervention Number: " << interventionnum << endl;
				cout << "Address: " << address << endl;
				cout << "Outcome: " << outcome << endl;
				cout << "Location: " << location << endl;
				cout << "\n\n";
			}
		}
	}
	else {
		cout << "File could not be opened." << endl;

	}
	system("pause");
	system("cls");
	viewing.close();
}
void deleteReq() {//This method deletes a request 
	Date remdate;
	Time remtime;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int interventionnum;
	int found = 0;
	int searchnum;
	int tempday;
	int tempmonth;
	int tempyear;
	int tempnum;
	int temphour;
	int tempminute;
	string outcome;
	string tempoutcome;
	string type;
	string tempaddress;
	string address;
	string location;
	string templocation;
	ifstream viewing;;
	ifstream search;
	ofstream write;
	cout << "Enter the intervention number" << endl << ">> ";
	cin >> searchnum;
	viewing.open("removal.txt", ios::in);
	if (viewing.is_open()) {
		while (!viewing.eof()) {
			viewing >> type >> day >> month >> year >> hour >> minute >> interventionnum >> outcome >> location;
			viewing.ignore();
			getline(viewing, address);
			if (searchnum == interventionnum) {
				found = 1;
				cout << "Appointment found." << endl;
				search.open("removal.txt", ios::in);
				if (search.is_open()) {
					write.open("temp.txt", ios::out);
					if (write.is_open()) {
						while (!search.eof()) {
							search >> type >> tempday >> tempmonth >> tempyear >> temphour >> tempminute >> tempnum >> tempoutcome >> templocation;
							search.ignore();
							getline(search, tempaddress);
							if (tempnum == searchnum) {

							}
							else {
								write << "\n" << type << " " << tempday << " " << tempmonth << " " << tempyear << " " << temphour << " " << tempminute << " " << tempnum << " " << tempoutcome << " " << templocation << endl << tempaddress;
							}
						}
					}
					else {
						cout << "Could not open file." << endl;
					}

				}
				else {
					cout << "Could not open file." << endl;
				}
				search.close();
				write.close();
				search.open("temp.txt", ios::in);
				if (search.is_open()) {
					write.open("removal.txt", ios::out);
					if (write.is_open()) {
						while (!search.eof()) {
							search >> type >> tempday >> tempmonth >> tempyear >> temphour >> tempminute >> tempnum >> tempoutcome >> templocation;
							search.ignore();
							getline(search, tempaddress);
							if (tempnum == searchnum) {

							}
							else {
								write << "\n" << type << " " << tempday << " " << tempmonth << " " << tempyear << " " << temphour << " " << tempminute << " " << tempnum << " " << tempoutcome << " " << templocation << endl << tempaddress;
							}

						}
						cout << "\n\nDelete Complete.\n\n";
					}
					else {
						cout << "Could not open file." << endl;
					}
				}
				else {
					cout << "Could not open file." << endl;
				}
				search.close();
				write.close();
			}
		}
	}
	else {
		cout << "The file could not be opened" << endl;
	}
	if (found == 0) {
		cout << "No appointment found." << endl;
	}
	system("pause");
	system("cls");
	viewing.close();
}
void reports() {//This the main reports menu and allows the user to choose between client based reports and remval reports
	system("Color F0");//system colour
	int choice;
	int check = 0;
	do {
		cout << "Select a report type" << endl;
		cout << "1. Clinic reports\n2. Removal Reports\n3. Back\n4. Exit" << endl << ">> ";
		cin >> choice;
		system("cls");
		loading();
		if (choice == 1) {
			clinicReports();
		}
		else if (choice == 2) {
			removeReports();
		}
		else if (choice == 3) {
			check = 1;
		}
		else if (check == 4) {
			exit(0);
		}
		else {
			cout << "Enter a valid option." << endl;
		}
	} while (check == 0);
}
void clinicReports() {// This method allows the user to generate a menu from the option list
	int dec = 0;
	int choice;
	do {
		cout << "Select a report" << endl;
		cout << "1. Location Report\n2. Visit Date Report\n3. Animal Report\n4. Back\n5. Exit" << endl << ">> ";
		cin >> choice;
		system("cls");
		loading();
		if (choice == 1) {
			locationReport();
		}
		else if (choice == 2) {
			visitReport();
		}
		else if (choice == 3) {
			animalReport();
		}
		else if (choice == 4) {
			dec = 1;
		}
		else if (choice == 5) {
			exit(0);
		}
	} while (dec == 0);
}
void locationReport() {// The method generates the report for location from the animals menu
	string location;
	ifstream search;
	int contactnum;
	string paymentoption;
	string fname;
	string lname;
	string breed;
	string type;
	string gender;
	int age;
	string reason;
	string clinicvisit;
	int day;
	int month;
	int year;
	Intervention ii;
	do {
		cout << "Enter the location (Caymanas/Winchester)" << endl << ">> ";
		cin >> location;
		ii.setLocation(location);
	} while (location.compare("Caymanas") && location.compare("Winchester"));
	system("cls");
	cout << "First\tLast Name\tContact\tAnimal\tVisit Date\tReason for visit\n";
	search.open("client.txt", ios::in);
	if (search.is_open()) {
		while (!search.eof()) {
			search >> fname >> lname >> contactnum >> paymentoption >> type >> breed >> age >> gender >> day >> month >> year;
			search.ignore();
			getline(search, reason);
			getline(search, clinicvisit);
			if (!location.compare(clinicvisit)) {
				cout << fname << "\t" << lname << "\t" << contactnum << "\t" << type << "\t";
				cout << day << "/" << month << "/" << year;
				cout << "\t" << reason << endl;
			}
		}
	}
	else {
		cout << "Could not open file." << endl;
	}
	system("pause");
	system("cls");
	search.close();
}
void visitReport() {// This method generates the report for the visit
	int findday;
	int findmonth;
	int findyear;
	ifstream search;
	int contactnum;
	string paymentoption;
	string fname;
	string lname;
	string breed;
	string type;
	string gender;
	int age;
	string reason;
	string clinicvisit;
	int day;
	int month;
	int year;
	cout << "Enter the date of visit (DD MM YYYY)" << endl << ">> ";
	cin >> findday >> findmonth >> findyear;
	system("cls");
	cout << "First\tLast Name\tContact\tAnimal\tReason for visit\tLocation\n";
	search.open("client.txt", ios::in);
	if (search.is_open()) {
		while (!search.eof()) {
			search >> fname >> lname >> contactnum >> paymentoption >> type >> breed >> age >> gender >> day >> month >> year;
			search.ignore();
			getline(search, reason);
			getline(search, clinicvisit);
			if (findday == day && findmonth == month && findyear == year) {
				cout << fname << "\t" << lname << "\t" << contactnum << "\t" << type << "\t";
				cout << "\t" << reason << "\t" << clinicvisit << endl;
			}
		}
	}
	else {
		cout << "Could not open file." << endl;
	}
	system("pause");
	system("cls");
	search.close();
}
void animalReport() {//This method generates the report for the anmila 
	string animal;
	ifstream search;
	int contactnum;
	string paymentoption;
	string fname;
	string lname;
	string breed;
	string type;
	string gender;
	int age;
	string reason;
	string clinicvisit;
	int day;
	int month;
	int year;
	cout << "Enter the Animal" << endl << ">> ";
	cin >> animal;
	system("cls");
	cout << "First\tLast Name\tContact\tVisit Date\tReason for visit\tLocation\n";
	search.open("client.txt", ios::in);
	if (search.is_open()) {
		while (!search.eof()) {
			search >> fname >> lname >> contactnum >> paymentoption >> type >> breed >> age >> gender >> day >> month >> year;
			search.ignore();
			getline(search, reason);
			getline(search, clinicvisit);
			if (!animal.compare(type)) {
				cout << fname << "\t" << lname << "\t" << contactnum << "\t";
				cout << day << "/" << month << "/" << year;
				cout << "\t" << reason << "\t" << clinicvisit << endl;
			}
		}
	}
	else {
		cout << "Could not open file." << endl;
	}
	system("pause");
	system("cls");
	search.close();
}
void removeReports() {//This gives the user the option to select which report they want
	int dec = 0;
	int check = 0;
	do {
		cout << "Select a report type" << endl;
		cout << "1. Location Report\n2. Date Report\n3. Outcome Report\n4. Back\n5. Exit" << endl << ">> ";
		cin >> dec;
		system("cls");
		loading();
		if (dec == 1) {
			remLocationReport();
		}
		else if (dec == 2) {
			reqDateReport();
		}
		else if (dec == 3) {
			outcomeReport();
		}
		else if (dec == 4) {
			check = 1;
		}
		else if (dec == 5) {
			exit(0);
		}
		else {
			cout << "Enter a valid option." << endl;
		}
	} while (check == 0);
}
void remLocationReport() {// this method generated the report for location
	string location;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int interventionnum;
	int emptyfile = 0;
	string outcome = "Pending";
	string type;
	string address;
	string searchlocation;
	ifstream search;
	do {
		cout << "Enter the location (Winchester/Caymanas)" << endl << ">> ";
		cin >> searchlocation;
	} while (searchlocation.compare("Winchester") && searchlocation.compare("Caymanas"));
	system("cls");
	search.open("removal.txt", ios::in);
	if (search.is_open()) {
		cout << "Appointment\tIntended Date\tTime\tNumber\tOutcome" << endl;
		while (!search.eof()) {
			search >> type >> day >> month >> year >> hour >> minute >> interventionnum >> outcome >> location;
			search.ignore();
			getline(search, address);
			if (!location.compare(searchlocation)) {
				cout << type << "\t" << day << "/" << month << "/" << year << "\t" << hour << ":" << minute << "\t";
				cout << interventionnum << "\t" << outcome << endl;
			}
		}
	}
	else {
		cout << "Could not open file." << endl;
	}
	system("pause");
	system("cls");
	search.close();
}
void reqDateReport() {//this method generates a report for dates
	string location;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int interventionnum;
	int emptyfile = 0;
	string outcome = "Pending";
	string type;
	string address;
	int searchday;
	int searchmonth;
	int searchyear;
	ifstream search;
		//try {
	cout << "Enter the date (DD MM YYYY)" << endl << ">> ";
	cin >> searchday >> searchmonth >> searchyear;
	system("cls");
		search.open("removal.txt", ios::in);
		if (search.is_open()) {
			cout << "Appointment\tTime\tNumber\tOutcome\t\tLocation" << endl;
			while (!search.eof()) {
				search >> type >> day >> month >> year >> hour >> minute >> interventionnum >> outcome >> location;
				search.ignore();
				getline(search, address);
				if (searchday == day && searchmonth == month && searchyear == year) {
					cout << type << "\t" << hour << ":" << minute << "\t";
					cout << interventionnum << "\t" << outcome << "\t" << location << endl;
				}
			}
		}
		else {
			cout << "Could not open file." << endl;
			//throw runtime_error("Could not open file");
		}
	/*catch (runtime_error&s) {//handle exception
		cerr << s.what();
	}*/
	system("pause");
	system("cls");
	search.close();
}
void outcomeReport() {//this method prints the outcome report
	string location;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int interventionnum;
	int emptyfile = 0;
	string outcome = "Pending";//initialize outcome
	string type;
	string address;
	string searchoutcome;
	ifstream search;
	try{
	do {
		//searching for outcome of a removal
		cout << "Enter the outcome (Adoption/Euthanization/Pending)" << endl << ">> ";
		cin >> searchoutcome;
	} while (searchoutcome.compare("Adoption") && searchoutcome.compare("Euthanization") && searchoutcome.compare("Pending"));
	system("cls");
	search.open("removal.txt", ios::in);
	if (search.is_open()) {
		cout << "Appointment\tIntended Date\tTime\tNumber\tLocation" << endl;
		while (!search.eof()) {
			//display result of search if found
			search >> type >> day >> month >> year >> hour >> minute >> interventionnum >> outcome >> location;
			search.ignore();
			getline(search, address);
			if (!outcome.compare(searchoutcome)) {
				if (!type.compare("Removal")) {
					cout << type << "\t\t" << day << "/" << month << "/" << year << "\t" << hour << ":" << minute << "\t";
					cout << interventionnum << "\t" << location << endl;
				}
				else {
					cout << type << "\t" << day << "/" << month << "/" << year << "\t" << hour << ":" << minute << "\t";
					cout << interventionnum << "\t" << location << endl;
				}
			}
		}
	}
	else {
		//cout << "Could not open file." << endl;
		throw runtime_error("Could not open");
		cout << type << "\t" << day << "/" << month << "/" << year << "\t" << hour << ":" << minute << "\t";
		cout << interventionnum << "\t" << location << endl;
	}
}//end try block
catch(runtime_error&z)//handle exception
{
	cerr << z.what();
}
	system("pause");
	system("cls");
	search.close();
}
void loading() {//this method enables a loading screen to appear when the user selects an option
	system("cls");
	char x = '.';
	cout << "Loading";
	for (int y = 0; y < 4; y++) {
		cout << x;
		Sleep(500);
	}
	cout << endl;
	system("cls");
}
