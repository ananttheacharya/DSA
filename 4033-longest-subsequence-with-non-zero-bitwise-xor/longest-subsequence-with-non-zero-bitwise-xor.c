int longestSubsequence(int* nums, int numsSize)
{
    int totalXor = 0;

    for (int i = 0; i < numsSize; i++)
    {
        totalXor ^= nums[i];
    }

    if (totalXor != 0)
    {
        return numsSize;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            return numsSize - 1;
        }
    }

    return 0;
}