#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write(const string& filename) {
    ofstream outFile(filename, ios::trunc); // Open file in write mode (overwrite)
    if (!outFile) {
        cerr << "Error opening file for writing!\n";
        return;
    }
    string data;
    cout << "Enter text to write to file (end with an empty line):\n";
    cin.ignore();
    while (true) {
        getline(cin, data);
        if (data.empty()) break;
        outFile << data << endl;
    }
    outFile.close();
    cout << "Data written successfully.\n";
}

void append(const string& filename) {
    ofstream outFile(filename, ios::app); // Open file in append mode
    if (!outFile) {
        cerr << "Error opening file for appending!\n";
        return;
    }
    string data;
    cout << "Enter text to append to file (end with an empty line):\n";
    cin.ignore();
    while (true) {
        getline(cin, data);
        if (data.empty()) break;
        outFile << data << endl;
    }
    outFile.close();
    cout << "Data appended successfully.\n";
}

void read(const string& filename) {
    ifstream inFile(filename); // Open file in read mode
    if (!inFile) {
        cerr << "Error opening file for reading!\n";
        return;
    }
    string data;
    cout << "File contents:\n";
    while (getline(inFile, data)) {
        cout << data << endl;
    }
    inFile.close();
}

int main() {
    string filename = "data.txt";
    int ch;
    do {
        cout << "\nFile Operations Menu:\n";
        cout << "1. Write to File (Overwrite)\n";
        cout << "2. Append to File\n";
        cout << "3. Read from File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch (choice) {
            case 1:
                write(filename);
                break;
            case 2:
                append(filename);
                break;
            case 3:
                read(filename);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (ch != 4);
    
    return 0;
}
