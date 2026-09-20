class Solution {
public:
    unordered_map<int,int> mp;
    int n;
    int dp[2001][2001];

    bool solve(vector<int>& stones, int curr_stone_idx, int prev_jump) {

        if(curr_stone_idx == n - 1)
            return true;

        if(dp[curr_stone_idx][prev_jump] != -1)
            return dp[curr_stone_idx][prev_jump];

        for(int nextJump = prev_jump - 1;
            nextJump <= prev_jump + 1;
            nextJump++) {

            if(nextJump > 0) {

                int next_stone =
                    stones[curr_stone_idx] + nextJump;

                if(mp.find(next_stone) != mp.end()) {

                    if(solve(stones,
                             mp[next_stone],
                             nextJump)) {

                        return dp[curr_stone_idx][prev_jump] = 1;
                    }
                }
            }
        }

        return dp[curr_stone_idx][prev_jump] = 0;
    }

    bool canCross(vector<int>& stones) {

        n = stones.size();

        if(stones[1] != 1)
            return false;

        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        memset(dp, -1, sizeof(dp));

        return solve(stones, 0, 0);
    }
};