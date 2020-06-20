#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for (int i=0;i<progresses.size();i++){
        int day = (100-progresses[i])/speeds[i];
        int res = (100-progresses[i])%speeds[i];
        if (res != 0) day++;
        q.push(day);
    }
    int cnt=1;
    int now = q.front();
    q.pop();
    while(!q.empty()){
        if (now >= q.front()){
            q.pop();
            cnt++;
        }
        else {
            answer.push_back(cnt);
            now = q.front();
            cnt = 1;
            q.pop();
        }
    }
    answer.push_back(cnt);
    return answer;
}
