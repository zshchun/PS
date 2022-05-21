#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll v, t, s, d, i, j;
	cin>>v>>t>>s>>d;
	i = d/v;
	j = (d%v) ? 1 : 0;
	if (t <= i && i+j <= s)
		cout<<"NO\n";
	else
		cout<<"Yes\n";
	return 0;
}
