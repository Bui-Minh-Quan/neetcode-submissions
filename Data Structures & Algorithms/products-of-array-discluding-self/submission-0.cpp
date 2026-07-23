class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> postfix(n, 1);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            postfix[n - i - 1] = postfix[n - i] * nums[n - i];
        }

        for (int i = 0; i < n; i++)
            prefix[i] *= postfix[i];
        
        return prefix;
    }
};
