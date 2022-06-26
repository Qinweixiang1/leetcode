#define N 3500

bool isValid(char * s){
char stack[N]={0}; int i=0;
int str=strlen(s);
int j=0;
int c=0;
while(j<str){
if(s[j]=='(' || s[j]=='{' || s[j]=='[') {
    stack[i++]=s[j++]; 
    continue;
}
if(i){
c=stack[--i]; 
if(c=='(') if(s[j++]==')') continue; 
if(c=='{') if(s[j++]=='}')continue;
if(c=='[') if(s[j++]==']') continue;
}
return 0;
}
return i==0;
}
