#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <mkl_cblas.h>

float bdp(long N, float *pA, float *pB) {
    float R = cblas_sdot(N, pA, 1, pB, 1);
    return R;
}

int main(int argc, char *argv[]) {
    struct timespec start, end;
    float *pA;
    float *pB;
    double R;
    char *p;
    long N;
    double mean_time;
    double bandwidth;
    double flops;
    float result = 0.0;
    float timeSum;
    float *timeElapsArr;

    if (argc < 3) {
        printf("Error: N and R values are not provided. \n");
        return 0;
    } else {
        N = strtol(argv[1], &p, 10);
        R = strtod(argv[2], &p);
        pA = (float *)malloc(N * sizeof(float));
        pB = (float *)malloc(N * sizeof(float));
        timeElapsArr = (float *)malloc(sizeof(float) * R);

        if (pA == NULL || pB == NULL) {
            printf("Error: Memory allocation failed.\n");
            return 1;
        }

        for (int i = 0; i < N; ++i) {
            pA[i] = 1.0;
            pB[i] = 1.0;
        }
    }

    
    for (int i = 0; i < R; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        result = bdp(N, pA, pB);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeElapsArr[i] = (((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3))/1e6;
    }
    printf("result: %.3f.\n", result);

    timeSum = 0.0;
    for (int i = (R / 2); i < R; i++)
    {
        timeSum += timeElapsArr[i];
    }

    mean_time = (timeSum / (R / 2));
    flops = ((2.0 * N )-1) / (mean_time * 1e9);
    bandwidth = (2.0 * N * sizeof(float)) / (mean_time * 1e9);
    
    printf("N: %ld <T>: %.09lf sec B: %.03lf GB/sec F: %.03lf GFLOP/sec\n", N, mean_time, bandwidth, flops);

    free(pA);
    free(pB);

    return 0;
}
