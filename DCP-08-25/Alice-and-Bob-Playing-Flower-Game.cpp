class Solution {
public:
    // The final formula can be easily transformed to a simple one as below :
    // Case 1 : When m and n are even
    // For n : (n/2) numbers are odd, (n/2) numbers are even
    // For m : (m/2) numbers are odd, (m/2) numbers are even

    // Formula:
    // = (n/2 * m/2) + (n/2 * m/2)
    // = nm/2

    // Case 2 : Both n and m are odd
    // For n → (n+1)/2 numbers are odd, (n-1)/2 numbers are even
    // For m → (m+1)/2 numbers are odd, (m-1)/2 numbers are even

    // Formula:
    // ((n+1)/2 * (m-1)/2) + ((n-1)/2 * (m+1)/2)
    // = (nm - 1)/2


    // Case 3: One odd and one even
    // Say n is odd → (n+1)/2 numbers are odd, (n-1)/2 numbers are even
    // m is even → (m/2) numbers are odd, (m/2) numbers are even

    // Formula:
    // ((n+1)/2 * m/2) + ((n-1)/2 * m/2)
    // = (nm)/2

    // Final Conclusion:
    // Both even → nm/2
    // Both odd → (nm - 1)/2
    // One odd & one even → nm/2

    // So final simplified formula is always : n*m/2 (Note that n*m/2 will give floor value only)
    long long flowerGame(int n, int m) {
        // return 1LL * ((n+1)/2) * (m/2) + 1LL * (n/2) * ((m+1)/2);
        return (1LL * n * m) / 2;
    }
};