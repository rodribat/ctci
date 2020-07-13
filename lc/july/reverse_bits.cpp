
/*
    Reverse Bits
    Links: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3388/
*/

#include<iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t reversed_bits = 0x0;
        
        for (int i=0; i<32; i++)
        {
            // read ith bit
            uint32_t read_bit = (n & (1 << i)) >> i;
            
            // compound output in reverse order
            if (i>0)
                reversed_bits = (reversed_bits << 1);
            reversed_bits = (reversed_bits | read_bit);
        }
        
        return reversed_bits;
    }
};

int main()
{
    Solution s;
    uint32_t n = 43261596; // 00000010100101000001111010011100
    cout << s.reverseBits(n) << endl; // expected 964176192 (00111001011110000010100101000000)

    return 0;
}