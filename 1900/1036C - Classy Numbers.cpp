#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define ll long long

ll v[20][4][2];
string n;

int dp(int pos, int cnt, bool t){
    if (cnt>3){
        return 0;
    }
    if (pos==(int)n.size()){
        return 1;
    }
    int &res = v[pos][cnt][t];
    if (res!=-1){
        return res;
    }
    res = 0;
    int lim = 9;
    if (t){
        lim = n[pos]-'0';
    }
    for (int d=0;d<=lim;d++){
        res+=dp(pos+1,cnt+(d!=0),t&&(d==lim));
    }
    return res;
}

int precal(int x){
    if (x<=0){
        return 1;
    }
    n=to_string(x);
    memset(v,(int)-1,sizeof(v));
    return dp(0,0,1);
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        // cout << precal(l-1) << " " << precal(r) << endl;
        cout << precal(r)-precal(l-1) << endl;
    }
}