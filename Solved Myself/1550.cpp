// 1 July 2024
// https://leetcode.com/problems/three-consecutive-odds/description/

// Comments : Solved Myself, but cleaner code exists.
// Approach 1 : Brute Force : if(arr[i]%2==1 && arr[i+1]%2==1 && arr[i+2]%2==1) 
// Approach 2 : Counting : Increment Counter whenever we see Odd Nos. If Counter Reaches 3, return true. Whenever we see Even, reset the counter to 0.
// Approach 3 : prod = arr[i]*arr[i+1]*arr[i+2] and if(prod%2==1) return true;

// All above Solutions have O(N) Time Complexity and O(1) Space Complexity

// My O(N) Time Complexity and O(1) Space Complexity Solution : 

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        if(arr.size()<3) return false;

        int l = 0;
        int r = 2;
        int prod = 1;
        for(int i=l; i<=r; i++)
        {
            prod*=arr[i];
        }

        if(prod%2==1) return true;
        while(r<arr.size()-1)
        {  
            prod/=arr[l];
            l++;
            r++;
            prod*=arr[r];

            if(prod%2==1) return true;
        }

        return false;
    }
};
