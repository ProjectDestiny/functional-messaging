#ifndef RECEIVER_H
#define RECEIVER_H



class Receiver;

template <typename T> Receiver *get_receiver(T obj);

// template <typename T> Receiver &subscribe(T obj);

#include "receiver.cpp"

#endif
