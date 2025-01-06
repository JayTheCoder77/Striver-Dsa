int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == k) return i;
    }
    return -1;
}

tc = o(n)