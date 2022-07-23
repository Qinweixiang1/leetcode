/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp_p(int *a, int *b, char *p){
    int and = 1;
    while(*p != '\0'){
        if(!(and = and & a[*p%26]==b[*p%26]))
            return and;
        p++;
    }
    return and;
}

int* findAnagrams(char * s, char * p, int* returnSize){
int len_p=strlen(p);
int *result=(int*)malloc(sizeof(int)* strlen(s));
*returnSize=0;
int a[26]={0};
int b[26]={0};
int i=0;
int j=0;
while(p[i] != '\0')
    ++a[p[i++]%26];

i=0;
while(s[j] != '\0'){
    ++b[s[j]%26];
    if(j-i+1==len_p) {
        if(cmp_p(a,b,p)) 
            result[(*returnSize)++]=i;         
        --b[s[i++]%26];
    }
    j++;
}
return result;
}
