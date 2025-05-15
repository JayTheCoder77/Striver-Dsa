class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int,int> hash;
        priority_queue<int , vector<int> , greater<int>> minHeap;
        for(int i = 0 ; i < hand.size() ; i++) hash[hand[i]]++;
        for (auto& e : hash) {
            minHeap.push(e.first);
        }
        while(!minHeap.empty()){
            int first = minHeap.top();
            for(int i = first ; i < first + groupSize ; i++){
                if(hash[i] == 0) return false;
                hash[i]--;
                if(hash[i] == 0 && i == minHeap.top()) minHeap.pop();
            }
        }
        return true;
    }
};

