#include <bits/stdc++.h> 

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
    fastio
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            if(b+a*i==d+c*j){
                cout << b+a*i;
                return 0;
            }
        }
    }
    cout << "-1\n";
}