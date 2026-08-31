/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <limits.h>
#include <stdlib.h>

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize)
{
    int* ans = malloc(2 * sizeof(int));
    *returnSize = 2;

    
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }

    int firstCritical = -1;
    int lastCritical = -1;

    int minDistance = INT_MAX;

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;

    int index = 1;

    while (curr->next != NULL)
    {
        int nextVal = curr->next->val;

        
        if ((curr->val > prev->val && curr->val > nextVal) ||
            (curr->val < prev->val && curr->val < nextVal))
        {
            
            if (firstCritical == -1)
            {
                firstCritical = index;
            }
            else
            {
                
                int distance = index - lastCritical;

                if (distance < minDistance)
                    minDistance = distance;
            }

            
            lastCritical = index;
        }

        prev = curr;
        curr = curr->next;
        index++;
    }

    
    if (firstCritical == lastCritical)
    {
        ans[0] = -1;
        ans[1] = -1;
    }
    else
    {
        ans[0] = minDistance;
        ans[1] = lastCritical - firstCritical;
    }

    return ans;
}