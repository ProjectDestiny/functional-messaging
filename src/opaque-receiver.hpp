#ifndef OPAQUE_RECEIVER
#define OPAQUE_RECEIVER

// OpaqueReceiver is the base class of a Receiver only.
class OpaqueReceiver
{
public:
    OpaqueReceiver() {}
	virtual ~OpaqueReceiver() {}

private:
};

// OpaqueIntermetiateReceiver is the base class of InterMediateReceiverCreator
// only.
class OpaqueIntermetiateReceiver {
private:
	/* data */
public:
	OpaqueIntermetiateReceiver ();
	virtual ~OpaqueIntermetiateReceiver ();

};

#endif
