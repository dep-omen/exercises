#include <stdio.h>
#include <stdint.h>


void print_binary(uint8_t reg){
    for(int32_t i = 7; i >= 0; i--){ 
        printf("%d",(reg>>i)&1);
    }
}

int main(){

    uint8_t reg = 0b00001111;  
    print_binary(reg);
 
    // reg = (1 << 5)|reg;
    reg |= (1 << 5); 
    printf("\n");
    print_binary(reg);

    reg &= ~( 1<<2 );
    printf("\n");
    print_binary(reg);
    printf("\n");
    if((reg&(1<<3))){
        printf("Bit is SET\n");
        print_binary(reg);
    }
    else{
        printf("\nBit is NOT SET\n");
        print_binary(reg);
    }
    printf("\n");
    return 0;

}