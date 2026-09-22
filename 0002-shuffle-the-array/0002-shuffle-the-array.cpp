class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr1;
        vector<int> arr2;

        for(int i = 0; i < 2*n; i++){
            if(i < n){
                arr1.push_back(nums[i]);
            }else
            arr2.push_back(nums[i]);
        }

        int x = arr1.size();
        int y = arr2.size();

        int i = 0;  
        int j = 0;
        int k = 0;
        while(i < x && j < y){
            nums[k] = arr1[i];
            k++;
            i++;
            nums[k] = arr2[j];
            k++;
            j++;
        }

        return nums;
    }
};