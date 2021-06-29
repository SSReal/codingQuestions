#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a linked list,
reverse the list and return the 
new head of the list
*/

/*
By Sajal Singhal (June 2021)

Approach:
Three pointer approach.
two for reversing the order, and one
for advancing to the next element.

Time: O(n) where n is the length of the list
Space: O(1), in place.
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
    Node *reverseList(Node *head) {
        Node *a = nullptr, *b = head, *c = head->next;
        if(!b || !c) return b;
        while(c) {
            b->next = a;
            a = b;
            b = c;
            c = c->next;
        }
        b->next = a;
        return b;
    }
};