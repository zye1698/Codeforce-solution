#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
 
signed main() {
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    int ans = 0;
    int ans1 = 1;
    int start=-1;
    for (int i=0;i<n;i++){
        auto c = s[i];
        if (s[i]=='('){
            st.push(i);
        }else{
            if (!st.empty()){
                st.pop();
                int x;
                if (!st.empty()){
                    x = st.top();
                }else{
                    x = start;
                }
                if (i-x==ans){
                    ans1++;
                }else if (i-x>ans){
                    ans = i-x;
                    ans1=1;
                }
            }else{
                start = i;
            }
            
        }
    }
    cout << ans << " " << ans1 << endl;
}