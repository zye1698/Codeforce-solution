#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
 
vector<pii> v[210000];
bool visited[210000]={0};
 
int ans[210000];
 
 
signed main() {
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].pb({c,b});
        v[b].pb({c,a});
    }
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({0,{1,0}});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int node = x.second.first;
        int prev = x.second.second;
        if (visited[node]){
            continue;
        }
        int len = x.first;
        ans[node] = prev;
        if (node==n){
            vector<int> ans1;
            while(node!=1){
                ans1.pb(node);
                node = ans[node];
            }
            reverse(ans1.begin(),ans1.end());
            cout << 1 << " ";
            for (auto o:ans1){
                cout << o << " ";
            }
            return 0;
        }
        visited[node] = 1;
        for (auto [val,o]:v[node]){
            if (!visited[o]){
                pq.push({len+val,{o,node}});
            }
        }
    }
    cout << "-1" << endl;
}