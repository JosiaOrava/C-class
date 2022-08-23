#include <stdio.h>

int main(){
    float salaries[12];
    int x = 0;
    float sum = 0;
    char equal = "=";
    while(x < 12){
        printf("Give month %d salarie: ", x);
        fflush(stdin);
        scanf("%.2f", &salaries[x]);
        x++;
    }
    for (int i = 0; i < 12; i++){
        printf("month[ %d] %3.c  %10.2f\n", i, equal, salaries[i]);
        sum = sum + salaries[i];
    }
    printf("%.2f", sum);

    return 0;
}