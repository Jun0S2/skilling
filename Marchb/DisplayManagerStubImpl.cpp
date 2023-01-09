
#include <iostream>
#include <memory>

using namespace std;

class DisplayManagerStubImpl
{
private:
    /* data */
public:
    DisplayManagerStubImpl(/* args */);
    ~DisplayManagerStubImpl();
    void printHell();
    
};

void DisplayManagerStubImpl::printHell()
{
    cout<<"Hell "<< endl;
}
