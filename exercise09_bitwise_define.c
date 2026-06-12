#include <stdio.h>
#include <stdint.h>

#define GPIO_PIN_0 (1<<0)
#define GPIO_PIN_1 (1<<1)
#define GPIO_PIN_2 (1<<2)
#define GPIO_PIN_3 (1<<3)
#define GPIO_PIN_4 (1<<4)
#define GPIO_PIN_5 (1<<5)
#define GPIO_PIN_6 (1<<6)
#define GPIO_PIN_7 (1<<7)

void print_binary(uint8_t reg){
    for(int32_t i = 7; i >= 0; i--){ 
        printf("%d",(reg>>i)&1);
    }
     printf("\n");
}

int main(){

    uint8_t gpio_reg = 0x00;
    print_binary(gpio_reg);
    gpio_reg |= GPIO_PIN_0;
    gpio_reg |= GPIO_PIN_3;
    gpio_reg |= GPIO_PIN_7;
    print_binary(gpio_reg);
    gpio_reg &=~(GPIO_PIN_3);
    print_binary(gpio_reg);
    if(gpio_reg&(GPIO_PIN_7)){
        printf("PIN is HIGH\n ");
        print_binary(gpio_reg);
    }
    else{
        printf("PIN is LOW\n ");
        print_binary(gpio_reg);
    }

    return 0;
}