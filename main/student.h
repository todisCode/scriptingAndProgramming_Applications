#ifndef STUDENT
#define STUDENT

#pragma once

#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
	
	private:
		//Variables
		string id;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysToCompleteCourse[3];
		DegreeProgram degreeProgram;

	public:
		//Default constructor
		Student();

		//Constructor using all of the input parameters provided in the table
		Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, int numOfDaysToCompleteCourse[], DegreeProgram studentDegreeProgram);

		//Accessor functions
		string GetID();
		string GetFirstName();
		string GetLastName();
		string GetEmail();
		int GetAge();
		int* GetDaysToCompleteCourse();
		DegreeProgram GetDegreeProgram();

		//Mutator functions
		void SetID(string studentID);
		void SetFirstName(string studentFirstName);
		void SetLastName(string studentLastName);
		void SetEmail(string studentEmail);
		void SetAge(int studentAge);
		void SetDaysToCompleteCourse(int numOfDaysToCompleteCourse[]);
		void SetDegreeProgram(DegreeProgram studentDegreeProgram);

		//Print specific student data
		void print();

};

#endif /* STUDENT */