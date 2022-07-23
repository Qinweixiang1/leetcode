int cmp_s1_dict(const int *a, const int *b, const char *s1){
    int and =1;
    while(*s1!='\0'){
        if(!(and = and & a[*s1%26]==b[*s1%26]))
            return and;     
        s1++;
    }
    return and;
}

bool checkInclusion(char * s1, char * s2){
int m=strlen(s1);
int n=strlen(s2);
int a[26]={0};
int b[26]={0};
char *p1=s1, *p2=s2;
while(*p1 != '\0'){
    ++a[*p1%26];
    p1++;
}
p1=s2;
while(*p2 != '\0'){
    b[*p2%26]++;
    if(p2-p1+1 == m){
        if(cmp_s1_dict(a, b, s1))
            return 1;
        else{
            --b[*p1%26];
            p1++;
        }
    }
    p2++;
}
return 0;
}
