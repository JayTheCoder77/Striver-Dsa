int NthRoot(int n, int m) {
  // Write your code here.
  for(int i = 1;i <= m;i++){
    if((pow(i,n)) == m) return i;
    else if(pow(i,n) > m) break;
  }
  return -1;
}
tc = o (nth root (n)) as we break if it exceeds



// tc = o (n) where n is the number whose root is to be found
