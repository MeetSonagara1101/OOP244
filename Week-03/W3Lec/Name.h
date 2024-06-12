#ifndef SENECA_NAME_H
#define SENECA_NAME_H
namespace seneca {


    class Name {
    private:
        char* m_name{};
        char* m_surname{};
        void deallocate();
    public:
        Name();     //Constructor
        ~Name();    //Destructor
        void set(const char* name, const char* surname);
        void print()const ;
        void read();

    };


}
#endif // !SENECA_NAME_H



