#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

bool dp[2000]={0};
bool visited[2000]={0};

void print(int m){
    for (int i=0;i<m;i++){
        cout << dp[i] << " ";
    }
    cout << endl;
}
 
signed main() {
    int n,m;
    cin >> n >> m;
    dp[0]=1;
    for (int k=0;k<n;k++){
        int a;
        cin >> a;
        a%=m;
        if (a==0){
            cout << "YES" << endl;
            return 0;
        }
        for (int i=m;i>=0;i--){
            if (!visited[i] and dp[i]){
                if ((i+a)>m and !dp[(i+a)%m]){
                    visited[(i+a)%m]=1;
                }
                dp[(i+a)%m]=1;
                if (i+a==m){
                    cout << "YES" << endl;
                    return 0;
                }
            }
            if (visited[i]){
                visited[i]=0;
            }
        }
    }
    cout << "NO" << endl;
}
