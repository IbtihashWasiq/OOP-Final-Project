#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include"Header..h"

using namespace std;

//input operator for student.
istream& operator >> (istream& in, Student& obj) {

	//count number of lines and hence find latest student id number.
	obj.countLines();

	system("cls");
	cout << " ------------------------------------------------- " << endl;
	cout << "                 ENTER STUDENT DATA                " << endl;
	cout << " ------------------------------------------------- " << endl;
	cout << "Enter First Name              : "; in >> obj.firstName;
	cout << "Enter Second Name             : "; in >> obj.lastName;
	cout << "Enter Registration Date       : "; in >> obj.regDate;
	cout << "Enter Department              : "; in >> obj.DepartmentName;
	cout << "Enter Gender                  : "; in >> obj.gender;
	cout << "Enter Contact No.             : "; in >> obj.contactNo;
	cout << "Fee paid                      : "; in >> obj.feeStatus;
	cout << "Enter Blood Group             : "; in >> obj.BloodGroup;
	cout << "Enter Address                 : "; in >> obj.Address;
	obj.sID = obj.DepartmentName + "-" + to_string(obj.count);
	cout << "---------------------------------------------------" << endl;
	return in;
}

//input operator for Teacher.
istream& operator >> (istream& in, Teacher& obj) {

	//count number of lines and hence find latest student id number.
	//obj.countLines();

	system("cls");
	cout << " ------------------------------------------------- " << endl;
	cout << "                 ENTER TEACHER DATA                " << endl;
	cout << " ------------------------------------------------- " << endl;
	cout << "Enter First Name              : "; in >> obj.firstName;
	cout << "Enter Second Name             : "; in >> obj.lastName;
	cout << "Enter Department Name         : "; in >> obj.DepartmentName;
	cout << "Enter Registration Date       : "; in >> obj.regDate;
	cout << "Enter Gender                  : "; in >> obj.gender;
	cout << "Enter Contact No.             : "; in >> obj.contactNo;
	cout << "Enter Qualification           : "; in >> obj.Qualification;
	cout << "Enter Address                 : "; in >> obj.Address;
	cout << "Enter Username                : "; in >> obj.Username;
	cout << "Enter Password                : "; in >> obj.Password;
	obj.tID = obj.DepartmentName + "-" + to_string(obj.count);
	do {

		try {

			cout << "Re-enter Password             : "; in >> obj.confirmPassword;

			if (obj.Password != obj.confirmPassword) { throw(obj.confirmPassword); }
			else { cout << "Password Match! " << endl; }
		}

		catch (string pwd) {
			cout << "Wrong Password:  " << pwd << endl;
		}

	} while (obj.Password != obj.confirmPassword);

	cout << " ------------------------------------------------- " << endl;

	return in;
}

int main() {
	//Showing Main Screen.
	/*displayGraphic("flex.jpg");*/


	Student stu; Admin adm; Teacher teach;
	int choice = 0, choice2 = 0, ctrl = 1;

	while (ctrl == 1) {
		choice = 0;
		system("cls");
		cout << "\t\t\tFlex Management System" << endl;
		cout << "Enter 1 for Admin Module" << endl;
		cout << "Enter 2 for Teacher Module" << endl;
		cout << "Enter 3 for student Module" << endl;
		cout << "Enter 4 to Quit Program" << endl;
		cin >> choice;

		switch (choice) {
			//admin.
		case 1:
			//resetting choice2.
			choice2 = 0;

			cout << " -----------------------  \n Admin Module \n ----------------------- \n ";
			//admin login.
			if (adm.Login() == 1) {

				while (choice2 != 7) {
					//admin menu.
					choice2 = adm.Menu();

					switch (choice2) {

						//new student.
					case 1:
						cin >> stu;
						stu.saveData();
						break;
						////view studnets.
					case 2:
						stu.viewAllStudents();
						break;
						//edit student.
					case 3:
						stu.editStudent();
						break;
						//add teacher.
					case 4:
						cin >> teach;
						teach.saveData();
						break;
						//view teachers.
					case 5:
						teach.viewAllTeachers();
						break;
						//edit teacher.
					case 6:
						teach.editTeacher();
						break;
					case 7:
						cout << " ---------------  \n Admin Module \n Exited \n ---------------  \n";
						break;

						//admin choice2 switch.
					default:
						break;
					}
				}
			}
			else { }
			break;

			//Teacher.
		case 2:
			//resetting choice2.
			choice2 = 0;

			cout << " -----------------------  \n Teacher Module \n -----------------------  \n";
			//teacher login.
			if (teach.Login() == 1) {
				while (choice2 != 4) {
					//teacher menu.
					choice2 = teach.Menu();

					switch (choice2) {

						//view timetable.
					case 1:
						teach.viewTimeTable();
						break;
						//marks and grade.
					case 2:
						teach.AssignMarks();
						break;
						//attendance.
					case 3:
						teach.MarkAttendance();
						break;
					case 4:
						cout << " ---------------  \n Teacher Module \n Exited \n ---------------  \n";
						break;

						//teacher choice2 switch.
					default:
						break;
					}
				}
			}
			else {}
			break;

			//student.
		case 3:

			//resetting choice2.
			choice2 = 0;

			cout << " ----------------------- \n Student Module \n----------------------\n";
			//student login.
			if (stu.Login() == 1) {
				while (choice2 != 6) {
					//student menu.
					choice2 = stu.Menu();

					switch (choice2) {

					case 1:
						//attendance.
						stu.viewAttendance();
						break;
					case 2:
						//marks.
						stu.viewMarks();
						break;
					case 3:
						//grades.
						stu.viewGrades();
						break;
					case 4:
						//courses.
						stu.viewCourses();
						break;
					case 5:
						//fee status.
						stu.viewFeeStatus();
						break;
					case 6:
						cout << " ---------------  \n Student Module \n Exited \n ---------------  \n";
						break;

						//teacher choice2 switch.
					default:
						break;
					}
				}
			}
			else {  }
			break;

		case 4:
			cout << " -----------------------  \n Program Exited \n -----------------------  \n";
			ctrl = 0;
			break;

			//choice switch.
		default:
			cout << " -----------------------  \n Invalid Input \n ----------------------- \n";
				ctrl = 0;
			break;
		}
	}
	return 0;
}