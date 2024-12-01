#include <iostream>
#include <string>

// Dimensional Arrays (2D, 3D Arrays)

void visualize2DArray(std::string title, int A[][4], int row, int col)
{
    std::cout << title << std::endl;
    for (int i = 0; i < row; ++i)
    {
        std::cout << "\t";
        for (int j = 0; j < col; ++j)
            std::cout << A[i][j] << "  ";

        std::cout << std::endl;
    }
}

// visualize2DArray overload for double pointer arrays
void visualize2DArray(std::string title, int **A, int row, int col)
{
    std::cout << title << std::endl;
    for (int i = 0; i < row; ++i)
    {
        std::cout << "\t";
        for (int j = 0; j < col; ++j)
            std::cout << A[i][j] << "  ";

        std::cout << std::endl;
    }
}

int main()
{
    // i) Declare 2D Array First Method
    int A[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    }; // 3 Rows 4 Columns

    visualize2DArray("2D [3,4] Array A: ", A, 3, 4);

    // ii) Declare 2D Array Second Method
    int *B[3]; // on STACK for rows (each pointer for column which created on HEAP)

    // on HEAP for columns
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    visualize2DArray("2D [3,4] Array B: ", B, 3, 4);

    // deallocation
    for (int i = 0; i < 3; ++i)
        delete[] B[i];

    // iii)  Declare 2D Array Third Method (double pointer)
    // on HEAP for both rows and columns
    int **D = new int *[3];

    D[0] = new int[4];
    D[1] = new int[4];
    D[2] = new int[4];

    visualize2DArray("2D [3,4] Array D: ", D, 3, 4);

    for (int i = 0; i < 3; ++i) // Deallocate each row
        delete[] D[i];

    delete[] D; // Deallocate the array of pointers

    return 0;
}