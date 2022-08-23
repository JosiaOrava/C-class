#include <stdio.h>
#include <stdbool.h>

int main(){
    int sum = 0, count = 0;
    float average = 0;
    while (true){

        int number;
        printf("Give number: ");
        scanf("%d", &number);
        if(number < 0){
            printf("Number must be positive!\n");
        }
        else if (number == 0){
            break;
        }
        else{
            sum = sum + number;
            count++;
        }
    }
    average = sum / count;
    printf("Average is: %.2f", average);
    return 0;
}