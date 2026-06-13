#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef enum{

    SENSOR_OFF,
    SENSOR_IDLE,
    SENSOR_ACTIVE,
    SENSOR_ERROR,

}SensorState;

typedef struct {

    int32_t id;
    float value;
    SensorState state;

}Sensor;

void print_sensor(Sensor *s,int32_t i){

    printf("\nSensor id %d",s[i].id);
    
    switch(s[i].state){
        case SENSOR_OFF:
            printf("\nSensor is OFF");
            break;
        case SENSOR_IDLE:
            printf("\nSensor is IDLE");
            break;
        case SENSOR_ACTIVE:
            printf("\nSensor is ACTIVE");
            break;
        case SENSOR_ERROR:
            printf("\nSensor has Error");
            break;
        default:
            printf("\n Invalid State");
            break;
    }
    
    printf("\nSensor value %f",s[i].value);

    printf("\n");

}

void sensor_init(Sensor *s,int32_t i){

    if(s[i].state==SENSOR_OFF){
        s[i].state = SENSOR_IDLE;
    }
    print_sensor(s,i);

}
void sensor_start(Sensor *s,int32_t i){

    if(s[i].state==SENSOR_IDLE){
        s[i].state = SENSOR_ACTIVE;
        print_sensor(s,i);
    }

}
void sensor_read(Sensor *s,int32_t i){
   
    if(s[i].state==SENSOR_ACTIVE){
        printf("\nEnter the sensor value --> ");
        scanf("%f",&s[i].value);
    }
    if(s[i].value<0||s[i].value>100){
        s[i].state=SENSOR_ERROR;
        printf("\nSensor value %f",s[i].value);
        print_sensor(s,i);
    }
    else{
        printf("\nSensor value %f",s[i].value);
        print_sensor(s,i);
    }

    
}
void sensor_reset(Sensor *s,int32_t i){
    
    s[i].value = 0.00;
    s[i].state = SENSOR_OFF;
    print_sensor(s,i);
    
}

int main(){

    int32_t i = 0;

    Sensor s[1];

    s[i].id = 001;
    s[i].state = SENSOR_OFF;
    s[i].value = 0;

    sensor_init(s,i);
    sensor_start(s,i);
    sensor_read(s,i);  
    sensor_reset(s,i);
    return 0;

}