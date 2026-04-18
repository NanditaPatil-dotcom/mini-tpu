# Matrix Computation Engine

This project begins by implementing a basic matrix abstraction and a naive matrix multiplication algorithm.

Matrix multiplication is the core operation behind most machine learning workloads, especially in deep learning models where large tensor operations are common.

The current implementation uses a straightforward triple-loop approach:

Iterates over rows of the first matrix
Iterates over columns of the second matrix
Computes dot products using element-wise multiplication

While simple and correct, this approach is computationally expensive and does not utilize memory efficiently. In particular:

Accessing elements of the second matrix leads to poor cache locality
Data is not stored in a contiguous layout, increasing memory overhead
The algorithm runs in cubic time complexity O(n^3)

This baseline serves as a reference point for future optimizations and architectural improvements.