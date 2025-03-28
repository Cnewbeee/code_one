#include <stdio.h>
#include <string.h>

typedef struct {
    char student_id[11]; 
    char name[21];       
    int score;           
} Student;

int main() {
    int n;
    scanf("%d", &n);

    Student students[n]; 
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", students[i].student_id, students[i].name, &students[i].score);
    }

    Student target_student;
    scanf("%s %s %d", target_student.student_id, target_student.name, &target_student.score);

    int left = 0, right = n - 1;
    int mid, found = -1;

    while (left <= right) {
        mid = (left + right) / 2;
        printf("%d ", mid); 
        int cmp = strcmp(students[mid].student_id, target_student.student_id);
        if (cmp == 0) {
            found = mid;
            break;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("\n");

    if (found != -1) {
        if (students[found].score == target_student.score) {
            printf("F %d\n", found);
        } else {
            students[found].score = target_student.score;
            printf("U %d\n", found);
        }
    } else {
        for (int i = n; i > left; i--) {
            students[i] = students[i - 1];
        }
        students[left] = target_student;
        printf("I %d\n", left);
    }

    return 0;
}
