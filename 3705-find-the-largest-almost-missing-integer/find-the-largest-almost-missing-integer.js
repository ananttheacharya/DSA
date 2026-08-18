var largestInteger = function (nums, k)
{
    const cnt = Array(51).fill(0);

    for (const x of nums)
    {
        cnt[x]++;
    }

    if (k === nums.length)
    {
        return Math.max(...nums);
    }

    if (k === 1)
    {
        let ans = -1;

        for (const x of nums)
        {
            if (cnt[x] === 1)
            {
                ans = Math.max(ans, x);
            }
        }

        return ans;
    }

    const a = cnt[nums[0]] === 1 ? nums[0] : -1;
    const b = cnt[nums[nums.length - 1]] === 1
        ? nums[nums.length - 1]
        : -1;

    return Math.max(a, b);
};