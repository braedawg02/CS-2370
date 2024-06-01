//
//  bits.hpp
//  CS-2370
//
//  Created by Braeden's UVU account on 5/31/24.
//

#ifndef bits_hpp
#define bits_hpp

#include <stdio.h>
class Bits {
private:
    using IType = unsigned long long; // We only have to change the integer type here, if desired
    enum {NBITS = sizeof(IType)*8};
    IType bits = 0;
public:
    Bits();
    Bits(IType n);
    static int size();
    bool at(int pos) const;
    void set(int pos);        // Sets the bit at position pos
    void set();               // Sets all bits
    void reset(int pos);      // Resets (makes zero) the bit at position pos
    void reset();             // Resets all bits
    void assign(int pos, bool val); // Sets or resets the bit at position pos depending on val
    void assign(IType n);     // Replaces the underlying integer with n
    void toggle(int pos);     // Flips the bit at position pos
    void toggle();            // Flips all bits
    void shift(int n);        // If n > 0, shifts bits right n places; if n < 0, shifts left
    void rotate(int n);       // If n > 0, rotates right n places; if n < 0, rotates left
    int ones() const;         // Returns how many bits are set in the underlying integer
    int zeroes() const;       // Returns how many bits are reset in the underlying integer
  
    IType to_int() const;
    friend bool operator==(const Bits& b1, const Bits& b2);
    friend bool operator!=(const Bits& b1, const Bits& b2);
    friend std::ostream& operator<<(std::ostream& os, const Bits& b);
};
#endif /* bits_hpp */
