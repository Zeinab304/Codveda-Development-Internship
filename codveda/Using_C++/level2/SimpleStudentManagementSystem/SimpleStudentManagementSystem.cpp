#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student {
	string name;
	int grade;
	int id;
};

Student s[100];
int studentCount = 0;

void saveToFile() {
	ofstream file("students.txt");
	if (file.is_open()) {
		for (int i = 0; i < studentCount; i++)
		file << s[i].name << "," << s[i].grade << "," << s[i].id << endl;
		file.close();
	}
}

void readFromFile() {
	ifstream file("students.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line));
		file.close();
	}
}

void addStudent() {
	cout << "\n-Adding a new student-" << endl;
	cout << "\nID assigned automatically:";
	if (studentCount == 0) {
		s[studentCount].id = 1;
	}
	else {
		s[studentCount].id = s[studentCount - 1].id + 1;
	}
	cout << s[studentCount].id << endl;
	cout << "Enter student name: ";
	cin >> s[studentCount].name;
	cout << "Enter student grades: ";
	cin >> s[studentCount].grade;
	studentCount++;
	saveToFile();
}

void deleteStudent() {
	cout << "\n-Deleting a student-" << endl;	
	int id;
	cout << "\nEnter student ID to delete: ";
	cin >> id;
	for (int i = 0; i < studentCount; i++) {
		if (s[i].id == id) {
			for (int j = i; j < studentCount - 1; j++) {
				s[j] = s[j + 1];
			}
			studentCount--;
			saveToFile();
			cout << "Student with ID " << id << " deleted." << endl;
			return;
		}
	}
	cout << "Student with ID " << id << " not found." << endl;
}

void displayStudents() {
	cout << "\n-Displaying all students-" << endl;
	cout << "\nTotal students: " << studentCount << endl;
	cout << "ID\t\tName\t\tGrade\n" << endl;
	for (int i = 0; i < studentCount; i++) {
		cout << s[i].id << "\t\t" << s[i].name << "\t\t" << s[i].grade << endl;
	}
}


int main() {

	readFromFile();

	if (studentCount == 0) {
		s[0].name = "Amr";
		s[0].grade = 99;
		s[0].id = 1;

		s[1].name = "Zeinab";
		s[1].grade = 98;
		s[1].id = 2;

		studentCount = 2;
		saveToFile();
	}

	int choice;
	do {
		cout << "\n---Student Management System---\n" << endl;
		cout << "1. Add Student" << endl;
		cout << "2. Delete Student" << endl;
		cout << "3. Display Students" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			displayStudents();
			break;
		case 4:
			cout << "\nExiting..." << endl;
			break;
		default:
			cout << "\nInvalid choice. Please try again." << endl;
		}
	} while (choice != 4);
	return 0;
}