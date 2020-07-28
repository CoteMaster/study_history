#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int memo[550];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int S = triangle.size();
   
    for(int i = 0; i<triangle[S-1].size(); i++)
    {
        memo[i] = triangle[S-1][i];
    }
  
     
    for(int i = triangle.size()-2; i>=0; i--)
    {
        for(int j = 0; j<triangle[S-1].size()-1; j++)
        {
          memo[j] = max(triangle[i][j]+memo[j],triangle[i][j]+memo[j+1]);
        }
    }
   
    answer = *max_element(memo,memo+S);
    return answer;
}
