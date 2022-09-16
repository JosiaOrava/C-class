#include <stdio.h>
#include <string.h>
#define ARR_SIZE 20

struct items{
    char name[50];
    float price;
};

void iniArr(struct items *item, int *count){
    char stop[5] = {"stop"};
    int tmp;
    while(1){
        fflush(stdin);
        tmp = *count;
        if(tmp >= ARR_SIZE){
            printf("Maximun list count reached.");
            break;
        }
        printf("Give item name: ");
        scanf("%[^\n]", &item[*count].name);
        if(strncmp(item[*count].name, stop, 4) == 0){
            break;
        }
        printf("Give item price: ");
        scanf("%f", &item[*count].price);
        *count += 1;
    }

}

void writeFile(struct items *item, int count){
    FILE * f;
    f = fopen("pricelist.txt", "w");
    for(int i = 0; i< count; i++){
        fprintf(f, "%.2f;%s\n", item[i].price, item[i].name);
    }
    fclose(f);
}

int main(){
    struct items item[ARR_SIZE];
    int count = 0;

    iniArr(item, &count);
    writeFile(item, count);
    return 0;
}