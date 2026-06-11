#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t a[5];
    int32_t j = 1;
    printf("Enter the five elements in the array --> \n");
    
    for(int32_t i=0;i<5;i++){
        
        printf("Enter number %d : ",j);
        if(scanf("%d",&a[i])!=1){
            printf("Invalid Input");
        }
        j++;
    }

    printf("\nReversed:\n");
    for(int32_t i=4;i>=0;i--){

        printf("%d\n",a[i]);

    }
    
    return 0;
}