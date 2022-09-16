class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1, r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    vector<int> temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[l++];
                    temp[2]=nums[r--];
                    ans.push_back(temp);
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
                else if(sum<0) l++;
                else r--;
            }
            
            while(i<nums.size()-2 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};