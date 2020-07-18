#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
    fastio
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans(n,'0');
    int tmp = 0;
    for(int i = 0;i < n;i++){
        if(s[i]=='(') tmp++;
        ans[i] = '0' + (tmp&1);
        if(s[i]==')') tmp--;
    }
    cout << ans << "\n";
}