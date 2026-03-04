#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// One thing at a time

// S0: ek DS bnana hai jo insert(), erase(), getMin(), support kre
// s1: insert krne se phle hm jo bhi element bda hai x se usko remove bacause x ke rhte ko bhi Minimum nhi ho sakta
//s2: erase(), remove krte time agr last element remove nhi hua uper wale function se to woh ab first element pe aa gya rhega and agr exist krta rhega to usko remove kr denge 
//s3: getMin(), hmara front element hmesha Minimum hoga

struct monotone_deque {
  deque<int> dq;

  void insert(int x) {
    // sirf 1 line change max mil jayega in window

 // while (!dq.empty() && dq.back() < x) dq.pop_back();
    while (!dq.empty() && dq.back() > x) dq.pop_back();
    dq.push_back(x);
  }
  void erase(int x) {
    if (dq.front() == x) dq.pop_front();
  }

  int getMin() { return dq.front(); }
};
void solve() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  monotone_deque mt;
  for (int i = 0; i < n; ++i) {
    mt.insert(arr[i]);
    if ((i - k) >= 0) {
      mt.erase(arr[i - k]);
    }
    if (i >= (k - 1)) {
      cout << mt.getMin() << " ";
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
