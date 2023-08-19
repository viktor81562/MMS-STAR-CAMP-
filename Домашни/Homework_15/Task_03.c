#include <stdio.h>
#include <string.h>

struct Student {
    char name[16];
    double avg_grade;
};

int main() {
    FILE* f1 = fopen("students.bin", "rb"); 

    if (!f1) {
        perror("Error opening file");
        return 1;
    }

    struct Student students[1000];
    size_t num_students = fread(students, sizeof(struct Student), 1000, f1); 
    if (num_students != 1000) {
        perror("Error reading data");
        fclose(f1);
        return 1;
    }

    fclose(f1);

    double highest_avg_grade = 0;
    struct Student highest_avg_student;

    for (size_t i = 0; i < num_students; i++) {
        if (students[i].avg_grade > highest_avg_grade) {
            highest_avg_grade = students[i].avg_grade;
            highest_avg_student = students[i];
        }
    }

    printf("Student with highest avg_grade:\n");
    printf("Name: %s\n", highest_avg_student.name);
    printf("Avg Grade: %.2f\n", highest_avg_student.avg_grade);

    return 0;
}
