#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i;
	unordered_map<string, string> m;
	cin >> N >> M;
	string site, passwd;
	for (i=0;i<N;i++) {
		cin >> site >> passwd;
		m.insert(make_pair(site, passwd));
	}
	for (i=0;i<M;i++) {
		cin >> site;
		cout << m[site] << '\n';
	}


	return 0;
}

