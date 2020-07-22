//모든 경우를 다 볼 필요없이 한번 계산했을 때, 최선의 방법을 찾는다.

#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(),people.end());
    
    int sidx = 0;
    int eidx = people.size()-1;
   
    while(1)
    {
        if(sidx > eidx)break;
        int hap = people[sidx]+people[eidx];
        answer++;
        if(hap <= limit)
        {
            sidx++;
            eidx--;
        }
        else eidx--;
           
    }
    
    return answer;
}
