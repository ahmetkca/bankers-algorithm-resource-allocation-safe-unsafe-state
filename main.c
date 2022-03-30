#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "banker.h"

#define BUFFER_LENGTH 256

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Usage: you need to provide at least one resource type\n\t ./main 10 5 7 as in ten instance of first type, five instance of second type and seven instance of third type.\n");
        return 1;
    }

    init(atoi(argv[1]), atoi(argv[2]));
    for (int i = 0 ;i < number_of_resource; i++) {
        available[i] = atoi(argv[3 + i]);
    }
    printf("Please fill the maximum matrix\n");
    for (int i = 0; i < number_of_process; i++) {
        char delim[] = " ";
        char buffer[BUFFER_LENGTH];
        printf("max resource of P%d: ", i);
        fgets(buffer, BUFFER_LENGTH, stdin);
        char *ptr = strtok(buffer, delim);
        int resource_counter = 0;
        while (ptr != NULL && resource_counter < number_of_resource) {
            maximum[i][resource_counter] = atoi(ptr);
            resource_counter++;
            ptr = strtok(NULL, delim);
        }
    }
    printf("Please fill the allocation matrix\n");
    for (int i = 0; i < number_of_process; i++) {
        char delim[] = " ";
        char buffer[BUFFER_LENGTH];
        printf("max resource of P%d: ", i);
        fgets(buffer, BUFFER_LENGTH, stdin);
        char *ptr = strtok(buffer, delim);
        int resource_counter = 0;
        while (ptr != NULL && resource_counter < number_of_resource) {
            allocation[i][resource_counter] = atoi(ptr);
            resource_counter++;
            ptr = strtok(NULL, delim);
        }
    }
    printf("Available vector\n");
    for (int i = 0; i < number_of_resource; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    printf("Maximum matrix\n");
    for (int i = 0 ;i < number_of_process; i++) {
        for (int r = 0; r < number_of_resource; r++) {
            printf("%d ", maximum[i][r]);
        }
        printf("\n");
    }

    printf("Allocation matrix\n");
    for (int i = 0 ;i < number_of_process; i++) {
        for (int r = 0; r < number_of_resource; r++) {
            printf("%d ", allocation[i][r]);
        }
        printf("\n");
    }
    
    calculate_need();
    printf("Is system in safe state? %d\n", is_safe());
    return 0;
}