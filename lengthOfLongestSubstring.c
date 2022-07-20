#define max(a,b) ((a)>(b)?(a):(b))

int lengthOfLongestSubstring(char * s){
    if(*s == '\0')
        return 0;

    int map[128]={0};
    char *p1=s, *p2=s;
    int res=0;
    while(*p2 != '\0'){
        map[*p2]++;
        while(map[*p2]>1){
            map[*p1]--;
            p1++;
        }
        p2++;
        res=max(res,p2-p1);
    }
    return res;
}
