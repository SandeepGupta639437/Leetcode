class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // edge case
        if (n == 1) return 1; // zero not possible
        if (n == 2) return 2; // zero not posible (like  {1,2,3});

        // let the max number is 7 .. and 7 is 3 bit number .. so we can generfate all 3 bit number including 0 till y7 ..i.e: cnt = 8;
        int p = 1;
        while (p <= n)
            p <<= 1;     // It gives the number of that it pow of 2 and is greater that n for that bit  ( Ex : for 4 ..it gives 8 .. 4->3bit,  8-> 4bit)

        return p;
    }
};