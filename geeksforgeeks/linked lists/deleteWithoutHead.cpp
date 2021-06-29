#include <bits/stdc++.h>
using namespace std;

/*
Given the reference to a node to be
deleted from the linked list, delete that
node in place.
The given node is guaranteed not to be the tail
of the list.
*/

/*
By Sajal Singhal (June 2021)

Approach:
Copy the data of the next node to the current node
and delete the next node.

Time: O(1)
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
    void deleteNode(Node *del) {
        Node *delnext = del->next;
        del->data = delnext->data;
        del->next = delnext->next;
        delete delnext;
    }
};