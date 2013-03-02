#include <iostream>
#include <cmath>
using namespace std;

int graphHeight, graphWidth, aspectedGraphHeight, row, column, radius, x, y;
double startAngle, endAngle, angle, angleStep;
char circle[150][150];

int main(void)
{  
    
    cout << "Enter graph Height: ";
    cin >> graphHeight;
    cout << "Enter graph Width: ";
    cin >> graphWidth;
    cout << "Radius: ";
    cin >> radius;
    cout << "startAngle: ";
    cin >> startAngle;
    cout << "endAngle: ";
    cin >> endAngle;
    
    
    aspectedGraphHeight = graphHeight/2 + .5;  
    //graphHeight is divided by scaling factor 2 for aspected ratio of characters in terminal
    startAngle *= M_PI/180.;
    endAngle *= M_PI/180.;
    angleStep = (2* M_PI)/(2 * 2 * radius);   //2 * 2 *radius = no. of dots
        
    
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
     
    //points of arc  
    for (angle = startAngle;  angle <= endAngle; angle += angleStep)
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

