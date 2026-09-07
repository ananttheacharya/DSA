function numDistinct(s: string, t: string): number {
    const m = s.length;
    const n = t.length;
    
    const dp = new Array<number>(n + 1).fill(0);
    dp[0] = 1;
    
    for (let i = 1; i <= m; i++) {
        for (let j = n; j > 0; j--) {
            if (s[i - 1] === t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    
    return dp[n];
}