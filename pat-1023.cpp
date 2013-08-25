#include <cstdlib>
#include <iostream>

using namespace std;


int box1[10] = {0};
int box2[10] = {0};

void gao(int* a, string in)
{
    for (int i = 0; i < in.length(); i++)
        a[in[i]-'0']++;
}

void exp(string& in)
{
    int carry = 0;
    int res = 0;
    for (int i = in.length()-1; i >= 0; --i)
    {
        res = (in[i]-'0')*2+carry;
        carry = res/10;
        in[i] = res%10+'0';
    }
    if (carry) {cout << "No\n"; cout << "1" << in << endl; exit(0);}
}

int main()
{
    string input;
    cin >> input;
    gao(box1, input);
    exp(input);
    gao(box2, input);
    for (int i = 0; i < 10; i++)
        if (box1[i] != box2[i])
        {
            cout << "No\n";
            cout << input << endl;
            return 0;
        }
    cout << "Yes\n";
    cout << input << endl;
}

