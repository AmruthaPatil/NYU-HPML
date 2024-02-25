import sys
import numpy as np
import time

def dp(N, A, B):
    R = 0.0
    for j in range(0, N):
        R += A[j] * B[j]
    return R

def benchmark(N, R):
    A = np.ones(N, dtype=np.float32)
    B = np.ones(N, dtype=np.float32)
    timeElapsArr = np.zeros(R, dtype =np.float32)

    for i in range (0, R):
        start_time = time.monotonic()
        results = dp(N, A, B)
        end_time = time.monotonic()
        timeElapsArr[i] = end_time-start_time
    print(f"R: {results}")

    timeSum = sum(timeElapsArr[int(R/2) : R])
    mean_time = timeSum / (R/2)
    bandwidth = (2.0 * N * sys.getsizeof(float)) / (mean_time * 1000000000.0) 
    flops = ((2.0 * N)-1) / (mean_time * 1000000000.0)

    return mean_time, bandwidth, flops

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python benchmark.py <N> <R>")
        sys.exit(1)

    N = int(sys.argv[1])
    R = int(sys.argv[2])

    mean_time, bandwidth, flops = benchmark(N, R)

    print(f"N: {N} <T>: {mean_time:.6f} sec B: {bandwidth:.3f} GB/sec F: {flops:.3f} GFLOP/sec")
