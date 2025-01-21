int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
   // k -= 1;  // to get it to 0 based indexing
    int n1 = arr1.size() , n2 = arr2.size();
    int i = 0 , j = 0;
    int count = 0 , result = 0;
    while(i < n1 && j < n2){
      if (arr1[i] <= arr2[j]) {
        result = arr1[i];
        i++;
      } else {
        result = arr2[j];
        j++;
      }
      count++;
      if(count == k) return result;
    }
    while(i < n1){
        result = arr1[i];
        i++;
        count++;
        if(count == k) return result;
    }
    while(j < n2){
        result = arr2[j];
        j++;
        count++;
        if(count == k) return result;
    }
    return -1;  
}

tc = o(n1+n2)
sc = o(1)