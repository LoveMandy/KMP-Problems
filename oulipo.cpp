#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int function(string& W, string& T) {
		W.push_back('#');	// ½áÊø·û #
		vector<int> next = getNext(W);
		int i = 0, j = 0, count = 0;
		while (i < T.length()) {
			if (j == -1 || W[j] == T[i]) {
				i++;
				j++;
			} else {
				if (W[j] == '#') count++;
				j = next[j];
			}
		}
		if (W[j] == '#') count++;
		return count;
	}
	vector<int> getNext(string s) {
		vector<int> next(s.length(), -1);
		int k = -1, j = 0;
		while (j < next.size() - 1) {
			if (k == -1 || s[k] == s[j]) {
				k++;
				j++;
				if (s[k] == s[j]) next[j] = next[k];
				else next[j] = k;
			} else {
				k = next[k];
			}
		}
		return next;
	}
};

int main() {
	Solution* s = new Solution();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string W, T;
		cin >> W >> T;
		cout << s->function(W, T) << endl;
	}
	system("pause");
	return 0;
}