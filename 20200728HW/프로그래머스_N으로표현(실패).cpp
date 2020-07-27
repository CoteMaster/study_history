//정확도 43%

#include <string>
#include <vector>
#include<iostream>

using namespace std;
vector<int> save[9];

int solution(int N, int number) {
    int answer = 0;
    
    save[1].push_back(N);
    save[2].push_back((N*10)+N);
    save[3].push_back((N*100)+(N*10)+N);
    save[4].push_back((N*1000)+(N*100)+(N*10)+N);
    save[5].push_back((N*10000)+(N*1000)+(N*100)+(N*10)+N);
    save[6].push_back((N*100000)+(N*10000)+(N*1000)+(N*100)+(N*10)+N);
    save[7].push_back((N*1000000)+(N*100000)+(N*10000)+(N*1000)+(N*100)+(N*10)+N);
    save[8].push_back((N*10000000)+(N*1000000)+(N*100000)+(N*10000)+(N*1000)+(N*100)+(N*10)+N);
   
    for(int i = 2; i<=8; i++)
    {
        for(int j = 0; j<save[i-1].size(); j++)
        {
            int now = save[i-1][j];
            if(now / N > 0)
                save[i].push_back(now/N);
            if(now-N > 0)
                save[i].push_back(now-N);
            if(now+N <= 32000)
                save[i].push_back(now+N);
            if(now * N <= 32000)
                save[i].push_back(now*N);
        }
    }
    
    bool flag = false;
    for(int i = 1; i<=8; i++)
    {
        for(int j = 0; j<save[i-1].size(); j++)
        {
            if(save[i][j] == number) {
                answer = i;
                flag = true;
                break;
            }
        }
        if(flag)break;
    }

    if(answer == 0) answer = -1;
    
    return answer;
}
