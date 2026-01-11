#include <stdio.h>
#include "reg51.h"
#define int long long
#define OPERATION_MODE 1

/* Preprocessor Directives */

int startMode_1(void)
{
    return 0;
}

int startMode_2(void)
{
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
#pragma optimize("", off)

// for ghs compiler:
#pragma ghs section ".bss" = ".mySection"
int myArray[1000]; // it will put this array in section called ".mySection" in memory
#pragma ghs section

#define MAX(a, b) ((a) > (b)) ? (a) : (b)

// void testFunction(void){
//     #ifdef IN_DEBUG_MODE
//         printf("DEBUG: entered testFunction\n");
//     #endif
// }

void testFunction(void)
{
#ifdef IN_DEBUG_MODE
    printf("DEBUG: entered testFunction\n");
#endif

#undef IN_DEBUG_MODE

#ifdef IN_DEBUG_MODE
    printf("DEBUG: still in debug mode\n");
#endif
}

#define OUTPUT 1
#define LOGIC_HIGH 1

// #define LED_INIT(PORT, PIN)      \
//     portInit(PORT, PIN, OUTPUT); \
//     portState(PORT, PIN, LOGIC_HIGH);

#define square(a) a *a

// stringification:
#define LED_INIT(PORT, PIN)                  \
    printf("Initializing PORT: '#PORT' \n"); \
    portInit(PORT, PIN, OUTPUT);             \
    portState(PORT, PIN, LOGIC_HIGH);

// concatenation:
void portInit_implementation1(void)
{
    printf("testing 1...\n");
}

void portInit_implementation2(void)
{
    printf("testing 2...\n");
}

void portInit_implementation3(void)
{
    printf("testing 3...\n");
}

#define PORT_INIT(NUM) \
    portInit_implementation##NUM()

signed main(int argc, char **argv)
{
    testFunction();

    printf("max value is: %d\n", MAX(5, 10));

    // LED_INIT('A', 3);

    // why macros are error-prone:
    printf("%d\n", square(5));
    printf("%d\n", square(1 + 2)); // expected 9, got 5

    int x = 5;
    int y = x;
    printf("post-inc as: %d\n", square(x++)); // expected 26, got 30

    printf("wow: %d\n", y++ * y++);
    printf("x val: %d\n", x);
    printf("%d\n", MAX("abc", "def")); // undefined behavior

    // LED_INIT('A', 3);

    PORT_INIT(2);
    return 0;
}
