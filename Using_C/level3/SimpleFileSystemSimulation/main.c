#include <stdio.h>
#include <stdlib.h>

typedef enum{false,true}bool;

struct File {
    char name[100];
    char content[1000];
};

bool createFile(struct File* file, const char* name, const char* content) {
    if (strlen(name) >= 100) {
        printf("\nError: File name is too long!\n");
        return false;
    }

    strncpy(file->name, name, sizeof(file->name) - 1);
    file->name[sizeof(file->name) - 1] = '\0';

    strncpy(file->content, content, sizeof(file->content) - 1);
    file->content[sizeof(file->content) - 1] = '\0';

    return true;
}


void readFile(const struct File* file) {
    printf("\n--- File Content ---\n");
    printf("File Name: %s\n", file->name);
    printf("Content: %s\n", file->content);
    printf("--------------------\n");
}

void deleteFile(struct File* files, int* fileCount, const char* name) {
    printf("\n--- Deleting File ---\n");
    bool found = false;
    for (int i = 0; i < *fileCount; i++) {
        if (strcmp((files + i)->name, name) == 0) {
            found = true;
            for (int j = i; j < *fileCount - 1; j++) {
                *(files + j) = *(files + j + 1);
            }
            (*fileCount)--;
            printf("\nFile '%s' deleted successfully and system reorganized!\n", name);
            break;
        }
    }
    if (!found) {
        printf("\nError: File not found!\n");
    }
}

void listFiles(const struct File files[], int fileCount) {
    if (fileCount == 0) {
        printf("\nSystem is empty.\n");
        return;
    }
    printf("\nFiles in the system:\n");
    for (int i = 0; i < fileCount; ++i) {
        printf("%d. %s\n", i + 1, files[i].name);
    }
}

void saveToFileSystem(struct File files[], int fileCount) {
    FILE* outFile = fopen("filesystem_data.bin", "wb");
    if (outFile != NULL) {
        fwrite(&fileCount, sizeof(int), 1, outFile);
        fwrite(files, sizeof(struct File), 10, outFile);
        fclose(outFile);
    }
}

void loadFromFileSystem(struct File files[], int* fileCount) {
    FILE* inFile = fopen("filesystem_data.bin", "rb");
    if (inFile != NULL) {
        fread(fileCount, sizeof(int), 1, inFile);
        fread(files, sizeof(struct File), 10, inFile);
        fclose(inFile);
    }
}


void menuDrivenProgram() {
    struct File files[10];
    int fileCount = 0;
    loadFromFileSystem(files, &fileCount);

    while (true) {
        printf("\n\t----- Advanced File System Simulation -----\n\n");
        printf("Menu:\n");
        printf(" 1. Create File\n");
        printf(" 2. Read File\n");
        printf(" 3. Delete File\n");
        printf(" 4. List Files\n");
        printf(" 5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("\nInvalid choice! Please try again.\n");
            continue;
        }
        getchar();

        switch (choice) {
        case 1: {
            if (fileCount >= 10) {
                printf("\nError: Maximum file limit reached!\n");
                break;
            }
            char name[100], content[1000];
            printf("\nEnter file name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;

            printf("Enter file content: ");
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = 0;

            if (createFile(&files[fileCount], name, content)) {
                fileCount++;
                printf("File created successfully!\n");
            }
            break;
        }
        case 2: {
            char name[100];
            printf("\nEnter file name to read: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;

            bool found = false;
            for (int i = 0; i < fileCount; ++i) {
                if (strcmp(files[i].name, name) == 0) {
                    readFile(&files[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("\nError: File not found!\n");
            }
            break;
        }
        case 3: {
            char name[100];
            printf("\nEnter file name to delete: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;

            deleteFile(files, &fileCount, name);
            break;
        }
        case 4:
            listFiles(files, fileCount);
            break;
        case 5:
            saveToFileSystem(files, fileCount);
            printf("\nExiting the program. Goodbye!\n");
            return;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}

int main() {
    menuDrivenProgram();
    return 0;
}
