int f (vector<int> &arr,int n,int x){
	int low = 0;
	int high = n-1;
	int first = -1;

	while(low <= high){
		int mid = (low+high) /2 ;
                if (arr[mid] == x) {
                  first = mid;
				  high = mid - 1;
                }
				else if(arr[mid] < x){
					low = mid + 1;
				}
				else{
					high = mid - 1;
				}
        }
		return first;
}
int l (vector<int> &arr,int n,int x){
	int low = 0;
	int high = n-1;
	int last = -1;

	while(low <= high){
		int mid = (low+high) /2 ;
                if (arr[mid] == x) {
                  last = mid;
				  low = mid + 1;
                }
				else if(arr[mid] < x){
					low = mid + 1;
				}
				else{
					high = mid - 1;
				}
        }
		return last;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
	int first = f(arr,n,k);
	if(first == -1) return {-1,-1};
	int last = l(arr,n,k);
	return {first,last};
}

tc = o(2 * logn)