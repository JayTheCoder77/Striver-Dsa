class Solution {
    public:
      vector<int> nextLargerElement(vector<int>& arr) {
          // code here
          int n = arr.size();
          vector<int> nge (n,-1);
          for(int i = 0 ; i < arr.size() ; i++){
              for(int j = i+1 ; j < arr.size() ; j++){
                  if(arr[j]> arr[i]){
                      nge[i] = arr[j];
                      break;
                  }
                 
              }
          }
          return nge;
      }
  };
  

tc = 0(n2)
sc = o(n)