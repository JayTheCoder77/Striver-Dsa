// overflow case
int func(int mid , int n , int m){
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = ans * mid;
      if (ans > m)
        return 2;
    }
   if (ans == m) return 1;
   return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1;
  int high = m;
  while (low <= high) {
    long long mid = (low + high) / 2; 
    long long eval = func(mid, n ,m);
    if (eval ==2) {
      high = mid - 1;
    } else if(eval == 0){
      low = mid + 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

tc = o(n log m) n is root and m is the number whose root is to be found