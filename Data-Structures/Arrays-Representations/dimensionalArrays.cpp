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

int main()
{
    // 2D Array First Method
    int A[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    }; // 3 Rows 4 Columns

    visualize2DArray("2D [3,4] Array: ", A, 3, 4);

    // 2D Array Second Method
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    // 2D Array Third Method

    return 0;
}