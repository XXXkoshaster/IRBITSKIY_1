#include "../inc/core.hpp"

int main()
{
    Complex a = Complex(3.0, 4.0); 
    Complex b = Complex(1.0, 2.0);

    std::cout << "Complex number A: (" << a.get_real() << ", " << a.get_imag() << "i)" << std::endl;
    std::cout << "Complex number B: (" << b.get_real() << ", " << b.get_imag() << "i)" << std::endl;

    Complex sum = a.add(b);
    std::cout << "A + B: (" << sum.get_real() << ", " << sum.get_imag() << "i)" << std::endl;

    Complex diff = a.sub(b);
    std::cout << "A - B: (" << diff.get_real() << ", " << diff.get_imag() << "i)" << std::endl;

    Complex prod = a.multiply(b);
    std::cout << "A * B: (" << prod.get_real() << ", " << prod.get_imag() << "i)" << std::endl;

    try {
        Complex quot = a.divide(b);
        std::cout << "A / B: (" << quot.get_real() << ", " << quot.get_imag() << "i)" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Module of A: " << a.module() << std::endl;
    std::cout << "Argument of A: " << a.get_args() << std::endl;

    return 0;
}
