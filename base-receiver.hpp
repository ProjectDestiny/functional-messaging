#ifndef BASE_RECEIVER_H
#define BASE_RECEIVER_H

#include <memory>
#include <type_traits>
#include <iostream>

class PostOffice;
class Receiver;

class _SharedReceiverData
{
public:
	_SharedReceiverData();
    ~_SharedReceiverData() {};

	Receiver * GetReceiver();

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

	template <typename T>
	class _ConstChecker<const T *>
	{
	public:
		const void * operator()(const T * obj) {
			const void* voidPtrVal = nullptr;
			std::cout << "consts: " << std::is_const<const T*>::value << std::endl;
			if(std::is_const<const T*>::value)
			{
				// If pointer is const, remove qualifier, then
				// interpret pointer as being void*
				voidPtrVal = static_cast<const void*>(const_cast<const T*>(obj));
			}
			else
			{
				voidPtrVal = static_cast<const void*>(obj);
			}
			return voidPtrVal;
		}
	};

    Receiver* objectReceiver;
};

#endif
