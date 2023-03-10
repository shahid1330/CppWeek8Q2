#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    char *st;

    String(string s = "")
    {
        st = new char(s.length());
        strcpy(st, s.c_str()); // IMP C style string to char array conversion

        // NOTE :
        /*
        char *c=new char(0);
        strcpy(c,"Hello");
         being dynamic memory allocation the size of gets mutated acc to the string
        */
    }

    String(String &ob)
    {
        st = ob.st;
    }

    ~String()
    {
        cout << "Memory Destroyed" << endl;
    }

    void display()
    {
        cout << st << endl;
    }

    void chang_case()
    {
        cout << "\nCHANGE CASE   :   " << endl;
        char *str = String::st;
        int i = 0;
        while (*str != '\0')
        {
            if (*str >= 65 && *str <= 90)
            {
                st[i] = *str + 32;
            }
            else if (*str >= 97 && *str <= 122)
            {
                st[i] = *str - 32;
            }
            i++;
            str++;
        }
    }

    string rev(char *str)
    {
        cout << "\nREVERSE " << endl;
        string x;
        char *end = str;
        int length = 0;
        while (*end != '\0')
        {
            length++;
            end++;
        }
        end--;

        char temp;
        for (int i = 1; i <= length / 2; i++)
        {
            temp = *str;
            *str = *end;
            *end = temp;

            str++;
            end--;
        }
        x = end;
        return x;
    }

    String operator+(String &str)
    {
        cout << "\n+ OP " << endl;
        String obj;
        strcat(this->st, str.st);
        strcpy(obj.st, this->st);
        return obj;
    }
    char operator[](int x)
    {
        char c = *st + x;
        return c;
    }

    friend istream &operator>>(istream &inn, String ob);

    friend ostream &operator<<(ostream &out, String ob);
};

istream &operator>>(istream &in, String ob)
{
	cout<<"MOHAMMAD SHAHID RAZA"<<endl;
        cout << "A35404821013" << endl;
		cout << "Week 8 Question 2 output:"<<endl;
    cout << "\nENTERING DATA : ";
    in >> ob.st;
    return in;
}
ostream &operator<<(ostream &out, String ob)
{
    cout << "\nSHOWING DATA : ";
    out << ob.st << endl;
    return out;
}

int main()
{
    String x;
    cin >> x;
    cout << x;

    String ob1("Hello");
    ob1.display();
    String ob2(" World");
    ob2.display();

    String temp;
    temp = ob1 + ob2;
    temp.display();

    temp.chang_case();
    temp.display();

    cout << temp.rev(ob1.st) << endl;

    cout << temp.st[1] << endl;
}
