int reqTime(vector<int> v, int hourly){
    int n = v.size();
    int totalHours = 0;
    for(int i = 0 ; i < n ; i++){
        totalHours += ceil((double)v[i] / hourly);
    }
    return totalHours;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int n = v.size();
    int max = v[0];
    for(int i = 0 ; i < n ; i++){
        if(v[i] > max) max = v[i];
    }
    // max amt of bananas found
    // now calculating time
    for(int i = 1 ; i <= max ; i++){
        int time = reqTime(v,i);
        if(time <= h) return i;
    }
    return max;
}

tc = o(M * n)
M is the max amt of bananas