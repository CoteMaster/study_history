#include <string>
#include <vector>

using namespace std;

long long memo[90];

long long solution(int N) {
   
    memo[0] = 0;
    memo[1] = 4;
    memo[2] = 6;
    
    if(N >= 3){
        for(int i = 3; i<=N; i++)
        {
            memo[i]=(memo[i-1]+memo[i-2]);
        }
    }
    
    return memo[N];
}
