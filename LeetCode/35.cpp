class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right){
            int middle = (left + right)/2;
            
            if(nums[middle] == target) return middle;
                
            if(nums[middle] < target){
                left = middle + 1;
            }
            else{
                right = middle - 1;
            }
        }
        
        return left;     
    }
};
