#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

queue<char>Q;

int solution(string arrangement) {
    int answer = 0;
    string N;
    
    for(int i = 0; i<arrangement.length(); i++)
    {
        if(arrangement[i] == '(' && arrangement[i+1] == ')'){
            N+= '*';
            i+=1;
        }
        else
            N+=arrangement[i];
    }
    
    int count = 0;
    int num = 0;
    for(int i = 0; i<N.length(); i++)
    {
        if(N[i]=='(')Q.push(N[i]);
        else if(!Q.empty() && N[i] == '*')count++;
        else if(N[i] == ')'){ num++; Q.pop();}
        if(Q.empty()){answer += (count * num);
                      num = 0; count = 0;
                     }
    }
  
    return answer;
}
