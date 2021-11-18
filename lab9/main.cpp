#include <bits/stdc++.h>
#define MAX_DISK_SIZE 200

using namespace std;

enum Direction {left,right};

void diskscan(int head, vector<int> arr, Direction dir){
  vector<int> sequence(arr.begin(),arr.end());
  vector<int> res;
  sort(sequence.begin(),sequence.end());
  
  if(dir == ::left){
    // left
    for(int i= sequence.size()-1; i >= 0; i--){
      if(sequence[i] < head){
        res.push_back(sequence[i]);
      }
    }
        res.push_back(0);
    
    for(int i=0; i < sequence.size(); i++){
      if(sequence[i] >= head){
        res.push_back(sequence[i]);
      }
    }


    for(int s:res){
      cout<<s<<" ";
    }

  }else{
    // right
    for(int i= 0; i< sequence.size(); i++){
      if(sequence[i] >= head){
        res.push_back(sequence[i]);
      }
    }
        res.push_back(MAX_DISK_SIZE-1);
    
    for(int i=sequence.size()-1; i >=0 ; i--){
      if(sequence[i] < head){
        res.push_back(sequence[i]);
      }
    }


    for(int s:res){
      cout<<s<<" ";
    }

  }
  
}


int main(){
  vector<int> arr { 176, 79, 34, 60, 92, 11, 41, 114 };
  int head = 50;
  Direction dir = ::right;
  
  diskscan(head,arr,dir);
}