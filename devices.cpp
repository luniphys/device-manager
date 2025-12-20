#include <iostream>

class Device {
    private:
        std::string name;
    
    public:
        Device(std::string name) : name(std::move(name)) {}

        const std::string& getName() const { return name; }

        // "virtual" meaning this is the base class fct that later is overridden.
        virtual void printInfo() {
            std::cout << "Device Name: " << name << std::endl;
        }

        // virtual destructor needed?
};

class Computer : virtual public Device { // virtual takes reference base, no copy
    private:
        int ramGB;
    
    public:
        Computer(std::string name, int ramGB) : Device(std::move(name)), ramGB(ramGB){} // base classe always 1st in initiator list

        const int& getRamGB() const { return ramGB; }

        void printInfo() override {
            std::cout << "Device Name: " << getName() << ", Ram: " << getRamGB() << " GB" << std::endl;
        }
};

class Smartphone : virtual public Device {
    private:
        bool has5G;
    
    public:
        Smartphone(std::string name, bool has5G) : Device(std::move(name)), has5G(has5G){}

        const bool& getHas5G() const { return has5G; }

        void printInfo() override {
            std::cout << "Device Name: " << getName() << ", 5G: " << has5G << std::endl;
        }
};


int main() {

    Device device("iphone");
    device.printInfo();

    Computer computer("hp", 8);
    computer.printInfo();

    Smartphone smartpone("galaxy", true);
    smartpone.printInfo();

    return 0;
}

// Within class methods: Use attribute directly or via getter?