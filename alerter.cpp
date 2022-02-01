
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
        alertFailureCount += 1;
    }
}

void alertInCelcius(float farenheit) 
{
    float celcius = Fahr2Celcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    failureCount(returnCode);
}

void testTempConversion(int tempInFahr, int expectedValue)
{
    float celcius = Fahr2Celcius(tempInFahr);
    assert(celcius == expectedValue);
}

void testAlertSignal(int temperature, int expectedValue)
{
    alertInCelcius(temperature);
    assert(expectedValue == alertFailureCount);
}

void testFailureCount(int errorCode, int expectedValue)
{
    alertFailureCount = 0;
    failureCount(errorCode);
    assert(alertFailureCount == expectedValue);
}

int main() 
{
    testAlertSignal(400.5,1);
   
    testAlertSignal(303.6,2);
    
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
   
    testTempConversion(32,0);

    testFailureCount(200, 0);

    testFailureCount(300,1);

    return 0;
}