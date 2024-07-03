// 3 July 2024
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

// Comment :
// Was able to figure out some cases of the problem, but not all.

// Approach 1 :
// Time Complexity : O(NlogN)
// Space Complexity : O(1)

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) return 0;
        sort(nums.begin(),nums.end());

        int ans = INT_MAX;
        ans = min(ans,nums[n-4]-nums[0]);
        ans = min(ans,nums[n-1]-nums[3]);
        ans = min(ans,nums[n-2]-nums[2]);
        ans = min(ans,nums[n-3]-nums[1]);

        return ans;
        // return min(nums[nums.size()-4]-nums[0],nums[nums.size()-1]-nums[3]);   
    }
};

// Approach 2 : Optimized
// Time Complexity : O(N)+O(nN logk)
// Space Complexity : O(logK)+O(N) if the same Array is used else O(8) if a new array is used to save only the first minimum 4 and last minimum 4 elements

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) return 0;
        // sort(nums.begin(),nums.end());

        priority_queue<int>maxHeap;
        // Maxheap pops out the maximum number thereby keeping the minimum
        // Minheap pops out the minimum number thereby keeping the maximum
        priority_queue<int, vector<int>,greater<int>>minHeap;

        for(int i=0; i<nums.size();i++)
        {
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);

            if(maxHeap.size()>4) maxHeap.pop();
            if(minHeap.size()>4) minHeap.pop();
        }

        int l = 3;
        int r = nums.size()-4;

        while(!maxHeap.empty())
        {
            nums[l] = maxHeap.top();
            l--;
            maxHeap.pop();

            nums[r] = minHeap.top();
            r++;
            minHeap.pop();
        }

        int ans = INT_MAX;
        ans = min(ans,nums[n-4]-nums[0]);
        ans = min(ans,nums[n-1]-nums[3]);
        ans = min(ans,nums[n-2]-nums[2]);
        ans = min(ans,nums[n-3]-nums[1]);

        return ans;
        // return min(nums[nums.size()-4]-nums[0],nums[nums.size()-1]-nums[3]);   
    }
};
