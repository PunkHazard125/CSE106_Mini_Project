#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_matrix(int size, int **matrix) {

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }

}

void sum_of_deg(int size, int **matrix, long long *in_degree, long long *out_degree) {

    long long row_sum = 0, col_sum = 0;

    for (int i = 0; i < size; i++)
    {
        row_sum = 0;
        col_sum =  0;

        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != 0)
            {
                row_sum++;
            }

            if (matrix[j][i] != 0)
            {
                col_sum++;
            }
        }

        *in_degree = *in_degree + row_sum;
        *out_degree = *out_degree + col_sum;
    }

}

int main(void) {

    int size;

    printf("\nEnter Number of Vertices: ");
    scanf("%d", &size);

    int **matrix = malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++)
    {
        matrix[i] = malloc(size * sizeof(int));
    }

    srand(time(NULL));

    generate_matrix(size, matrix);

    long long in_degree = 0;
    long long out_degree = 0;

    clock_t start, end;
    double computational_time;

    start = clock();

    sum_of_deg(size, matrix, &in_degree, &out_degree);

    end = clock();

    computational_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nSum of In-Degrees:  %lld\n", in_degree);
    printf("Sum of Out-Degrees: %lld\n\n", out_degree);


    if (in_degree == out_degree)
    {
        printf("Since Sum of In-Degrees = Sum of Out-Degrees,\n");
        printf("Theorem for Directed Graphs is proved.\n\n");
    }
    else
    {
        printf("Since Sum of In-Degrees != Sum of Out-Degrees,\n");
        printf("Some Error Must Have Occured.\n\n");
    }

    for (int i = 0; i < size; i++) 
    {
        free(matrix[i]);
    }
    
    free(matrix);

    printf("Computational Time: %f milliseconds\n\n", (computational_time * 1000));

    return 0;
}
