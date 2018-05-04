#include <bits/stdc++.h>
using namespace std;
string s;

int cal(string s)
{
    int len =s.size();
    if(len==0)
        return 0;
    string t="";
    int l=0;
    s+="#";
    for(int i=1;i<=len;i++)
    {
        if(s[i]!=s[i-1])
        {
            if(l==i-1)
                t+=s[i-1];
            l=i;
        }
    }
    if(t.size()==len)return 0;
    return  len-t.size()+cal(t);

}
int main() {
    int n;

    scanf("%d",&n);
    while(n--)
    {
        cin >> s;
        int score=0;
        for(int i=0;i<=s.size();i++)
        {
            string tmp;
            tmp=s;tmp.insert(i,"A");
            score = max(score,cal(tmp));
            tmp=s;tmp.insert(i,"B");
            score = max(score,cal(tmp));
            tmp=s;tmp.insert(i,"C");
            score = max(score,cal(tmp));
        }
        printf("%d\n",score);
    }

}