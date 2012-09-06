// CONCRETE MATHEMATICS
// 1.2 Lines in the Plane (Page 4 - 8)
// Ex.13 (Page 13)

// L(n) = n * (n + 1) / 2 + 1;
// Z(n) = L(2 * n) - 2 * n = 2 * n ^ 2 - n + 1;
// ZZ(n) = ?

// zig-zag := two *parallel* infinite half-lines joined by a straight line segment

// ZZ(0) = 1;
// ZZ(n) = ZZ(n - 1) + {[3 * (n - 1)] + 1} //segment hits the previous lines in 3 * (n - 1) different place
//                  + {[3 * (n - 1) + 1] + 1} //half-lines hits the previous lines in 3 * (n - 1) different place
//                  + {[3 * (n - 1) + 1] + 1} //half-lines is parallel to the one before
//                  - 2 * (3 - 1); // different from lines to half-lines
// ZZ(n) = ZZ(n - 1) + 9 * n - 8;

#include <iostream>
inline int ZZ(int n)
{
    return (9 + 9 * n) * n / 2 - 8 * n + 1;
}
int main(void)
{
    int n;
    while(std::cin >> n)
        std::cout << ZZ(n) << std::endl;
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2741859 2008-02-02 15:26:12 Accepted 1652 C++ 00:00.24 840K ¤ï¤¿¤·

// 2012-09-07 00:57:04 | Accepted | 1652 | C++ | 120 | 188 | watashi | Source
