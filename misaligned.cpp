#include <iostream>
#include <assert.h>

#define MAX_COLORS 5

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int numberOfMinorColors = MAX_COLORS;
int numberOfMajorColors = MAX_COLORS;

std::string colorPair(int majorIdx, int minorIdx)
{
 
    std::string output = std::to_string(majorIdx * 5 + minorIdx);
    char ch = '|';
    output+=ch;
    output.append(majorColor[majorIdx]);
    output+=ch;
    output.append(minorColor[majorIdx] );
   
    return output;
}


std::string numToColor(int pairNumber)
{
    int zeroBasedPairNumber = pairNumber - 1;
    int majorClrIdx = (zeroBasedPairNumber / numberOfMinorColors);
    int minorClrIdx = (zeroBasedPairNumber % numberOfMinorColors);

    return colorPair(majorClrIdx, minorClrIdx);
}

void printToConsol(int i, int j)
{
    std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
}


int printColorMap() {

    int i = 0, j = 0;
    
    for(i = 0; i < MAX_COLORS; i++) 
    {
        for(j = 0; j < MAX_COLORS; j++) 
        {
            printToConsol(i,j);
        }
    }
    
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(numToColor(5) == "4|White|Slate");
    std::cout << "All is well (maybe!)\n";
    return 0;
}