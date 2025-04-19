#include "Matrix.hpp"
#include <iostream>
using namespace std;

int main()
{
    Matrix A{{6, 4},
             {8, 3}};

    Matrix B{{1, 2, 3},
             {4, 5, 6}};

    Matrix C{{2, 4, 6},
             {1, 3, 5}};

    //Assignment equation 
    Matrix D = A + (B * 3) * C.transposed();

    //Other Tests 
    Matrix E = A * B;
    Matrix F = C * B.transposed();
    Matrix G = B + C;

    cout << "Result D =\n" << D
         << "\nE =\n"      << E
         << "\nF =\n"      << F
         << "\nG =\n"      << G;

    return 0;
}
