def knapsack(W , val, Wt):


    n = len(val)


    dp = [[0 for _ in range(W+1)] for _ in range(n+1)]

    for i in range(n+1):
        for j in range(W+1):
            if i ==0 or j == 0:
                dp[i][j] = 0

            else:
                pick =0 
                if Wt[i -1] <= j:
                    pick = val[i - 1] + dp[i - 1][j - Wt[i - 1]]
                not_pick = dp[i - 1][j]
                dp[i][j] = max(pick, not_pick)
    return dp[n][W]




    pass 






val = [1, 2, 3]
wt = [4, 5, 1]
W = 4
print(knapsack(W, val, wt))

