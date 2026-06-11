    #include <stdio.h>
    #include <stdint.h>

    void fill_array(int32_t *arr, int32_t size){

    
        for(int32_t i=0;i<size;i++){
        
            printf("Enter number %d : ",i+1);
            if(scanf("%d",&arr[i])!=1){
                printf("Invalid Input");
            }
             
        }
      
        
    }

    void print_sum(int32_t *arr, int32_t size){

        int32_t sum = 0;
        for(int32_t i=0;i<size;i++){
            sum = sum + arr[i];
        }
        printf("Sum of elements of arrays is --> %d\n",sum);
    }

    int main(){
        
        int32_t j;
        printf("Enter the number of elements you want insert in the array --> ");
        scanf("%d",&j);
        int32_t a[j];
        int32_t *pa = a;
        
        

        fill_array(pa,j);
        print_sum(pa,j);

        return 0;
    }