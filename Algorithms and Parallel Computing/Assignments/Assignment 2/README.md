✅ Why do we pass a null pointer to std::time()?

Because std::time() has two possible behaviors, depending on the pointer you give it.

Here is its real signature

std::time_t time(std::time_t* arg);

So the function works in two ways:

std::time_t t;
std::time(&t);



Then:

    The function writes the current time into t.

    And also returns it.

This is mostly kept for compatibility with old C-style code.


If you pass nullptr

Example: std::time_t now = std::time(nullptr);

Now the function does:

It does NOT write to any memory, because the pointer is null.

It simply returns the current time.

_____________________

Exactly — std::shared_ptr is a smart pointer.

________________________

🔹 Why use std::make_shared instead of new?

Old way:

std::shared_ptr<Workshop> workshop(new Workshop());

Problems with this:

Two allocations happen internally: one for the object, one for the control block.

More verbose and easy to make mistakes.

Exception safety: if something throws after new, you could leak memory.


Modern way:

auto workshop = std::make_shared<Workshop>();


Safer

More efficient

Cleaner syntax

std::make_shared is a C++ helper function that:

Creates a new object of some class (like Workshop)

Wraps it in a std::shared_ptr

Returns the shared_ptr

All in one line.

________________________________
Constructor parameter       Class member variable
-------------------        ---------------------
id = "E001"     --->       Event::id = "E001"
title = "Workshop" --->     Event::title = "Workshop"
organizer = "Alice" --->    Event::organizer = "Alice"


En el constructor tengo dos etapas, el paso de los parametros al consructor y la inicializaicion de los atributos en funcion de esos parametros

The constructor parameters don’t automatically set the attributes. You must explicitly initialize them (or assign them) in the initializer list or in the constructor body.

____________________________-
What happens during construction

When you construct a derived class object (Workshop) that inherits from an abstract class (Event):

Base class constructor runs first

The Event part of the object is initialized.

Even though Event is abstract, its constructor can run, and it can initialize members like id, title, etc.

Derived class constructor runs next

Workshop-specific members are initialized after the base class.

Workshop::Workshop(...) 
    : Event(id, title, organizer, date, duration, capacity),  // base class constructor
      topic(topic), difficulty_level(difficulty) {
}


Event(...) → initializes the base part (id, title, etc.)

Then Workshop(...) → initializes its own members (topic, difficulty_level)

_____________________________


TAREAS IMPORTANTES

Algo pasa con la cancelación. Revisar lo que ya hicmos prevismnete.
Que pasa si quierp ṕoner un curso para el cual ya estoy inscrito
PENDIENTE LA CANCELACION