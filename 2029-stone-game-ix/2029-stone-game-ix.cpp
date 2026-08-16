class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        // Count stones according to remainder when divided by 3
        for (int x : stones) {
            cnt[x % 3]++;
        }

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];

        // If there are no remainder-1 or remainder-2 stones,
        // Alice cannot make a valid first move.
        if (one == 0 && two == 0)
            return false;

        // If count of remainder-0 stones is even,
        // the game between remainder 1 and 2 determines the result.
        if (zero % 2 == 0) {
            return one > 0 && two > 0;
        }

        // zero is odd
        // Alice can win if one side has enough stones
        // compared to the other.
        return abs(one - two) > 2;
    }
};