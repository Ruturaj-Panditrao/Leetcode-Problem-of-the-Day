// 4 July
// https://leetcode.com/problems/merge-nodes-in-between-zeros/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// The Approach of using a new Linked List is Good
// Also, there exists a 2 Pointer Solution that modifies the Existing Linked List
// Current Solution
// Time Complexity : O(N)
// Space Complexity : O(N) // The number of intervals between Zeroes

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* ansList = new ListNode(0);
        ListNode* travel = ansList;
        vector<int>ans;
        int sum = 0;
        while(temp!=NULL)
        {
            if(temp->val==0)
            {
                if(sum!=0)
                {
                    // ans.push_back(sum);
                    travel->next = new ListNode(sum);
                    travel=travel->next;
                    sum=0;
                }
            }
            else sum+=temp->val;
            temp=temp->next;
        }
        // for(auto it : ans) cout<<it<<" ";
        return ansList->next;
    }
};
