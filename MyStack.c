
#define N 20

typedef struct {
int *base;
int top;
} MyStack;


MyStack* myStackCreate() {
MyStack *S;
S=(MyStack*)malloc(sizeof(MyStack));
S->top=0;
S->base=(int*)malloc(sizeof(int)*N);
return S;
}

void myStackPush(MyStack* obj, int x) {
obj->base[(obj->top)++]=x;
}

int myStackPop(MyStack* obj) {
return obj->base[--(obj->top)];
}

int myStackTop(MyStack* obj) {
return obj->base[obj->top-1];
}

bool myStackEmpty(MyStack* obj) {
return obj->top==0;
}

void myStackFree(MyStack* obj) {
free(obj->base);
obj->top=0;
free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
