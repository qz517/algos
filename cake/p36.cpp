#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool judge(vi deck, vi half1, vi half2) {
  if (deck.empty())
    return true;
  
  int a=0, b=0;
  int n = sz(deck);
  fori(i, 0, n) {
    int card = deck[i];
    
    if (a<sz(half1) && card == half1[a]) {
      ++a;
    } 
    else if (b<sz(half2) && card == half2[b]) {
      ++b;
    }
    else 
      return false;
  }
  return true;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  return 0;
}