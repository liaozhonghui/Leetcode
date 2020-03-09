#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    int a[3] = {0};
    cout << &i << endl;
    cout << &a << endl;
    cout << &a[3] << endl;
    /*  cout << &a[2] << endl;
    cout << &a[3] << endl;
    for (; i <= 3; i++)
    {
        a[i] = 0;
        cout << &a[3] << endl;
    } */
    return 0;
}