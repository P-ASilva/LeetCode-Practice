int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int sumT[n];
    int bias[n];
    for (int i = 0; i < n;i++) {
      sumT[i] = 0;
      bias[i] = 0;
    }
    for (int i = 0; i < trustSize; i++) {
        sumT[trust[i][1]-1]++;
        bias[trust[i][0]-1]++;
    }
    for (int i = 0; i < n; i++) {
        //printf("%d %d\n", bias[i], sumT[i]);
        if (bias[i] == 0 && sumT[i] == n-1) {
            return i+1;
        }
    }
    return -1;
} 