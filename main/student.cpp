#pragma once

#include "student.h"
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Default constructor
Student::Student() {
	id = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	daysToCompleteCourse[0] = 0;
	daysToCompleteCourse[1] = 0;
	daysToCompleteCourse[2] = 0;
	degreeProgram = DegreeProgram::UNKNOWN;
}

//Constructor using all of the input parameters provided in the table
Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, int numOfDaysToCompleteCourse[], DegreeProgram studentDegreeProgram) {
	id = studentID;
	firstName = studentFirstName;
	lastName = studentLastName;
	emailAddress = studentEmail;
	age = studentAge;
	daysToCompleteCourse[0] = numOfDaysToCompleteCourse[0];
	daysToCompleteCourse[1] = numOfDaysToCompleteCourse[1];
	daysToCompleteCourse[2] = numOfDaysToCompleteCourse[2];
	degreeProgram = studentDegreeProgram;
}

//Mutator functions
void Student::SetID(string studentID) {
	id = studentID;
}

void Student::SetFirstName(string studentFirstName) {
	firstName = studentFirstName;
}

void Student::SetLastName(string studentLastName) {
	lastName = studentLastName;
}

void Student::SetEmail(string studentEmail) {
	emailAddress = studentEmail;
}

void Student::SetAge(int studentAge) {
	age = studentAge;
}

void Student::SetDaysToCompleteCourse(int numberOfDaysToCompleteCourse[]) {
	daysToCompleteCourse[0] = numberOfDaysToCompleteCourse[0];
	daysToCompleteCourse[1] = numberOfDaysToCompleteCourse[1];
	daysToCompleteCourse[2] = numberOfDaysToCompleteCourse[2];
}

void Student::SetDegreeProgram(DegreeProgram studentDegreeProgram) {
	degreeProgram = studentDegreeProgram;
}

//Accessor functions
string Student::GetID() {
	return id;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmail() {
	return emailAddress;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDaysToCompleteCourse() {
	return daysToCompleteCourse;
}

//Print specifc sudent data
void Student::print() {
	cout << GetID() << '\t';
	cout << "First Name: " << GetFirstName() << '\t';
	cout << "Last Name: " << GetLastName() << '\t';
	cout << "Age: " << GetAge() << '\t';
	cout << "Days In Course: {" << GetDaysToCompleteCourse()[0] << ", " << GetDaysToCompleteCourse()[1] << ", " << GetDaysToCompleteCourse()[2] << "}" << '\t';
	cout << "Degree Program: " << stringDegreeProgram[GetDegreeProgram()] << endl;
}