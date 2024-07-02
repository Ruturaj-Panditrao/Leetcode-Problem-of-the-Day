// 2 July 2024
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Comment : Solved Myself but Optimized Approach to Mine and an alternate Approach exists
// These are after my Solution :

// My Solution : O(M+N) Time and O(2002) Space :

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mp1(1001,0);
        vector<int>mp2(1001,0);
        for(int i=0; i<nums1.size();i++) mp1[nums1[i]]++;
        for(int i=0; i<nums2.size();i++) mp2[nums2[i]]++;
        vector<int>ans;
         for(int i=0; i<1001; i++)
         {
            if(mp1[i]==0 || mp2[i]==0) continue;

            for(int j=0; j<min(mp1[i],mp2[i]);j++)
            {
                ans.push_back(i);
            }
         }
         return ans;
    }
};

// Optimized Approach : Don't use 2 Frequency Arrays, use only 1 
// O(M+N) Time and O(1001) Space 

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mp(1001,0);
        for(int i=0; i<nums1.size();i++) mp[nums1[i]]++;
        vector<int>ans;
        
        for(int i=0; i<nums2.size(); i++)
        {
            if(mp[nums2[i]]>=1)
            {
                ans.push_back(nums2[i]);
                mp[nums2[i]]-=1;
            }
        }

         return ans;
    }
};

// Sorting to avoid using Space
// O(MlogM + NlogN + N + M) Time and O(1) Space

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int>ans;
        
        while(i<nums1.size() && j<nums2.size())
        {
        if(nums1[i]==nums2[j]) 
        {
            ans.push_back(nums1[i]);
            i++;  j++;
        }

        // My failed way unnecessary checks will be required
        // if(nums1[i]!=nums2[j])
        // {
        //     if(nums1[i]==nums1[i-1] && i>=1) i++;
        //     if(nums2[j]==nums2[j-1] && j>=1) j++;
        // }

        // An easier way
        else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};
