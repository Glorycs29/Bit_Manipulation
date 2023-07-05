# Bit-manipulation (Discussed) || C++ || Karnaugh-map ||

#### Intuition
The intuition to solve this problem is to represent all the numbers in bits and count the number of set bits at each index.
After getting a number of set bits, we can module three (%3) and will get the required number, but the problem is the modulo of three can be 0(00) or 1(01) or 2(10), so in order to get our ans we require Karnaugh-map relation(K-map).

#### Approach
we will take two 32-bit var. ones and twos, here ones store a number when it is encountered for the first time int the array...i.e
ones = (ones^ nums[i])&(~twos) -----> A^0 = A
and this relation came from K-Map.
Similarly, twos store the num. if the number is encountered for the second time, then the number is removed from the ones and stored in the second:-

twos = (twos^nums[i]) & (~ones)----->A^A = 0(in ones).

If a number occurs for the third time, then it will be removed from both ones and twos.

Finally, ones will contain the answer, So return ones.

##### Complexity
Time complexity:
O(32* n)

Space complexity:
O(1)

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for(auto iter: nums){
            ones = (ones ^ iter) & (~twos);
            twos = (twos ^ iter) & (~ones);
        }
        return ones;    
    }
};
```
