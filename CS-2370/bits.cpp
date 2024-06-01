//
//  bits.cpp
//  CS-2370
//
//  Created by Braeden's UVU account on 5/31/24.
//
// Define a class named Bits that holds a single integer variable.
// You will use this integer simply as a container of bits.
// The number of bits you can support depends on the type of integer you use.
// We will use an unsigned long long, which on most platforms occupies 64 bits.
// However, DO NOT HARD-CODE the type of integer you use throughout your code.
// You should be able to change only one line of code for your class to work with a different size integer (see the using statement on the second code line below).
// The code skeleton below gets you started, and also shows you the interface your class needs to implement.
// I gave you the code for some of the functions. The body of at should help you with many other functions.
#include "bits.hpp"
#include <cassert>
#include <iostream>
#include <bitset>

class Bits
{
    using IType = unsigned long long; // We only have to change the integer type here, if desired
    enum
    {
        NBITS = sizeof(IType) * 8
    };
    IType bits = 0;

public:
    Bits() = default;
    Bits(IType n)
    {
        bits = n;
    }
    static int size()
    {
        return NBITS;
    }
    bool at(int pos) const
    { // Returns (tests) the bit at bit-position pos
        assert(0 <= pos && pos < NBITS);
        return bits & (IType(1) << pos);
    }

    void set(int pos)
    { // Sets the bit at position pos
        assert(0 <= pos && pos < NBITS);
        bits |= (IType(1) << pos);
    }
    void set()
    {
        bits = ~IType(0); // ~ is the bitwise NOT operator
    }
    void reset(int pos)
    { // Resets (makes zero) the bit at position pos
        assert(0 <= pos && pos < NBITS);
        bits &= ~(IType(1) << pos);
    }

    void reset()
    {
        bits = IType(0);
    } // Resets all bits
    void assign(int pos, bool val) // Sets or resets the bit at position pos depending on val
    {
        assert(0 <= pos && pos < NBITS);
        if (val)
        {
            set(pos);
        }
        else
        {
            reset(pos);
        }
    }
    void assign(IType n)
    { // Replaces the underlying integer with n
        bits = n;
    }

    void toggle(int pos) // Flips the bit at position pos,  ^= is the bitwise XOR operator which flips bit at pos since 1^1 = 0 and 0^1 = 1
    {
        assert(0 <= pos && pos < NBITS);
        bits ^= (Itype(1) << pos);
    }
    void toggle() // Flips all bits,
    {
        bits = ~bits;
    }
    void shift(int n);  // If n > 0, shifts bits right n places; if n < 0, shifts left
    void rotate(int n); // If n > 0, rotates right n places; if n < 0, rotates left
    int ones() const
    {
        int num
    } // Returns how many bits are set in the underlying integer
    int zeroes() const
    { // Returns how many bits are reset in the underlying integer
        return NBITS - ones();
    }
    IType to_int() const
    {
        return bits;
    }
    friend bool operator==(const Bits &b1, const Bits &b2)
    {
        return b1.bits == b2.bits;
    }
    friend bool operator!=(const Bits &b1, const Bits &b2)
    {
        return b1.bits != b2.bits;
    }
    friend std::ostream &operator<<(std::ostream &os, const Bits &b)
    {
        return os << std::bitset<NBITS>(b.bits); // Be sure to #include <bitset>
    }
}
/*
I have also defined for you the following non-member, friend functions:

an output stream operator (<<) that prints the bits to an output stream (without a newline; hint: use std::bitset)
the equality operator ==
the inequality operator !=
Remember that bit positions are numbered right-to-left, so bit-position 0 is the low-order (right-most) bit. "Rotate" means that bits that fall off one end replace the vacated bits on the other (in the same order as they appeared originally).

Define all functions inline in a header file named bits.h.

rotate is the most interesting function to implement.

I suggest that you develop your code offline in the development environment of your own choice, implementing and testing one function at a time. When you are satisfied everything is working, submit your code for grading.

Something think about

What will you do if a user of your Bits class tries to use a bit position out of range of what the integer holds? You can just use asserts for now, as shown above.

Remember

Never use using namespace std; in a header file!

Hints

Don't use unadorned constants when shifting or forming masks. For example, instead of 1 << pos, use IType(1) << pos.

*/
