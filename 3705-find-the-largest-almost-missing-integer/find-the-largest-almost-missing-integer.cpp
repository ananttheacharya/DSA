class Solution
{
public:
    int largestInteger(vector<int>& nums, int k)
    {
        vector<int> cnt(51);

        for (int x : nums)
        {
            cnt[x]++;
        }

        if (k == nums.size())
        {
            return *max_element(nums.begin(), nums.end());
        }

        if (k == 1)
        {
            int ans = -1;

            for (int x : nums)
            {
                if (cnt[x] == 1)
                {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        int a = cnt[nums.front()] == 1 ? nums.front() : -1;
        int b = cnt[nums.back()] == 1 ? nums.back() : -1;

        return max(a, b);
    }
};