typedef struct {
int **d;
int c,r;
} SubrectangleQueries;


SubrectangleQueries* subrectangleQueriesCreate(int** rectangle, int rectangleSize, int* rectangleColSize) {
SubrectangleQueries* S=(SubrectangleQueries*)malloc(sizeof(SubrectangleQueries));
S->d=(int**)malloc(sizeof(int*)*rectangleSize);
for(int i=0;i<rectangleSize;i++){
S->d[i]=(int*)malloc(sizeof(int)*(*rectangleColSize));
}

for(int i=0;i<rectangleSize;i++){
    for(int j=0;j<(*rectangleColSize);j++){
        S->d[i][j]=rectangle[i][j];
    }
}
S->r=rectangleSize;
S->c=rectangleColSize;
return S;
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries* obj, int row1, int col1, int row2, int col2, int newValue) {
int a=col1;
while(row1<=row2){
while(a<=col2){
    obj->d[row1][a++]=newValue;
}

a=col1;
row1++;
}
}

int subrectangleQueriesGetValue(SubrectangleQueries* obj, int row, int col) {
return obj->d[row][col];
}

void subrectangleQueriesFree(SubrectangleQueries* obj) {
for(int i=0;i<obj->r;i++)
free(obj->d[i]);

free(obj->d);
free(obj);
}

/**
 * Your SubrectangleQueries struct will be instantiated and called as such:
 * SubrectangleQueries* obj = subrectangleQueriesCreate(rectangle, rectangleSize, rectangleColSize);
 * subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);
 
 * int param_2 = subrectangleQueriesGetValue(obj, row, col);
 
 * subrectangleQueriesFree(obj);
*/
