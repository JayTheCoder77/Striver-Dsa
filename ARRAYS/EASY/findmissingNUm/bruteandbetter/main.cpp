int missingNumber(vector<int>&a, int N) {
    // Write your code here.
    // BETTER - HASHING

    int hash[N+1] ={0};
    for(int i = 0; i < N-1 ; i++){
      hash[a[i]] = 1;
    }
    for(int i = 1;i <= N ; i++){
        if(hash[i] == 0){
            return i;
        }
    }
}

    //BRUTE FORCE
    // for(int i =1 ; i <=N ; i++){
    //     int flag = 0;
    //     for(int j = 0;j < N;j++){
    //         if(a[j] == i){
    //             flag = 1;
    //         }
    //     }
    //     if(flag == 0){
    //         return i;
    //     }
    // }