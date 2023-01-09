#include <memory>
#include <iostream>

class DisplayManager {
public:
    void print() {
        //call print
    }
};

class DisplayManagerStubImpl {
public:
    void print() {
        std::cout << "Connect to Socket FUnction \n";
        // gdbus랑 통신하는 코드
    }
};

class DisplayStubImpl {
public:
    DisplayStubImpl() : mpDisplayManagerStubImpl(std::make_shared<DisplayManagerStubImpl>()) {}

    void callPrint() {
       // mpDisplayManagerStubImpl.print();
       mpDisplayManagerStubImpl->print();
    }

private:
    std::shared_ptr<DisplayManagerStubImpl> mpDisplayManagerStubImpl; // Disply
};

int main() {
    DisplayStubImpl si;
    si.callPrint();
    return 0;
}
