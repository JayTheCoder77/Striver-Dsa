 vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long xor1 = 0;
        for(int i = 0 ; i < n ; i++){
            xor1 ^= (long long)arr[i];
            xor1 ^= (long long)(i + 1);
        }
        int bitNum = xor1 & ~(xor1 - 1);
        // while(1){
        //     if((xor1 & (1 << bitNum)) != 0){
        //         break;
        //     }
        //     bitNum++;
        // }
        int zero = 0;
        int one = 0;
        for(int i = 0 ; i < n ; i++){
            if((arr[i] & (bitNum)) != 0){
                one = one ^ arr[i];
            }
            else{
                zero = zero ^ arr[i];
            }
        }
        for(int i = 1 ; i <= n ; i++ ){
            if((i & ( bitNum)) != 0){
                one = one ^ i;
            }
            else{
                zero = zero ^ i;
            }
        }
        int count = 0;
        for (int i = 0 ; i < n ; i++){
            if(arr[i] == zero) count++;
        }
        if (count == 2) return {zero,one};
        return {one,zero};
    }

    tc = o(4n) = o(n)
    sc = o(1)