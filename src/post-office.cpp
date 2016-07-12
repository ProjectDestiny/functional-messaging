#include <utility>
#include "post-office.hpp"
#include "receiver.hpp"

OpaqueReceiver* PostOffice::GetReceiverFor(const void * ptr) {
    auto it = clientReceivers.find(ptr);
	if(it == clientReceivers.end()) {
		return nullptr;
	}

	return it->second;
}

OpaqueReceiver* PostOffice::SetReceiverFor(const void* ptr, OpaqueReceiver* receiver) {
	//clientReceivers.insert(std::make_pair<const void*,OpaqueReceiver* >(ptr,newReceiver));
	return nullptr;
}
