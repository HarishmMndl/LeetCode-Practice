class Solution {
public:
    bool checkDivisibility(int n) {
      int totalsum = 0;
      int totalprod = 1;
      
      int num  = n;

      while(num>0){
        int digit = num % 10;

        totalsum += digit;
        totalprod *= digit;

        num /= 10;
      }

      if(n % (totalsum + totalprod) == 0) return true;

      return false;
        
    }
};