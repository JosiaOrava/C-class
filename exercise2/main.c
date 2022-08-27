#include <stdio.h>

int main(){
    float salaries[12];
    int x = 0;
    float sum = 0;
    while(x < 12){
        printf("Give month %d salarie: ", x+1);
        fflush(stdin);
        scanf("%f", &salaries[x]);
        x++;
    }
    for (int i = 0; i < 12; i++){
        if (i < 9){
            printf("month[ %d] %*s  %10.2f\n", i+1, 2, "=", salaries[i]);
        } else{
            printf("month[%d] %*s  %10.2f\n", i+1, 2, "=", salaries[i]);
        }
        sum = sum + salaries[i];
    }
    printf("total %*s %11.2f",6,"=", sum);
    return 0;
}