#include <iostream>
#include <fstream>
#include <string>


using namespace std;

bool find();


int main()
{
    find() ? cout << "n or o found" << endl : cout << "n or o not found" << endl;
    return 0;
}


bool find()
{
    ifstream t("t.txt");
    string s;

    int k = 0;

    while (getline(t, s))
    {
        for (int i = 0; i < s.length() - 2; i++)
        {
            if (s[i] == 'n' &&
                s[i + 2] == 'o')
            {
                return true;
            }
        }
    }
    return false;
}

