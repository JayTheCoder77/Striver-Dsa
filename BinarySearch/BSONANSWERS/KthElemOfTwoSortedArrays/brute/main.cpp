int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    int n1 = arr1.size() , n2 = arr2.size();
    // k -= 1;
    vector<int> arr3;
    int i = 0 , j = 0;
    while(i < n1 && j < n2){
      if (arr1[i] <= arr2[j]) {
        arr3.push_back(arr1[i]);
        i++;
      } else {
        arr3.push_back(arr2[j]);
        j++;
      }
    }
    while(i < n1){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j < n2){
        arr3.push_back(arr2[j]);
        j++;
    }
    return arr3[k-1];  //either k-1 or above k -= 1;
}

tc = o(n1 + n2);
sc = o(n1 + n2);