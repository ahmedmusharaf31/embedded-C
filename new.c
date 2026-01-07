#include <stdio.h>
#define OPERATION_MODE 1

int startMode_1(void){
    return 0;
}

int startMode_2(void){
    return 0;
}

int main(void){

    #if(OPERATION_MODE == 1)
        startMode_1();
    #elif(OPERATION_MODE == 2)
        startMode_2();
    
    #else
        #error OPERATION_MODE must be 1 or 2 

    #endif

    printf("Done!\n\n"); 
    
    return 0;
}
