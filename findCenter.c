

int findCenter(int** edges, int edgesSize, int* edgesColSize){
int i, j;
i=edges[0][0];
j=edges[0][1];
if(edges[1][0]==i)return i;
if(edges[1][1]==i)return i;
if(edges[1][0]==j)return j;
if(edges[1][1]==j)return j;
return -1;
}
