
#include <iostream>
#include <assert.h>

#define MAX_THRESHOLD 35

int alertFailureCount = 0;

int networkAlertStub(float celcius) 
{
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    
    if (MAX_THRESHOLD < celcius)
    {
        return 500;
       
    }
   
    return 200;
}

int Fahr2Celcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

void failureCount(int result)
{
    
    if (result != 200) 
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

void alertInCelcius(float farenheit) 
{
    float celcius = Fahr2Celcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    failureCount(returnCode);
}

int main() 
{
    alertInCelcius(400.5);
    assert(alertFailureCount == 1);
    alertInCelcius(303.6);
    assert(alertFailureCount == 2);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}