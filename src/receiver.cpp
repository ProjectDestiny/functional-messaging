#include <iostream>
#include <memory>
#include <type_traits>
#include "base-receiver.hpp"

template <typename T>
class _ObjectReceiverFetcher : public _SharedReceiverData
{
public:
	_ObjectReceiverFetcher(T & obj) :
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

//==============================================================================

template<typename T>
Receiver<T> *get_receiver(T & obj) {
	// how do we figure out if the object already has a receiver?
	// if it's not receiver, create
	_ObjectReceiverFetcher<T> ownerChecker(obj);

	// std::cout << typeid(object).name() << std::endl;
	OpaqueReceiver* base = ownerChecker.GetReceiver();
	Receiver<T>* receiver = dynamic_cast<Receiver<T>*>(base);

	return receiver;
}

//==============================================================================

template <typename T>
InterMediateReceiverCreator<T> &subscribe(T obj) {
	typedef typename std::remove_pointer<T>::type T1;
	typedef typename std::decay<T1>::type T2;

    Receiver<T2> receiver = get_receiver(obj);

	InterMediateReceiverCreator<T> interim;
    return interim;
}

template <typename T>
InterMediateReceiverCreator<T> &subscribe(T * obj) {
	typedef typename std::remove_pointer<T>::type T1;
	typedef typename std::decay<T1>::type T2;

    Receiver<T2> receiver = get_receiver(obj);

	InterMediateReceiverCreator<T> interim;
    return interim;
}

template <typename T>
InterMediateReceiverCreator<T> &subscribe(std::shared_ptr<T> obj) {
    typedef typename std::remove_pointer<T>::type T1;
	typedef typename std::decay<T1>::type T2;

    Receiver<T2> receiver = get_receiver(*obj);

	InterMediateReceiverCreator<T> interim;
    return interim;
}


//=============================================================================

template <typename ReceiverOwnerType>
template <typename FunctionType>
InterMediateReceiverCreator<ReceiverOwnerType> & InterMediateReceiverCreator<ReceiverOwnerType>::respondWith(FunctionType func) {
    return InterMediateReceiverCreator<ReceiverOwnerType>();
}

template <typename ReceiverOwnerType>
InterMediateReceiverCreator<ReceiverOwnerType> & InterMediateReceiverCreator<ReceiverOwnerType>::to(std::string msgName) {
    return InterMediateReceiverCreator<ReceiverOwnerType>();
}

template <typename ReceiverOwnerType>
template <typename SenderType>
InterMediateReceiverCreator<ReceiverOwnerType> & InterMediateReceiverCreator<ReceiverOwnerType>::from(std::shared_ptr<SenderType> sender) {
	return InterMediateReceiverCreator<ReceiverOwnerType>();
}
