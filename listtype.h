#include <iostream>
#ifndef listtype
#define listtype
using namespace std;

const int maximum = 1024;

template <class T>
class listType
{
	int index;		//the index of the last item who got inside the list.
	int size;		//the size of the container.
	T* container;	//the container.
	public:
		listType(int s=10);			//the constructor of the list.
		~listType();				//the destructor of the list.
		int getCount() const {return size;}
		int getIndex() const {return index;}
		T& first();					//return the first value of the list.
		T& last(); 					//return the last value of the list.
		void clear();				//clear all the list.
		void add(T element);		//add a value to the last time an array inserted.
		void remove(int i);			//remove a value by the index of the value.
		
		listType<T>& operator=(const listType<T>& list);	//assignment operator.
		T& operator[](int i);								// [] operator.
		T operator[](int i) const;							// [] operator.
};
template <class T>
ostream& operator<<(ostream& os,const listType<T>& list);	//a function to print out the list.


template <class T>
listType<T>::listType(int s)
{
//	cout<<"The default constructor has been activated.\n";
	if(s > maximum)
	{
	//	cerr<<"The maximum size of the array is "<<maximum<<endl;
		size=10;
	}
	if (s <= 0)
	{
	//	cerr<<"You need a positive number above 0!\n";
		size=10;
	}
	else this->size=s;
	this->index=0;
	container = new T[size];
}

template <class T>
listType<T>::~listType()
{
//	cout<<"The default destructor has been activated.\n";
//	delete[] container;
}

template <class T>
T& listType<T>::first()
{
	if (index==0)
	{
	//	cerr<"The list is empty.\n";
		exit(1);			//exception
	}
//	cout<<"The first element in the list returned successfully\n";
	return container[0];
}

template <class T>
T& listType<T>::last()
{
	if (index==0)
	{
	//	cerr<"The list is empty.\n";
		exit(1);			//exception
	}
//	cout<<"The last element in the list returned successfully\n";
	return container[this->index-1];
}

template <class T>
void listType<T>::clear()
{
	delete[] container;
	container = new T[size-index];
	size-=index;
	index=0;
//	cout<<"The list has been deleted and size now is "<<size<<"\n";
}

template <class T>
void listType<T>::add(T element)
{
	int i;
	if (index > maximum)
	{
	//	cerr<<"The list is too big! you cant afford it.\n";
		return;
	}
	
	if (this->size > index)
	{
		this->container[index] = element;
	}
	else
	{
		T* temp = new T[size];
		for (i=0; i<size; i++) temp[i] = container[i];
		delete[] container;
		size+=10;
		container = new T[size];
		for (i=0; i<(size-10); i++) container[i] = temp[i];
		this->container[index] = element;
	}

//	cout<<"The element added successfully to index "<<index<<endl;
	this->index++;
}

template <class T>
void listType<T>:: remove(int i)
{
	int j=0, flag=0;
	if (i>=index || i<0)
	{
//		cerr<<"This index is not exist in the list\n";
		return;
	}
	T* temp = new T[size];
	for (j=0; (j<size); j++)
	{
		if (j == i && flag==0)
		{
			j--;
			flag=1;
		}
		
		else 
		{
			if (flag ==1)
			{
				temp[j] = container[j+1];
				if (j==size-1) break;
			}
			else temp[j] = container[j];
		}
		
	}
	delete[] container;
	container = new T[size-1];
	for (j=0; j<size-1; j++) container[j]=temp[j];
	this->size--;
	if (index > 0) this->index--;
//	cout<<"The element in index "<<i<<" deleted successfully from the list.\n";
}


template <class T>
listType<T>& listType<T>::operator=(const listType<T>& list)
{
	if (this == &list) return *this;
	delete[] container;
	this->size = list.getCount();
	this->index = list.getIndex();
	this->container = new T[size];
	for (int i=0; i<size; i++) this->container[i] = list.container[i];
	return *this;
}

template <class T>
T& listType<T>::operator[](int i)
{
	if (i < 0 || i >= this->index)
	{
	//	cerr<<"The index is not exists!\n";
		exit(1);							//exception
	}
	return container[i];
}

template <class T>
T listType<T>::operator[](int i) const
{
	if (i < 0 || i >= this->index)
	{
	//	cerr<<"The index is not exists!\n";
		exit(1);							//exception
	}
	return container[i];
}

template <class T>
ostream& operator<<(ostream& os,const listType<T>& list)
{
	os<<"Size of the list: "<<list.getCount()<<"\tNext index to inseret an element: "<<list.getIndex()<<"\n";
	for (int i=0; i<list.getIndex(); ++i)
		os<<"["<<list[i]<<"], ";
	return os;
}

#endif
