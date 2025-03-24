#include <iostream>
#include <cmath>

// Relation between Height and Node count in a tree

/*
    Binary tree height vs. node count:

    Minimum number of nodes for height => n = h + 1
    Maximum number of nodes for height => n = 2^(h+1) - 1

        n = node count
        h = height of the binary tree

    Example cases:

        Height 2 (Max):
                1
               / \
              2   3
             / \  / \
            4  5  6  7

        Height 2 (Min):
                1
                 \
                  2
                   \
                    3

    For strict (full binary tree) min and max formulas:

    Minimum number of nodes for height => n = 2h + 1
    Maximum number fo nodes for height => n = 2^(h+1) - 1

        n = node count
        h = height of the binary tree

*/

std::pair<int, int> maxMinNodeCountFromHeight(int height)
{
    std::pair<int, int> maxMin = {0, 0};

    maxMin.first = static_cast<int>(std::pow(2, height + 1) - 1);
    maxMin.second = height + 1;

    return maxMin;
}

int main()
{
    auto [max, min] = maxMinNodeCountFromHeight(3);
    auto [max2, min2] = maxMinNodeCountFromHeight(5);

    std::cout << "Max node count for height: " << 3 << " is: " << max << std::endl; // 15
    std::cout << "Min node count for height: " << 3 << " is: " << min << std::endl; // 4

    std::cout << "Max node count for height: " << 5 << " is: " << max2 << std::endl; // 63
    std::cout << "Min node count for height: " << 5 << " is: " << min2 << std::endl; // 6

    return 0;
}