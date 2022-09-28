#include <stdio.h>
#include <stdbool.h>


void readFile(char *filename, int lineNumber){
    FILE *f;
    f = fopen(filename, "r");
    char line[300], c;
    int tmp = 1, lineCount = 1;
    bool printed = false;
    //count how many lines are in file
    for (c = getc(f); c != EOF; c = getc(f)){
        if (c == '\n'){
            lineCount++;
        }      
    }
    fclose(f);
    f = fopen(filename, "r");
    if(f != NULL){
        if(lineNumber < 0){
            printf("\nGive number above 0\n");
        }
        while(fgets(line, sizeof(line), f)){
            //count to the given line number and if linenumber is <= linecount 
            //then start to print from there. else give error
            if(tmp < lineNumber){
                tmp++;
            } else if(tmp == lineNumber && lineNumber <= lineCount){
                printf("%s", line);
                printed = true;
            } 
        }
        if(printed == false){
            printf("\nERROR: File %s does not have %d lines\n", filename, lineNumber);
        }      
    } else{
        printf("\nERROR: Give proper filename\n");
    }
    fclose(f);
} 

int main(){
    char file[50], stop[5] = {"stop"};
    int line;
    while(1){
        printf("\nGive filename: ");
        scanf("%s", file);
        if(strncmp(file, stop, 4) == 0){
            break;
        }
        printf("Give line number: ");
        scanf("%d", &line);
        readFile(file, line);
    }

    return 0;
}