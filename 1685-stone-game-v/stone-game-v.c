#include <stdlib.h>

int **dp;
int *prefix;
int n;

int rangeSum(int l, int r)
{
    return prefix[r + 1] - prefix[l];
}

int solve(int l, int r)
{
    if (l == r)
    {
        return 0;
    }

    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }

    int best = 0;

    for (int k = l; k < r; k++)
    {
        int leftSum = rangeSum(l, k);
        int rightSum = rangeSum(k + 1, r);

        if (leftSum < rightSum)
        {
            int score = leftSum + solve(l, k);

            if (score > best)
            {
                best = score;
            }
        }
        else if (leftSum > rightSum)
        {
            int score = rightSum + solve(k + 1, r);

            if (score > best)
            {
                best = score;
            }
        }
        else
        {
            int leftScore = leftSum + solve(l, k);
            int rightScore = rightSum + solve(k + 1, r);

            int score = leftScore > rightScore ? leftScore : rightScore;

            if (score > best)
            {
                best = score;
            }
        }
    }

    dp[l][r] = best;

    return best;
}

int stoneGameV(int *stoneValue, int stoneValueSize)
{
    n = stoneValueSize;

    prefix = (int *) malloc((n + 1) * sizeof(int));
    prefix[0] = 0;

    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    dp = (int **) malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        dp[i] = (int *) malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    int answer = solve(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        free(dp[i]);
    }

    free(dp);
    free(prefix);

    return answer;
}