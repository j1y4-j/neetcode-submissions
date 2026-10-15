class Solution {
public:
    int findMin(vector<int> &nums) {
        int st=0;
        int ed=nums.size()-1;
        int mi=INT_MAX;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(nums[mid]>=nums[st]){
                mi=min(mi,nums[st]);
                st=mid+1;
            }
            else{
                mi=min(mi,nums[mid]);
                ed=mid-1;
            }
        }
        return mi;
    }
};
