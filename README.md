# Dot Product Microbenchmark Summary

This project investigates the performance of computing the dot product in C and Python, using various implementations and optimizations. The goal is to measure execution time, compute bandwidth and throughput, and compare the results across different implementations.

## Introduction

Microbenchmarking is the process of measuring the performance of small units of code, such as individual functions, to identify areas for optimization and compare different algorithms or implementations. In high-performance machine learning, it helps optimize code, select efficient algorithms, evaluate hardware, and verify code correctness, playing a crucial role in enhancing performance.

## Tasks

### Computing Dot Product in C

- Write a micro-benchmark in C to compute the dot product of two float arrays.
- Measure execution time for N=1000000 and N=300000000.
- Compute mean execution time and bandwidth.
- Compile with gcc and execute on a suitable node.

### C2: Computing Dot Product with Unrolling

- Perform the same microbenchmark with unrolling to potentially improve performance.

### C3: Computing Dot Product with MKL

- Use MKL (Intel Math Kernel Library) to compute the dot product and compare performance with the C implementation.

### C4: Computing Dot Product in Python

- Implement the microbenchmark in Python using numpy arrays.
- Compare performance with the C implementations.

### C5: Computing Dot Product with numpy.dot

- Use numpy's built-in dot product function and compare performance with the other implementations.

## Run the code

To run the project, use the provided shell submit file.

## Summary of My Results
- Basic dot product in C, achieving 1.733 GFLOP/sec and 6.932 GB/sec bandwidth for N = 1000000.
- Dot product with loop unrolling in C, improving performance to 5.465 GFLOP/sec and 21.859 GB/sec for N = 1000000.
- Dot product using Intel MKL in C, further enhancing performance to 6.314 GFLOP/sec and 25.257 GB/sec for N = 1000000.
- Basic dot product in Python with NumPy arrays, significantly lower performance at 0.004 GFLOP/sec and 1.655 GB/sec for N = 1000000.
- Dot product using NumPy's dot function in Python, showing a substantial improvement to 6.104 GFLOP/sec and 2539.353 GB/sec for N = 1000000.

## Observations
- The C implementations (C1, C2, C3) generally outperform the Python implementations (C4, C5) in terms of throughput and bandwidth, especially for larger values of N.
- Loop unrolling (C2) and using Intel MKL (C3) significantly improve the performance of the dot product computation in C.
- The performance of the basic Python implementation (C4) is much lower compared to C, highlighting the interpreted nature of Python and its inefficiency in numerical operations.
- Utilizing NumPy's dot function (C5) greatly enhances performance in Python, achieving throughput and bandwidth closer to C implementations.

## Inferences
- The choice of programming language and optimization techniques can have a significant impact on the performance of numerical computations.
- Utilizing specialized libraries like Intel MKL for C and NumPy for Python can lead to substantial performance improvements.
- While Python offers ease of use, it comes with a performance trade-off compared to lower-level languages like C. However, this gap can be narrowed by using optimized libraries.
- Benchmarking different implementations is essential for understanding their performance characteristics and making informed choices for specific applications.
