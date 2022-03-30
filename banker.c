#include <stdlib.h>
#include <stdbool.h>

#include "banker.h"


void init(int num_resource, int num_process)
{
    number_of_resource = num_resource;
    number_of_process = num_process;

    available = (int *) malloc(number_of_resource * sizeof(int *));

    maximum = (int **) malloc(number_of_process * sizeof(int *));
    for (int i = 0 ;i < num_process; i++) {
        maximum[i] = (int *) malloc(number_of_resource * sizeof(int));
    }
    allocation = (int **) malloc(number_of_process * sizeof(int *));
    for (int i = 0 ;i < num_process; i++) {
        allocation[i] = (int *) malloc(number_of_resource * sizeof(int));
    }
    need = (int **) malloc(number_of_process * sizeof(int *));
    for (int i = 0 ;i < num_process; i++) {
        need[i] = (int *) malloc(number_of_resource * sizeof(int));
    }
}

bool cmp_vectors(int size1, const int *vec1,int size2, const int * vec2) {
    int min;
    if (size1 > size2)
        min = size2;
    else
        min = size1;

    bool lt_or_eq = false;
    for (int i = 0; i < min; i++) {
        if (*(vec1 + i) <= *(vec2 + i)) {
            lt_or_eq = true;
        } else {
            lt_or_eq = false;
            break;
        }
    }
    return lt_or_eq;
}

int **calculate_need() {
    for(int p = 0 ;p < number_of_process; p++) {
        for(int r = 0; r < number_of_resource; r++) {
            need[p][r] = maximum[p][r] - allocation[p][r]; 
        }
    }
    return need;
}

bool is_safe() {
    int work[number_of_resource];
    for (int i = 0; i < number_of_resource; i++) {
        work[i] = available[i];
    }
    int finish[number_of_process];
    for (int i = 0; i < number_of_process; i++) {
        finish[i] = false;
    }

    
    
    for (int i = 0; i < number_of_process; i++) {
        if (finish[i] == false)
            return false;
    }
    return true;
}