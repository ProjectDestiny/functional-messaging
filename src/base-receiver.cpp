#include "base-receiver.hpp"
#include "post-office.hpp"
#include "receiver.hpp"

_SharedReceiverData::_SharedReceiverData() {

}

OpaqueReceiver* _SharedReceiverData::GetReceiver() {
	std::cout << objectReceiver << std::endl;
	return objectReceiver;
}

bool _SharedReceiverData::CanGetReceiverFor(const void * ptr) {
	return GetPostOffice().GetReceiverFor(ptr) != nullptr;
}

void _SharedReceiverData::SetNewReceiverFor(const void * ptr, OpaqueReceiver * receiver) {
	GetPostOffice().SetReceiverFor(ptr, receiver);
}

void _SharedReceiverData::SetReceiverFor(const void * ptr) {
	objectReceiver = GetPostOffice().GetReceiverFor(ptr);
}

PostOffice& _SharedReceiverData::GetPostOffice() {
	static PostOffice* mngr = nullptr;
	if(mngr == nullptr) {
		mngr = new PostOffice();
	}
	return *mngr;
}
