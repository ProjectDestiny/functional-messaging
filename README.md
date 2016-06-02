functional-messaging
====================

A messaging system in c++ that takes inpiration from javascript's functional approach.

# Design Pillars

I want to make it a habit of writing software for which I have clear design
pillars. These are goals that describe why this project is important not just
for me but for others looking inspiration. If you are looking to make a project
similar to this one, I'd would love to have a talk if your project is also
designed around the following three(3) pillars.

## Remove Clutter

Previous versions of c++ led programmers of such systems like these to
force users to define the event handling methods in the class's definition.
With the ability to mimic javascript lambdas, we can remove the need to define
those methods in the class definition and leave them solely in the implementation.
When have you used those methods directly?

## Flexible

No matter how you define your event bindings or send messages, the
end result should be the same. What does this mean? The interface
makes use <insert_pattern_name_here>, which allows for chaining
statements of functions in any order. My hope is that with this interface,
the standard for how to define message reception and sending is defined by
the organization.

## Educational

It's been long since I've written C++, and, more specifically, generic code.
With the speed the standard has been changing the last few years, it is sometimes
hard to keep up, specially if your day job does not require you to write C++.
My hope is that those looking for examples on how to use the new C++ standard
tools to write generic code can satisfy their curiosity here. And as the ever
knowledge seeker I am, I hope for others to correct me and tell me how I could
have done better. 

# Notes

There are instances where it seems that the const-ness of certain variables
is removed, mainly in tests 1-4. I need to look for understanding around this.
