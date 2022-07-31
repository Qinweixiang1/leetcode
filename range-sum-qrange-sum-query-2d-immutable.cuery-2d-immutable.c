void display(int **obj, int size, int col){
    for(int i=0; i<size; ++i){
        for(int j=0; j<col; ++j)
            printf("%4d ",obj[i][j]);
        putchar('\n');
    }
    putchar('\n');
}


// typedef struct {

// } NumMatrix;
typedef int** NumMatrix;

NumMatrix numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix obj=(NumMatrix)malloc(sizeof(int*) * (matrixSize + 1 ) );
    for(int i=0; i< matrixSize + 1; i++){
        obj[i]=(int*)malloc(sizeof(int)* ((*matrixColSize)+ 1) );
        memset(obj[i],0,sizeof(int)* ((*matrixColSize) + 1) );
    }
    for(int i=1; i<= matrixSize; ++i)
        for(int j=1; j<=(*matrixColSize);++j)
            obj[i][j]=obj[i-1][j] + obj[i][j-1] + matrix[i - 1][j - 1] - obj[i-1][j-1]; 
    return obj;
}

int numMatrixSumRegion(NumMatrix obj, int row1, int col1, int row2, int col2) {
    return obj[row2+1][col2+1] - obj[row1][col2+1] - obj[row2+1][col1] + obj[row1][col1];
}

void numMatrixFree(NumMatrix* obj) {

}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
