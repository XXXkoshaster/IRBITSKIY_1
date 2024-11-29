#include "../inc/core.hpp"

int main()
{
    LogicalValuesArray a = LogicalValuesArray(0b10101010);
    LogicalValuesArray b = LogicalValuesArray(0b11001100); 

    std::cout << "Value A: ";
    LogicalValuesArray::print_binary(a);

    std::cout << "Value B: ";
    LogicalValuesArray::print_binary(b);

    LogicalValuesArray inv_a = a.invertion();
    std::cout << "Inversion of A: ";
    LogicalValuesArray::print_binary(inv_a);

    LogicalValuesArray conj_ab = a.conuction(b);
    std::cout << "Conjunction (A AND B): ";
    LogicalValuesArray::print_binary(conj_ab);

    LogicalValuesArray disj_ab = a.disuction(b);
    std::cout << "Disjunction (A OR B): ";
    LogicalValuesArray::print_binary(disj_ab);

    LogicalValuesArray impl_ab = a.implication(b);
    std::cout << "Implication (A -> B): ";
    LogicalValuesArray::print_binary(impl_ab);

    LogicalValuesArray xor_ab = a.xor_operation(b);
    std::cout << "XOR (A XOR B): ";
    LogicalValuesArray::print_binary(xor_ab);

    LogicalValuesArray eq_ab = a.equialation(b);
    std::cout << "Equialation (A <-> B): ";
    LogicalValuesArray::print_binary(eq_ab);

    LogicalValuesArray pierce_ab = a.pierce_arrow(b);
    std::cout << "Pierce Arrow (NOR): ";
    LogicalValuesArray::print_binary(pierce_ab);

    LogicalValuesArray sheffer_ab = a.sheffer_stroke(b);
    std::cout << "Sheffer Stroke (NAND): ";
    LogicalValuesArray::print_binary(sheffer_ab);

    bool are_equal = LogicalValuesArray::equals(a, b);
    std::cout << "A equals B: " << (are_equal ? "True" : "False") << std::endl;


    return 0;
}