#include <iostream>
#include <cmath>
using namespace std;
int main(){
char sine[150][150];
        int row,column,numberOfCycles,sineWidth,sineHeight;
        double middleOfGraphWidth, graphStart,graphEnd,range,unitStepY,pointStartX;
        cout<<"\n\n";
        cout<<"\t\t\t###########SINE WAVE###########\n\n\n";
        /*
 Function to represent Horizontal Sine Wave
*/
cout<<"\n\t\tEnter width and height of sine wave: ";
    cin>>sineWidth>>sineHeight;
    cout<<"\n\t\tEnter number of cycles you want: ";
    cin>>numberOfCycles;    
    middleOfGraphWidth = sineWidth / 2;
    graphStart = 0.;
    graphEnd = 360. * numberOfCycles;
    graphStart *= M_PI / 180;
    graphEnd *= M_PI / 180;
    range = graphEnd - graphStart;
    unitStepY = range / sineHeight;
    /*
 Function to represent Vertical Sine Wave
*/

 for(row = 0; row <= sineHeight; row++)
	{
	    for(column = 0; column <= sineWidth; column++)
	    sine[row][column] = ' ';
	}
	
	//to draw x-axis of graph    
	             
	for(row = 0; row <= 0 + sineHeight; row++)
    {   
        column = sineWidth/2;  
        sine[row][column] = '|';
    }	    

    //to draw sine wave
    int sineWaveY = 0;
    for(double sineWaveX = graphStart; sineWaveX <= graphEnd; sineWaveX += unitStepY)
    { 
		double pointStartX = sin(sineWaveX);
		double pointStartX1 = (pointStartX *  middleOfGraphWidth) + sineWidth/2;                                  
		int pointStartX2 = round(pointStartX1);
		sine[sineWaveY][pointStartX2] = '*';
		sineWaveY++;
    }
	
	
	//Print the complete array
    for(row = 0; row <= sineHeight; row++)
	{
	    for(column = 0; column <= sineWidth; column++)
	    {
	        cout<<sine[row][column];
	    }
	    cout<<endl;
    }
    
}

