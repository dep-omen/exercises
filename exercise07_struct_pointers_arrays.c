#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct Sensor{
    char name[20];
    int32_t id; 
    float value;
};

void print_all(struct Sensor *s, int32_t size){

    for(int32_t i = 0;i<size;i++){

        printf("--- Sensor %d ---\n",s[i].id);
        printf("%d\n", s[i].id);
        printf("%s\n", s[i].name);
        printf("%f\n", s[i].value);

    }

}

int main(){

    struct Sensor S[3];
    S[0].id = 1;
    strcpy(S[0].name, "Temp");
    S[0].value = 56.4;
    S[1].id = 2;
    strcpy(S[1].name, "Pressure");
    S[1].value = 251.5;
    S[2].id = 3;
    strcpy(S[2].name, "Humidity");
    S[2].value = 55.20;

   struct Sensor *ps = S;
    print_all(ps,3);

    return 0;

}