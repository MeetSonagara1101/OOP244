#ifndef SENECA_CONTAINER_H
#define SENECA_CONTAINER_H
#include <iostream>

namespace seneca {
	class Container
	{
		int m_contents;
		int m_capacity;

	public:
		Container(int capacity = 250, int content = 100);

		Container& addTo(int value);
		Container& operator+=(int value);
		int getContent();

		operator int()const;
		operator double()const;
		//Container& operator+ (Container& left)const;

		std::ostream& print(std::ostream& ostr = std::cout)const;
		bool operator!()const;

		Container& operator++(); //prefix
		Container& operator++(int); // postfix

		friend Container operator+ (const Container& left, const Container& right);
	};

	//value = value + C;
	//helper function
	int operator+=(int& leftOperand, Container& rightOperand);
	
	//this is not supposed to be a non-member but just to understand a concept
	Container operator+ (const Container& left, const Container& right);

}

#endif // !SENECA_CONTAINER_H



