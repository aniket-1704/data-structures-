#include <iostream>
using namespace std;
void movetoend(string s)
{
    if(s.length()==0)
    {
        return ;
    }
    if(s[0]=='x')
    {
        movetoend(s.substr(1));
        cout<<s[0];
    }
    else
    {
        cout<<s[0];
        movetoend(s.substr(1));
    }
    
}
int main()
{
    string str="axbcxdxefx";
    movetoend(str);
    return 0;
}