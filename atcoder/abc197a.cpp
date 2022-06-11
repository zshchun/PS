#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	string s;
	cin >> s;
	for (i=1;i<s.size();i++)
		cout << s[i];
	cout << s[0] << '\n';
	return 0;
}
