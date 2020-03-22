#include <bits/stdc++.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    double n,m,a;
    cin >> n >> m >> a;
    cout << (long long)ceil(n/a)*(long long)ceil(m/a);
    return 0;
}