#include "../inc/core.hpp"

int main()
{
    BinaryInt a_1 = BinaryInt(60);
    BinaryInt a_2 = BinaryInt(31);

    BinaryInt a_3 = a_1 + a_2;
    std::cout << "a_3: " << a_3 << std::endl;

    BinaryInt a_4 = a_1 - a_2;
    std::cout << "a_4: " << a_4 << std::endl;

    BinaryInt a_5 = a_1 * a_2;
    std::cout << "a_5: " << a_5 << std::endl;

    a_1 += a_3;
    std::cout << "a_1: " << a_1 << std::endl;

    a_2 -= a_4;
    std::cout << "a_2: " << a_2 << std::endl;

    a_3 *= a_5;
    std::cout << "a_3: " << a_3 << std::endl;

    a_4++;
    std::cout << "a_4: " << a_4 << std::endl;

    ++a_4;
    std::cout << "a_4: " << a_4 << std::endl;

    a_5--;
    std::cout << "a_5: " << a_5 << std::endl;

    --a_5;
    std::cout << "a_5: " << a_5 << std::endl;

    a_1 <<= 2;
    std::cout << "a_1: " << a_1 << std::endl;

    a_2 >>= 2;
    std::cout << "a_2: " << a_2 << std::endl;

    BinaryInt a_6 = a_1 << 2;
    std::cout << "a_6: " << a_6 << std::endl;

    BinaryInt a_7 = a_2 >> 2;
    std::cout << "a_7: " << a_7 << std::endl;

    std::pair<BinaryInt, BinaryInt> a_8 = a_1.split();
    std::cout << a_8.first << " " << a_8.second << std::endl;

    return 0;
}