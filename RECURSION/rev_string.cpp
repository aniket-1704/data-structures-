#include <iostream>
using namespace std;

void revstr(string s)
{
    if(s.length()==0)
    {
        return ;
    }
    revstr(s.substr(1));
    cout<<s[0];
}
int main()
{
    string str="aniket";
    revstr(str);
    return 0;
}