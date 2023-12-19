

#include <string>
using namespace std;

class Admin {

	string ID;
	string Password;

protected:
	int marks, P, A;
	string stuID, courseName;
	char grade;

public:
	Admin();
	virtual bool Login();
	virtual int Menu();
	virtual void countLines() {};


	
};


class Student : public Admin 
{

	string firstName, lastName, DepartmentName, regDate;
	char gender;
	string contactNo, BloodGroup, Address;
	bool feeStatus;
	int marks;
	string sID;
	int count;

	string loggedIn;

public:

	Student();

	friend istream& operator >> (istream& in, Student& obj);

	bool Login();
	int Menu();
	void saveData();
	void viewAllStudents();
	void editStudent();
	void DisplayRollNo();
	void countLines();
	void viewMarks();
	void viewGrades();
	void viewCourses();
	void viewFeeStatus();
	void viewAttendance();

	
};



class Teacher : public Admin
{

	string firstName, lastName, DepartmentName, regDate;
	string Username, Password, confirmPassword;
	char gender;
	string Qualification, Address;
	string tID, contactNo;
	int count;

	string loggedIn;


public:

	Teacher();

	friend istream& operator >> (istream& in, Teacher& obj);

	bool Login();
	int Menu();

	void saveData();
	void viewAllTeachers();
	void editTeacher();
	void DisplayTeacherID();
	void countLines();
	void MarkAttendance();
	void AssignMarks();
	void AssignGrade();

	void viewTimeTable();


};



