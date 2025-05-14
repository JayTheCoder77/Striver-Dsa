most optimal greedy solution

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
    for (char task : tasks)
        freq[task - 'A']++;

    sort(freq.begin(), freq.end());

    int maxFreq = freq[25];
    int maxCount = 1;

    // Count how many tasks have the same max frequency
    for (int i = 24; i >= 0; i--) {
        if (freq[i] != maxFreq) break;
        maxCount++;
    }

    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int emptySlots = partCount * partLength + maxCount;

    return max((int)tasks.size(), emptySlots);
    }
};

