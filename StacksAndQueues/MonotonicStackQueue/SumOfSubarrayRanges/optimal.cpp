class Solution {
    public:
        // sum of subarray max - sum of subarray min
        // sum min
        // next smaller and previous smaller than equal to
        vector<int> nse(vector<int> &nums){
            int n = nums.size();
            stack<int> s;
            vector<int> nse1(n , n);
            for(int i = n-1 ; i >= 0 ; i--){
                while(!s.empty() && nums[s.top()] > nums[i]){
                    s.pop();
                }
                nse1[i] = s.empty() ? n : s.top();
                s.push(i);
            }
            return nse1;
        }
        vector<int> psee(vector<int> &nums){
            int n = nums.size();
            stack<int> s;
            vector<int> psee1(n , -1);
            for(int i = 0 ; i <= n-1 ; i++){
                while(!s.empty() && nums[s.top()] >= nums[i]){
                    s.pop();
                }
                psee1[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
            return psee1;
        }
        long long sumMin(vector<int> &nums){
            int n = nums.size();
            long long total = 0;
            vector<int> nse1 = nse(nums);
            vector<int> psee1 = psee(nums);
            for(int i = 0 ; i < n ; i++){
                long long left = i - psee1[i];
                long long right = nse1[i] - i;
                long long contribution = (left * right  * nums[i] );
                total = (total + contribution) ;
            }
            return total;
        }
        // sum max
        // next greater and previous greater than equal to
        vector<int> nge(vector<int> &nums){
             int n = nums.size();
            stack<int> s;
            vector<int> nge1(n , n);
            for(int i = n-1 ; i >= 0 ; i--){
                while(!s.empty() && nums[s.top()] < nums[i]){
                    s.pop();
                }
                nge1[i] = s.empty() ? n : s.top();
                s.push(i);
            }
            return nge1;
        }
        vector<int> pgee(vector<int> &nums){
             int n = nums.size();
            stack<int> s;
            vector<int> pgee1(n ,-1);
            for(int i = 0 ; i <= n-1 ; i++){
                while(!s.empty() && nums[s.top()] <= nums[i]){
                    s.pop();
                }
                pgee1[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
            return pgee1;
        }
        long long sumMax(vector<int> &nums){
            int n = nums.size();
            int mod = (int)(1e9 + 7);
            long long total = 0;
            vector<int> nge1 = nge(nums);
            vector<int> pgee1 = pgee(nums);
            for(int i = 0 ; i < n ; i++){
                long long left = i - pgee1[i];
                long long right = nge1[i] - i;
                long long contribution = (left * right* nums[i]);
                total = (total + contribution);
            }
            return total;
        }
        long long subArrayRanges(vector<int>& nums) {
            return sumMax(nums) - sumMin(nums);
        }
    };

    tc = o(10n)
    sc = o(10n)