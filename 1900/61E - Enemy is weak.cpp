#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<ll, ll>
#define endl "\n"
 
int bit[1001000] = {0};
ll r[1001000] = {0};
ll l[1001000] = {0};
void update(int i, int x) {
  for (; i < 1000100; i += i & -i) {
    bit[i] += x;
  }
}
 
int query(int i) {
  int cnt = 0;
  for (; i > 0; i -= i & -i) {
    cnt += bit[i];
  }
  return cnt;
}
 
int main() {
  int n;
  cin >> n;
  vector<int> v, v1;
  map<int, int> compress;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.pb(a);
    v1.pb(a);
  }
  sort(v1.begin(), v1.end());
  for (int i = 1; i <= n; i++) {
    compress[v1[i - 1]] = i;
  }
  for (int i = n - 1; i >= 0; i--) {
    r[i] = query(compress[v[i]] - 1);
    if (i > 0) {
      update(compress[v[i]], 1);
    }
  }
  fill(begin(bit), end(bit), 0);
  for (int i = 0; i < n; i++) {
    l[i] = i - query(compress[v[i]] - 1);
    update(compress[v[i]], 1);
  }
  ll ans = 0;
  for (int i = 1; i < n - 1; i++) {
    ans += l[i] * r[i];
  }
  cout << ans << endl;
}