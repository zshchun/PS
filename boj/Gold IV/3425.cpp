#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll x, n, i, j, y;
	while (1) {
		vector<string> cmd;
		string s;
		cin >> s;
		while (s != "END") {
			if (s == "NUM") {
				cmd.push_back(s);
				cin >> s;
			} else if (s == "QUIT")
				return 0;
			cmd.push_back(s);
			cin >> s;
		}
		cin >> n;
		for (i=0;i<n;i++) {
			cin >> x;
			stack<ll> q;
			q.push(x);
			bool error = false;
			for (j=0;j<cmd.size();j++) {
				string c = cmd[j];
				if (c == "NUM") {
					x = stoi(cmd[++j]);
					q.push(x);
				} else if (c == "POP") {
					if (q.empty()) {
						error = true;
						break;
					}
					q.pop();
				} else if (c == "INV") {
					if (q.empty()) {
						error = true;
						break;
					}
					x = q.top();
					q.pop();
					q.push(-x);
				} else if (c == "DUP") {
					if (q.empty()) {
						error = true;
						break;
					}
					q.push(q.top());
				} else if (c == "SWP") {
					if (q.size() < 2) {
						error = true;
						break;
					}
					x = q.top(); q.pop();
					y = q.top(); q.pop();
					q.push(x);
					q.push(y);
				} else if (c == "ADD") {
					if (q.size() < 2) {
						error = true;
						break;
					}
					x = q.top(); q.pop();
					y = q.top(); q.pop();
					q.push(x+y);
				} else if (c == "SUB") {
					if (q.size() < 2) {
						error = true;
						break;
					}
					x = q.top(); q.pop();
					y = q.top(); q.pop();
					q.push(y-x);
				} else if (c == "MUL") {
					if (q.size() < 2) {
						error = true;
						break;
					}
					x = q.top(); q.pop();
					y = q.top(); q.pop();
					q.push(y*x);
				} else if (c == "DIV") {
					if (q.size() < 2) {
						error = true;
						break;
					}
					x = q.top(); q.pop();
					y = q.top(); q.pop();
					if (x == 0) {
						error = true;
						break;
					}
					ll sign = (x < 0 && y > 0) || (y < 0 && x > 0) ? -1 : 1;
					q.push(abs(y) / abs(x) * sign);
				} else if (c == "MOD") {
					if (q.size() < 2) {
						error = true;
						break;
					}
					x = q.top(); q.pop();
					y = q.top(); q.pop();
					if (x == 0) {
						error = true;
						break;
					}
					ll sign = y < 0 ? -1 : 1;
					q.push(abs(y) % abs(x) * sign);
				}
				if (!q.empty() && abs(q.top()) > 1000000000) {
					error = true;
					break;
				}
			}
			if (error || q.size() != 1) {
				cout << "ERROR\n";
			} else {
				cout << q.top() << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
