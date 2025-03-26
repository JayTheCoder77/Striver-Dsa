swap two nums

void swapNumber(int &a, int &b) {
	// Write your code here.
	// using xor
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

temp = a
a = b
b = temp

------------------------------------------------------
check if ith bit is in set or not -> brute for loop
better =>
// brute
string convertToBinary(int n){
    string res = "";
    while(n > 0){
        if(n % 2 == 1) res += '1';
        else res += '0';
        n = n / 2;
    }
    reverse(res.begin(),res.end());
    return res;
}
bool isKthBitSet(int n, int k)
{
    // Write your code here.
    string binary = convertToBinary(n);
    // If k is out of bounds
    if (k > binary.length()) return false;
    
    // Correct index conversion
    int index = binary.length() - k;
    return binary[index] == '1';
}

optimal
class Solution {
    public:
      bool checkKthBit(int n, int k) {
          // Your code here
          left shift
          if(n & (1 << k) != 0) return true;
          return false;
          
          right shift
          if((n >> k) & (1) != 0) return true;
          return false;
      }
      tc , sc = o(1)
  };
------------------------------------------------------

set the ith bit
optimal

class Solution {
    public:
      int setKthBit(int n, int k) {
          // Code here
          return ((n) | (1 << k));
      }
  };

-------------------------------------------------------
clear the ith bit

int clear_bit = num & ~(1 << i);

-------------------------------------------------------
toggle ith bit 
if set -> clear and vice versa

brute -> convert to binary check the bit and reconvert to decimal

optimal

int toggle_bit = num ^ (1 << i);
-------------------------------------------------------

remove last set bit (rightmost)

eg 16 -> 10000
   15 -> 01111 
   as we see in n-1 the bits after rightmost set bit are 1's

   return (n & (n-1));

--------------------------------------------------------

set rightmost bit 

15 -> 01111 
31 -> 11111

class Solution {
    public:
      int setBit(int n) {
          // Write Your Code here
           return (n | (n+1));
      }
  };

----------------------------------------------------------

check if power of 2

if only 1 set bit in binary form then power of 2
if more than one then its not a power of 2

bool isPowerofTwo(int n) {
    // code here
    if(((n) & (n - 1)) == 0 && n > 0) return true;
    return false;
}
----------------------------------------------------------

count set bits

// 1. __builtin_popcount(n) returns set bits count
int countSetBits(int n)
{
    // Your logic here
    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        count += __builtin_popcount(i);
    }
    return count;
}
// 2.
int count(int n) {
    int count = 0;
    while (n > 1) {  
        count += (n & 1);  
        n = n >> 1;  
    }
    if(n == 1) count += 1;
    return count;
    tc = o(logn base2)
}
// .3
int count(int n) {
    int count = 0;
    while (n != 0) {   
        n = n & n-1;  
        count++;
    }
    return count;
}s
tc = o(no of set bits) o(31) worst case
sc = o(1)
----------------------------------------------------------

check odd or not
bool isEven(int n) {
    // code here
    if((n & 1) == 0) return true;
    return false;
}