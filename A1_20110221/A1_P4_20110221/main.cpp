#include <iostream>

using namespace std;

int power (int a , int n)
{
    if(n==1) return a ;
    else
    {
        return a * power(a,n-1);
    }
}

int power2 (int a , int n)
{
    if(n==1) return a ;
    else
    {
        return power(a,n/2) * power(a,n/2+n%2);
    }
}


int main()
{
    cout << "Hello world!" << endl;
    cout << power(2,3) <<endl;
    cout << power2(2,3);
    return 0;
}
