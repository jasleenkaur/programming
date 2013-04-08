#include <iostream>
#include <cmath>
using namespace std;
int main(){
char sine[150][150];
        int row,column,scalingFactor,numberOfCycles,sineWidth,sineHeight,sineHeight1;
        double middleOfGraphHeight,graphStart,graphEnd,range,unitStepX,unitStepY,pointStartX;
        cout<<"\n\n";
        cout<<"\t\t\t###########SINE WAVE###########\n\n\n";
        /*
 Function to represent Horizontal Sine Wave
*/
cout<<"\n\t\tEnter width and height of sine wave: ";
    cin>>sineWidth>>sineHeight;
    cout<<"\n\t\tEnter number of cycles you want: ";
    cin>>numberOfCycles;
    
     middleOfGraphHeight = sineHeight / 2;
    graphStart = 0.;
    graphEnd = 360. * numberOfCycles;
    graphStart *= M_PI / 180;
    graphEnd *= M_PI / 180;
    range = graphEnd - graphStart;
    unitStepX = range / sineWidth;
    
     for(row = 0; row <= sineHeight; row++)
	{ 
	    for(column = 0; column <= sineWidth; column++)
	    sine[row][column] = ' ';
	}

	//to draw x-axis of graph               
	for(column = 0; column <= sineWidth; column++)  
	{   
	    row = sineHeight/2; 
	    sine[row][column] = '-'; 
	}
	
	//to draw sine wave
	pointStartX = graphStart;
	for(int sineWaveX = 0; sineWaveX <= sineWidth; sineWaveX++)      
	{
	    double sineWaveY = sin(pointStartX);
        double sineWaveY1 = - sineWaveY * (middleOfGraphHeight) +sineHeight/2;                
        int sineWaveY2 = round(sineWaveY1);
        sine[sineWaveY2][sineWaveX] = '*';
        pointStartX += unitStepX;
    }

	//Print the complete array
	for(row = 0; row <= sineHeight; row++)
	{
	    for(column = 0; column <= sineWidth; column++)
	    { 
	        cout<<sine[row][column];
	    }
	    cout<<"\n";
	}
	}
