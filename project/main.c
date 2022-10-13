#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define WEEKDAYS 5
#define CHARAMMOUNT 50
#define ROW_DATA 500

int checkTime(int time){
    // This checks users entered time and based on that
    // it returns the row number that we want to edit
    int row;
    if(time == 9){
        row = 2;
    } else if(time == 10){
        row = 4;
    } else if(time == 11){
        row = 6;
    } else if(time == 12){
        row = 8;
    } else if(time == 13){
        row = 10;
    } else if(time == 14){
        row = 12;
    } else if(time == 15){
        row = 14;
    } else if(time == 16){
        row = 16;
    } else if(time == 17){
        row = 18;
    } else if(time == 18){
        row = 20;
    } else{
        printf("Time not correct.\n");
    }
    return row;
}
int checkDay(char *day){
    // Check users entered weekday and based on that return
    // column number that we want to edit in csv file
    char wkDays[WEEKDAYS][CHARAMMOUNT] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int dayCol;
    if(strcmp(day,wkDays[0]) == 0){
        dayCol = 0;
    } else if(strcmp(day,wkDays[1]) == 0){
        dayCol = 1; 
    } else if(strcmp(day,wkDays[2]) == 0){
        dayCol = 2;
    } else if(strcmp(day,wkDays[3]) == 0){
        dayCol = 3;
    } else if(strcmp(day,wkDays[4]) == 0){
        dayCol = 4;
    } else{
        printf("Day not correct.");
    }
    return dayCol;
}

void addClass(int time,char *day, char *name, char *room){
    FILE *f;
    FILE *fTemp;

    f = fopen("data.csv", "r");
    fTemp = fopen("tmp.csv", "w");

    // we save class name and room number later to these
    char *arrayClass[6] = {" ", " ", " ", " ", " ", " "};
    char *arrayRoom[6] = {" ", " ", " ", " ", " "," "};

    if(!f){
        printf("Can't open file\n");
    }
    else{
        char buffer[1024];
        int row,column;
        int tmpRow = 0;
        char rowData[ROW_DATA];
        char *token;

        row = checkTime(time);
        column = checkDay(day);
        
        while(fgets(rowData, ROW_DATA, f)){
            // Loop trough the file until we get to the row we want to edit
            if(tmpRow == row-1){
                token = strtok(rowData, ",");
                int j = 0;
                while(token != NULL){
                    arrayClass[j] = token;
                    j++;
                    token = strtok(NULL, ",");
                }
                for(int i = 0; i<5; i++){
                    if(i == column){
                        arrayClass[i+1] = name;
                    }
                }       
                // Print the class name and room arrays into file if it's the right row
                fprintf(fTemp,"%d:00,%s,%s,%s,%s,%s,\n", time, arrayClass[1], arrayClass[2], arrayClass[3], arrayClass[4], arrayClass[5]);
                
            } else if(tmpRow == row){
                token = strtok(rowData, ",");
                int x = 0;
                while(token != NULL){
                    arrayRoom[x] = token;
                    x++;
                    token = strtok(NULL, ",");
                }
                for(int k = 0; k<5; k++){
                    if(k == column){
                        arrayRoom[k+1] = room;
                    }
                }    
                fprintf(fTemp," ,%s,%s,%s,%s,%s,\n", arrayRoom[1], arrayRoom[2], arrayRoom[3], arrayRoom[4], arrayRoom[5]);
            }else{
                // else just print data that is alredy there / empty data 
                fprintf(fTemp, rowData);
            }
            tmpRow++;
        }
        // Close files and open data.csv file in w and tmp.csv in r
        // because we have written user entered data into the tmp.csv file
        // and now we want it into the data.csv file

        // We can't write into data.csv file straight earlier because then we would lose data 
        // that is saved alredy there
        fclose(fTemp);
        fclose(f);
        f = fopen("data.csv", "w");
        fTemp = fopen("tmp.csv", "r");
        while(fgets(rowData, ROW_DATA, fTemp)){
            fprintf(f, rowData);
        }
    }
    fclose(fTemp);
    fclose(f);
}

void iniDatabase(){
    FILE *f;
    FILE *fIni;

    f = fopen("data.csv", "w");
    fIni = fopen("database_ini.csv", "r");

    // Empty the database by simply copying empty db template
    if(!f || !fIni){
        printf("ERROR: Can't open file.\n");
    } else{
        char rowData[ROW_DATA];
        while(fgets(rowData, ROW_DATA, fIni)){
            fprintf(f, rowData);
        }
    }

   fclose(f);
   fclose(fIni);
}

void printDatabase(){
    FILE *f;
    f = fopen("data.csv", "r");
    char row[ROW_DATA];

    while(fgets(row, sizeof(row), f)){
        char *token;

        // Slash our row to tokens by "," so we can format it easier in print
        token = strtok(row, ",");

        while(token != NULL){
            printf("%-12s", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(f);
}

void delClass(char *day, int time){
    FILE *f;
    FILE *fTemp;

    f = fopen("data.csv", "r");
    fTemp = fopen("tmp.csv", "w");
    
    if(!f){
        printf("Can't open file.");
    } else{
        char buffer[1024];
        int row,column;
        int tmpRow = 0;
        char rowData[ROW_DATA];

        row = checkTime(time);
        column = checkDay(day);
        while(fgets(rowData, ROW_DATA, f)){
            if(tmpRow == row-1){
                fprintf(fTemp, "%d:00, , , , , ", time);
                fprintf(fTemp, " , , , , , ");
            } else{
                fprintf(fTemp, rowData);
            }
            tmpRow++;
        }
        fclose(f);
        fclose(fTemp);
        f = fopen("data.csv", "w");
        fTemp = fopen("tmp.csv", "r");
        while(fgets(rowData, ROW_DATA, fTemp)){
            fprintf(f, rowData);
        }
    }
    fclose(f);
    fclose(fTemp);
}


int main(){
    int time, choice;
    char day[CHARAMMOUNT];
    char name[CHARAMMOUNT];
    char classroom[CHARAMMOUNT];
    
    
    while(true){
        printf("Do you want to: Add class (1) | Remove class: (2) | Empty Database (3) | Print Database (4) | Stop (5)\n");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Give class: time, day, name, classroom\n");
            scanf("%d", &time);
            scanf("%s", day);
            scanf("%s", name);
            scanf("%s", classroom);
            addClass(time,day,name,classroom);
        } else if(choice == 2){
            printf("Give day and time:\n");
            scanf("%s", day);
            scanf("%d", &time);
            delClass(day, time);
        } else if (choice == 3){
            printf("Emptying database...");
            iniDatabase();
        } else if(choice == 4){
            printDatabase();
        } else if(choice == 5){
            break;
        } else{
            printf("Give proper number.");
        }
    }
    return 0;
}