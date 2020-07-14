#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
	fastio
    int a, b, n;
    cin >> a >> b >> n;
    for (int x = -1000; x <= 1000; x++) {
        int A = a;
        for (int i = 0; i < n; ++i) {
            A *= x;
            if (abs(A) > abs(b)) {
                break;
            }
        }
        if (A == b) {
            cout << x << '\n';
            return 0;
        }
    }
 
    cout << "No solution\n";
    return 0;
}