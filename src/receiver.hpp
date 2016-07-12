#ifndef RECEIVER_H
#define RECEIVER_H

#include <unordered_map>
#include <vector>
#include <memory>
#include <iostream>
#include "opaque-receiver.hpp"

class Response;

// Receiver is a class that holds all responses for all events an object is to
// react to.
template <typename OwnerType>
class Receiver : public OpaqueReceiver
{
public:
	Receiver() : OpaqueReceiver() {}
    virtual ~Receiver() {}

	typedef OwnerType ReceiverOwnerType;
	typedef std::shared_ptr<OwnerType> ReceiverOwnerPtrType;

private:
	ReceiverOwnerPtrType owner;

	// A response object has key-vector pairing, where key is a message name.
	// From there, we will grab the correct response for the sender of the message.
	// If the message has no sender, then we will look for a response to the message
	// that comes from the global scope.
    std::unordered_map<std::string, std::vector< std::shared_ptr<Response>>> messageResponses;
};

// InterMediateReceiverCreator is a class that holds a receiver while a new
// response object is being added to it.
template<typename ReceiverOwnerType>
class InterMediateReceiverCreator
{
public:
    typedef std::shared_ptr<Receiver<ReceiverOwnerType> > ReceiverPtrType;

private:
    ReceiverPtrType receiver;

    // The response object that we are building
	Response* newReceiverResponse;
public:
	InterMediateReceiverCreator (ReceiverPtrType r) {}
	virtual ~InterMediateReceiverCreator () {}

	template <typename FunctionType>
	InterMediateReceiverCreator &respondWith(FunctionType func);

	InterMediateReceiverCreator &to(std::string msgName);

    template <typename SenderType>
	InterMediateReceiverCreator &from(std::shared_ptr<SenderType> sender);

	void finalize();
};

template <typename T>
OpaqueReceiver *get_receiver(T & obj);

template <typename T>
InterMediateReceiverCreator<T> &subscribe(T obj);

template <typename T>
InterMediateReceiverCreator<T> &subscribe(T * obj);

template <typename T>
InterMediateReceiverCreator<T> &subscribe(std::shared_ptr<T> obj);

#include "receiver.cpp"

#endif
