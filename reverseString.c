void reverseString(char* s, int sSize){
// int left=0, right=sSize-1;
char *left = s, *right = s+sSize-1;
while(left<right){  
    char tmp=*left;
    *left++=*right;
    *right--=tmp;  
}
}
