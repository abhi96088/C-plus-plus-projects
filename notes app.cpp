// Program for a Notepad Application

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to write text to a file
void writeToFile(const string &filename) {
    ofstream file(filename.c_str(), ios::app); // Convert string to C-style string for compatibility
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "Enter text to add to the file (type END to stop): " << endl;
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break; // Stop writing when user types "END"
        file << line << endl;
    }

    file.close();
    cout << "Text written to " << filename << " successfully!" << endl;
}

// Function to read and display contents of a file
void readFromFile(const string &filename) {
    ifstream file(filename.c_str()); 
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "Contents of " << filename << ":" << endl; 
    string line;
    while (getline(file, line)) { // Read file line by line
        cout << line << endl;
    }
    file.close();
}

// Function to clear the contents of a file
void clearFile(const string &filename) {
    ofstream file(filename.c_str(), ios::trunc); 
    file.close();
    cout << "File contents cleared successfully!" << endl;
}

int main() {
    string filename = "notes.txt"; // Default file name
    int choice;

    do {
        cout << "\nNotepad Application" << endl;
        cout << "1. Write to File" << endl;
        cout << "2. Read from File" << endl;
        cout << "3. Clear File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character to avoid input issues

        switch (choice) {
            case 1:
                writeToFile(filename); 
                break;
            case 2:
                readFromFile(filename); 
                break;
            case 3:
                clearFile(filename); 
                break;
            case 4:
                cout << "Exiting..." << endl; 
                break;
            default:
                cout << "Invalid choice!" << endl; 
        }
    } while (choice != 4); 

    return 0;
}

