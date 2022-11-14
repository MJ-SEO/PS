class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int l_sum[10001];
        int r_sum[10001];
        
        l_sum[0] = 0;
        r_sum[0] = 0;
        
        for(int i=1; i<=nums.size(); i++){
            l_sum[i] = l_sum[i-1] + nums[i-1];
            r_sum[i] = r_sum[i-1] + nums[nums.size()-i];
        }
        
        for(int i=0; i<nums.size(); i++){
            if(l_sum[i] == r_sum[nums.size()-(i+1)]) {
                return i;
            }
        }
        
        return -1;
    }
};