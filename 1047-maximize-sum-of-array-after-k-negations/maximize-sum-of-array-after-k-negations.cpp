class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int sum = 0;

        for (int i =0;i<nums.size();i++) {
            pq.push(nums[i]);
            sum += nums[i];
        }

        while (k--) {
            int el = pq.top();
            pq.pop();

            if (el == 0)
                break;

            sum -= el;
            sum += -el;
            pq.push(-el);
        }

        return sum;
    }
};