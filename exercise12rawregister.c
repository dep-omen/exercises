// #include <stdio.h>
// #include <stdint.h>
// #include <string.h>

// #define RCC_AHB4ENSETR (*(volatile uint32_t*) (0x50000000+0xA28))
// #define GPIOH_BASE 0x50009000
// #define GPIOH_MODER (*(volatile uint32_t* ) (GPIOH_BASE + 0x00))
// #define GPIOH_BSRR (*(volatile uint32_t* ) (GPIOH_BASE + 0x18))


// void delay(){
    
//     for(volatile uint32_t i = 0; i < 100000; i++){
//         //wait
//     }

// }

// int main(){

//     RCC_AHB4ENSETR |= (1<<7);
//     GPIOH_MODER |= (1<<14); 
//     GPIOH_MODER &=~ (1<<15);

//     while(1){

//         for(uint32_t i = 0; i<5; i++){

//             GPIOH_BSRR = (1<<7);
            
//             delay();

//             GPIOH_BSRR = (1<<23);

//             delay();

//         }
//     }

//     return 0;

// }

#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(){

    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd!=-1){
        printf("Memory accessed\n");
    }
    else
         printf("Cannot access memory\n");
    return 0;

}