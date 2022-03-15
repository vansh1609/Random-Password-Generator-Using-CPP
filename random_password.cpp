#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <map>
using namespace std;
string randompassword(int n, map<string, int> &m)
{
    string s = "";
    srand(time(NULL));
    int x = (rand() % 26) + 97;
    int y = (rand() % 26) + 65;
    s += char(x);
    for (int i = 1; i <= n - 2; i++)
    {

        int j = (rand() % (125 - 33 + 1)) + 33;
        s += char(j);
        if (j >= 65 && j <= 97)
            m["upper"]++;
        else if (j >= 97 && j <= 122)
            m["lower"]++;
        else
            m["special"]++;
    }
    s += char(y);
    map<string, int>::iterator ir = m.begin();
    for (; ir != m.end(); ir++)
    {
        if (ir->second == 0)
            return "";
    }
    return s;
}
int main()
{
    map<string, int> m;
    string password;
    int max = 32, min = 12;
    srand(time(NULL));
    int n = (rand() % (max - min + 1)) + min;
    while (1)
    {
        password = randompassword(n, m);
        if (password == "")
            password = randompassword(n, m);
        else
        {
            cout << "Password is : " << password << endl;
            break;
        }
    }
    return 0;
}