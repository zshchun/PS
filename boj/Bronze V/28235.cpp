#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	if (s == "SONGDO")
		cout << "HIGHSCHOOL\n";
	else if (s == "CODE")
		cout << "MASTER\n";
	else if (s == "2023")
		cout << "0611\n";
	else if (s == "ALGORITHM")
		cout << "CONTEST\n";
	return 0;
}
