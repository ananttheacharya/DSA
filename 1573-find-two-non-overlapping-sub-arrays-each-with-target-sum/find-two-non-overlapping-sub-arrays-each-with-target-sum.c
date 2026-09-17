int minSumOfLengths(int* arr, int arrSize, int target) {
    int *dp = (int *)malloc(arrSize * sizeof(int));
    
    for (int i = 0; i < arrSize; i++)
        dp[i] = arrSize + 1;

    int left = 0;
    int sum = 0;
    int ans = arrSize + 1;

    for (int right = 0; right < arrSize; right++) {
        sum += arr[right];

        while (sum > target && left <= right) {
            sum -= arr[left++];
        }

        if (sum == target) {
            int len = right - left + 1;

            if (left > 0 && dp[left - 1] <= arrSize) {
                int total = len + dp[left - 1];
                if (total < ans)
                    ans = total;
            }

            if (right == 0)
                dp[right] = len;
            else
                dp[right] = dp[right - 1] < len ? dp[right - 1] : len;
        } else {
            if (right > 0)
                dp[right] = dp[right - 1];
        }
    }

    free(dp);

    return ans == arrSize + 1 ? -1 : ans;
}