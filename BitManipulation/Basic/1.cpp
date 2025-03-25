string convertToBinary(int n){
    string res = "";
    while(n != 1){
        if(n % 2 == 1) res += '1';
        else res += '0'
        n = n / 2;
    }
    reverse(res);
    return res;
    tc = 0(logn + logn)
    sc = o(logn)
}
int convertToDecimal(int x){
    int len = x.length();
    int num = 0;
    int p2 = 1;
    for(i = len - 1; i >= 0 ; i++){
        if(x[i] == '1'){
            num += p2;
            p2 = p2 * 2;
        }
    }
    tc = 0(string length)
    sc = o(1)
}

// get set and clear ith bit

class Solution {
    public:
      void bitManipulation(int num, int i) {
          // your code here
           // 1. Get the ith bit (1-based index)
          int get_bit = (num >> (i - 1)) & 1;
          
          // 2. Set the ith bit
          int set_bit = num | (1 << (i - 1));
          
          // 3. Clear the ith bit
          int clear_bit = num & ~(1 << (i - 1));
          
          // Print the results space-separated
          cout << get_bit << " " << set_bit << " " << clear_bit;
      }
  };