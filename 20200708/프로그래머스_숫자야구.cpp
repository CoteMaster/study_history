/*
숫자는 맞지만 위치가 틀렸을때 -> 볼
숫자와 위치가 모두 맞을때 -> 스트라이크
숫자와 위치가 모두 틀릴때 -> 아웃

123 -> 134

111 ~ 999
*/

#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool check[1000];

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for(int  i = 0; i<baseball.size(); i++)
    {
        string question = to_string(baseball[j][0]);
         
        if(baseball[i][1] == 3) {
            check[baseball[i][0]]=true;
            continue;
        }
        else
        {
                
                if(baseball[i][1] == 2 && baseball[i][2] == 0) //2스트라이크 1아웃
                {
                     for(int i = 123; i<=987; i++)
                    {
                        string ii = to_string(i);
                        if(ii[0]==ii[1] || ii[1]==ii[2] || ii[0] == ii[2])continue;
                        if(!check[i])
                        {
                            if(question[0]==ii[0] && question[1] == ii[1]) check[i]= true;
                            else if(question[1]==ii[1] && question[2]==ii[2])check[i]=true;
                            else if(question[2]==ii[2] && question[0]==ii[0])check[i]=true;
                        }
                        else
                        {
                            if(question[0]!=ii[0] && question[1] != ii[1]) check[i]= false;
                            else if(question[1]!=ii[1] && question[2]!=ii[2])check[i]=false;
                            else if(question[2]!=ii[2] && question[0]!=ii[0])check[i]=false;
                        }
                    }
                }
                else if(baseball[i][1] == 1 && baseball[i][2] == 2)//스트라이크1, 2볼
                {
                    for(int i = 123; i<=987; i++)
                    {
                        string ii = to_string(i);
                        if(ii[0]==ii[1] || ii[1]==ii[2] || ii[0] == ii[2])continue;
                        if(!check[i])
                        {
                            if(question[0]==ii[0] && (question[1] == ii[2] && question[2]==ii[1]))check[i]= true;
                            else if(question[1]==ii[1] && (question[2]==ii[1]&&question[1]==ii[2]))check[i]=true;
                            else if(question[2]==ii[2] && (question[0]==ii[1]&&question[1]==ii[0]))check[i]=true;
                        }
                        else
                        {
                            if(question[0]!=ii[0] && (question[1] == ii[2] && question[2]==ii[1]))check[i]= false;
                            else if(question[1]!=ii[1] && (question[2]==ii[1]&&question[1]==ii[2]))check[i]=false;
                            else if(question[2]!=ii[2] && (question[0]==ii[1]&&question[1]==ii[0]))check[i]=false;
                            else if(question[0]==ii[0] && (question[1] != ii[2] || question[2]!=ii[1]))check[i]= false;
                            else if(question[1]==ii[1] && (question[2]!=ii[1]||question[1]!=ii[2]))check[i]=false;
                            else if(question[2]==ii[2] && (question[0]!=ii[1]||question[1]!=ii[0]))check[i]=false;
                        }
                    }
                }
                else if(baseball[i][1] == 1 && baseball[i][2] == 1) //1스트라이크 1볼
                {
                    for(int i = 123; i<=987; i++)
                    {
                        string ii = to_string(i);
                        if(ii[0]==ii[1] || ii[1]==ii[2] || ii[0] == ii[2])continue;
                        if(!check[i])
                        {
                            if(question[0]==ii[0] && (question[1] != ii[2] && question[2]==ii[1]))check[i]= true;
                            else if(question[0]==ii[0] && (question[1] == ii[2] && question[2]=!ii[1]))check[i]= true;
                            else if(question[1]==ii[1] && (question[2]!=ii[1]&&question[1]==ii[2]))check[i]=true;
                            else if(question[1]==ii[1] && (question[2]==ii[1]&&question[1]!=ii[2]))check[i]=true;
                            else if(question[2]==ii[2] && (question[0]!=ii[1]&&question[1]==ii[0]))check[i]=true;
                            else if(question[2]==ii[2] && (question[0]==ii[1]&&question[1]!=ii[0]))check[i]=true;
                        }
                        else
                        {
                            if(question[0]!=ii[0] && (question[1] == ii[2] && question[2]==ii[1]))check[i]= false;
                            else if(question[1]!=ii[1] && (question[2]==ii[1]&&question[1]==ii[2]))check[i]=false;
                            else if(question[2]!=ii[2] && (question[0]==ii[1]&&question[1]==ii[0]))check[i]=false;
                            else if(question[0]==ii[0] && (question[1] != ii[2] || question[2]!=ii[1]))check[i]= false;
                            else if(question[1]==ii[1] && (question[2]!=ii[1]||question[1]!=ii[2]))check[i]=false;
                            else if(question[2]==ii[2] && (question[0]!=ii[1]||question[1]!=ii[0]))check[i]=false;
                        }
                    }
                }
                else if(baseball[i][1] == 1 && baseball[i][2]==0) //1스트라이크 2아웃
                {
                  for(int i = 123; i<=987; i++)
                    {
                        string ii = to_string(i);
                        if(ii[0]==ii[1] || ii[1]==ii[2] || ii[0] == ii[2])continue;
                        if(!check[i])
                        {
                            if(question[0]==ii[0] && (question[1] != ii[2] && question[2]==ii[1]))check[i]= true;
                            else if(question[0]==ii[0] && (question[1] == ii[2] && question[2]=!ii[1]))check[i]= true;
                            else if(question[1]==ii[1] && (question[2]!=ii[1]&&question[1]==ii[2]))check[i]=true;
                            else if(question[1]==ii[1] && (question[2]==ii[1]&&question[1]!=ii[2]))check[i]=true;
                            else if(question[2]==ii[2] && (question[0]!=ii[1]&&question[1]==ii[0]))check[i]=true;
                            else if(question[2]==ii[2] && (question[0]==ii[1]&&question[1]!=ii[0]))check[i]=true;
                        }
                        else
                        {
                            if(question[0]!=ii[0] && (question[1] == ii[2] && question[2]==ii[1]))check[i]= false;
                            else if(question[1]!=ii[1] && (question[2]==ii[1]&&question[1]==ii[2]))check[i]=false;
                            else if(question[2]!=ii[2] && (question[0]==ii[1]&&question[1]==ii[0]))check[i]=false;
                            else if(question[0]==ii[0] && (question[1] != ii[2] || question[2]!=ii[1]))check[i]= false;
                            else if(question[1]==ii[1] && (question[2]!=ii[1]||question[1]!=ii[2]))check[i]=false;
                            else if(question[2]==ii[2] && (question[0]!=ii[1]||question[1]!=ii[0]))check[i]=false;
                        }
                    }   
                }
                else if(baseball[i][1] == 0 && baseball[i][2] == 3) // 0스트라이크 3볼
                {
                     for(int i = 123; i<=987; i++)
                    {
                        string ii = to_string(i);
                        if(ii[0]==ii[1] || ii[1]==ii[2] || ii[0] == ii[2])continue;
                        if(!check[i])
                        {
                            if(question[0] == ii[1] || question[0] == ii[2] || question[1] == ii[0] || question[1])
                        }
                        else
                        {
                            if(question[0]!=ii[0] && (question[1] == ii[2] && question[2]==ii[1]))check[i]= false;
                            else if(question[1]!=ii[1] && (question[2]==ii[1]&&question[1]==ii[2]))check[i]=false;
                            else if(question[2]!=ii[2] && (question[0]==ii[1]&&question[1]==ii[0]))check[i]=false;
                            else if(question[0]==ii[0] && (question[1] != ii[2] || question[2]!=ii[1]))check[i]= false;
                            else if(question[1]==ii[1] && (question[2]!=ii[1]||question[1]!=ii[2]))check[i]=false;
                            else if(question[2]==ii[2] && (question[0]!=ii[1]||question[1]!=ii[0]))check[i]=false;
                        }
                    }
                }
                else if(baseball[i][1]== 0 && baseball[i][2]==2) //0스트라이크 2볼
                {
                    
                }
                else if(baseball[i][1]== 0 && baseball[i][2]== 1) // 0스트라이크 1볼
                {
                    
                }
                else continue;
        }
    }
    
    return answer;
}
