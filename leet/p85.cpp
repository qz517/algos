#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vector<vector<char>> bb;

bool check(int ux, int uy, int bx, int by) {
  fori(i, ux, bx+1) {
    fori(j, uy, by+1)
      if (bb[i][j] != '1')
        return 0;    
  }
  return 1;
}

// Brute force method.
// Time: O(n^2 * m^2)
int maximalRectangleOne() {
  if (sz(bb) <= 0) return 0;
  int n, m;
  n = sz(bb);
  m = sz(bb[0]);
  int res = 0;
  fori(ux, 0, n)
    fori(uy, 0, m)
      fori(bx, 0, n)
        fori(by, 0, m) {
          if (check(ux, uy, bx, by)) {
            int area = (bx - ux + 1) * (by - uy + 1);
            res = max(res, area); 
          }
        }
  return res;
}

int area(int ux, int uy, int bx, int by) {
  return (bx - ux + 1 ) * (by - uy + 1);
}

pii bottom_address(int ux, int uy) {
  // How big all ones area can we reach starting with uppper corner `(ux, uy).
  int n, m;
  int bx, by;
  int x, y;
  int y_max;

  n = sz(bb), m = sz(bb[0]);
  bx = ux, by = uy;
  y_max = m;
  x = ux;
  while (x < n && bb[x][uy] == '1') {
    int y = uy;
    while(y < y_max && bb[x][y] == '1') ++y;
    y_max = min(y_max, y);
    if (area(ux, uy, x, y-1) > area(ux, uy, bx, by)) {
      bx = x;
      by = y-1;
    }
    ++x;
  }

  if (bb[bx][by] == '1')
    return pii(bx, by);
  else
    return pii(-1, -1);
}

// Time: O(n^2 * m^2)
int maximalRectangleTwo() {
  int n, m;
  int res = 0;

  if (sz(bb) <= 0) return 0;
  n = sz(bb), m = sz(bb[0]);

  fori(ux, 0, n)
    fori(uy, 0, m) {
      pii b = bottom_address(ux, uy);
      int bx = b.fi, by = b.se;
      if (bx == -1 && by == -1) continue;
      int tmp = area(ux, uy, bx, by);
      // cout << ux << " " << uy << " " << bx << " " << by << " " << tmp <<"\n";
      res = max(res, tmp);
    }
  return res;
}

void update_dp(int *dp, int n, int y) {
  fori(x, 0, n) {
    if (bb[x][y] == '1')
      dp[x] += 1;
    else
      dp[x] = 0;
  }
}

pii bottom_address_dp(int *dp, int ux, int uy) {
  // How big all ones area can we reach starting with uppper corner `(ux, uy).
  int n, m, bx, by, x, y, y_max;

  n = sz(bb), m = sz(bb[0]);
  bx = ux, by = uy;
  y_max = m;
  x = ux;
  while (x < n && bb[x][uy] == '1') {
    int y = uy + dp[x];
    y = min(y_max, y);
    y_max = y;
    if (area(ux, uy, x, y-1) > area(ux, uy, bx, by)) {
      bx = x;
      by = y-1;
    }
    ++x;
  }

  if (bb[bx][by] == '1')
    return pii(bx, by);
  else
    return pii(-1, -1);
}

// Time: O(n^2 * m)
int maximalRectangleThree() {
  // DP method.
  if (sz(bb) <= 0) return 0;
  int n = sz(bb), m = sz(bb[0]);
  int res = 0;

  int dp[n];
  mst(dp, 0);

  // As long as our search can cover all the sub matrices, we can get the 
  // correct answer, no matter what order we are searching here.
  ford(uy, m-1, -1) {
    update_dp(dp, n, uy); 
    fori(ux, 0, n) {
      pii b = bottom_address_dp(dp, ux, uy);
      int bx = b.fi, by = b.se;
      if (bx == -1 && by == -1) continue;
      int tmp = area(ux, uy, bx, by);
      // cout << ux << " " << uy << " " << bx << " " << by << " " << tmp <<"\n";
      res = max(res, tmp);
    }
  }
  return res;
}

int largestRectangleArea(vector<int>& aa) {
  aa.pb(0);
  stack<int> stk;
  int res = 0;
  fori(i, 0, sz(aa)) {
    while(!stk.empty() && aa[i] <= aa[stk.top()]) {
      int h = aa[stk.top()]; stk.pop();
      int w = stk.empty() ? -1 : stk.top(); 
      res = max(res, h * (i - w - 1));
      // cout << i << " " << w << " " << res << "\n";
    }
    // We still need to compute the area with `i`th bar as the smallest bar.
    // So push it into stack.
    stk.push(i);
  }
  return res;
}

// Time: O(m * n)
int maximalRectangleFour() {
  // DP method.
  if (sz(bb) <= 0) return 0;
  int n = sz(bb), m = sz(bb[0]);
  int res = 0;

  int dp[n];
  mst(dp, 0);
  
  ford(uy, m-1, -1) {
    update_dp(dp, n, uy); 

    vi tmp;
    fori(i, 0, n)
      tmp.pb(dp[i]); 
    res = max(res, largestRectangleArea(tmp));  
  }
  return res;
}

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& aa) {
    bb = aa;
    // return maximalRectangleOne(aa);  
    // return maximalRectangleTwo(bb); 
    // return maximalRectangleThree();
    return maximalRectangleFour();
  }
};

void TEST(vector<vector<char>> aa) {
  Solution go;
  cout << go.maximalRectangle(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  vector<vector<char>> aa = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}};

  TEST(aa);
  TEST({{'0'}});
  TEST({{'0', '0'}});

  return 0;
}