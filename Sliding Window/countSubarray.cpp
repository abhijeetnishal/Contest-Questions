/*
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
*/

//TC : O(N)
//SC : O(N)

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long start=0, ans=0;
    
    bool minFound=false, maxFound=false;
    int minStart=0, maxStart=0;
    
    for(int i=0;i<nums.size();i++){
        if(nums[i]<minK || nums[i]>maxK){
            minFound=false;
            maxFound=false;
            start=i+1;
        }
        
        if(nums[i]==minK){
            minFound=true;
            minStart=i;
        }
        
        if(nums[i]==maxK){
            maxFound=true;
            maxStart=i;
        }
        
        if(minFound && maxFound){
            ans+=(min(minStart,maxStart)-start+1);
        }
    }
    
    return ans;
}