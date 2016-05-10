#include "base-receiver.hpp"
#include "post-office.hpp"

_SharedReceiverData::_SharedReceiverData() {

}

Receiver* _SharedReceiverData::GetReceiver() {
	return objectReceiver;
}

void _SharedReceiverData::SetGetReceiverFor(const void * ptr) {
	objectReceiver = GetManager().GetReceiverFor(ptr);
}

PostOffice& _SharedReceiverData::GetManager() {
	static PostOffice* mngr = nullptr;
	if(mngr == nullptr) {
		mngr = new PostOffice();
	}
	return *mngr;
}
