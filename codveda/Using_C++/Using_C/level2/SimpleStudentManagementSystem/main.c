#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int grade;
    int id;
};

struct Student s[100];
int studentCount = 0;

void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < studentCount; i++) {
            fprintf(file, "%s,%d,%d\n", s[i].name, s[i].grade, s[i].id);
        }
        fclose(file);
    }
}

void readFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file != NULL) {

        while (fscanf(file, " %[^,],%d,%d\n", s[studentCount].name, &s[studentCount].grade, &s[studentCount].id) == 3) {
            studentCount++;
            if (studentCount >= 100) break;
        }
        fclose(file);
    }
}

void addStudent() {
    printf("\n-Adding a new student-\n");
    printf("\nID assigned automatically:");
    if (studentCount == 0) {
        s[studentCount].id = 1;
    } else {
        s[studentCount].id = s[studentCount - 1].id + 1;
    }
    printf("%d\n", s[studentCount].id);

    printf("Enter student name: ");
    scanf("%s", s[studentCount].name);

    printf("Enter student grades: ");
    scanf("%d", &s[studentCount].grade);

    studentCount++;
    saveToFile();
}

void deleteStudent() {
    printf("\n-Deleting a student-\n");
    int id;
    printf("\nEnter student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (s[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                s[j] = s[j + 1];
            }
            studentCount--;
            saveToFile();
            printf("Student with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void displayStudents() {
    printf("\n-Displaying all students-\n");
    printf("\nTotal students: %d\n", studentCount);
    printf("ID\t\tName\t\tGrade\n\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t\t%s\t\t%d\n", s[i].id, s[i].name, s[i].grade);
    }
}

int main() {

    readFromFile();

    if (studentCount == 0) {
        strcpy(s[0].name, "Amr");
        s[0].grade = 99;
        s[0].id = 1;

        strcpy(s[1].name, "Zeinab");
        s[1].grade = 98;
        s[1].id = 2;

        studentCount = 2;
        saveToFile();
    }

    int choice;
    do {
        printf("\n---Student Management System---\n\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
