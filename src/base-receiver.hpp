#ifndef BASE_RECEIVER_H
#define BASE_RECEIVER_H

#include <memory>
#include <type_traits>
#include <iostream>

class PostOffice;
class OpaqueReceiver;

class _SharedReceiverData
{
public:
	_SharedReceiverData();
    ~_SharedReceiverData() {};

	OpaqueReceiver * GetReceiver();

protected:
	PostOffice& GetManager();
	void SetGetReceiverFor(const void * ptr);

	template <typename T>
	class _ConstChecker
	{
	public:
	    void * operator()(T obj) {
			void* voidPtrVal = nullptr;
			std::cout << "consts: " << std::is_const<T>::value << std::endl;
			if(std::is_const<T>::value)
			{
				// If pointer is const, remove qualifier, then
				// interpret pointer as being void*
				voidPtrVal = static_cast<void*>(const_cast<T*>(&obj));
			}
			else
			{
				voidPtrVal = static_cast<void*>(&obj);
			}
			return voidPtrVal;
		}
	};

	template <typename T>
	class _ConstChecker<T *>
	{
	public:
	    void * operator()(T * obj) {
			void* voidPtrVal = nullptr;
			std::cout << "consts: " << std::is_const<T *>::value << std::endl;
			if(std::is_const<T*>::value)
			{
				// If pointer is const, remove qualifier, then
				// interpret pointer as being void*
				voidPtrVal = static_cast<void*>(const_cast<T*>(obj));
			}
			else
			{
				voidPtrVal = static_cast<void*>(obj);
			}
			return voidPtrVal;
		}
	};

    OpaqueReceiver* objectReceiver;
};

#endif
