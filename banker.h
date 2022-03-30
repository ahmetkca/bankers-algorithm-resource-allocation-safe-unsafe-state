#ifndef BANKER_H_
#define BANKER_H_

int number_of_resource;
int number_of_process;

/* the available  amount of each resource */
int *available;

/* the maximum demand for each process */
int **maximum;

/* the amount currently allocated to each customer */
int **allocation;

/* the remaining need of each customer */
int **need;


void init(int num_resource, int num_process);

int cmp_vector(int size1, const int *vec1,int size2, const int * vec2);

int **calculate_need();

bool is_safe();

#endif