#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct File {
	char name[100];
	char content[1000];
};

bool createFile(File* file, const char* name, const char* content) {
	if (strlen(name) >= 100) {
		cout << "\nError: File name is too long!" << endl;
		return false;
	}
	strcpy_s(file->name, name);
	strcpy_s(file->content, content);
	return true;
}

void readFile(const File* file) {
	cout << "\n--- File Content ---" << endl;
	cout << "File Name: " << file->name << endl;
	cout << "Content: " << file->content << endl;
	cout << "--------------------" << endl;
}

void deleteFile(File* files, int& fileCount, const char* name) {
	cout << "\n--- Deleting File ---" << endl;
	bool found = false;
	for (int i = 0; i < fileCount; i++) {
		if (strcmp((files + i)->name, name) == 0) {
			found = true;
			for (int j = i; j < fileCount - 1; j++) {
				*(files + j) = *(files + j + 1);
			}
			fileCount--;
			cout << "\nFile '" << name << "' deleted successfully and system reorganized!" << endl;
			break;
		}
	}
	if (!found) {
		cout << "\nError: File not found!" << endl;
	}
}

void listFiles(const File files[], int fileCount) {
	if (fileCount == 0) {
		cout << "\nSystem is empty." << endl;
		return;
	}
	cout << "\nFiles in the system:" << endl;
	for (int i = 0; i < fileCount; ++i) {
		cout << i + 1 << ". " << files[i].name << endl;
	}
}

void saveToFileSystem(File files[], int fileCount) {
	ofstream outFile("filesystem_data.bin", ios::binary);
	if (outFile.is_open()) {
		outFile.write((char*)&fileCount, sizeof(int)); 
		outFile.write((char*)files, sizeof(File) * 10); 
		outFile.close();
	}
}

void loadFromFileSystem(File files[], int& fileCount) {
	ifstream inFile("filesystem_data.bin", ios::binary);
	if (inFile.is_open()) {
		inFile.read((char*)&fileCount, sizeof(int));
		inFile.read((char*)files, sizeof(File) * 10);
		inFile.close();
	}
}

void menuDrivenProgram() {
	File files[10];
	int fileCount = 0;
	loadFromFileSystem(files, fileCount);
	
	while (true) {
		cout << "\n\t----- Advanced File System Simulation -----\n" << endl;
		cout << "Menu:" << endl;
		cout << " 1. Create File" << endl;
		cout << " 2. Read File" << endl;
		cout << " 3. Delete File" << endl;
		cout << " 4. List Files" << endl;
		cout << " 5. Exit" << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: {
			if (fileCount >= 10) {
				cout << "\nError: Maximum file limit reached!" << endl;
				break;
			}
			char name[100], content[1000];
			cout << "\nEnter file name: ";
			cin.getline(name, sizeof(name));
			cout << "Enter file content: ";
			cin.getline(content, sizeof(content));
			if (createFile(&files[fileCount], name, content)) {
				fileCount++;
				cout << "File created successfully!" << endl;
			}
			break;
		}
		case 2: {
			char name[100];
			cout << "\nEnter file name to read: ";
			cin.getline(name, sizeof(name));
			bool found = false;
			for (int i = 0; i < fileCount; ++i) {
				if (strcmp(files[i].name, name) == 0) {
					readFile(&files[i]);
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "\nError: File not found!" << endl;
			}
			break;
		}
		case 3: {
			char name[100];
			cout << "\nEnter file name to delete: ";
			cin.getline(name, sizeof(name));
			deleteFile(files, fileCount, name);
			break;
		}
		case 4:
			listFiles(files, fileCount);
			break;
		case 5:
			saveToFileSystem(files, fileCount);
			cout << "\nExiting the program. Goodbye!" << endl;
			return;
		default:
			cout << "\nInvalid choice! Please try again." << endl;
		}
	}
}

int main()
{
	menuDrivenProgram();
	return 0;
}