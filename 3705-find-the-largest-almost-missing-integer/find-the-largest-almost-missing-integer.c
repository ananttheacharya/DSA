#include <stdlib.h>

int largestInteger(int* nums, int numsSize, int k)
{
    int cnt[51] = {0};

    for (int i = 0; i < numsSize; i++)
    {
        cnt[nums[i]]++;
    }

    if (k == numsSize)
    {
        int mx = nums[0];

        for (int i = 1; i < numsSize; i++)
        {
            if (nums[i] > mx)
            {
                mx = nums[i];
            }
        }

        return mx;
    }

    if (k == 1)
    {
        int ans = -1;

        for (int i = 0; i < numsSize; i++)
        {
            if (cnt[nums[i]] == 1 && nums[i] > ans)
            {
                ans = nums[i];
            }
        }

        return ans;
    }

    int a = cnt[nums[0]] == 1 ? nums[0] : -1;
    int b = cnt[nums[numsSize - 1]] == 1 ? nums[numsSize - 1] : -1;

    return a > b ? a : b;
}