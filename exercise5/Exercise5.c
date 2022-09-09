#include <stdio.h>
#include <string.h>

void strReplace(char * str){
    char tmp[2] = "_";
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' '){
            str[i] = tmp[0];
        }
    }
}

int main(){
    char str[100];
    char stp[5] = "stop", stp2[5] = "STOP";
    while(1){
        printf("Enter string\n");
        fgets(str, 100, stdin);
        if(strncmp(str, stp, 4) == 0 || strncmp(str, stp2, 4) == 0){
            break;
        }else{
            strReplace(str);
            printf("%s", str);
        }
        
    }
    
    return 0;
}