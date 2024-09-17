#include <stdio.h>

int main(){
    int num;
    float decimal;
    printf("Please enter an integer and a floating-point number: ");
    scanf("%d %f", &num, &decimal);
    printf("You entered number as: %d and float as: %f",num, decimal);
    return 0;
}