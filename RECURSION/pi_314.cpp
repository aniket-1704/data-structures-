#include <iostream>
using namespace std;
//"piiiipppippiii"
//"3.14iiipp3.14p3.14ii"
void replacepi(string s)
{
    if(s.length()==0)
    {
        return ;
    }
    if(s[0]=='p' && s[1]=='i')
    {
        cout<<"3.14";
        replacepi(s.substr(2));
    }
    else
    {
        cout<<s[0];
        replacepi(s.substr(1));
    }
    
}
int main()
{
    string str="piiiipppippiii";
    replacepi(str);
    return 0;
}