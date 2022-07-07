/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
int* decode=(int*)malloc( sizeof(int)*(encodedSize+ 1));
memset(decode,0,(sizeof(int)*encodedSize) + 1);
*returnSize=1+encodedSize;
int a=0;
decode[0]=first;
for(int i=0;i<encodedSize;i++){
    a=encoded[i]^first;
    decode[i]=first;
    decode[i+1]=a;
    first=a;
}


return decode;
}
