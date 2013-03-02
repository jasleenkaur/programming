#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int graphHeight, graphWidth, radius, angle, aspectedGraphHeight, row, column, x, y, angleStep;
    char circle[150][150];
           
    cout<<"\n\n\t\t\t###### Draw circle #######\n";
    cout << "\n\t\tEnter graph Height: ";
    cin >> graphHeight;
    cout << "\t\tEnter graph Width: ";
    cin >> graphWidth;
    cout << "\t\tRadius of circle: ";
    cin >> radius;
    
     
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
        circle[row][column]=' ';
        }
    }   
    
    //horizontal axis     
    for(column = 0; column <= graphWidth; column++)
    {
        row = aspectedGraphHeight / 2;
        circle[row][column] = '-';
    }
            
    //vertical axis
    for(row = 0; row <= aspectedGraphHeight; row++)
    {
         column = graphWidth / 2;
         circle[row][column] = '|';
    }
    
    //points of circle
     
    for (angle = 0;  angle <= 360; angle += 1)
    {   
       x = radius * cos(angle) +.5;  
       y = radius * sin(angle) +.5;
     
     row = (aspectedGraphHeight/2 - y/2 +.5);  
     // y is divided by scaling factor 2 for aspected ratio of characters in terminal
     column = graphWidth/2 + x;
     circle[row][column] = '.';
    }    
        
    
    //print circle
    for(row = 0; row<=aspectedGraphHeight; row++)
        {
             for(column = 0; column<=graphWidth; column++)
             cout << circle[row][column];
             cout<<endl;
        }     
}
