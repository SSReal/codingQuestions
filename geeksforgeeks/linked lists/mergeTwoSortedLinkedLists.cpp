#include <bits/stdc++.h>
using namespace std;

/*
Given the heads of two sorted linked lists,
merge them in place and return a reference to
the head of the merged linked list
*/

/*
Made by Sajal Singhal (June 2021)

Approach:
Two pointer approach, choosing the smaller element
each time, and then adding the remaining elements.

Time: O(m + n) where m and n are the lengths of the
    two given linked lists

Space: O(1), in place algorithm
*/

//definition of the Linked list node
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
    Node *sortedMerge(Node *head1, Node *head2) {
        //no need to merge?
        if(!head1) return head2;
        else if(!head2) return head1;

        //fixing the head of the merged list
        Node *head;
        if(head1->data <= head2->data) {
            head = head1;
            head1 = head1->next;
        }
        else {
            head = head2;
            head2 = head2->next;
        }

        //merging the other elements
        Node *ptr = head;
        while(head1 && head2) {
            if(head1->data <= head2->data) {
                ptr->next = head1;
                head1 = head1->next;
            }
            else {
                ptr->next = head2;
                head2 = head2->next;
            }
            ptr = ptr->next;
        }

        //remaining elements
        while(head1) {
            ptr->next = head1;
            head1 = head1->next;
            ptr = ptr->next;
        }
        while(head2) {
            ptr->next = head2;
            head2->next = head2;
            ptr = ptr->next;
        }

        return head;
    }
};

