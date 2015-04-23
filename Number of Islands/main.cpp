//
//  main.cpp
//  Number of Islands
//
//  Created by 黄美强 on 15/4/22.
//  Copyright (c) 2015年 黄 美强. All rights reserved.
//
#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;
typedef pair<int,int> mypair;


int numIslands(vector<vector<char> > &grid) {
    int rows = (int)grid.size();
    if(rows == 0)
        return 0;
    int cols = (int)grid[0].size();
    int count = 0;
    map<mypair,int> mymap;
    
    for(int i = 0; i<rows; i++){
        for(int j = 0 ; j<cols; j++){
            if(grid[i][j] == '0')
                continue;
            else{
                if(mymap.find(mypair(i,j)) == mymap.end()){
                    if(mymap.find(mypair(i+1,j)) != mymap.end())
                    {
                        int k = mymap[mypair(i+1,j)];
                        mymap[mypair(i,j)] = k;
                        if (j+1<rows && grid[i][j+1] == '1'){
                            mymap[mypair(i,j+1)] = k;
                        }
                    }
                    
                    if(mymap.find(mypair(i+1,j)) != mymap.end())
                    mymap[mypair(i,j)] = count;
                    if (i+1<rows && grid[i+1][j] == '0') {
                        if (j+1<cols && grid[i][j+1] == '1') {
                            mymap[mypair(i,j+1)] = count;
                        }
                    }
                    if (i+1<rows && grid[i+1][j] == '1'){
                        
                    }
                }
            }
        }
    }
    return count;
}
int main(int argc, char *argv[]) {
    vector<vector<char> > source;
    vector<char> temp;
    temp.push_back('1');
    temp.push_back('1');
    source.push_back(temp);
    cout<<numIslands(source);
}