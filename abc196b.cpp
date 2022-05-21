#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	size_t p;
	cin >> s;
	if ((p=s.find('.')) == string::npos)
		cout << s << "\n";
	else
		cout << s.substr(0, p) << "\n";
	return 0;
}
