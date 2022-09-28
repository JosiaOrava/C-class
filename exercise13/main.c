#include <stdio.h>
#include <string.h>
#define ARR_SIZE 100

struct items{
    char name[50];
    float price;
    int count;
};


int itemTotal(struct items *item, int *lines,const char *filename){
    FILE *f;
    f = fopen(filename, "r");
    char str[500], itemName[ARR_SIZE];
    float itemPrice;
    int itemCount = 0, total = 0, i=0;
    while(fgets(str,500,f)){
        sscanf(str,"%f;%[^;];%d", &itemPrice, itemName, &itemCount);
        total += itemCount;
        *lines += 1;
        strcpy(item[i].name, itemName);
        item[i].price = itemPrice;
        item[i].count = itemCount;
        i++;
    }

    fclose(f);
    
    return total;
}

int main(){
    struct items item[ARR_SIZE];
    int itemTotalCount, lineCount = 0;
    char filename[50];

    printf("Give filename: ");
    scanf("%s", &filename);

    filename[strcspn(filename, "\n")] = '\0';
    itemTotalCount = itemTotal(item, &lineCount, filename);

    printf("Lines read: %d\nTotal number of items: %d", lineCount, itemTotalCount);
    printf("\nName: %s Price: %.2f Count: %d", item[0].name, item[0].price, item[0].count);
    return 0;
}