#include <iostream>
#include <memory>
#include "base-receiver.hpp"

template <typename T>
class _ReceiverIdentifier : public _SharedReceiverData
{
public:
	_ReceiverIdentifier(T obj) :
	   _SharedReceiverData(),
	   verifier()
	{
		std::cout << "non-pointer" << std::endl;
		void * ptr = verifier(obj);
        SetGetReceiverFor(ptr);
	}
private:
	_ConstChecker<T> verifier;
};

template<typename T>
class _ReceiverIdentifier<T *> : public _SharedReceiverData
{
public:
	_ReceiverIdentifier(T * obj) :
	   _SharedReceiverData(),
	   verifier()
	{
		std::cout << "pointer" << std::endl;
		void * ptr = verifier(obj);
		SetGetReceiverFor(ptr);
	}
private:
	_ConstChecker<T *> verifier;
};

template<typename T>
class _ReceiverIdentifier<const T *> : public _SharedReceiverData
{
public:
	_ReceiverIdentifier(const T * obj) :
	   _SharedReceiverData(),
	   verifier()
	{
		std::cout << "const-val pointer" << std::endl;
		const void * ptr = verifier(obj);
		SetGetReceiverFor(ptr);
	}
private:
	_ConstChecker<const T *> verifier;
};

//==============================================================================

template <typename T>
Receiver *get_receiver(T object) {
    // how do we figure out if the object already has a receiver?
    // if it's not receiver, create
    _ReceiverIdentifier<T> identifier(object);
	// std::cout << typeid(object).name() << std::endl;
    return identifier.GetReceiver();
}

template <typename T>
Receiver &subscribe(T obj) {
    auto receiver = get_receiver(obj);
    return receiver;
}

//=============================================================================
