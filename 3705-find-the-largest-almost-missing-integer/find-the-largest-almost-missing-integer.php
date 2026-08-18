class Solution
{
    function largestInteger($nums, $k)
    {
        $cnt = array_fill(0, 51, 0);

        foreach ($nums as $x)
        {
            $cnt[$x]++;
        }

        if ($k == count($nums))
        {
            return max($nums);
        }

        if ($k == 1)
        {
            $ans = -1;

            foreach ($nums as $x)
            {
                if ($cnt[$x] == 1)
                {
                    $ans = max($ans, $x);
                }
            }

            return $ans;
        }

        $a = $cnt[$nums[0]] == 1 ? $nums[0] : -1;
        $b = $cnt[$nums[count($nums) - 1]] == 1
            ? $nums[count($nums) - 1]
            : -1;

        return max($a, $b);
    }
}