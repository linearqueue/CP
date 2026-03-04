#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int arr[100100];
int n, k;

// One thing at a time
// Creating dataStructure
struct monotone_deque {
  deque<int> dq;

  void insert(int x) {
    while (dq.back() > x && !dq.empty()) dq.pop_back();
    dq.push_back(x);
  }

  void erase(int x) {
    if (dq.front() == x) dq.pop_front();
  }

  int getmin() { return dq.front(); }
};

void solve() {
  // same code of previous O(n*log k)
  // here => O(n)
  // hamesh yhi uper wala datastructure use krna hai struct bna ke

  monotone_deque mt;
  for (int i = 0; i < n; ++i) {
    mt.insert(arr[i]);
    if ((i - k) >= 0) mt.erase(arr[i - k]);         // mt.size()>k
    if (i >= (k - 1)) cout << mt.getmin() << endl;  // mt.size()==k
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
