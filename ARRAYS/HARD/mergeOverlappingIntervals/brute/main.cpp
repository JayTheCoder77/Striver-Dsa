#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();
	sort(arr.begin(),arr.end());
	vector <vector <int>> ans; 

	for(int i = 0 ; i < n ; i++){
		int start = arr[i][0];
		int end = arr[i][1];
		if(!ans.empty() && end <= ans.back()[1]){
			continue;
		}
		for(int j = i+1 ; j < n ; j++){
			if(arr[j][0] <= end){
				end = max(end , arr[j][1]);
			}
			else{
				break;
			}
		}
            ans.push_back({start, end});
        }

	return ans;
}

tc = o(nlogn) + o(2N) as break and continue are used
sc = o(n)