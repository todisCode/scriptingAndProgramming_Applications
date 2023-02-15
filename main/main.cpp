#include "roster.h"

using namespace std;

int main()
{
	const int numOfStudents = 5;
	int i;
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Filipe,Araujo,farauj6@wgu.edu,27,7,14,21,SOFTWARE"
	};

	//Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Course: Scripting And Programing - Applications - C867" << endl;
	cout << "Programing Language Used: C++" << endl;
	cout << "WGU Student ID: 009468145" << endl;
	cout << "Name: Filipe Araujo" << endl;
	cout << endl;

	cout << endl;

	//Create an instance of the Roster class called classRoster.
	Roster classRoster;

	//Add each student to classRoster.
	for (i = 0; i < numOfStudents; i++) {
		classRoster.dataParse(studentData[i]);
	}

	//Convert the following pseudo code to complete the rest of the  main() function

	//Prints a complete tab-separated list of student data in the provided format
	cout << "Below we have a list of all students:" << endl;
	classRoster.printAll();
	cout << endl;

	cout << endl;

	//Displays all invalid email addresses
	cout << "These are the students with invalid email addresses:" << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << endl;

	//Loop through classRosterArray and for each element:

	//Prints a student’s average number of days in the three courses
	cout << "The average number of days of each student for all three courses are listed below:" << endl;

	for (i = 0; i < numOfStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetID());
	 }

	cout << endl;

	cout << endl;

	//Prints out student information for a degree program specified by an enumerated type.
	cout << "Student information for the SOFTWARE program: " << endl;	
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << endl;

	//Removing student by ID
	cout << "Removing student of ID: A3." << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << endl;

	//Print all students
	cout << "List of students after removing student of ID A3:" << endl;
	classRoster.printAll();
	cout << endl;

	cout << endl;

	//Removing student by ID
	cout << "Removing student of ID: A3." << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << endl;

	system("pause");

	return 0;
}