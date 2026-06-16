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

void delay(){
    
    for(volatile uint32_t i = 0; i < 100000000; i++){
        //wait
    }

}

int main(){

    int fd = open("/dev/mem", O_RDWR | O_SYNC);
        if (fd==-1){
            printf("Cannot access memory\n");
            return 1;
        }
        printf("Memory accessed\n");
    void *gpioh_map = mmap(NULL, 0x1000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x50009000);
        if(gpioh_map==MAP_FAILED){
            printf("Failed to MMAP memory\n");
            return 1;
        }
        printf("Memory Mapped for GPIOH\n");

    volatile uint32_t *gpioh_bsrr = (volatile uint32_t *)((uint8_t *)gpioh_map + 0x18);
    volatile uint32_t *gpioh_moder = (volatile uint32_t *)((uint8_t *)gpioh_map + 0x00);

    void *rcc_map = mmap(NULL, 0x1000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x50000000);
        if(rcc_map==MAP_FAILED){
            printf("Failed to MMAP memory\n");
            return 1;
        }
        printf("Memory Mapped for RCC\n");

    volatile uint32_t *RCC_AHB4ENSETR = (volatile uint32_t *)((uint8_t *)rcc_map + 0xA28);
        
        *RCC_AHB4ENSETR |= (1<<7);
        *gpioh_moder |= (1<<14); 
        *gpioh_moder &=~ (1<<15);

        while(1){

        for(uint32_t i = 0; i<5; i++){

            *gpioh_bsrr = (1<<7);
            printf("LED ON\n");
            
            delay();

            *gpioh_bsrr = (1<<23);
            printf("LED OFF\n");
            delay();

        }
    }
    munmap(gpioh_map, 0x1000);
    munmap(rcc_map, 0x1000);
    close(fd);
    return 0;
}



