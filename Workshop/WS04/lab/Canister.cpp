#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"


using namespace std;
namespace seneca {
    const double PI = 3.14159265;
    //private
    void Canister::setToDefault() {
        //This function sets the attributes to their default values.
        // It sets the content name pointer to null, height to 13.0, diameter to 10.0, content volume to 0.0 and usable flag to true.
        m_contentName = nullptr;
        m_diameter = 10.0; // in centimeters
        m_height = 13.0;   // in centimeters
        m_contentVolume = 0.0;  // in CCs
        m_usable = true;
    }
    void Canister::setName(const char* Cstr) {
        //Sets the content name of the current Canister.
        //If the incoming Cstr is not null and the Canister is usable, it will delete the current content name,
        //allocate memory to the length of Cstr (+1 for null) and copies the Cstr into the newly allocated memory.
        //Otherwise, it will silently do nothing.
        if (Cstr != nullptr && m_usable) {//no nullptr nad have something
            delete[] m_contentName;                             //delete m_contentName
            m_contentName = nullptr;                            //set to nullptr for safety guard
            m_contentName = new char[strlen(Cstr) + 1];        //allocate a new char
            strcpy(m_contentName, Cstr);                 //copy
        }

    }
    bool Canister::isEmpty()const {
        //Returns true if the content volume is less than 0.00001 CCs.
        return (m_contentVolume < 0.00001);
    }
    bool Canister::hasSameContent(const Canister& C)const {
        //Compares the content name of this Canister with the one received from the argument C.
        //Compare the two content names using strcmp from so that it returns true if both names are not null and are identical.
        //Otherwise, it returns false;

        return strcmp(m_contentName, C.m_contentName);//return 0 means equal  not 0 means not equal
        //return (m_contentName[0] != '\0' && C.m_contentName[0] != '\0' && !strcmp(m_contentName, C.m_contentName));
    }
    //--public
    Canister::Canister() {
        //Sets the attributes to their default values
        setToDefault();

    }
    Canister::Canister(const char* contentName) {
        //Sets the attributes to their default values (note: reuse code)
        //Sets the name to the incoming contentName argument.
        //Sets the attributes to their default values
        setToDefault();
        setName(contentName);
    }
    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        //        If the dimensions are within acceptable values:
        //        it will set the m_height and m_diameter to the corresponding argument values
        //        it will set the content volume to 0.
        //        it will set the content name to the corresponding argument value.
        //        If any of the dimensions have invalid values, it will set the Canister as unusable
        if (height < 10 || diameter < 10 || height > 40 || diameter > 30) {
            m_usable = false;
        }
        else {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0;
            setName(contentName);
        }
    }
    Canister::~Canister() {

        delete[] m_contentName;
        m_contentName = nullptr;
        //cos i new a new space in setName function
    }
    Canister& Canister::setContent(const char* contentName) {
        //        It will set the Content name of the canister using the following rule and then returns the reference of the current object (i.e. *this):
        //        If the contentName argument is null it will render the Canister unusable
        //        else if the Canister is empty it will set the name to the value pointed by the argument
        //        else if the name of the Canister is not the same as the contentName argument it will render the Canister unusable.
        if (contentName == nullptr) {
            m_usable = false;
        }
        else if (isEmpty()) {
            setName(contentName);
        }
        else if (hasSameContent(contentName)) {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(double quantity) {
        //Adds the quantity argument to the content volume of the Canister if the quantity fits in the Canister.
        //Otherwise, it will render the Canister unusable and then returns the reference of the current object.
        //Use this rule to accomplish the above:
        //If the Canister is usable and the quantity is more than zero and if the sum of the quantity and the volume() is less than or equal to the capacity(), add the quantity to the content volume,
        // otherwise set usable flag attribute to false.
        if (m_usable && quantity > 0 && ((quantity + volume()) <= capacity())) {
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(Canister& srcCan) {//I add the name Can
        //src to this
//        Pours the content of the Canister argument into the current Canister following the Specs stated at the top

//        Set the content name to the Canister argument using setContent().
//        if the srcCan volume()他杯子裡的現有液體 is greater than 大於the capacity() minus the volume()（我的剩餘容量）(我的容器大小減掉我已經裝的現有液體量)
//        Reduce the content volume of srcCan減少他的現有液體容量 by capacity() minus volume() 減 我的剩餘容量的and then set the content volume to capacity()我的液體量等於我的容量
//        else pour the content volume of srcCan using pour() method and set the content volume of the srcCan to 0.0.
//        return the reference of the current object at the end.
        this->setContent(srcCan.m_contentName);
        if (srcCan.volume() > (this->capacity() - this->volume())) {
            srcCan.m_contentVolume -= (this->capacity() - this->volume());
            this->m_contentVolume = this->capacity();
        }
        else {
            this->pour(srcCan.volume());
            srcCan.m_contentVolume = 0.0;
        }
        return *this;
    }
    double Canister::volume()const {
        //returns the content volume attribute
        return m_contentVolume;
        //return (!isEmpty())?m_contentVolume:0.0;

    }
    std::ostream& Canister::display()const {
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {
            cout << " of ";
            cout.width(7);
            cout.setf(ios::right);
            cout << m_contentVolume << "cc   " << m_contentName;
        }
        return cout;
    }
    double Canister::capacity()const {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }
    void Canister::clear() {
        //        Clears an unusable Canister back to an empty Canister by:
        //        deallocating the memory pointed by the content name attribute
        //        sets the content name attribute to nullptr
        //        sets the content volume attribute to 0.0
        //        set the usable flag attribute to true
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}