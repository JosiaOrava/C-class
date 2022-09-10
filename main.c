#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    char num[] = "";
    char num2[] = "";
    sprintf(num, "%d", x);
    sprintf(num2, "%d", x);
    

    strrev(num2);
    if(strcmp(num, num2)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int x = 121;
    isPalindrome(x);
    return 0;
}