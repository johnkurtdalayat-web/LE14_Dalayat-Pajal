#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    int idNumber, addMore;
    char completeName[100];
    char section[50];

    do {
        
        file = fopen("student_records.txt", "a+");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        
        printf("Enter Student Number: ");
        scanf("%d", &idNumber);
        getchar();
        
        printf("Enter Complete Name: ");
        fgets(completeName, sizeof(completeName), stdin);

        
        size_t len = strlen(completeName);
        if (len > 0 && completeName[len - 1] == '\n') {
            completeName[len - 1] = '\0';
        }

        printf("Enter Section: ");
        fgets(section, sizeof(section), stdin);

        len = strlen(section);
        if (len > 0 && section[len - 1] == '\n') {
            section[len - 1] = '\0';
        }

        fprintf(file, "ID Number: %d\n", idNumber);
        fprintf(file, "Complete Name: %s\n", completeName);
        fprintf(file, "Section: %s\n\n", section);

        printf("\nRecord added and saved successfully.\n\n");

        fclose(file);
        printf("Add another student? [Enter 1 for Yes, 0 for No]: ");
        scanf("%d", &addMore);
        getchar(); // to consume the newline character after scanf

    } while (addMore == 1);

    printf("All student records have been saved.\n");

    return 0;
}

