bool verifyPostorder(int* sequence, int sequenceLen ) {
    if( sequenceLen <= 1)
        return 1;
    int p = 0;
    while(sequence[p] < sequence[sequenceLen - 1])
        p++;
    for(int i = p; i < sequenceLen - p; ++i)
        if(sequence[i] < sequence[sequenceLen - 1])
            return 0;

     return verifyPostorder(sequence,p) && verifyPostorder(sequence+p,sequenceLen - p - 1);
}
