#include "lab.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef TEST
#define main main_exclude
#endif

int main(void)
{
    char *greeting = get_greeting("World");
    if (greeting) {
        printf("%s\n", greeting);
        free(greeting); // Free the allocated memory for the greeting
    } else {
        printf("Failed to create greeting.\n");
    }

    printf("3 * 4 = %d\n", multiply(3, 4));
    printf("2 + 3 = %d (bad_add says so, anyway)\n", bad_add(2, 3));

    /* Task 4: intentional memory leak - never freed */
    char *leaked = get_greeting("Leak");
    printf("Leaked greeting: %s\n", leaked);

    /* Task 4: intentional crash - dereference a NULL pointer */
    int *crash = NULL;
    *crash = 42;

    return 0;
}