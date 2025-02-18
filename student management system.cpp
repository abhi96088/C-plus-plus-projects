#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Structure to store student details
struct Student {
    string name;
    int rollNumber;
    float marks;
};

// Function to add a student record
void addStudent() {
    Student student;
    cout << "Enter Student Name: ";
    cin.ignore(); // Ignore leftover newline character
    getline(cin, student.name);
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Marks: ";
    cin >> student.marks;

    // Write to file
    ofstream file("students.txt", ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << student.name << "," << student.rollNumber << "," << student.marks << endl;
    file.close();
    cout << "Student record added successfully!\n";
}

// Function to display all students
void viewStudents() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }
    
    string line;
    cout << "\nStudent Records:\n";
    cout << "-----------------------------------------\n";
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int roll;
        float marks;
        getline(ss, name, ',');
        ss >> roll;
        ss.ignore();
        ss >> marks;
        
        cout << "Name: " << name << ", Roll No: " << roll << ", Marks: " << marks << endl;
    }
    cout << "-----------------------------------------\n";
    file.close();
}

// Function to search for a student by roll number
void searchStudent() {
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;

    ifstream file("students.txt");
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int rollNo;
        float marks;
        getline(ss, name, ',');
        ss >> rollNo;
        ss.ignore();
        ss >> marks;

        if (rollNo == roll) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << name << "\nRoll Number: " << rollNo << "\nMarks: " << marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << roll << " not found!\n";
    }

    file.close();
}

// Function to delete a student record
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    ifstream file("students.txt");
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }

    vector<string> records;
    string line;
    bool deleted = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int rollNo;
        float marks;
        getline(ss, name, ',');
        ss >> rollNo;
        ss.ignore();
        ss >> marks;

        if (rollNo == roll) {
            deleted = true;
        } else {
            records.push_back(line);
        }
    }
    file.close();

    if (deleted) {
        ofstream outFile("students.txt");
        for (size_t i = 0; i < records.size(); i++) {
    		outFile << records[i] << endl;
		}


        outFile.close();
        cout << "Student record deleted successfully!\n";
    } else {
        cout << "Student with Roll Number " << roll << " not found!\n";
    }
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

