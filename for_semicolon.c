#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int a[3][3]={{1,-22,0},{22,1,33},{12,3,-1445}}, count[3][3];
    for(int i=0; i<3; i++)
    {
        for(int j=0;j<3; j++)
        {
            count[i][j]=log10(a[i][j])+1;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0;j<3; j++)
        {
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(count[i][j]==1)
            {
                a[i][j]=10;
            }
            else if(count[i][j]==2)
            {
                a[i][j]=100;
            }
            else if(count[i][j]==3)
            {
                a[i][j]=1000;
            }
            else if(count[i][j]==4)
            {
                a[i][j]=10000;
            }
            else if(a[i][j]<0)
            {
                a[i][j] *= -1;
            }
            else if(a[i][j]==0)
            {
                a[i][j]=0;
            }
        }
    }
    cout<<endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
}
