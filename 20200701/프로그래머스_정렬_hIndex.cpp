#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/*
논문 n편중, h번 이상 인용된 논문이 h편이상, 나머지는 논문이 h번 이하 인용 ==> h의 최댓값이 과학자의 h-index
*/

using namespace std;
bool cmp(int a, int b)
{
    return a>b;
}
int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end(),cmp);
   
    int standard = 0;
    for(int i = 0; i<citations.size(); i++)
    {
        if(citations[i] <= standard) break;
        standard++;
    }
    answer = standard;
    return answer;
}
