#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, v, i, m;
	cin>>a>>b>>v;
	m = 0;
	i = (v-a+(a-b)-1) / (a-b) + 1;
	cout << i << "\n";
	return 0;
}
