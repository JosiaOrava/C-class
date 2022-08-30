#include <stdio.h>

float dotProduct(int vec1[],int vec2[]){
    float value;
    value = (vec1[0]*vec2[0]) + (vec1[1]*vec2[1]) + (vec1[2]*vec2[2]);

    return value;
}

int main(){
    int vec1[3], vec2[3];
    float value;

    printf("Give values for vector 1:\n");
    for (int i = 0; i < 3; i++){   
        scanf("%d", &vec1[i]);
    }

    printf("Give values for vector 2:\n");
    for (int x = 0; x < 3; x++){
        scanf("%d", &vec2[x]);
    }

    value = dotProduct(vec1, vec2);
    printf("Vector 1 values: %d, %d, %d\n", vec1[0], vec1[1], vec1[2]);
    printf("Vector 2 values: %d, %d, %d\n", vec2[0], vec2[1], vec2[2]);
    printf("Result is: %.2f", value);

    return 0;
}