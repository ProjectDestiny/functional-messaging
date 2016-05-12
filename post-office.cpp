#include "post-office.hpp"
#include "receiver.hpp"

Receiver* PostOffice::GetReceiverFor(const void * ptr) {
    auto it = clientReceivers.find(ptr);
	if(it == clientReceivers.end()) {
		Receiver * newReceiver = new Receiver;
        clientReceivers.insert(std::make_pair<const void*,Receiver*>(ptr,6.0));
	} else {
	    return nullptr;
	}
}
