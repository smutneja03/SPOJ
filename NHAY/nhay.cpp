
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <unistd.h>

using namespace std;
 
int *v;
 
void table(string p){

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
 
void kmp(string pattern, string text){

    table(pattern);
    int cur=0; //cur: All locations before cur have been matched.
    int length_text = text.size();
    int length_pattern = pattern.size();
    int flag = 0, j=0;
    while(j<length_text){
        /*
        Key points:
        1. Mismatch occurs at cur.
        2. Suppose anand is compared with ananandnd.
        3. Mismatch occur at a i.e. cur=4.  anand.
        4. But we shift as above v[cur]=2(and it matches 'a').So now we only compare and.
        5. We have saved our work of starting from beginning.
        6. This was luckily the longest possible one.In general,we try to save even the
        the smaller amount of work unitl we reach index 0 in the pattern.
        */
        while(cur>0 && pattern[cur]!=text[j])
            cur = v[cur];
 
        if(pattern[cur]==text[j]){
            cur++;
            if(cur==length_pattern){
                //if all all locations before index p.size() have been matched
                cout << j- length_pattern +1<< endl;
                cur--;
                cur = v[cur];
                flag = 1;
                j--;
            }
        }
        j++;
    }
}
 
int main(){

    int length;
    scanf("%d", &length);
    while(1){
        v = new int[length+2];
        string text, pattern;
        cin >> pattern >> text;
        kmp(pattern, text);//all the indexes are printed now
        if(scanf("%d", &length)==1){
            //there are more cases
            cout << endl;//for the separating line, between the test cases
        }
        else{
            break;
        }
    }

    return 0;
}
