
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <unistd.h>

using namespace std;

typedef long long int lld;

int v[100002];
 
void table(string p){

    lld length = p.size();
    
    //v[i] :where to go(what to compare next) if mismatch occur at i
    v[0]=0;  //obviously we'll stay at zero only even if its a mismatch
    v[1]=0;  //just think naturally where will u go if mismatch occur at 1
    lld zeros = 2;
    lld cur=0;
    for(lld j=2;j<length;j++){
        /*
        This is the case for mismatch : if mismatch occur at j we seek to find the first
        occurence of p[j-1] in the pattern such that the sequence preceding j-1(0...j-2)
        locations have already been matched
        */
        while(cur!=0 && p[cur]!=p[j-1])
            cur=v[cur];
 
        if(p[cur]==p[j-1]) //Case for match:length of prematched sequence increments by 1
            cur=cur+1;
 
        v[j]=cur;
        if(v[j]==0){
            zeros++;
        }
    }

    if(zeros+v[length-1]==length){
        lld length_substring = zeros-1;
        cout << length/length_substring << endl;
    }
    else{
        cout << "1" << endl;
    }
}
 
int main(){

    string input;
    cin >> input;
    lld i;
    while(input!="*"){
        
        table(input);
        cin >> input;
    }

    return 0;
}
