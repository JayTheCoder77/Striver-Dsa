int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    int n = arr.size();
    int count = 0;
    for(int i = 0 ; i<n;i++){
        for (int j = i ; j<n;j++){
            int sum = 0;
            for(int k = i ; k <= j ; k++){
                sum += arr[k];
            }
            if(sum == k) count++;
        }
    }
    return count;
}