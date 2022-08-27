#include <stdio.h>

float average(int grades[], int arrSize){
    int sum = 0;
    float avg = 0;
    for (int i = 0; i < arrSize; i++){
        sum += grades[i];
    }
    avg = (float)sum / arrSize;
    return avg;
}

int main(){
    int grades[100] = {0};
    int size = 0, grade;
    float avg;

    printf("How many students?\n");
    scanf("%d", &size);
    while (size > 100 || size < 1){
        printf("Give number between 1-100\n");
        printf("How many students?\n");
        scanf("%d", &size);
    }

    for (int i = 0; i < size; i++){
        printf("Grade for student nr:%d \n", i+45000);
        scanf("%d", &grade);
        while (grade < 0 || grade > 5){
            printf("Give number between 0-5.\n");
            printf("Grade for student nr: %d \n", i+45000);
            scanf("%d", &grade);
        }
        grades[i] = grade;
    }

    avg = average(grades, size);
    printf("Average of course grades is: %.1f", avg);
    return 0;
}