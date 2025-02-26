class Solution {
    public:
      double power(double b, int e) {
          // code here
          if(e > 0) return recursiveHelper(b,e);
          return 1 / recursiveHelper(b,e);
      }
      double recursiveHelper(double x , long n){
          if(n == 0) return 1.0;
          double res = recursiveHelper(x , n/2);
          res = res * res;
          if(n % 2 == 0) return res;
          else return res * x;
      }
  };

  tc = o(logn)
  sc = o(logn)