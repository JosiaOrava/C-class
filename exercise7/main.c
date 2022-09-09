#include <stdio.h>



void uppercase(char *x){

    *x = toupper(x[0]);
}

int main(){
    char str[100];

    while (1){
        printf("Enter string:\n");
        scanf("%s", &str);
        if(str == 'stop' || str == 'STOP'){
            break;
        }

        uppercase(&str);

        printf("%s\n", str);
    }
    


    return 0;
}