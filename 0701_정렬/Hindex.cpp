#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, low, high;
	vector<int> v;
	sort(citations.begin(), citations.end());
	
	int cit_sz = citations.size();
	int start = citations[0]; int end = citations[cit_sz - 1];
  if (start >= citations.size()) return citations.size(); //얘 안넣으면 tc9번 실패
  
	for (int i = start;i <= end;i++) { //i값이 h
		low = 0;
		high = 0;
		for (int j = 0;j<cit_sz;j++) {
			if (citations[j] < i) low++;
			else if (citations[j] >= i) high++;
		}
		if (high >= i) v.push_back(i);
	}

	answer = *max_element(v.begin(), v.end());
    return answer;
}
