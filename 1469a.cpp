#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, N, M;
	string s;
	cin >> T;
	while(T--) {
		cin >> s;
		if (s.size() %2 == 1 || s[0] == ')' || s[s.size()-1] == '(')
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
