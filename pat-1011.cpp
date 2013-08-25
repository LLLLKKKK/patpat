#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double s = 1;
    char g[3];

    for (int i = 0;i < 3;i++){
        double b = 0;
        double a;
        for (int j = 0; j < 3; j++)
        {
            cin >> a;
            if (a > b) {
                b = a;
                switch (j)
                {
                case 0: g[i] = 'W'; break;
                case 1: g[i] = 'T'; break;
                case 2: g[i] = 'L'; break;
                }
            }
        }
        s *= b;
    }
    
    cout <<g[0]<<" "<<g[1]<<" "<<g[2]<<" "<<setprecision(4)<<((int)((s*0.65-1)*2*100))/100.0<<endl;
    return 0;
}
