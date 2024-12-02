## Row Major and Column Major Formulas to Calculate Address of Element

## Row Major formula for nD Arrays:

**Type A[d1][d2][d3][d4];**

Address(A[i1][i2][i3][i4]) =

    L0 + [(i1 * d2 * d3) + (i2 * d3 * d4) + (i3 * d4) + i4] * w

    _L0: is the base address of the array in memory._
    _w: represents the size of each element in memory, typically in bytes._

![word-image-264](https://github.com/user-attachments/assets/4b737a76-cbe3-4bb6-9c3b-145145e993e5)

### Why the Formula Works:

- Arrays are stored linearly in memory: While arrays might be logically
  n-dimensional, in physical memory, they're stored as a contiguous block of memory.

- To find the location of any specific element, the formula translates n-dimensional indexing into a single-dimensional offset.

  - The product of dimensions calculates how many elements are in the "layers" of memory beyond the current index.

  - The summation accumulates the contributions of all dimensions to the final position.

### Why Need This Formula

1. Efficient Memory Access:

   - Arrays need to be stored contiguously in memory for fast access.
   - Knowing the exact position of an element helps the computer access it directly without scanning through the array.

2. Translation from Logical to Physical Representation:

   - Programmers work with multi-dimensional indices, but memory only understands linear addresses.
   - The formula bridges this gap by calculating the correct memory address for any multi-dimensional index.

3. Speed Optimization:

   - Accessing memory is one of the slowest operations in computing. Precomputed offsets allow direct addressing, reducing computation time.

## Row Major formula for 1D, 2D, 3D Arrays

![Matrix](https://github.com/user-attachments/assets/6b9e068b-a85d-4df9-8ef9-33d082a60dee)

Here is the also another good explanation from GeekForGeeks about calculation in 1D, 2D, 3D Arrays:
https://www.geeksforgeeks.org/calculation-of-address-of-element-of-1-d-2-d-and-3-d-using-row-major-and-column-major-order/
