struct Item{
    int value;
    int weight;
};

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        // per unit wt check
        // (100 , 20) = 20 -> gives 100
        // therefore 1 -> gives 100 / 20 = 5
       
        int n = val.size();
        // Pair: {value per unit weight, index}
        vector<pair<double, int>> ratioIndex;

        for (int i = 0; i < n; ++i) {
            double ratio = (double)val[i] / wt[i];
            ratioIndex.push_back({ratio, i});
        }

        // Sort by value per unit weight in descending order
        sort(ratioIndex.rbegin(), ratioIndex.rend());

        double totalValue = 0.0;
        for (auto& ri : ratioIndex) {
            int i = ri.second;
            if (wt[i] <= capacity) {
                totalValue += val[i];
                capacity -= wt[i];
            } else {
                totalValue += (double)val[i] / wt[i] * capacity;
                break;
            }
        }

        return totalValue;
    }

};