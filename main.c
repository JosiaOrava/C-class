#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
    int num[1000];
    int tmp, n, y, count = x;
    

    while(count > 0){
        int i = 0;
        tmp = count % 10;
        num[i] = tmp;
        count = count / 10;
        i++;
    }
    n = sizeof(num)/sizeof(num[0]);
    if(x < 0){
        return false;
    }
    else{
        for(int i = 0; i<n/2; i++){
            tmp = num[i];
            num[i] = num[n-i-1];
            num[n-i-1] = tmp;
        }
        for(int z = 0; z<n; z++){
            y += num[z];
        }
        if(y == x){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    int x = 121;
    isPalindrome(x);
    return 0;
}