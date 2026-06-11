#include <stdio.h>
#include <stdint.h>
int32_t multiply(int *pn1, int *pn2){
	
	int32_t mul;
	mul = *pn1 * *pn2;
	
	return mul;

}

int main(){
	
	int32_t result;
	int32_t num1,num2;
	num1 = 5;
	num2 = 5;
	result = multiply(&num1,&num2);
	printf("number 1 = %d, number 2 = %d \nmultiplication is = %d\n",num1,num2,result);
	return 0;

}
