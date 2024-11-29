#pragma once

#include "utils.hpp"

class BinaryInt: public BitwiseUtils
{
private:
    int value;

public:
    BinaryInt(int value): value(value) {}

    BinaryInt operator - () const 
    {
        return BinaryInt(negative(value));
    }

    BinaryInt& operator ++() 
    {
        value = sum(value, 1);
        return *this;
    }

    BinaryInt operator ++(int)
    {
        BinaryInt copy {*this};
        value = sum(value, 1);
        return copy;
    }

    BinaryInt& operator --() 
    {
        value = sub(value, 1);
        return *this;
    }

    BinaryInt operator -- (int)
    {
        BinaryInt copy {*this};
        value = sub(value, 1);
        return copy;
    }

    BinaryInt& operator += (const BinaryInt& addend)
    {
        value = sum(value, addend.value);
        return *this;
    }

    BinaryInt operator + (const BinaryInt& addend) const
    {
        return BinaryInt(sum(value, addend.value));
    }

    BinaryInt& operator -= (const BinaryInt& subtrahend)
    {
        value = sub(value, subtrahend.value);
        return *this;
    }

    BinaryInt operator - (const BinaryInt& subtrahend) const
    {
        return BinaryInt(sub(value, subtrahend.value));
    }

    BinaryInt& operator *= (const BinaryInt& multipler)
    {
        value = multiply(value, multipler.value);
        return *this;
    }

    BinaryInt operator * (const BinaryInt& multipler) const
    {
        return BinaryInt(multiply(value, multipler.value));
        
    }

    BinaryInt& operator <<= (int shift)
    {
        value <<= shift;
        return *this;
    }

    BinaryInt& operator >>= (int shift)
    {
        value >>= shift;
        return *this;
    }

    BinaryInt operator << (int shift) const
    {
        return BinaryInt(value << shift);
    }

    BinaryInt operator >> (int shift) const
    {
        return BinaryInt(value >> shift);
    }

    friend std::ostream& operator << (std::ostream& stream, const BinaryInt& binary)
    {
        int int_size = multiply(sizeof(int), 8);
        for (int i = sub(int_size, 1); i >= 0; --i)
            stream << ((binary.value >> i) & 1);
        
        return stream;
    }

    std::pair<BinaryInt, BinaryInt> split() const 
    {
        int int_size = multiply(sizeof(int), 8);

        int half_bits = int_size >> 1;
        
        int low_mask = sub((1 << half_bits), 1);
        int high_mask = low_mask << half_bits;

        return {BinaryInt(value & high_mask), BinaryInt(value & low_mask)};
    }
}; 
