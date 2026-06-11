#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct Sensor{
    char name[20];
    int32_t id; 
    float value;
};

void print_sensor(struct Sensor *s){

    printf("%d\n", s->id);
    printf("%s\n", s->name);
    printf("%f\n", s->value);

}

int main(){

    struct Sensor S1,S2;
    S1.id = 1;
    strcpy(S1.name, "Temp");
    S1.value = 56.4;
    S2.id = 2;
    strcpy(S2.name, "Pressure");
    S2.value = 251.5;

    print_sensor(&S1);
    print_sensor(&S2);
    return 0;

}