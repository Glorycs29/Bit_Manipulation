class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int k, i, j, n, hasBit, exept;
    k = 3;
    vector<int>bitCount(32,0);
    
    for (j = 0; j < nums.size(); j++) {
        n = nums[j];
        for (i = 0; i < 32; i++) {
            hasBit = (n & (1 << i)) != 0;
            if (hasBit) {
                bitCount[i] = (bitCount[i] + 1) % k;
            }
        }
    }
    exept = 0;
    for (i = 0; i < 32; i++) {
      if (bitCount[i] > 0) {
        exept |= (1 << i);
      }
    }
    return exept;
}
};
