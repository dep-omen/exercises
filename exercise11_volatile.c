#include <signal.h>
#include <stdio.h>
#include <stdint.h>

volatile uint8_t flag; 

volatile uint32_t counter;
void interrupt(){

    flag = 1;
    counter = counter + 1;
    
}


int main(){


    signal(SIGALRM, interrupt);

    for(uint8_t i=5;i>0;i--){

        raise(SIGALRM);
        if(flag==1){
            printf("\nInterrupt Fired ! Counter = %d ",counter);
            flag = 0;
        }
    }

    printf("\nTotal Interrupts = %d \n",counter);

    return 0;

}