#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestBaseSubSeq(vector<string> sequences) {
		string result = "";
		// 起始位置从0遍历到最后
		for (int i = 0; i < sequences[0].length() - 2; i++) {
			string subseq = sequences[0].substr(i, sequences[0].length() - i);
			vector<int> next = getNext(subseq);
			string current = "";
			for (int j = 1; j < sequences.size(); j++) {
				int index = 0, k = 0, maxLen = 0;
				while (index < sequences[j].length() && k < (int)subseq.length()) {
					if (k == -1 || sequences[j][index] == subseq[k]) {
						index++;
						k++;
					} else {
						// 得到子串，判断长度
						maxLen = k > maxLen ? k : maxLen;
						k = next[k];
					}
				}
				// 注意边界
				maxLen = k > maxLen ? k : maxLen;
				if (maxLen < 3) {
					current = "";
					break;
				}
				if (current.empty() || maxLen < current.length()) {
					current = subseq.substr(0, maxLen);
				}
			}
			if (current.length() >= 3 && (current.length() > result.length() ||
				(current.length() == result.length() && current.compare(result) < 0))) {
				result = current;
			}
		}
		if (result.empty()) return "no significant commonalities";
		else return result;
	}
	// 获取next数组
	vector<int> getNext(string& s) {
		vector<int> next(s.length(), -1);
		int k = -1, j = 0;
		while (j < s.length() - 1) {
			if (k == -1 || s[k] == s[j]) {
				k++;
				j++;
				if (s[j] == s[k]) next[j] = next[k];
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
	int count, n;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> n;
		vector<string> sequences(n);
		for (int j = 0; j < n; j++) {
			cin >> sequences[j];
		}
		cout << s->longestBaseSubSeq(sequences) << endl;
	}
	system("pause");
	return 0;
}