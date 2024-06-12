#ifndef SENECA_NAME_H
#define SENECA_NAME_H
#include <iostream>

namespace seneca {

	class Name
	{
		//char m_value[81];
		char* m_data;
		int m_age;
		
		void deallocate();
	public:

		Name();
		Name(const char* name);
		Name(const char* name, int age);
		
		~Name();

		Name* returnValue();
		Name& returnTargetOf();

		Name& setName(const char* name);
		Name& setName(const char* name, int age);

		std::ostream& print(std::ostream& ostr = std::cout)const;
	};

}
#endif // !SENECA_NAME_H



