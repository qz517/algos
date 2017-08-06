#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

void reorderList(ListNode* head) {
    ListNode *p, *q;
    p = q = head;
    while (q->next && q->next->next) {
        q = q->next->next;
        p = p->next;
    }    

    ListNode *prev = NULL;
    q = p->next;
    p->next = NULL;
    while (q) {
        ListNode *next = q->next;
        q->next = prev;
        prev = q;
        q = next;
    }

    q = head;
    p = prev;
    while (p) {
        ListNode *x = q->next;
        ListNode *y = p->next;
        q->next = p;
        p->next = x;

        q = x;
        p = y;
    }
      
}

int main(int argc, char** argv) {
    return 0;
}
