#include <iostream>
#include <iomanip>
#include <string>
#include "roster.h"

using namespace std;

void Roster::dataParse(string studentData) {
	//Parse each set of data identified in the “studentData Table.”
	long long int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs); //studentID

	long long int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentFirstName = studentData.substr(lhs, rhs - lhs); //studentFirstName

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentLastName = studentData.substr(lhs, rhs - lhs); //studentLastName

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentEmailAddress = studentData.substr(lhs, rhs - lhs); //studentEmailAddress

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int studentAge = stoi(studentData.substr(lhs, rhs - lhs)); //studentAge

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int studentDaysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs)); //studentDaysInCourse1

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int studentDaysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs)); //studentDaysInCourse2

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int studentDaysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs)); //studentDaysInCourse3

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentProgram = studentData.substr(lhs, rhs - lhs); //studentDegreeProgram

	DegreeProgram studentDegreeProgram = SOFTWARE;

	if (studentProgram == "SECURITY") {
		studentDegreeProgram = SECURITY;
	}
	else if (studentProgram == "NETWORK") {
		studentDegreeProgram = NETWORK;
	}

	//Add each student object to classRosterArray.
	add(studentID, studentFirstName, studentLastName, studentEmailAddress, studentAge, studentDaysInCourse1, studentDaysInCourse2, studentDaysInCourse3, studentDegreeProgram);
}

//Sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string studentFirstName, string studentLastName, string studentEmailAddress, int studentAge, int studentDaysInCourse1, int studentDaysInCourse2, int studentDaysInCourse3, DegreeProgram studentDegreeProgram) {
	int daysInCourse[3] = { studentDaysInCourse1, studentDaysInCourse2, studentDaysInCourse3 };

	classRosterArray[++lastValue] = new  Student(studentID, studentFirstName, studentLastName, studentEmailAddress, studentAge, daysInCourse, studentDegreeProgram);
}

//Removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID) {
	bool deleted = false;
	int i;

	for (i = 0; i <= Roster::lastValue; i++) {
		if (classRosterArray[i]->GetID() == studentID) {
			cout << "Student found." << endl;

			deleted = true;

			if (i < numOfStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numOfStudents - 1];
				classRosterArray[numOfStudents - 1] = temp;
				
			}

			Roster::lastValue--;
		}
	}

	if (deleted) {
		cout << "Student with ID \"" << studentID << "\" has been removed." << endl;
	}
	else {
		cout << "Student with ID \"" << studentID << "\" could not be found." << endl;
	}
}

//Prints a complete tab-separated list of student data in the provided format:
//A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
//The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
void Roster::printAll() {
	int i;

	for (i = 0; i <= Roster::lastValue; i++) {
		classRosterArray[i]->print();
	}
}

//Correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
	int i;

	for (i = 0; i <= Roster::lastValue; i++) {
		if (classRosterArray[i]->GetID() == studentID) {
			cout << "The average days in course for " << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << " is: ";
			cout << (classRosterArray[i]->GetDaysToCompleteCourse()[0] + classRosterArray[i]->GetDaysToCompleteCourse()[1] + classRosterArray[i]->GetDaysToCompleteCourse()[2]) / 3.0 << endl;
		}
	}
}

//Verifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails() {
	int i;

	for (i = 0; i <= Roster::lastValue; i++) {
		string currEmail;

		currEmail = classRosterArray[i]->GetEmail();

		if ((currEmail.find("@") != string::npos) && (currEmail.find(".") != string::npos)) {
			if (currEmail.find(" ") != string::npos) {
				cout << currEmail << endl;
			}
		}
		else {
			cout << currEmail << endl;
		}
	}
}

//Prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram studentDegreeProgram) {
	int i;
	
	for (i = 0; i <= Roster::lastValue; i++) {
		if (Roster::classRosterArray[i]->GetDegreeProgram() == studentDegreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	int i;

	cout << endl;
	cout << endl << "Destructor Activated!" << endl;

	for (i = 0; i <= Roster::lastValue; i++) {
		cout << "Deleting student with ID: " << classRosterArray[i]->GetID() << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}

	cout << "Memory release completed." << endl;
}