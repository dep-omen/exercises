#include <stdio.h>
#include <stdint.h>
int32_t multiply(int32_t n1, int32_t n2){
	
	int32_t mul;
	mul = n1 * n2;
	
	return mul;

}

int main(){
	
	int32_t result;
	int32_t num1,num2;
	int32_t n = 0;

	printf("How many times you want to perform multiplication --> ");
		if(scanf("%d", &n) != 1){
	 	        printf("Invalid input\n");
    			return 1;
		}

	for(int32_t i=1;i<=n;i++){

		printf("%d.\n",i);
		printf("Enter your first number  --> ");
		    if(scanf("%d", &num1) != 1){
                        printf("Invalid input\n");
                        return 1;
                }

		printf("Enter your second number --> ");
		    if(scanf("%d", &num2) != 1){
                        printf("Invalid input\n");
                        return 1;
                }

		result = multiply(num1,num2);
		printf("number 1 = %d, number 2 = %d \nmultiplication is = %d\n",num1,num2,result);

	}

	return 0;

}
