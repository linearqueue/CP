// Find minimum in every K Window

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int arr[100100];
int n, k;

// One thing at a time
void solve() {

  // s0: sabse phle mai multiset bnaunga fir usme
  // s1: element insert krunga
  // s2: agr multiset ki size > k hota hai to i-k element remove krunga
  // s3: agr multiset ki size ==k hota to first element mera smallest hoga

  multiset<int> mt;
  for (int i = 0; i < n; ++i) {
    mt.insert(arr[i]);
    if ((i - k) >= 0) mt.erase(mt.find(arr[i - k]));  // mt.size()>k
    if (i >= (k - 1)) cout << *mt.begin() << endl;    // mt.size()==k
  }

  // TC => O (n * log k)
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
