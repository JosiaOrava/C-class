#include <stdio.h>


void encrypt(char * x){
    char alphRev[27] =  {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    char alph[27] =     {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 

    // Go trough the array letter by letter and find index of letter from alphabet 
    // and use the same index finding corresponding letter from reversed alphabet    
    for (int i = 0; i < strlen(x); i++){
        for (int j = 0; j < strlen(alph); j++){
            if(x[i] == alph[j]){
                x[i] = alphRev[j];
                break;
            }
        }
    }
}


int main(){
    char str[100];

    printf("Give string:\n");
    scanf("%s", &str);
    printf("---------------\n");
    printf("This is the original string:\n");
    printf("%s\n", str);
    printf("This is encrypted string:\n");
    encrypt(str);
    printf("%s\n", str);
    printf("This is decrypted string:\n");
    encrypt(str);
    printf("%s", str);
    return 0;
}