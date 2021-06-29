#include <bits/stdc++.h>
using namespace std;

/*
Given two linked lists representing numbers, 
return the sum of the two numbers in the form
of linked list.
For eg: 153 would be represented by 
1->5->3
*/

/*
By Sajal Singhal (June 2021)

Approach:
Reverse both the lists, so that the unit digits are matched with unit digits,
tens with tens, and so on.
Then do the addition as usual with carry.
Return the reverse of the sum.

Time: O(m + n)
Space: O(max(m, n))
where m and n are the number of digits in the numbers respectively
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

    //utility function to reverse linked list
    Node *reverse(Node *head) {
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

public:
    Node *addTwoLists(Node *first, Node *second) {
        Node *rev_first = reverse(first);
        Node *rev_second = reverse(second);
        Node *sumHead = new Node(); //sentinel node
        Node *sum = sumHead;
        int carry = 0;
        while(rev_first && rev_second) {
            sum->next = new Node();
            sum = sum->next;
            int x = rev_first->data + rev_second->data + carry;
            sum->data = x%10;
            carry = x/10;
            rev_first = rev_first->next;
            rev_second = rev_second->next;
        }
        while(rev_first) {
            sum->next = new Node();
            sum = sum->next;
            int x = rev_first->data + carry;
            sum->data = x%10;
            carry = x/10;
            rev_first = rev_first->next;
        }
        while(rev_second) {
            sum->next = new Node();
            sum = sum->next;
            int x = rev_second->data + carry;
            sum->data = x%10;
            carry = x/10;
            rev_second = rev_second->next;
        }
        if(carry > 0) {
            sum->next = new Node();
            sum = sum->next;
            sum->data = carry;
        }
        Node *sum = sumHead->next;
        delete sumHead;
        return reverse(sum);
    }
};