#include <stdio.h>
#include <time.h>

struct student{
    char name[20];
    int sNumber;
    char address[100];
    char *city;
    int creditsTotal;
};

int findStudent(struct student *st, char city[]){
    int count = 0;
    for(int i = 0; i<8; i++){
        if(strcmp(st[i].city, city) == 0){
            count++;
        }
    }

    return count;
}

int main(){
    int number;
    srand(time(NULL));
    
    char ct[100];
    char stop[5] = {"stop"};
    struct student st[16];
    char cities[5][100] = {"Helsinki", "Vantaa", "Espoo", "Hanko"};

    for(int i = 0; i<8; i++){
        st[i].city = cities[rand() % 4];
    }
    while(1){
        printf("Give city (Helsinki, Vantaa, Espoo, Hanko)\n");
        scanf("%s", &ct);
        number = findStudent(st, ct);
        if(strncmp(ct, stop, 4) == 0){
            break;
        }
        else if(number == 0){
            printf("No students live in the given city.\n");
        } else{
            printf("Number of students in %s: %12.d\n", ct, number);
        }
    }
    
    return 0;
}