/*
	Note: DO NOT INCLUDE THIS FILE IN THE BUILD PROCESS! THIS IS A
	TEMPLATE FILE IMPLEMENTATION. IT IS TO ONLY BE INCLUDED IN
	receiver.hpp
*/

#include <type_traits>
#include "base-receiver.hpp"

// PlainTypeViewer strips T from all qualifiers, even pointers.
// If T is already a type with no qualifiers, then it stays the same.
template <typename T>
struct PlainTypeViewer {
	typedef typename std::decay<T>::type value;
};

template <typename T>
struct PlainTypeViewer<T*>{
	typedef typename std::remove_pointer<T>::type T1;
	typedef typename std::decay<T1>::type value;
};

//==============================================================================

// _ObjectReceiverFetcher is a helper class that fetches the receiver for
// for an object of type T. It makes sure to also create the appropiate one for
// an instance with no receiver yet, and it creates the template receiver by
// removing all qualifier from type T.
template <typename T, typename PlainType>
class _ObjectReceiverFetcher : public _SharedReceiverData
{
public:
	_ObjectReceiverFetcher(T & obj) :
	   _SharedReceiverData(),
	   verifier()
	{
		void * ptr = verifier(obj);
		if(!CanGetReceiverFor(ptr)){
			CreateNewReceiver(ptr);
		} else {
			SetReceiverFor(ptr);
		}
	}
private:

	void CreateNewReceiver(const void * ptr) {
		auto newReceiver = new Receiver<PlainType>;
		SetNewReceiverFor(ptr,newReceiver);
		objectReceiver = newReceiver;
		//clientReceivers.insert(std::make_pair<const void*,OpaqueReceiver* >(ptr,newReceiver));
	}

	_ConstCaster<T> verifier;
};

template <typename T, typename PlainType>
class _ObjectReceiverFetcher<T*, PlainType> : public _SharedReceiverData
{
public:
	_ObjectReceiverFetcher(T * obj) :
	   _SharedReceiverData(),
	   verifier()
	{
		void * ptr = verifier(obj);
		if(!CanGetReceiverFor(ptr)){
			CreateNewReceiver(ptr);
		} else {
			SetReceiverFor(ptr);
		}
	}
private:

	void CreateNewReceiver(const void * ptr) {
		auto newReceiver = new Receiver<PlainType>;
		SetNewReceiverFor(ptr,newReceiver);
		objectReceiver = newReceiver;
		//clientReceivers.insert(std::make_pair<const void*,OpaqueReceiver* >(ptr,newReceiver));
	}

	_ConstCaster<T*> verifier;
};

template <typename T, typename PlainType>
class _ObjectReceiverFetcher<T const, PlainType> : public _SharedReceiverData
{
public:
	_ObjectReceiverFetcher(T const & obj) :
	   _SharedReceiverData(),
	   verifier()
	{
		void const * ptr = verifier(obj);
		if(!CanGetReceiverFor(ptr)){
			CreateNewReceiver(ptr);
		} else {
			SetReceiverFor(ptr);
		}
	}
private:

	void CreateNewReceiver(const void * ptr) {
		auto newReceiver = new Receiver<PlainType>;
		SetNewReceiverFor(ptr,newReceiver);
		objectReceiver = newReceiver;
		//clientReceivers.insert(std::make_pair<const void*,OpaqueReceiver* >(ptr,newReceiver));
	}

	_ConstCaster<T const> verifier;
};

//==============================================================================

// NullPointerChecker is a type of is_pointer class that determines if a pointer
// null or not.
template <typename T>
struct NullPointerChecker {
	bool isNull(T & obj) {
		return false;
	}
};

template <typename T>
struct NullPointerChecker<T*> {
	bool isNull(T * obj) {
		return obj == nullptr;
	}
};


template<typename T>
OpaqueReceiver *get_receiver(T & obj) {
	// Remove all top level qualifiers, even if it is a pointer.
	typedef typename PlainTypeViewer<T>::value RealType;

	_ObjectReceiverFetcher<T, RealType> ownerChecker(obj);
	return ownerChecker.GetReceiver();
}

template<typename T>
OpaqueReceiver *get_receiver(T const & obj) {
	typedef typename PlainTypeViewer<T const>::value RealType;
	std::cout << "using get_receiver for const objects" << std::endl;

	_ObjectReceiverFetcher<T const, RealType> ownerChecker(obj);
	return ownerChecker.GetReceiver();;
}

template<typename T>
OpaqueReceiver *get_receiver(T * obj) {
	std::cout << "using get_receiver for pointers" << std::endl;
	typedef typename PlainTypeViewer<T*>::value RealType;

	// Remove all top level qualifiers, even if it is a pointer.
	if(NullPointerChecker<T*>().isNull(obj)) {
		return nullptr;
	}

	_ObjectReceiverFetcher<T*, RealType> ownerChecker(obj);
	return ownerChecker.GetReceiver();;
}

//==============================================================================

template <typename T>
InterMediateReceiverCreator<T> &subscribe(T obj) {
	typedef typename PlainTypeViewer<T>::value RealType;

    auto receiver = dynamic_cast<Receiver<RealType>*>(get_receiver(obj));

	InterMediateReceiverCreator<RealType> interim;
    return interim;
}

template <typename T>
InterMediateReceiverCreator<T> &subscribe(T * obj) {
	typedef typename PlainTypeViewer<T>::value RealType;

    auto receiver = dynamic_cast<Receiver<RealType>*>(get_receiver(obj));

	InterMediateReceiverCreator<RealType> interim;
    return interim;
}

template <typename T>
InterMediateReceiverCreator<T> &subscribe(std::shared_ptr<T> obj) {
	typedef typename PlainTypeViewer<T>::value RealType;

    auto receiver = dynamic_cast<Receiver<RealType>*>(get_receiver(obj));

	InterMediateReceiverCreator<RealType> interim;
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
