#ifndef SENECA_MYARRAY_H
#define SENECA_MYARRAY_H
namespace seneca {

	class MyArray
	{
		int* m_array;
		int m_size;
	public:
		MyArray(int size);
		~MyArray();

		// overloading the [] operator
		int& operator[](int index);

		int element(int index);
		int size()const;
	};


}
#endif // !SENECA_MYARRAY_H


