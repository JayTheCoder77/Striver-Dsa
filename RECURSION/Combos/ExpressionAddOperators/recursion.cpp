class Solution {
    public:
        void generate(string s, int target , vector<string> &ans , int i, string path, long eval , long residual){
            // base case
            if(i == s.length()){
                if(eval == target) ans.push_back(path);
                return;
            }
    
            string current;
            long num = 0;
            // backtracking loop
            for(int j = i ; j < s.length(); j++){
                // handle zeroes
                if(j > i && s[i] == '0') return;
                current += s[j];
                num = num * 10 + s[j] - '0';
                if(i == 0) generate(s,target,ans,j+1,path+current,num,num);
                else{
                    generate(s,target,ans,j+1,path+'+'+current,eval+num,num);
                    generate(s,target,ans,j+1,path+'-'+current,eval-num,-num);
                    generate(s,target,ans,j+1,path+'*'+current,eval - residual + residual * num , residual * num);
                }
            } 
        }
        vector<string> addOperators(string num, int target) {
            vector <string> ans;
            generate(num,target,ans,0,"",0,0);
            return ans;
        }
    };

    tc = o(3^n * n)
    sc = O(n) + O(3^n)