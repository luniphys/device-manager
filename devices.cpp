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

        // Virtueller Destructor. Grund: Wenn ein Objekt aus einer child class über einen base class
        // Pointer gelöscht wird sichergestellt das desctructor in child UND base class aufgerufen wird
        virtual ~Device() {
            std::cout << "Device destructor called." << std::endl;
        }
};

class Computer : virtual public Device { // virtual takes reference base, no copy
    private:
        int ramGB;

    public:
        Computer(std::string name, int ramGB) : Device(std::move(name)), ramGB(std::move(ramGB)) {}
        // base classe always 1st in initiator list

        const int& getRamGB() const { return ramGB; }

        void printInfo() override {
            std::cout << "Computer Name: " << getName() << ", Ram: " << ramGB << " GB" << std::endl;
        }

        ~Computer() {
            std::cout << "Computer destructor called." << std::endl;
        }
};

class Smartphone : virtual public Device { // virtual takes reference base, no copy
    private:
        bool has5G;
    
    public:
        Smartphone(std::string name, bool has5G) : Device(std::move(name)), has5G(std::move(has5G)) {}

        const bool& getHas5G() const { return has5G; }

        void printInfo() override {
            std::cout << "Smartphone Name: " << getName() << ", 5G: " << has5G << std::endl;
        }

        ~Smartphone() {
            std::cout << "Smartphone destructor called." << std::endl;
        }
};

class SmartComputer : public Computer, public Smartphone {
    private:
        bool touchscreen;

    public:
        SmartComputer(std::string name, int ramGB, bool has5G, bool touchscreen) :
        Device(std::move(name)), Computer(std::move(name), std::move(ramGB)), Smartphone(std::move(name), std::move(has5G)), touchscreen(std::move(touchscreen)) {}

        const bool& getTouchscreen() const { return touchscreen; }

        void printInfo() override {
            std::cout << "SmartComputer Name: " << getName() << ", Ram: " << getRamGB() << " GB, 5G: "
            << getHas5G() << ", Touchscreen: " << touchscreen << std::endl;
        }

        ~SmartComputer() {
            std::cout << "SmartComputer destructor called." << std::endl;
        }

};



int main() {

    Device dvc("iphone");
    dvc.printInfo();

    Computer pc("hp", 8);
    pc.printInfo();

    Smartphone sp("galaxy", true);
    sp.printInfo();

    SmartComputer sc("surface", 4, false, true);
    sc.printInfo();

    std::cout << std::endl;

    return 0;
}

// Within class methods: Use attribute directly or via getter?
