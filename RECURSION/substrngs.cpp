#include <iostream>
using namespace std;
void substrs(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    //pass first with char and then without char
    substrs(ros,ans);
    substrs(ros,ans+ch);
    //also print ascii variants
    // substrs(ros,ans+ to_string(code));
    // int code=ch
}
int main()
{
    string str="ABC";
    substrs(str,"");
    return 0;
}