#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    int lowlow_scoville; //가장 맵지 않은 음식의 스코빌 지수
	int low_scoville;    //두 번째로 맵지 않은 음식의 스코빌 지수

	//우선순위 큐 이용. 자동 오름차순 정렬.
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());


	//가장 맵지 않은 음식 스코빌 지수 < 기준치 K 이면 계속 반복.
	while (pq.top() < K) {
		//섞을 2개의 음식이 남아있지 않으면 -1 반환.
		if (pq.size() == 1) return answer = -1;

		//가장 맵지 않은 음식
		lowlow_scoville = pq.top();
		pq.pop();

		//두 번쨰로 맵지 않은 음식
		low_scoville = pq.top();
		pq.pop();
		
		//두 음식을 섞은 후 우선순위 큐에 넣어줌.
		pq.push(lowlow_scoville + (low_scoville * 2));

		//횟수 추가
		answer++;
	}

	return answer;
}
