#pragma once

#include <iostream>

class LogicalValuesArray
{
private:
    unsigned int value;

public:
    LogicalValuesArray(unsigned int value = 0) : value(value) {};

    unsigned int getValue() const 
    {
        return value;
    }

    LogicalValuesArray invertion() const
    {
        return LogicalValuesArray(~value);
    }

    LogicalValuesArray conuction(const LogicalValuesArray& other) const 
    {
        return LogicalValuesArray(value & other.value);
    }

    LogicalValuesArray disuction(const LogicalValuesArray& other) const
    {
        return LogicalValuesArray(value | other.value);
    } 

    LogicalValuesArray implication(const LogicalValuesArray& other) const
    {
        return LogicalValuesArray(~value | other.value);
    }

    LogicalValuesArray xor_operation(const LogicalValuesArray& other) const
    {
        return LogicalValuesArray(value ^ other.value);
    }

    LogicalValuesArray equialation(const LogicalValuesArray& other) const
    {
        return LogicalValuesArray(~(value ^ other.value));
    } 

    LogicalValuesArray pierce_arrow(const LogicalValuesArray& other) const
    {
        return LogicalValuesArray(~(value | other.value));
    }

    LogicalValuesArray sheffer_stroke(const LogicalValuesArray& other) const
    {
        return LogicalValuesArray(~(value & other.value));
    }

    static bool equals(const LogicalValuesArray& a,const LogicalValuesArray& b)
    {
        return a.value == b.value;
    }

    bool get_bit(unsigned int position) const
    {
        return (value >> position) & 1;
    }

    void to_binary_string(char* buffer) const
    {
        size_t ui_size = sizeof(unsigned int) * 8;

        for (size_t i = 0; i < ui_size; i++)
            buffer[i] = (value & (1 << (ui_size - i - 1))) ? '1' : '0';

        buffer[ui_size] = '\0';
    }

    static void print_binary(const LogicalValuesArray& lva)
    {
        int int_size = sizeof(int) * 8;
        char buffer[int_size];

        lva.to_binary_string(buffer);
        
        std::cout << buffer << std::endl;
    }

    virtual ~LogicalValuesArray() {}
};
