/* Done by Pushpendra V. 

Sample comands to execute - 
g++ main.cpp && ./a.out 7 0 1 2 0 3 0 4 2 3 0 3 2 => got ans, miss = 6
g++ main.cpp && ./a.out 1 2 1 4 2 3 5 => got ans, miss = 5


*/
#include <bits/stdc++.h>
#define capacity 4
using namespace std;
int main(int argn, char *argv[]){
    if(argn <= 1){
        cout<<"Error : Please pass the schedule of pages as Command Line Argument \n";
        return 0;
    }

    int n = argn-1;
    vector<int> schedules(n);
    for(int i=1; i <= n; i++){
       schedules[i-1] = atoi(argv[i]);
    }
    
    unordered_set<int> st;
    int miss = 0, hit = 0;
    for(int i=0; i < n; i++){
        if(st.size() < capacity){
            // just add into pages
            if(st.find(schedules[i]) == st.end()){
                miss++;
                st.insert(schedules[i]);
            }else{
                hit++;
            }
        }else{
            if(st.find(schedules[i]) == st.end()){
                // not found
                unordered_set<int> tst;
                int last = 0;
                for(int a = 1; tst.size() < capacity; a++){
                    last = schedules[i-a];
                    tst.insert(last);
                }
                int lru_element = last;
                st.erase(lru_element);
                st.insert(schedules[i]);
                miss++;
            }else{
                // found
                hit++;
            }
        }
    }

    cout<<"\n Miss Count = "<<miss
        <<"\n Hit Count = "<<hit
        <<"\n Hit Ratio = "<<((double)(((double)hit)/((double)(hit+miss))))*100 <<"% \n";





}