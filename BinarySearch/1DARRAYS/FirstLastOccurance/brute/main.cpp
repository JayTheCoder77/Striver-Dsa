pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    //brute
    int first = -1 , last = -1;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == k){
          if (first == -1) {
            first = i;
          }
            last = i;
        }
    }
    return make_pair(first,last);
}

tc = O(log(n))