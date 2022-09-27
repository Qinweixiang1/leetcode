// 不带备忘录
int minMoney(int* arr, int arrLen, int aim ) {
    if (aim == 0)
        return 0;
    int ans = INT_MAX;
    for (int i=0; i< arrLen; i++) {
        // 金额不可达
        if (aim - arr[i] < 0)
            continue;
        int subProb = minMoney(arr,arrLen, aim-arr[i] );
        // 子问题无解
        if (subProb == -1)
            continue;
        ans = fmin(ans, subProb + 1);
    }
    return ans == INT_MAX ? -1 : ans;
}

/*==========================================*/

// 带备忘录
int helper(int* coins, int coinsSize, int amount, int *memo){
    if(!amount)
        return 0;
    if(memo[amount]!=-2)
        return memo[amount];
    int ans=INT_MAX;
    for(int i=0; i<coinsSize; i++){
      // 金额不可达
        if(amount - coins[i]  < 0)
            continue;
        int subProb = helper(coins, coinsSize, amount-coins[i], memo);
      // 子问题无解
        if(subProb == -1)
            continue;
        ans=fmin(ans, subProb+1);
    }
    memo[amount]= ans == INT_MAX ? -1 : ans;
    return memo[amount];
}

int coinChange(int* coins, int coinsSize, int amount){
int *memo = (int*)malloc(sizeof(int)* (amount + 1));
for(int i =0; i<amount+1; i++)
    memo[i]=-2;
return helper(coins, coinsSize, amount, memo);
}
