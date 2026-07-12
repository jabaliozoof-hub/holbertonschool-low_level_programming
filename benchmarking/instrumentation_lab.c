#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;
    state = SEED_VALUE;
    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i, v;
    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0) v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;
    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];
    return sum;
}

int main(void)
{
    unsigned long checksum;
    clock_t start_total, end_total;
    clock_t start_b, end_b, start_p, end_p, start_r, end_r;
    double t_total, t_build, t_process, t_reduce;

    start_total = clock();
    
    start_b = clock();
    build_dataset();
    end_b = clock();

    start_p = clock();
    process_dataset();
    end_p = clock();

    start_r = clock();
    checksum = reduce_checksum();
    end_r = clock();

    end_total = clock();

    if (checksum == 0ul) printf("impossible\n");

    t_total = (double)(end_total - start_total) / CLOCKS_PER_SEC;
    t_build = (double)(end_b - start_b) / CLOCKS_PER_SEC;
    t_process = (double)(end_p - start_p) / CLOCKS_PER_SEC;
    t_reduce = (double)(end_r - start_r) / CLOCKS_PER_SEC;

    printf("TOTAL seconds: %.6f\n", t_total);
    printf("BUILD_DATA seconds: %.6f\n", t_build);
    printf("PROCESS seconds: %.6f\n", t_process);
    printf("REDUCE seconds: %.6f\n", t_reduce);

    return 0;
}
