#include <iostream>
using namespace std;
void permute(string s,string ans)
{
    if(s.length()==1)
    {
        cout<<ans+s<<endl;
        return;
    }
    //pass each character with remaining string
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        string ros=s.substr(0,i) + s.substr(i+1);
        permute(ros,ans+ch);
    }
}
int main()
{
    string str="ABC";
    permute(str,"");
    return 0;
}