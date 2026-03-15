1// Company tags: Adobe, Amazon, Apple, Bloomberg, Flipkart, Infosys, Meta, Microsoft, Qualcomm, Snowflake, TikTok, Uber
2
3class Solution {
4public:
5    // T.C: O(n)
6    // S.C: O(n)
7    ListNode* swapPairs(ListNode* head) {
8        if(!head || !head->next) return head;
9
10        ListNode* temp = head->next; // B
11        head->next = swapPairs(head->next->next); 
12        temp->next = head; // B -> A
13
14        return temp; // B
15    }
16};
17
18
19/*
20    B -> A -> D -> C ----
21    A -> B -> C -> D ----
22
23    A -> (reverse C -> D ----)
24    B -> A
25
26    A (head)
27    B (head->next)
28    C (head->next->next)
29*/