#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    for(int i = 0; i<commands.size(); i++)
    {
        vector<int>S;
        int start = commands[i][0];
        int end = commands[i][1];
        
        for(int j = start-1; j<end; j++)
        {
            S.push_back(array[j]);
        }
        //cout<<"\n";
        sort(S.begin(),S.end());
        answer.push_back(S[commands[i][2]-1]);
        //cout<<commands[i][0];
    }
    return answer;
}
