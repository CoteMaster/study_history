/* 
테케만 맞음
작업소요시간을 기준으로 정렬해서 계산해봄
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool cmp( const vector<int>& v1,const vector<int>& v2 )
{
    return v1[1]-v1[0] < v2[1]-v2[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<int> ProcessTime;
    //priority_queue<int> pq;
    sort(jobs.begin(),jobs.end(),cmp);
    int end = 0;
    for (int i=0;i<jobs.size();i++){
        int start =  jobs[i][0];
        end += jobs[i][1];
        ProcessTime.push_back(end-start);
    }
    int sum=0;
    int Process_sz = ProcessTime.size();
    for (int j =0;j<Process_sz;j++){
        sum += ProcessTime[j];
    }
    answer = sum / Process_sz;
    return answer;
}
