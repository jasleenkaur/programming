#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int graphHeight, graphWidth, radius1, radius2, angle, aspectedGraphHeight, row, column, x, y, angleStep;
    char hypocycloid[150][150];
           
    cout<<"\n\n\t\t\t###### Draw hypocycloid #######\n";
    cout << "\n\t\tEnter graph Height: ";
    cin >> graphHeight;
    cout << "\t\tEnter graph Width: ";
    cin >> graphWidth;
    cout << "\t\tRadius of hypocycloid: ";
    cin >> radius2;
    int k=3;
    radius1 = k * radius2;
    
     
    //converting degree to radian by multiplying with pi/180
    angle = angle * M_PI/180;
    
    //graphHeight is divided by scaling factor 2 for aspected ratio of characters in terminal
    //.5 is for precision
    aspectedGraphHeight = graphHeight/2 + .5;  
    
    
    // define graphpaper          
    for(row=0; row<=aspectedGraphHeight; row++)
    {    
        for(column=0; column<=graphWidth; column++)
        {
        hypocycloid[row][column]=' ';
        }
    }   
    
    //horizontal axis     
    for(column = 0; column <= graphWidth; column++)
    {
        row = aspectedGraphHeight / 2;
        hypocycloid[row][column] = '-';
    }
            
    //vertical axis
    for(row = 0; row <= aspectedGraphHeight; row++)
    {
         column = graphWidth / 2;
         hypocycloid[row][column] = '|';
    }
    
    //points of hypocycloid
     
    for (angle = 0;  angle <= 360; angle += 1)
    {   
       x = ((radius1- radius2) * cos(angle)) + (radius2 * cos((radius1/radius2 - 1.0)*angle)) +.5;  
       y = ((radius1- radius2) * sin(angle)) - (radius2 * sin((radius1/radius2 - 1.0)*angle)) +.5;
     
     row = (aspectedGraphHeight/2 - y/2 +.5);  
     // y is divided by scaling factor 2 for aspected ratio of characters in terminal
     column = graphWidth/2 + x;
     hypocycloid[row][column] = '.';
    }    
        
    
    //print hypocycloid
    for(row = 0; row<=aspectedGraphHeight; row++)
        {
             for(column = 0; column<=graphWidth; column++)
             cout << hypocycloid[row][column];
             cout<<endl;
        }     
}
