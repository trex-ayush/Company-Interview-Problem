class Solution {
  public:
    int countSetBits(int n) {
        int total = 0;

        while (n > 0) {
            // 1) Find highest power of 2 <= n
            int pov = 1;       // power of 2 value
            int count = 0;     // exponent

            while ((pov << 1) <= n) {
                pov <<= 1;     // pov = pov * 2
                count++;       // count is exponent (for pov = 2^count)
            }
            // Now: pov = 2^count, and pov <= n < 2^(count+1)

            // 2) Bits from 1 to (2^count - 1)
            // formula: count * 2^(count-1)  (for count >= 1)
            int bits = 0;
            if (count > 0) {
                int maxVal = 1 << (count - 1);   // 2^(count-1)
                for (int i = 1; i <= count; i++) {
                    bits += maxVal;              // bits = count * 2^(count-1)
                }
            }

            // 3) Bits contributed by MSB from 2^count to n
            int msbBits = n - pov + 1;

            // add to total
            total += bits + msbBits;

            // 4) Reduce problem to remaining numbers
            n = n - pov;   // now we need set bits from 1 to (n - pov)
        }

        return total;
    }
};
