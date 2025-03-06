void generate(vector<int> &ans,vector<int> &num,int ind,int n,int sum){
	if(ind == n){ 
		ans.push_back(sum);
		return;
	}
	generate(ans,num,ind + 1,n,sum + num[ind]);
	generate(ans,num,ind + 1,n,sum);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> ans;
	int n = num.size();
	generate(ans,num,0,n,0);
	sort(ans.begin(),ans.end());
	return ans;	
}

tc = o(2^n) + o(2^n log(2^n)) for sorting
sc = O(2^n) + O(n)

for brute of this problem use code from power set