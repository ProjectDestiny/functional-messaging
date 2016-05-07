#include <iostream>
#include <memory>

template <typename T>
Receiver &get_receiver(T object) {
  // how do we figure out if the object already has a receiver?
  // if it's not receiver, create
  

  return receiver;
}

template <typename T>
Receiver &subscribe(T obj) {
  auto receiver = get_receiver(object);
  return receiver;
}
