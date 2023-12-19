#include"Header..h"

#include <iostream>
#include <string>

#include <fstream>

#include <iomanip>
using namespace std;


Admin::Admin() {

	//default admin login info.
	ID = "admin";
	Password = "admin";

	marks = P = A = 0;
	courseName = stuID = " ";
	grade = '-';
}

bool Admin::Login() {

	string id, pass;

	while (1) {
		system("cls");
		cout << " --------------------------------------- " << endl;
		cout << "               ADMIN LOGIN               " << endl;
		cout << " --------------------------------------- " << endl << endl;
		cout << "    ID           :"; cin >> id;
		cout << "    PASSWORD     :"; cin >> pass;
		cout << " --------------------------------------- " << endl;

		if (id != ID || pass != Password) {
			cout << endl << "Try Again!" << endl;
			return 0;
			system("pause");
		}
		else {
			cout << endl << "Login Success!" << endl;
			system("pause");
			return 1;
			break;
		}
	}
}

int Admin::Menu() {

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "            ADMIN MENU              " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " Add Student                     (1)" << endl;
	cout << " View All Students               (2)" << endl;
	cout << " Edit Student Details            (3)" << endl;
	cout << " Add Teacher                     (4)" << endl;
	cout << " View All Teachers               (5)" << endl;
	cout << " Edit Teacher Details            (6)" << endl;
	cout << " Exit                            (7)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while (!(choice > 0 && choice < 8)) {
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	return choice;
}

Teacher::Teacher() {
	firstName = lastName = DepartmentName = regDate = ".";
	Username = Password = confirmPassword = ".";
	gender = '.';
	Qualification = Address = ".";
	tID = contactNo = ".";

}

bool Teacher::Login() {

	string id, pass;

	ifstream infile;
	try {
		infile.open("Teacher.txt", ios::in);

		if (!infile) { throw invalid_argument("Teacher file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }

	system("cls");
	cout << " --------------------------------------- " << endl;
	cout << "               TEACHER LOGIN             " << endl;
	cout << " --------------------------------------- " << endl << endl;
	cout << "    ID           :"; cin >> id;
	cout << "    PASSWORD     :"; cin >> pass;
	cout << " --------------------------------------- " << endl;

	infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;

	while (!infile.eof()) {

		try {
			if (id == Username && pass == Password) {
				loggedIn = Username;
				cout << endl << "Login Success!" << endl;
				return 1;
				break;
			}
			else {
				infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
			}
			if (id != Username && pass != Password) { throw invalid_argument("No Teacher Exists!"); }
		}

		catch (invalid_argument x) {
			cout << x.what() << endl;
			return 0;
		}
	}
}

int Teacher::Menu() {

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "            TEACHER MENU            " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " View TimeTable                  (1)" << endl;
	cout << " Assign Marks&Grade              (2)" << endl;
	cout << " Mark Attendance                 (3)" << endl;
	cout << " Exit                            (4)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while (!(choice > 0 && choice < 5)) {
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	return choice;
}

//Save data to file.
void::Teacher::saveData() {

	ofstream outfile;

	try {

		outfile.open("Teacher.txt", ios::app);

		if (!outfile) { throw invalid_argument("Teacher file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }


	outfile << firstName << "    " << lastName << "    " << tID << "    " << DepartmentName << "    " << regDate << "    " << Username << "    "
		<< Password << "    " << gender << "    " << Qualification << "    " << contactNo << "    " << Address << endl;

	outfile.close();
	cout << "Data Recorded! " << endl << endl;

	system("pause");

}

//Print All Teachers.
void Teacher::viewAllTeachers() {

	system("cls");

	ifstream infile;
	try {
		infile.open("Teacher.txt", ios::in);

		if (!infile) { throw invalid_argument("Teacher file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }



	cout << "__________________________________Teachers___________________________________" << endl;
	cout << " ___________________________________________________________________________ " << endl;
	cout << "|   FirstName  LastName   Gender   Qualification   Contact         Username |" << endl;
	cout << "| _________________________________________________________________________ |" << endl;

	while (1) {
		infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
		if (!infile.eof()) {
			cout << "| " << setw(10) << firstName << setw(10) << lastName << setw(5) << gender << setw(15) << Qualification << setw(20) << contactNo << setw(13) << Username << " |" << endl;
		}
		else { break; }
	}

	cout << " ___________________________________________________________________________ " << endl;
	system("pause");
	infile.close();
}

//Edit specific Teacher details.
void Teacher::editTeacher() {

	system("cls");
	DisplayTeacherID();

	string checkID;
	cout << "Enter Teacher ID to Edit: ";
	cin >> checkID;
	system("pause");
	system("cls");

	ifstream infile;

	ofstream outfile;
	outfile.open("NewTeacher.txt", ios::app);

	try {
		infile.open("Teacher.txt", ios::in);

		if (!infile) { throw invalid_argument("Teacher file not found!"); }

		else {
			infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;

			while (!infile.eof()) {

				if (checkID == tID) { //If ID match then edit and save data.
					cout << " ------------------------------------------------- " << endl;
					cout << "                   Enter New Data                  " << endl;
					cout << " ------------------------------------------------- " << endl;
					cout << "Enter Address                : "; cin >> Address;
					cout << "Enter Contact No.            : "; cin >> contactNo;
					cout << "Enter Qualification          : "; cin >> Qualification;
					cout << " ------------------------------------------------ " << endl;

					outfile << firstName << "    " << lastName << "    " << tID << "    " << DepartmentName << "    " << regDate << "    " << Username << "    "
						<< Password << "    " << gender << "    " << Qualification << "    " << contactNo << "    " << Address << endl;
				}
				else { //If ID not match then save data as it is.
					outfile << firstName << "    " << lastName << "    " << tID << "    " << DepartmentName << "    " << regDate << "    " << Username << "    "
						<< Password << "    " << gender << "    " << Qualification << "    " << contactNo << "    " << Address << endl;
				}
				//getting data for next teacher.
				infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
			}
		}

	}

	catch (invalid_argument x) { cout << x.what(); }

	infile.close();
	outfile.close();

	remove("Teacher.txt");
	rename("NewTeacher.txt", "Teacher.txt");


}

//Display Teacher IDs for editTeacher function.
void Teacher::DisplayTeacherID() {

	ifstream infile;
	try {
		infile.open("Teacher.txt", ios::in);

		if (!infile) { throw invalid_argument("Teacher file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }


	cout << "Teacher IDs: " << endl;
	while (1) {
		infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
		if (!infile.eof()) {
			cout << tID << endl;
		}
		else { break; }
	}
	infile.close();
}

//count number of lines in file and hence number of Teachers.
void Teacher::countLines() {

	ifstream countfile;
	count = -1;

	try {
		countfile.open("Teacher.txt", ios::in);

		if (!countfile) { throw invalid_argument("Teacher file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }


	while (!countfile.eof()) {

		countfile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
		count++;
	}
	countfile.close();
}

void Teacher::MarkAttendance() {

	system("cls");

	string id;
	int choice;

	ifstream infile;
	try {
		infile.open("Attendance.txt", ios::in);

		if (!infile) { throw invalid_argument("Attendance file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }

	ofstream outfile;
	outfile.open("temp.txt", ios::app);

	cout << "--------Attendance--------" << endl;
	cout << " Enter Student ID       : "; cin >> id;

	infile >> stuID >> P >> A;

	while (!infile.eof()) {

		if (stuID == id) {

			cout << " --------------------- " << endl;
			cout << "Press (1) for Present  " << endl;
			cout << "Press (2) for Absent   " << endl;
			cout << "Enter Choice         : "; cin >> choice;
			cout << " --------------------- " << endl;
			if (choice == 1) {
				P++;
				cout << "Present Recorded! " << endl;
			}
			else if (choice == 2) {
				A++;
				cout << "Absent Recorded! " << endl;
			}
			system("pause");

			outfile << stuID << "    " << P << "    " << A << endl;
		}

		else {
			outfile << stuID << "    " << P << "    " << A << endl;
		}

		infile >> stuID >> P >> A;
	}

	infile.close();
	outfile.close();

	remove("Attendance.txt");
	rename("temp.txt", "Attendance.txt");

}

void Teacher::AssignMarks() {

	string id, cName;

	ifstream infile;
	try {
		infile.open("Marks.txt", ios::in);

		if (!infile) { throw invalid_argument("Marks file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }


	ofstream outfile;
	outfile.open("temp.txt", ios::app);

	system("cls");
	cout << "----------Assigning Marks and Grades----------" << endl;
	cout << "  ------------------------------------------  " << endl;
	cout << "Enter Student ID                       : "; cin >> id;
	infile >> stuID >> courseName >> marks >> grade;

	//if previous data is found.
	while (!infile.eof()) {

		if (stuID == id) {

			cout << "Enter Course Name                      : "; cin >> cName;
			cout << " --------------------- " << endl;

			if (courseName == cName) {
				cout << "Enter Marks          : "; cin >> marks;
				cout << " --------------------- " << endl;
				cout << "Marks Recorded! " << endl;
				AssignGrade();
				system("pause");
				outfile << stuID << "    " << courseName << "    " << marks << "    " << grade << endl;
			}
			else if (courseName != cName) { break; }
		}

		else {
			AssignGrade();
			outfile << stuID << "    " << courseName << "    " << marks << "    " << grade << endl;
		}

		infile >> stuID >> courseName >> marks >> grade;
	}

	//IF previous data is not found.
	if (stuID == id && courseName != cName) {

		cout << "Enter Marks          : "; cin >> marks;
		cout << " --------------------- " << endl;
		cout << "Marks Recorded! " << endl;
		AssignGrade();
		outfile << stuID << "    " << cName << "    " << marks << "    " << grade << endl;
		system("pause");
	}

	if (stuID != id) {
		cout << endl << "------ Invalid Student ID! ------" << endl;
		system("pause");
	}


	infile.close();
	outfile.close();

	remove("Marks.txt");
	rename("temp.txt", "Marks.txt");

}

void Teacher::AssignGrade() {

	if (marks >= 80) { grade = 'A'; }
	else if (marks >= 70) { grade = 'B'; }
	else if (marks >= 60) { grade = 'C'; }
	else if (marks >= 50) { grade = 'D'; }
	else { grade = 'F'; }
}

void Teacher::viewTimeTable()
{
	cout << setw(15) << "Day" << setw(25) << "Time" << setw(30) << "Subject" << endl;
	cout << setfill('-') << setw(75) << "" << setfill(' ') << endl;

	// Display the timetable entries
	cout << setw(15) << "Monday" << setw(25) << "9:00 AM - 10:30 AM" << setw(30) << "Mathematics" << endl;
	cout << setw(15) << "Tuesday" << setw(25) << "10:00 AM - 11:30 AM" << setw(30) << "Science" << endl;
	cout << setw(15) << "Wednesday" << setw(25) << "1:00 PM - 2:30 PM" << setw(30) << "English" << endl;
	cout << setw(15) << "Thursday" << setw(25) << "3:00 PM - 4:30 PM" << setw(30) << "History" << endl;
	cout << setw(15) << "Friday" << setw(25) << "2:00 PM - 3:30 PM" << setw(30) << "Physics" << endl;
	system("pause");

}

Student::Student() {
	firstName = lastName = DepartmentName = regDate = ".";
	gender = '.';
	contactNo = ".";
	BloodGroup = Address = ".";
	feeStatus = 0;
	marks = 0;
}

bool Student::Login() {

	string id;

	ifstream infile;
	try {
		infile.open("Student.txt", ios::in);

		if (!infile) { throw invalid_argument("Student file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }

	system("cls");
	cout << " --------------------------------------- " << endl;
	cout << "               STUDENT LOGIN             " << endl;
	cout << " --------------------------------------- " << endl << endl;
	cout << "    ID           :"; cin >> id;
	cout << " --------------------------------------- " << endl;

	infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

	while (!infile.eof()) {

		if (id == sID) {
			loggedIn = id;
			cout << endl << "Login Success!" << endl;
			return 1;
			break;
		}

		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

	};
	if (id != sID) {
		//playSound();
		cout << endl << "No Student Exists!" << endl;
		return 0;
	}

	infile.close();


}

int Student::Menu() {

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "            STUDENT MENU            " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " View Attendance                 (1)" << endl;
	cout << " View Marks                      (2)" << endl;
	cout << " View Grades                     (3)" << endl;
	cout << " View Courses                    (4)" << endl;
	cout << " View Fee Status                 (5)" << endl;
	cout << " Exit                            (6)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while (!(choice > 0 && choice < 7)) {
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	return choice;
}

//save data to file.
void Student::saveData() {

	ofstream outfile, outfile2, outfile3;


	try {
		outfile.open("Student.txt", ios::app);
		outfile2.open("Attendance.txt", ios::app);
		outfile3.open("Marks.txt", ios::app);

		if (!outfile) { throw invalid_argument("Student file not found!"); }
		if (!outfile2) { throw invalid_argument("Attendance file not found!"); }
		if (!outfile3) { throw invalid_argument("Marks file not found!"); }
	}

	catch (invalid_argument x) { cout << x.what(); }


	outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
		<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;

	//initializing attendance for new student to 0.
	outfile2 << sID << "    " << 0 << "    " << 0 << endl;

	//initializing marks file with atleast 1 course name.
	if (DepartmentName == "CS" || DepartmentName == "SE" || DepartmentName == "EE") {
		outfile3 << sID << "    " << "OOP" << "    " << 0 << endl;
	}
	else if (DepartmentName == "BA") {
		outfile3 << sID << "    " << "Accounting" << "    " << 0 << endl;
	}

	outfile.close();
	outfile2.close();
	cout << "Data Recorded! " << endl << endl;

	system("pause");
}

//display all students.
void Student::viewAllStudents() {

	system("cls");

	ifstream infile;
	try {
		infile.open("Student.txt", ios::in);

		if (!infile) { throw invalid_argument("Student file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }


	cout << "________________________________________Students_______________________________________" << endl;
	cout << " _____________________________________________________________________________________ " << endl;
	cout << "|  ID      FirstName   LastName   Gender   Department     Contact             Address |" << endl;
	cout << "| ___________________________________________________________________________________ |" << endl;

	while (1) {
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		if (!infile.eof()) {
			cout << "| " << setw(5) << sID << setw(12) << firstName << setw(10) << lastName << setw(6) << gender << setw(10) << DepartmentName << setw(24) << contactNo << setw(15) << Address << "  |" << endl;
		}
		else { break; }
	}

	cout << " _____________________________________________________________________________________ " << endl;
	system("pause");
	infile.close();
}

//edit specific student.
void Student::editStudent() {

	system("cls");
	DisplayRollNo();

	string checkID;
	cout << "Enter Student ID to Edit: ";
	cin >> checkID;
	system("pause");
	system("cls");

	ifstream infile;

	ofstream outfile;
	outfile.open("NewStudent.txt", ios::app);

	try {
		infile.open("Student.txt", ios::in);

		if (!infile) { throw invalid_argument("Student file not found!"); }

		else {
			infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

			while (!infile.eof()) {

				if (checkID == sID) { //If ID match then edit and save data.
					cout << " ------------------------------------------------- " << endl;
					cout << "                   Enter New Data                  " << endl;
					cout << " ------------------------------------------------- " << endl;
					cout << "Enter First Name             : "; cin >> firstName;
					cout << "Enter Last Name              : "; cin >> lastName;
					cout << "Enter Fee Status             : "; cin >> feeStatus;
					cout << "Enter Address                : "; cin >> Address;
					cout << "Enter Contact No.            : "; cin >> contactNo;
					cout << " ------------------------------------------------ " << endl;

					outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
						<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;
				}
				else { //If ID not match then save data as it is.
					outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
						<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;
				}
				//getting data for next teacher.
				infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
			}
		}

	}

	catch (invalid_argument x) { cout << x.what(); }

	infile.close();
	outfile.close();

	remove("Student.txt");
	rename("NewStudent.txt", "Student.txt");
}

//Display roll numbers for edit function.
void Student::DisplayRollNo() {

	ifstream infile;
	infile.open("Student.txt", ios::in);

	cout << "Roll Numbers: " << endl;
	while (!infile.eof()) {
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		cout << sID << endl;
	}
	infile.close();
}

////count number of lines in file and hence number of students.
void Student::countLines() {

	ifstream countfile;
	count = -1;
	try {
		countfile.open("Student.txt", ios::in);

		if (!countfile) { throw invalid_argument("Student file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }


	while (!countfile.eof()) {

		countfile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		count++;
	}
	countfile.close();
}

void Student::viewMarks() {

	system("cls");

	ifstream infile;
	try {
		infile.open("Marks.txt", ios::in);

		if (!infile) { throw invalid_argument("Marks file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }


	cout << "--------Marks--------" << endl;

	while (!infile.eof()) {

		infile >> stuID >> courseName >> marks >> grade;

		if (stuID == loggedIn) {
			cout << "-----------------------" << endl;
			cout << "Course: " << courseName << endl;
			cout << "Marks: " << marks << endl;
			cout << "-----------------------" << endl;
		}

	}

	system("pause");

	infile.close();
}

void Student::viewGrades() {

	system("cls");

	ifstream infile;
	try {
		infile.open("Marks.txt", ios::in);

		if (!infile) { throw invalid_argument("Marks file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }


	cout << "--------Grades---------" << endl;

	while (!infile.eof()) {

		infile >> stuID >> courseName >> marks >> grade;

		if (stuID == loggedIn) {
			cout << "-----------------------" << endl;
			cout << "Course: " << courseName << endl;
			cout << "Grdae: " << grade << endl;
			cout << "-----------------------" << endl;
		}

	}
	system("pause");

	infile.close();
}

void Student::viewCourses() {

	system("cls");

	ifstream infile;
	try {
		infile.open("Marks.txt", ios::in);

		if (!infile) { throw invalid_argument("Marks file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }

	cout << "---------Courses---------" << endl;

	while (!infile.eof()) {
		infile >> stuID >> courseName >> marks >> grade;
		if (stuID == loggedIn) {
			cout << "-------------------------" << endl;
			cout << courseName << endl;
		}
	}
	cout << "-----------------------" << endl;

	system("pause");

	infile.close();
}

void Student::viewFeeStatus() {

	system("cls");

	ifstream infile;
	try {
		infile.open("Student.txt", ios::in);

		if (!infile) { throw invalid_argument("Student file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }

	while (!infile.eof()) {
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		if (stuID == loggedIn) {

			cout << "-----------------------" << endl;
			cout << "Fee Status: ";

			if (feeStatus == 1) { cout << "  Paid" << endl; }
			else { cout << "  Un-Paid" << endl; }

		}
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
	}
	cout << "-----------------------" << endl;

	system("pause");

	infile.close();
}

void Student::viewAttendance() {

	system("cls");

	ifstream infile;
	try {
		infile.open("Attendance.txt", ios::in);

		if (!infile) { throw invalid_argument("Attendance file not found!"); }
	}
	catch (invalid_argument x) { cout << x.what(); }

	infile >> stuID >> P >> A;

	while (!infile.eof()) {

		if (stuID == loggedIn) {
			cout << " ------------------------ " << endl;
			cout << "Present Count        : " << P << endl;
			cout << "Absent Count         : " << A << endl;
			cout << " ------------------------ " << endl;
		}

		infile >> stuID >> P >> A;
	}

	system("pause");

	infile.close();
}




