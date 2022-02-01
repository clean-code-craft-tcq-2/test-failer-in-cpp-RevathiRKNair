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
    output.append(minorColor[minorIdx] );
   
    return output;
}


std::string numToColor(int pairNumber)
{
    int majorClrIdx = (pairNumber / numberOfMinorColors);
    int minorClrIdx = (pairNumber % numberOfMinorColors);

    return colorPair(majorClrIdx, minorClrIdx);
}

void printToConsol(int i, int j)
{
    std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
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
    assert(numToColor(5) == "5|Red|Blue");
    assert(numToColor(8) == "8|Red|Brown");
    assert(numToColor(13) == "13|Black|Brown");
    assert(numToColor(20) == "20|Violet|Blue");
    assert(numToColor(24) == "24|Violet|Slate");
    std::cout << "All is well!\n";
    return 0;
}