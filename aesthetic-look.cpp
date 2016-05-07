#include <iostream>

// template <typename T>
// Receiver &get_receiver(T object) {
//   // how do we figure out if the object already has a receiver?
//   // if it's not receiver, create
//   return receiver;
// }
//
// template <typename T>
// Receiver &subscribe(T obj) {
//   auto receiver = get_receiver(object);
//   return receiver;
// }

Subscription subscribe(Receiver &receiver) {
  // create a new subscription object
  return newSubscription;
}

Subscription &Subscription::to(const char *message) {
  // add this subscription to the manager with the message specified if not
  // there already.

  return *this;
}

template <typename FuncType>
void Subscription::respondWith(FuncType processor) {
  // stores the
}

int main(void) {

	// subscribe to message titled messageName. Does not specify sender,
	// to object will receive messageName message from anyone.
	subscribe(object)
		.to("messageName")
		.respondWith([&object]() {
		  // do logic to handle receiving the message
		})
		.finalize();

	// subscribe to message titled messageName. Does not specify sender,
	// to object will receive messageName message from anyone.
	subscribe(object)
		.to("messageName")
		.from(senderObj)
		.respondWith([&object](){
		  // do logic to handle receiving the message
		})
		.finalize();


	// dispatches a message titled messageName. Sends it to whoever is
	// listening.
	dispatchMessage()
		.sender(object)
		.titled("messageName")
		.withPayload(... data params go here...)
		.finalize();

    // dispatches a message titled messageName. Sends it to whoever is
	// listening, but only those that pass whatever check functor
	// executes on the object will get to process the message.
	dispatchMessage()
		.sender(object)
		.titled("messageName")
		.withPayload(... data params go here...)
		.qualifier(functor)
		.finalize();

	return 0;
}
