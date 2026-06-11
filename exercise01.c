#include <stdio.h>
#include <stdint.h>
int main(){

	int32_t num1,num2;
	float avg;
	
	num1 = 5;
	num2 = 2;
	
	avg = ((float)num1+num2)/2.0f;

	printf("number 1 = %d, number 2 = %d\n avg = %f\n",num1,num2,avg);

	return 0;
}
