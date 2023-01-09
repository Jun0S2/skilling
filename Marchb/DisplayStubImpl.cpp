#include <iostream>
#include <memory>
#include <string>
#include <DisplayManagerStubImpl.h>
#include <DisplayStubImpl.h>

// class DisplayStubImpl{
//     public:
//         DisplayStubImpl():mA(1),mptr(std::make_shared<DisplayManagerStubImpl>()){}
//         //std::shared_ptr<DisplayManagerStubImpl> mptr = std::make_shared<DisplayManagerStubImpl>();
// };

DisplayStubImpl::DisplayStubImpl() : mA(0),mptr(std::make_shared<DisplayManagerStubImpl>())  {
}

int main(){
    // std::cout<< mA <<endl;
    DisplayStubImpl mA;
    printf("$d",  mA);
    //mptr.printHell();
}