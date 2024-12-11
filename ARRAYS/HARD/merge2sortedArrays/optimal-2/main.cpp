// uses shell sort - gap method/technique

#include<vector>
void swapIfgreater(vector<long long> &a, vector<long long> &b ,int ind1,int ind2){
	if(a[ind1] > b[ind2]){
		swap(a[ind1] , b[ind2]);
	}
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n = a.size();
	int m = b.size();
	int len = n + m;
	int gap = (len / 2) + (len % 2);
        while (gap > 0) {
          int left = 0;
          int right = left + gap;
		  while(right < len){
			  //arr1 and arr2
			  if(left < n && right >= n){
				  swapIfgreater(a, b, left, right - n);
			  }
			  //arr2 and arr2
			  else if(left >=n){
				  swapIfgreater(b, b, left -n, right-n);
			  }
			  //arr1 and arr1
			  else{
				  swapIfgreater(a, a, left, right);
			  }
			  left++ ;
			  right++;
		  }
			  if(gap == 1) break;
			  gap = (gap/2) + (gap%2);
        }
}

tc = log 2 (n + m)  * o(n+m)
sc = o(1)