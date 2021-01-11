#include<iostream>
#include<locale>
#include<string>
#include<iomanip>
#include<fstream>
#include <sstream>
#define TESTING

using namespace std;

#pragma pack(push, 1)

struct Bday
{
    int day;
    int month;
    int year;
};

struct Zodiac
{
    string surname;
    string name;
    string zodiac_sign;
};

#pragma pack(pop)

void Create(const string file_name, const int option);
void Print(const string file_name);
void Find(const string file_name);

#ifdef TESTING
int main()
{
    string file_name = "t.txt";

    int MenuItem;

    while (true)
    {
        cout << endl
            << endl
            << endl;
        cout << "Choose an action:" << endl;
        cout << "1 - Enter user information" << endl;
        cout << "2 - Display user information" << endl;
        cout << "3 - Search for a person by zodiac" << endl;
        cout << "0 - Shut down the program" << endl;
        cout << "Enter:";
        cin >> MenuItem;
        cout << endl;

        switch (MenuItem)
        {
        case 1:
            Create(file_name, 1);
            break;
        case 2:
            Print(file_name);
            break;
        case 3:
            Find(file_name);
            break;
        }
        if (MenuItem == 0)
            break;
    }

    return 0;
}
#endif

void Create(const string file_name, int option)
{
    Zodiac S;
    Bday B;

    ofstream f;

    if (option == 1)
        f.open(file_name, ios::out);
    else
        f.open(file_name, ios::app);

    if (!f.is_open())
    {
        cout << "File not open!" << endl;
        return;
    }
    cin.get();

    string keep;

    do
    {
        cout << endl << endl;
        cout << "Surname: "; getline(cin, S.surname);
        f << S.surname << endl;

        cout << "Name: "; getline(cin, S.name);
        f << S.name << endl;

        cout << "Zodiak: "; getline(cin, S.zodiac_sign);
        f << S.zodiac_sign << endl;

        cout << "Enter birthday: "; cin >> B.day;
        f << B.day << endl;

        cout << "Enter the month of birth: "; cin >> B.month;
        f << B.month << endl;

        cout << "Enter the year of birth: "; cin >> B.year;
        f << B.year << endl;

        cin.get();
        cout << "To continue, enter (Y): "; getline(cin, keep); cout << endl;
    } while (keep == "Y");
}

void Print(const string file_name)
{
    ifstream f(file_name);
    string str;

    cout << "==============================================================================" << endl;
    cout << "|  #  |  Surname  | Name | Zodiac  |  Day  |  Month  |  Year          |" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    int id = 1;
    while (!f.eof()) {

        getline(f, str);
        if (str.length() == 0)
            continue;

        cout << "|" << setw(4) << id++ << setw(2);
        cout << "|" << setw(4) << str << setw(7);
        getline(f, str);
        cout << "|" << setw(2) << str << setw(3);
        getline(f, str);
        cout << "|" << setw(4) << str << setw(5);
        getline(f, str);
        cout << "|" << setw(5) << str << setw(3);
        getline(f, str);
        cout << "|" << setw(6) << str << setw(4);
        getline(f, str);
        cout << "|" << setw(11) << str << setw(6) << "|" << endl;
    }
    cout << "==============================================================================" << endl;
    f.close();
}

void Find(const string file_name)
{
    string f_zodiac_sign;
    cout << "Enter the user's zodiac: "; cin >> f_zodiac_sign;
    ifstream f(file_name);

    if (!f.is_open())
    {
        cout << "File not open!" << endl;
        return;
    }
    string str[6];
    while (!f.eof())
    {


        getline(f, str[0]);
        if (str[0].length() == 0)
            continue;
        getline(f, str[1]);
        getline(f, str[2]);
        getline(f, str[3]);
        getline(f, str[4]);
        getline(f, str[5]);
        if (str[2] == f_zodiac_sign)
        {

            cout << "|  #  |  Surname  | Name | Zodiac  |  Day  |  Month  |  Year          |" << endl;
            cout << "------------------------------------------------------------------------------" << endl;
            cout << "|" << setw(4) << 1 << setw(2);
            cout << "|" << setw(4) << str[0] << setw(7);
            cout << "|" << setw(2) << str[1] << setw(3);
            cout << "|" << setw(4) << str[2] << setw(5);
            cout << "|" << setw(5) << str[3] << setw(3);
            cout << "|" << setw(6) << str[4] << setw(4);
            cout << "|" << setw(11) << str[5] << setw(6) << "|" << endl;
            cout << "==============================================================================" << endl << endl;
            break;
        }

    }
    if (f.eof())
        cout << "User not found" << endl;
    f.close();
}
