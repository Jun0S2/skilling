#include <memory>
#include "DisplayManagerStubImpl.h"

class DisplayStubImpl
{
private:
    /* data */
public:
    DisplayStubImpl(/* args */);
    ~DisplayStubImpl();
    std::shared_ptr<DisplayManagerStubImpl> mptr;
    int mA;
};

DisplayStubImpl::DisplayStubImpl(/* args */)
{
    int m;
}

DisplayStubImpl::~DisplayStubImpl()
{
}