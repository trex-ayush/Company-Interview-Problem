/*
    Problem Name: Leetcode 2429. Minimize XOR
    https://leetcode.com/problems/minimize-xor/description/
    Company :  
*/

/*
    Time Complexity : O(31) = O(1)
    Space Complexity : O(1)
*/
class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    bool isUnset(int x, int bit) {
        return (x & (1 << bit)) == 0;
    }

    int minimizeXor(int num1, int num2) {
        int x = 0;

        int requiredSetBitCount = __builtin_popcount(num2);

        for(int bit = 31; bit >= 0 && requiredSetBitCount > 0; bit--) {
            if(isSet(num1, bit)) {
                setBit(x, bit); //Or you can write x |= (1 << bit);
                requiredSetBitCount--;
            }
        }

        for(int bit = 0; bit < 32 && requiredSetBitCount > 0; bit++) {
            if(isUnset(num1, bit)) {
                setBit(x, bit); //Or you can write x |= (1 << bit);
                requiredSetBitCount--;
            }
        }

        return x;
        
    }
};