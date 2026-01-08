#include <stdio.h>
#define OPERATION_MODE 1

/* Preprocessor Directives */

int startMode_1(void){
    return 0;
}

int startMode_2(void){
    return 0;
}

// int main(void){

//     #if(OPERATION_MODE == 1)
//         startMode_1();
//     #elif(OPERATION_MODE == 2)
//         startMode_2();
    
//     #else
//     /* Display error message and stop process */
//     #error OPERATION_MODE must be 0 or 1 

//     #endif
    
//     return 0;
// }


/* Code Compilation Process */

#define IN_DEBUG_MODE 0
// for gcc compiler:
#pragma optimize("",off)

// for ghs compiler:
#pragma ghs section ".bss"=".mySection"
int myArray[1000]; // it will put this array in section called ".mySection" in memory
#pragma ghs section

#define MAX(a,b) ((a)>(b))?(a):(b)

// void testFunction(void){
//     #ifdef IN_DEBUG_MODE
//         printf("DEBUG: entered testFunction\n");
//     #endif
// }

void testFunction(void){
    #ifdef IN_DEBUG_MODE
        printf("DEBUG: entered testFunction\n");
    #endif

    #undef IN_DEBUG_MODE

    #ifdef IN_DEBUG_MODE
        printf("DEBUG: still in debug mode\n");
    #endif

}

signed main(int argc, char **argv){
    testFunction();

    printf("max value is: %d\n\n",MAX(5,10));
    return 0;
}
