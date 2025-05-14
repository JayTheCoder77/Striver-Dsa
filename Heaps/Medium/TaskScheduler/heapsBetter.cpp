optimal solution is greedy
this is the better solution using max heap  
class Solution {
public:
    // greedy is most optimal for this
    // but right here is the max heap solution
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        unordered_map<int,int> freq;
        // mapping frequencies
        for(int i = 0 ; i < tasks.size() ; i++) freq[tasks[i]]++;
        // push freq to max heap
        for(auto &e : freq) maxHeap.push(e.second);

        int time = 0;
        // cooldown queue
        queue<pair<int,int>> cooldown;
        while(!maxHeap.empty() || !cooldown.empty()){
            time++;

        if (!maxHeap.empty()) {
            int count = maxHeap.top(); maxHeap.pop();
            count--;
            if (count > 0)
                cooldown.push({count, time + n});
        }

        if (!cooldown.empty() && cooldown.front().second == time) {
            maxHeap.push(cooldown.front().first);
            cooldown.pop();
        }   
                
        }
        return time;
    }
};

tc = o(nlogn)
sc = o(n)