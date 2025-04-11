brute

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            vector <int> nge (n,-1);
            for(int i = 0 ; i < nums1.size() ; i++){
                bool found = false;
                for(int j = 0 ; j < nums2.size() ; j++){
                    if(nums1[i] == nums2[j]) found = true;
                    if(found && nums2[j] > nums1[i]){
                        nge[i] = nums2[j];
                        break;
                    }
                }
            }
            return nge;
        }
    };


optimal


class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> nextGreater;  
            stack<int> st;
            for(int i : nums2){
                while(!st.empty() && st.top() < i){
                    nextGreater[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            while(!st.empty()){
                nextGreater[st.top()] = -1;
                st.pop();
            }
            vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = nextGreater[nums1[i]];
        }
        
        return result;
        }
    };

    tc = o(n + m)