int t_map(const char * t, int *map){
    //map[]里t小于等于0 返回1；
    int and=1;
    while(and && *t != '\0'){
        and =  and &  map[*t]<=0;
        t++;
    }
    return and;
}

char * minWindow(char * s, char * t){
    int t_len= strlen(t);
    int s_len=strlen(s);
    if(t_len>s_len)
        return "";
    
    int window[128]={0};

    char *p1=t;
    while(*p1 != '\0'){
        window[*p1]++;
        p1++;
    }

    char *p2 = s;
    p1=s;
    char *result=(char*)malloc(sizeof(char)*s_len+1);
    memset(result,0,sizeof(char)*s_len+1);
    while(*p2 != '\0'){
        if(--window[*p2++]==0 && t_map(t, window)){
            while(++window[*p1++]<=0)
                ;

            if(strlen(result)==0 || p2-p1 < strlen(result)){
                memset(result,0,sizeof(char)*s_len+1);
                strncpy(result, p1-1, p2-p1+1);
            }   
        }
    }
    return result;
}



// 评论区高分解
// #define MAX_LEN 123
// #include <limits.h>
// char *minWindow(char *s, char *t)
// {
//     int store[MAX_LEN] = {0};
//     int lent = (int)strlen(t);
//     int lens = (int)strlen(s);

//     for (int i = 0; i < lent; i++) {
//         store[t[i]]++;
//     }

//     int left = 0;
//     int right = 0;
//     int size = 0;
//     int start = 0;
//     int min = INT_MAX;

//     for (right = 0; right < lens; right++) {
//         if (store[s[right]]-- > 0) {
//             lent--;
//         }

//         while (lent == 0) {
//             size = right - left + 1;
//             if (size < min) {
//                 min = size;
//                 start = left;
//             }

//             if(++store[s[left]]>0)
//             {
//                 lent++;
//             }

//             left++;
//         }
//     }
    
//     if (min != INT_MAX) {
        
//         char *ret=(int *)malloc(sizeof(char)*(min+1));
//         *ret = '\0';
//         strncat(ret,s+start,min);
//         return ret;
//     }

//     return "";
// }
