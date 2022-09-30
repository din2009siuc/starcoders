#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string a,b;
    while(getline(cin,a) && getline(cin,b)){
        vector<int>s1(26,0);
        vector<int>s2(26,0);
        string ans;
        for (int i =0;i < a.size();++i){
            ++s1[a[i]-'a'];
        }
        for (int i =0;i < b.size();++i){
            ++s2[b[i]-'a'];
        }
        for (int i =0;i < 26;++i){
            int cur = min(s1[i],s2[i]);
            for (int k = 0;k < cur;++k){
                ans.push_back('a'+i);
            }
        }
        cout << ans<<endl;
    }
}