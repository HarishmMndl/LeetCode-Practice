class Solution {
public:
    int smallestNumber(int n, int t) {

        int x = n;

        while (true) {

            int temp = x;
            int pro = 1;

            while (temp > 0) {
                pro *= (temp % 10);
                temp /= 10;
            }

            if (pro % t == 0)
                return x;

            x++;
        }
    }
};