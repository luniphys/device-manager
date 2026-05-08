#include <iostream>
#include <vector>

class Device {
    private:
        std::string name;

    public:
        Device(std::string name) : name(std::move(name)) {
            std::cout << "Constructor called: Device" << std::endl;
        }

        const std::string& getName() const { return name; }

        // "virtual" meaning this is the base class fct that later is overridden.
        virtual void printInfo() {
            std::cout << "Device Name: " << name << std::endl;
        }

        // Virtueller Destructor. Grund: Wenn ein Objekt aus einer child class über einen base class
        // Pointer gelöscht wird, wird sichergestellt das desctructor in child UND base class aufgerufen wird
        // Ohne: Undefiniertes Verhalten
        // Solte bei virtuellen Funktionen immer verwendet werden
        virtual ~Device() {
            std::cout << "Destructor called: Device" << std::endl;
        }
};

class Computer : virtual public Device { // virtual takes reference of parent, no copy -> Diamond inheritance
    private:
        int ramGB;
 
    public:
        // std::move not for primitive types
        // base classe always 1st in initiator list
        Computer(std::string name, int ramGB) : Device(std::move(name)), ramGB(ramGB) {
            std::cout << "Constructor called: Computer" << std::endl;
        }

        // no const& for primitive types (for return type)
        int getRamGB() const { return ramGB; }
        
        // override needed since base class function is virtual
        void printInfo() override {
            std::cout << "Computer Name: " << getName() << ", Ram: " << ramGB << " GB" << std::endl;
        }

        ~Computer() override {
            std::cout << "Destructor called: Computer." << std::endl;
        }
};

class Smartphone : virtual public Device { // virtual takes reference of parent, no copy -> Diamond inheritance
    private:
        bool has5G;
    
    public:
        Smartphone(std::string name, bool has5G) : Device(std::move(name)), has5G(has5G) {
            std::cout << "Constructor called: Smartphone" << std::endl;
        }

        bool getHas5G() const { return has5G; }

        void printInfo() override {
            std::cout << "Smartphone Name: " << getName() << ", 5G: " << has5G << std::endl;
        }

        ~Smartphone() override {
            std::cout << "Destructor called: Smartphone" << std::endl;
        }
};

class SmartComputer : public Computer, public Smartphone {
    private:
        bool touchscreen;

    public:
        // "Die virtuelle Basisklasse wird effektiv nur vom am weitesten abgeleiteten Konstruktor initialisiert."
        // -> Smartphone kreiert hier Device. Die Device Konstruktoren in Computer & Smartphone werden hier ignoriert.
        SmartComputer(std::string name, int ramGB, bool has5G, bool touchscreen) :
        Device(std::move(name)), Computer(name, ramGB), Smartphone(name, has5G), touchscreen(touchscreen) {
            std::cout << "Constructor called: Smartcomputer" << std::endl;
        }

        bool getTouchscreen() const { return touchscreen; }

        void printInfo() override {
            std::cout << "SmartComputer Name: " << getName() << ", Ram: " << getRamGB() << " GB, 5G: "
            << getHas5G() << ", Touchscreen: " << touchscreen << std::endl;
        }

        ~SmartComputer() override {
            std::cout << "Destructor called: SmartComputer" << std::endl;
        }

};



int main() {

    std::cout << "------------------------------------------------------------------------\nUpcasting:\n" << std::endl;

    SmartComputer* sc = new SmartComputer("Surface", 4, false, true);

    Device* scDvc = sc;
    std::cout << std::endl;
    scDvc->printInfo();

    std::cout << "------------------------------------------------------------------------\nDowncasting:\n" << std::endl;

    // dynamic_cast does not change object type, it only checks what object is in dynamic memory  
    // scDvc->getTouchscreen() would fail since Compiler sees scDvc as type Device* which has no touchscreen attribute
    
    SmartComputer* sc_dyn = dynamic_cast<SmartComputer*>(scDvc);
    if (sc_dyn != nullptr) {
        std::cout << "Has Touchscreen: " << sc_dyn->getTouchscreen() << std::endl;
    }
    
    std::cout << "------------------------------------------------------------------------\nPolymorphismus:\n" << std::endl;

    Computer* pc = new Computer("HP", 8);
    Smartphone* sp = new Smartphone("Galaxy", true);

    std::vector<Device*> devices;
    devices.push_back(pc);
    devices.push_back(sp);
    devices.push_back(sc);

    std::cout << std::endl;

    for (Device* dvs : devices) {
        dvs->printInfo();
    }

    std::cout << "------------------------------------------------------------------------" << std::endl;

    delete sc;
    delete pc;
    delete sp;


    return 0;
}
