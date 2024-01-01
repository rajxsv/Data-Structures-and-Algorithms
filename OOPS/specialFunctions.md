# SPECIAL FUNCTIONS

***

- **Some special functions that c++ gives us when an object is created.**
- 4 different special functions are always present inside a class.

***

## Constructor

- responsible for `creating` the object.
- gets called _automatically_ and only once for a single object.
- in order to override the function, you need to write a function that has _same name as the class_
- has no return type
- for every object only _one_ of the constructor (parameterised or normal) will be called.
- there can be different constructors made for a single class.
- when there are different functions of the same name, it is called _function overloading_, in this particular case the function is a constructor, so it is called **constructor overloading**.
- **advantage:** intialize the object with values using the constructor

---

## Copy Constructor

- make a `copy` of the given object
- exists by default
- parameter must be passed by **reference** because:
	+ at this moment we are writing _our own_ copy constructor
	+ so there is no way for the compiler to make a copy of the object that is passed by value because the default constructor is being over-written
	+ hence we need to pass the object by reference.
- **Need to define your own copy constructor:**
	+ the default constructor makes a _shallow_ copy, so to make a _deep_ copy, you need to define your own copy constructor
	+ `Deep Copy` is needed when your class has some pointer to dynamically allocated memory (ex: array).
		- when a _shallow_ copy is created, the address of the dynamic array is also copied.
		- so the new object's data member will also point to the same address.
		- hence whenever a change will be made to that data member, it will reflect in every object that was _shallow_ copied.

---

## Copy Assignment Operator

- _copies_ the object when you do `assignment`;
- **example:**
	+ car d = c; here _copy constructor_ is called
	+ car d; d = c; here _copy assignment operator_ is called
- here also the concepts of _shallow_ and _deep_ copy exist. so if any pointers to dynamically allocated memory are present, then you need to define your own copy assignment operator in order to create a deep copy.
- defined by using `operator` keyword followed by the symbol i. e. `=` in this case.

---

> **NOTE:** copy constructor can only be called once but copy assignment operator can be called any number of times

---

## Destructor

- goal is to `clear` the occupied memory
- gets called automatically when the object _goes out of scope_
- **Need to define your own destructor**
	+ when you have _dynamically allocated_ memory inside the class
- object that was made at the `last` is destroyed `first`.

---
