#include <stdio.h>
#include <time.h>

void createFile(){
    // Creates file with 100 random numbers
    srand(time(NULL));
    FILE* f;
    f = fopen("numbers.txt", "w");
    
    for(int j = 0; j < 100; j++){
        fprintf(f,"%d\n", rand() % 100);
    }
    fclose(f);
}

void readFile(int arr[]){
    FILE* f;
    f = fopen("numbers.txt", "r");
    for(int i = 0; i<100; i++){
        fscanf(f, "%d\n", &arr[i]);
    }
    fclose(f);
}

void writeNewFile(float avg, int arr[]){
    FILE *f;
    f = fopen("average.txt", "w");
    fprintf(f,"There were 100 numbers and average was: %.2f\n", avg);
    for(int i = 0; i<100; i++){
        fprintf(f, "%d\n", arr[i]);
    }
    fclose(f);
}

int main(){
    int arr[100];
    int sum = 0;
    float avg;

    createFile();
    readFile(arr);

    for(int i = 0; i<100; i++){
        sum += arr[i];
    }
    avg = (float)sum / 100;
    
    writeNewFile(avg, arr);

    return 0;
}