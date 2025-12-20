#include <iostream>

class Device {
    private:
        std::string name;
    
    public:
        Device(std::string name) : name(std::move(name)) {}

        const std::string& getName() const { return name; }

        virtual void printInfo() const {
            std::cout << "Device Name: " << name << std::endl;
        }
};

int main() {

    Device device("iphone");

    return 0;
}