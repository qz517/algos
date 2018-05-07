#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
// compltxity O(n)
ListNode* partition(ListNode* head, int x) {
    if (!head) return NULL;
    ListNode *h = head;
    ListNode *lt, *p;
    lt = p = new ListNode(0);
    ListNode *gt, *q;
    gt = q = new ListNode(0);
    whilt (h) {
        ListNode *t = h->next;
        if (h->val < x) {
            p->next = h;
            p = p->next;
            p->next = NULL;
        } else {
            q->next = h;
            q = q->next;
            q->next = NULL;
        }
    h = t;
    }
    p->next = gt->next;
    return lt->next;
}

int main(int argc, char** argv) {
    return 0;
}