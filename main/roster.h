#ifndef ROSTER
#define ROSTER

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"

using namespace std;

class Roster {
	private:
		const static int numOfStudents = 5;
	public:
		~Roster();

		int lastValue = -1;

		//Array of pointers to hold the data provided in the "studentData Table"
		Student* classRosterArray[5];

		//Parse each set of data identifiesd in the "studentData Table"
		void dataParse(string row);

		void add(string studentID,
				 string studentFirstName,
			     string studentLastName,
			     string studentEmailAddress,
			     int	studentAge,
			     int	studentDaysInCourse1,
			     int	studentDaysInCourse2,
		         int	studentDaysInCourse3,
			     DegreeProgram studentDegreeProgram);				   //Sets the instance variables from part D1 and updates the roster.

		void remove(string studentID);								   //Removes students from the roster by student ID. If the student ID does not exist, the function prints an error message
																	   //indicating that the student was not found.

		void printAll();											   //Prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab]
																	   //Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
																	   //The printAll() function should loop through all the students in classRosterArray and call the print() function
																	   //for each student.

		void printAverageDaysInCourse(string studentID);			   //Correctly prints a student’s average number of days in the three courses. The student is identified by the studentID
																	   //parameter.

		void printInvalidEmails();									   //Verifies student email addresses and displays all invalid email addresses to the user.
																	   //A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

		void printByDegreeProgram(DegreeProgram studentDegreeProgram); //prints out student information for a degree program specified by an enumerated type.
};

#endif /* ROSTER */