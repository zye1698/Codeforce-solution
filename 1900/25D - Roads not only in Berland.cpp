#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<ll, ll>
// #define endl "\n"
 
int parent[1100];
int sizes[1100] = {0};
int edges[1100] = {0};
 
int find(int x) {
  if (x == parent[x]) {
    return x;
  }
  return find(parent[x]);
}
 
vector<pii> ee[1100];
 
void unite(int a, int b) {
  pii x = {a, b};
  a = find(a);
  b = find(b);
  if (a != b) {
    if (sizes[a] < sizes[b]) {
      swap(a, b);
    }
    sizes[a] += sizes[b];
    edges[a] += edges[b];
    for (auto o : ee[b]) {
      ee[a].pb(o);
    }
    parent[b] = a;
  } else {
    ee[a].pb(x);
  }
  edges[a]++;
}
 
bool visited[1100] = {0};
vector<pii> v;
map<int, int> extra;
 
void print(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    return;
  }
  auto x = ee[a].back();
  cout << x.first << " " << x.second << " " << x.first << " " << b << endl;
  extra[a] += extra[b] - 1;
  ee[a].pop_back();
  sizes[a] += sizes[b];
  edges[a] += edges[b];
  for (auto o : ee[b]) {
    ee[a].pb(o);
  }
  parent[b] = a;
}
 
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 1100; i++) {
    parent[i] = i;
    sizes[i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    unite(a, b);
  }
  for (int i = 1; i <= n; i++) {
    int x = find(i);
    if (!visited[x]) {
      visited[x] = 1;
      v.pb({ee[x].size(), x});
    }
  }
  sort(v.begin(),v.end());;
  reverse(v.begin(),v.end());
  cout << v.size() - 1 << endl;
  for (int i = 0; i < v.size() - 1; i++) {
    print(v[i].second, v[i + 1].second);
  }
}