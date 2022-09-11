#include <stdio.h>


int main(){
    int nums[21];
    int i = 0, tmp;
    FILE *f;

    while (1){
        if(i==20){
            break;
        }
        printf("Give number %d(negative numer to stop):\n", i+1);
        scanf("%d", &tmp);
        if(tmp < 0){
            break;
        } else{
            nums[i] = tmp;
        }
        i++;
    }

    f = fopen("numbers.txt", "w");
    
    for(int j = 0; j < i; j++){
        fprintf(f,"%d ", nums[j]);
    }
    fclose(f);

    return 0;
}