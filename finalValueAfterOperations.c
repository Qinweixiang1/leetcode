int finalValueAfterOperations(char ** operations, int operationsSize){
int x=0;
for(int i=0;i<operationsSize;i++)
    operations[i][1]=='+'?x++:x--;


return x;
}
