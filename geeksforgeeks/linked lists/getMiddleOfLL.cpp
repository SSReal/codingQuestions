#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, return its middle element value.
If the list has an even number of elements, return the
second of the two middle values
*/

/*
By Sajal Singhal (June 2021)

Approach:
Tortoise and Hare Approach.
One pointer moves one at a time, while the other
moves two at a time.
When the second one reaches the end, the first one
will be at the required node.

Time: O(n)
Space: O(1)
*/

//utility class for Linked List
class Node {
public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = nullptr;
    }
};

class Solution {
public:
    int getMiddleElement(Node *head) {
        if(!head) return -1;
        Node *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};