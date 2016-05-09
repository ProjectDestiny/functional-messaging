#include <iostream>
#include <memory>
#include "base-receiver.hpp"

template <typename T>
class _ReceiverIdentifier : public _SharedReceiverData
{
public:
	_ReceiverIdentifier(T obj) :
	   _SharedReceiverData(),
	   checker()
	{
		std::cout << "non-pointer" << std::endl;
		void * ptr = checker(obj);
        SetGetReceiverFor(ptr);
	}
private:
	_Checker<T> checker;
};

template<typename T>
class _ReceiverIdentifier<T *> : public _SharedReceiverData
{
public:
	_ReceiverIdentifier(T * obj) :
	   _SharedReceiverData(),
	   checker()
	{
		std::cout << "pointer" << std::endl;
		void * ptr = checker(obj);
		SetGetReceiverFor(ptr);
	}
private:
	_Checker<T *> checker;
};

template <typename T>
Receiver *get_receiver(T object) {
    // how do we figure out if the object already has a receiver?
    // if it's not receiver, create
    _ReceiverIdentifier<T> identifier(object);
    return identifier.GetReceiver();
}

// template <typename T>
// Receiver &subscribe(T obj) {
//     auto receiver = get_receiver(object);
//     return receiver;
// }

//=============================================================================
