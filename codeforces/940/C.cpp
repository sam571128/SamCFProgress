#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<char> st;
int main(){
    fastio
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(auto c : s) st.insert(c);
    if(n < k){
        for(int i = 0;i < k-n;i++){
            s += *st.begin();
        }
        cout << s << "\n";
    }else{
        s = s.substr(0,k);
        for(int i = k-1;i >= 0;i--){
            if(st.upper_bound(s[i])==st.end()){
                s[i] = *st.begin();
            }else{
                s[i] = *st.upper_bound(s[i]);
                break;
            }
        }
        cout << s << "\n";
    }
}