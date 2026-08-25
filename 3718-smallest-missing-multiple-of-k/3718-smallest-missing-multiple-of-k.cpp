class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
      vector<int> store;
      int n = nums.size();
      
      for(int i=0; i < n; i++){
        if(nums[i] % k == 0){
            store.push_back(nums[i]);
        }
      }
      sort(store.begin(),store.end());
      int multiple = 1;
      for(int i = 0; i < store.size(); i++){
        if(store[i] / k == multiple) multiple++;
        else if(i > 0 && store[i] == store[i-1]) {
                continue;   // duplicate ignore
            }
        else break;
      }
      
      
      return (multiple * k);
    
    }
};