
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <unistd.h>

using namespace std;

typedef long long int lld;

int *v;
 
void table(string p){

    v = new int[p.size()+3];

    //v[i] :where to go(what to compare next) if mismatch occur at i
    v[0]=0;  //obviously we'll stay at zero only even if its a mismatch
    v[1]=0;  //just think naturally where will u go if mismatch occur at 1
 
    int cur=0;
    int length = p.size();
    for(int j=2;j<length;j++){
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
    }
 
}
 
lld kmp(string pattern, string text){

    table(pattern);
    int cur=0; //cur: All locations before cur have been matched.
    int length_text = text.size();
    int length_pattern = pattern.size();
    int j=0;
    lld count = 0;
    while(j<length_text){
        
        while(cur>0 && pattern[cur]!=text[j])
            cur = v[cur];
 
        if(pattern[cur]==text[j]){
            cur++;
            if(cur==length_pattern){
                count++;
                cur = 0;
            }
        }
        j++;
    }
    return count;
}
 
int main(){

    string input;
    cin >> input;
    lld i;
    while(input!="*"){
        lld solution = 1;
        lld length = input.size();
        string substr = "";
        for(i=0;i<length/2+1;i++){
            substr = substr + input[i];
            lld length_substring = i+1;
            lld count =  kmp(substr, input);//number of times substring occurs
            if(length_substring*count==length){
                cout << count << endl;
                break;
            }
        }
        if(i==length/2+1){
            cout << "1" << endl;
        }
        cin >> input;
    }

    return 0;
}
