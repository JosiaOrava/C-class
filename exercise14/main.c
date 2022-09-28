#include <stdio.h>

void writeFile(){
    FILE *f;
    f = fopen("students.dat", "ab+");
    char name[50], address[50], city[50], stop[] = "stop";
    int stNumber, credits;
    while(1){
        printf("Give student name: ");
        scanf("%s", name);
        if(strncmp(name, stop, 4) == 0){
            break;
        } else{
            printf("Give student number: ");
            scanf("%d", &stNumber);
            printf("Give street address: ");
            scanf("%s", address);
            printf("Give city: ");
            scanf("%s", city);
            printf("Give number of credits: ");
            scanf("%d", &credits);
            
            fprintf(f,"Name: %s | student number: %d | address: %s | city: %s | credits: %d\n", name, stNumber, address, city, credits);

        }
    }
    fclose(f);
}

void openFile(){
    FILE *f;
    f = fopen("students.dat", "rb");
    char line[500];
    while(fgets(line, sizeof(line), f)){
        printf("%s", line);
    }
    fclose(f);
}

int main(){
    int tmp;
    printf("Do you want to write (1) or read (2) file? ");
    scanf("%d", &tmp);
    if(tmp == 1){
        writeFile();
    } else if(tmp == 2){
        openFile();
    }
    return 0;
}