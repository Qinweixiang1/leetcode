// 暴力
int fib(int n){
if( n < 2)
    return n;
return fib(n-1) + fib(n-2);
}

/*=========================================================*/
// 带备忘录 自顶向下
int helper(int n, int *memo){
    if(n<2)
        return n;
    if(memo[n]!=0)
        return memo[n];
    memo[n] = helper(n-1, memo) + helper(n-2, memo);
    return memo[n];
}

int fib(int n){
int *memo=(int*)malloc(sizeof(int) * (n + 1));
memset(memo, 0, sizeof(int) * (n + 1));
return helper(n, memo);
}

/*=========================================================*/
// 带备忘录 自底向上

int fib(int n){
if(n<2)
    return n;
int *memo=(int*)malloc(sizeof(int) * (n + 1));
memo[0]=0; memo[1]=1;
for(int i=2; i<=n; i++)
    memo[i]=memo[i-1] + memo[i-2];
return memo[n];
}

/*========================================================*/
// 优化备忘录
int fib(int n){
if(n<2)
    return n;
int prev = 0, current = 1;
int sum;
while(n>=2){
    sum = prev + current;
    prev = current;
    current = sum;
    n--;
}
return sum;
}
