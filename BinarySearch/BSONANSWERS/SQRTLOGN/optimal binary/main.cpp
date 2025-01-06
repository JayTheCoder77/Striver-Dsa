int floorSqrt(int n) {
  // Write your code here.
  int low = 1;
  int high = n;
  int ans = 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (mid * mid >= n) {
        ans = mid;
      high = mid - 1;
    } else if (mid * mid <= n) {
        ans = mid;
      low = mid + 1;
    }
  }
  return ans;
}
tc = o(logn) base2