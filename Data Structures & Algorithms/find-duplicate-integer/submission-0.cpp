class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        std::unordered_map<int, int> tracking;

        for(int i{0}; i < nums.size(); i++) {

            if(tracking.contains(nums[i])) {
                return nums[i];
            } else {
                tracking[nums[i]] = 1; //value is the key
            }
        }
    }
};
