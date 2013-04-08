#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
    int row,column,graphHeight,graphWidth,step;
    double base1,altitude1;
    char triangle[130][130];
    cout<<"Enter graph height: ";
    cin>>graphHeight;
    cout<<"Enter graph width: ";
    cin>>graphWidth;
    cout<<"Enter base and altitude of triangle such that base is smaller than altitude: ";
    cin>>base1>>altitude1;
    if(altitude1 > base1)
    {
        double unit = double(altitude1/(base1/2));
        step = unit + .5;
    }
    else
    {
        cout<<"sorry,base is either greater than or equals to altitude.\n";
        exit (0);
    }

    double hypotenuse1 = sqrt((altitude1/2) * (altitude1/2) + (base1/2) * (base1/2)) + 0.5;
    int hypotenuse = hypotenuse1;
    int altitude = altitude1;
    int base = base1;
    
    //define graph
    for(row = 0; row <= graphHeight; row++)
    {
        for(column = 0; column <= graphWidth; column++)
        {
            triangle[row][column] = ' ';
        }
    }

    // Y-axis
    for(int y = 0; y <= graphHeight; y++)
    {
        int x = graphWidth/2;                        
        triangle[y][x] = '|';
    }

    // X-axis
    for(int x = 0; x <= graphWidth; x++)
    {
        int y = graphHeight/2;
        triangle[y][x] = '_';
    }

    //base of triangle
    int k = graphHeight/2 + altitude/2;
    for(int row = (graphWidth/2 - base/2);
        row < (graphWidth/2 - base/2) + base;
        row++)
    {
        triangle[k][row] = '.';
    }
    //side 1 of triangle
    for(int p = (graphHeight/2 - altitude/2), q = graphWidth/2;
        p <= (graphHeight/2 - altitude/2) + hypotenuse, q > graphWidth/2 - base/2;
        p += step, q--)
    {
        triangle[p][q] = '.';
    }
    //side 2 of triangle
    for(int p = (graphHeight/2 - altitude/2), q = graphWidth/2;
        p <= (graphHeight/2 - altitude/2) + hypotenuse, q < graphWidth/2 + base/2;
        p += step, q++)
    {
        triangle[p][q] = '.';
    }

    // print triangle
    for(row = 0; row <= graphHeight; row++)
        { 
        for(column = 0; column <= graphWidth; column++)
            {
            cout<<triangle[row][column];
            }
            cout<<endl;
        }
}

