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
