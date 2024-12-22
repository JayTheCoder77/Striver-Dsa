int team(vector <int> & skill, int n)
{
    // Write your code here.
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(skill[i] > 2 * skill[j]){
                count++;
            }
        }
    }
    return count;
}

tc = o(n2)
sc = o(1)