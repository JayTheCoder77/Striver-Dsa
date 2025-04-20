vector<int> calculateSpan(vector<int>& arr) {
    // write code here
    
vector<int> days(arr.size() ,1);
for(int i = 0 ; i < arr.size() ; i++){
    int count = 1;
    for(int j = i-1 ; j >=0 ; j--){
        if(arr[j] > arr[i]) break;
        else count++;
    }   
    days[i] = count;
}
return days;
}

// leetcode brute


class StockSpanner {
    public:
        vector<int> arr;
        StockSpanner() {
            
        }
        
        int next(int price) {
            arr.push_back(price);
            int count = 1;
            for(int i = arr.size()-2 ; i>= 0 ; i--){
                if(arr[i] <= price) count++;
                else break;
            }
            return count;
        }
    };

tc = o(no of days)
sc = o(total number of next calls)