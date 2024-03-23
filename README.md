# C++ Modules Documentation

## Module 00: Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff

### Namespaces
- Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when using libraries.
- Namespaces are defined using the `namespace` keyword followed by the namespace name:
```
namespace my_namespace {
    // code here
}
```
- Namespaces can be nested:
```
namespace outer_namespace {
    namespace inner_namespace {
        // code here
    }
}
```

### Classes
- Classes are user-defined data types that can contain data members and member functions.
- Classes are defined using the `class` keyword followed by the class name:
```
class MyClass {
    // code here
}
```
- Classes can have access specifiers:
    - `public`: members are accessible from outside the class
    - `private`: members are only accessible from within the class
    - `protected`: members are accessible from within the class and derived classes
- Classes can have constructors and destructors:
    - Constructors are special member functions that are called when an object is created.
    - Destructors are special member functions that are called when an object is destroyed.
- Classes can have member functions:
    - Member functions are functions that are defined within the class.
    - Member functions can access the data members of the class.
- Classes can have static members:
    - Static members are shared by all objects of the class.
    - Static members can be accessed using the class name.
- The Syntax for defining a class is:
```
class MyClass 
{
    public:
        // public members
    private:
        // private members
    protected:
        // protected members
}
```

### Member Functions

- Member functions are functions that are defined within a class.
- Member functions can access the data members of the class, getters and setters are examples of member functions.
- Member functions can be defined inside the class definition or outside the class definition.

The syntax for defining a member function inside the class definition is:
```
class MyClass 
{
    public:
        void myFunction() {
            // code here
        }
}
```

In case the member function is defined outside the class definition, the syntax is:
```
class MyClass 
{
    public:
        void myFunction();
}

void MyClass::myFunction() {
    // code here
}
```

### stdio Streams

#### Streams in C++

- Streams are sequences of bytes that represent input and output sources.
- Streams are used to read data from and write data to files, the console, and other sources.
- For analogies, think of streams as pipes that carry data from one place to another.
- Streams are objects of the `iostream` class.

### stdio

- `stdio` stands for standard input-output.
- `stdio` is a library in C++ that provides functions for reading and writing data to and from files, the console, and other sources.
- std::cin and std::cout are examples of `stdio` streams.
    - std::cin is used to read data from the console.
    - std::cout is used to write data to the console.

### Initialization Lists

- Initialization lists are used to initialize data members of a class.
- Initialization lists are used in the constructor of a class. (Think about the constructor as a function that is called when an object is created, We will discuss constructors in detail in later modules).
- These lists are commonly used to initialize const data members and reference data members, that cannot be initialized later on in the constructor body or anywhere else.

The syntax for using initialization lists is:
```
class MyClass 
{
    public:
        MyClass(const int x, const int y) : x(x), y(y) {
            // code here
        }
}
```

### Static

- Static members are shared by all objects of the class.
- Static members can be accessed using the class name.
- We don't need to create an object of the class to access static members.

### Const

- Const is a keyword in C++ that is used to declare constants.
- Const variables cannot be modified after they are initialized.
- Const member functions are functions that do not modify the data members of the class.

## Module 01: Memory allocation, pointers to members, references, switch statements

### Memory Allocation

- Memory allocation is the process of reserving memory for variables and objects.
- Memory allocation can be done in two ways:
    - Stack allocation: memory is allocated on the stack.
    - Heap allocation: memory is allocated on the heap.

#### Stack Allocation

- Stack allocation is done automatically by the compiler without the need for the programmer to explicitly allocate or deallocate memory.
- Stack allocation is faster than heap allocation.

#### Heap Allocation

- Heap allocation is done explicitly by the programmer using the `new` keyword or `malloc` functions (To respect the rules of our modules, we will use the `new` keyword).
- Heap allocation is slower than stack allocation.
- Memory allocated on the heap must be deallocated using the `delete` keyword.

### Pointers to Members

- Pointers to members are pointers that point to members of a class.
- Pointers to members can be used to access the members of a class using the pointer.

The syntax for declaring a pointer to a member is:
```
class MyClass 
{
    public:
        int x;
}

int MyClass::*ptr = &MyClass::x;
```

The syntax for delcaring a pointer to a member function is:
```
class MyClass 
{
    public:
        void myFunction() 
        {
            // code here
        }
}

void (MyClass::*ptr)() = &MyClass::myFunction;
```

### References

- References are aliases for variables.
- References are used to pass arguments to functions by reference.
- References are declared using the `&` symbol.
```
int x = 10;
// To declare a reference to x, we use the & symbol as follows:
int &y = x;
```
- References can never be null.
- References cannot be reseated or uninitialized.

### Switch Statements

- Switch statements are used to select one of many code blocks to be executed.
- They are a substitute for long if-else chains.

- The syntax for a switch statement is:
```
switch (expression) 
{
    case value1:
        // code here
        break;
    case value2:
        // code here
        break;
    default:
        // code here
}
```
- This code is equivalent to:
```
if (expression == value1) 
{
    // code here
} else if (expression == value2) 
{
    // code here
} else {
    // code here
}
```

## Module 02: Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

### Ad-hoc Polymorphism

#### What is Polymorphism in the first place?

- Polymorphism is the ability of a function to behave differently depending on the arguments passed to it.
- Polymorphism is a key concept in object-oriented programming.
- For Analogy's sake, think of polymorphism as a person who can take on different roles depending on the situation.
- In C++, Polymorphism of function can be achieved by declaring multiple functions with the same name but different parameters.
- This is known as function overloading.

```
class MyClass 
{
    public:
        void myFunction(int x) 
        {
            // code here
        }
        void myFunction(int x, int y) 
        {
            // code here
        }
    // The myFunction function is overloaded because it has two definitions with different parameters.
    // The compiler will choose the appropriate function based on the arguments passed to it.
}

```

#### Ad-hoc Meaning

- Ad-hoc means "for this purpose only".
- Ad-hoc polymorphism is a type of polymorphism in which a function can behave differently depending on the arguments passed to it.
- Ad-hoc polymorphism is achieved by function overloading and operator overloading.

### Operator Overloading

- Operator overloading is a type of ad-hoc polymorphism in which operators are overloaded to work with user-defined data types.
- Operator overloading allows us to define the behavior of operators for user-defined data types.
- Operator overloading is achieved by defining a function that is called when an operator is used with a user-defined data type.

The syntax for operator overloading is:
```
class MyClass 
{
    public:
        MyClass &operator+(const MyClass &obj) 
        {
            MyClass result;
            result.x = this->x + obj.x;
            result.y = this->y + obj.y;
            return result;
        }
    
    // This is an example of operator overloading for the + operator.
    // The function is called when the + operator is used with two objects of the MyClass class.
    // The same syntax can be used for other operators such as -, *, /, etc.
}
```

### Orthodox Canonical Class Form

- The Orthodox Canonical Class Form is a set of rules that define how a class should be implemented in C++.
- The Orthodox Canonical Class Form consists of four parts:
    - The default constructor
    - The copy constructor
    - The copy assignment operator
    - The destructor

#### The Default Constructor

- The default constructor is a constructor that is called when an object is created without any arguments.
- The default constructor is used to initialize the data members of the class.

The syntax for defining a default constructor is:
```
class MyClass 
{
    public:
        MyClass() 
        {
            // code here
        }
}
```

- The default constructor does not take any arguments and does not have a return type.
- The default constructor can be overloaded to accept arguments.

In case of defining a default constructor outside the class definition, the syntax is:
```
class MyClass 
{
    public:
        MyClass();
}

MyClass::MyClass() 
{
    // code here
}
```

#### The Copy Constructor

- The copy constructor is a constructor that is called when an object is created as a copy of another object.
- The copy constructor is used to initialize an object with the values of another object.
- The copy constructor is called when an object is passed by value to a function, returned by value from a function, or when an object is created as a copy of another object.

The syntax for defining a copy constructor is:
```
class MyClass 
{
    public:
        MyClass(const MyClass &obj) 
        {
            // code here
        }
}
```

- Like the default constructor, the copy constructor does not have a return type and can be overloaded to accept arguments and its syntax if defined outside the class definition is:
```
class MyClass 
{
    public:
        MyClass(const MyClass &obj);
}

MyClass::MyClass(const MyClass &obj) 
{
    // code here
}
```

#### The Copy Assignment Operator

- The copy assignment operator is an operator that is called when an object is assigned the value of another object.
- The copy assignment operator is used to assign the values of one object to another object.
- The copy assignment operator is called when an object is assigned the value of another object using the `=` operator.
- The difference between the copy constructor and the copy assignment operator is that the copy constructor is called when an object is created as a copy of another object, while the copy assignment operator is called when an object is assigned the value of another object. Otherwise, they are very similar.

The syntax for defining a copy assignment operator is:
```
class MyClass 
{
    public:
        MyClass &operator=(const MyClass &obj) 
            {
                // code here
                return *this;
            }
}
```

- The copy assignment operator returns a reference to the object that is being assigned the value.
- The copy assignment operator can be overloaded to accept arguments and its syntax if defined outside the class definition is:
```
class MyClass 
{
    public:
        MyClass &operator=(const MyClass &obj);
}

MyClass &MyClass::operator=(const MyClass &obj) 
{
    // code here
    return *this;
}
```

#### The Destructor

- The destructor is a special member function that is called when an object is destroyed.
- The destructor is used to release resources that were allocated by the object.
- The destructor is called when an object goes out of scope, is deleted, or when the program terminates.

The syntax for defining a destructor is:
```
class MyClass 
{
    public:
        ~MyClass() 
        {
            // code here
        }
}
```

- The destructor does not take any arguments and does not have a return type.

In case of defining a destructor outside the class definition, the syntax is:
```
class MyClass 
{
    public:
        ~MyClass();
}

MyClass::~MyClass() 
{
    // code here
}
```

#### Summary

- The Orthodox Canonical Class Form is a set of rules that define how a class should be implemented in C++.

An orthodox class should be implemented as follows:
```
class MyClass 
{
    private:
        int x;
        int y;
    public:
        MyClass(); // default constructor
        MyClass(const MyClass &obj); // copy constructor
        MyClass &operator=(const MyClass &obj); // copy assignment operator
        ~MyClass(); // destructor
}

MyClass::MyClass() 
{

}

MyClass::MyClass(const MyClass &obj) 
{
    this->x = obj.x;
    this->y = obj.y;
}

MyClass &MyClass::operator=(const MyClass &obj) 
{
    this->x = obj.x;
    this->y = obj.y;
    return *this;
}

MyClass::~MyClass() 
{

}
```

## Module 03: Inheritance 

### Inheritance

- Inheritance is a key concept in object-oriented programming, It allows us to create a new class that is based on an existing one.
- The new class inherits the properties and behaviors of the existing class.
- The existing class is called the parent class or base class.
- The new class is called the child class or derived class.

Example:
```

// We will attempt to create a class named Phone
// The Phone class will have a Name, Model, and Price data members
// The Phone class will also have Call and Text member functions

// This class is going to serve as the base class (parent class)

class Phone
{
    private:
        std::string Name;
        std::string Model;
        int Price;
    public:
        void Call();
        void Text();       
}

// Now, we will create two classes that will inherit from the Phone class
// The first class is the iPhone class
// The iPhone class will inherit the properties and behaviors of the Phone class

class iPhone : public Phone
{

}

// The second class is the Samsung class

class Samsung : public Phone
{

}

```

- As we can see from the example above, the syntax for inheriting from a class is:
```
class DerivedClass : accessSpecifier BaseClass
{
    // code here
}
```

- The access specifier can be `public`, `protected`, or `private`.

### Access Specifiers

- Access specifiers are used to control the access to the members of a class.

#### Public Access Specifier

- Members that are declared as public are accessible from outside the class.
- Public members can be accessed by objects of the class and by derived classes.

#### Protected Access Specifier

- Members that are declared as protected are accessible from within the class and by derived classes.
- Protected members are not accessible from outside the class.

#### Private Access Specifier

- Members that are declared as private are only accessible from within the class.
- Private members are not accessible from outside the class or by derived classes.

### Access specifiers in Inheritance

- The access specifier in the inheritance declaration specifies the access level of the base class members in the derived class.
- If the access specifier is `public`, the base class members are inherited as public members in the derived class.
- If the access specifier is `protected`, the base class members are inherited as protected members in the derived class, which means they are not accessible from outside the class but are accessible from within the class and by derived classes.
- If the access specifier is `private`, the base class members are inherited as private members in the derived class, which means they are not accessible from outside the class or by derived classes.

To visualize this better, let's consider the following example:
```
class Base {
public:
    int publicMember;
protected:
    int protectedMember;
private:
    int privateMember;
};

class Derived_Public : public Base {
    // publicMember is accessible
    // protectedMember is accessible
    // privateMember is not accessible
};

class Derived_Protected : protected Base {
    // publicMember becomes protected
    // protectedMember becomes protected
    // privateMember is not accessible
};

class Derived_Private : private Base {
    // publicMember becomes private
    // protectedMember becomes private
    // privateMember is not accessible
};
```

### Types of Inheritance

#### Single Inheritance

- Single inheritance is a type of inheritance in which a class inherits from only one base class.
- Single inheritance is the most common type of inheritance.

#### Multiple Inheritance

- Multiple inheritance is a type of inheritance in which a class inherits from more than one base class.
- The syntax for multiple inheritance is:
```
class Derived : public Base1, public Base2
{
    // code here
}
```

#### Multilevel Inheritance

- Multilevel inheritance is a type of inheritance in which a class inherits from a base class, and the derived class is used as a base class for another class.

Example:
```
class Base {
    // code here
};

class Derived1 : public Base {
    // code here
};

class Derived2 : public Derived1 {
    // code here
}
```

#### Hierarchical Inheritance

- Hierarchical inheritance is a type of inheritance in which more than one derived class inherits from a single base class.

Example:
```
class Base {
    // code here
};

class Derived1 : public Base {
    // code here
};

class Derived2 : public Base {
    // code here
}
```

### Why use Inheritance?

- Inheritance allows us to reuse code, which reduces code duplication and makes the code easier to maintain. It also allows us to keep our code organized and modular. It can also help us achieve polymorphism, where objects of different classes can be treated as objects of the same base class.

## Module 04: Subtype polymorphism, abstract classes, interfaces

### Subtype Polymorphism

- Subtype polymorphism is a type of polymorphism in which objects of different classes can be treated as objects of the same base class.
- Subtype polymorphism allows us to write code that is more flexible and reusable.

Example:
```
class Animal {
    public:
        virtual void makeSound() = 0;
};

class Dog : public Animal {
    public:
        void makeSound() {
            std::cout << "Woof!" << std::endl;
        }
};

class Cat : public Animal {
    public:
        void makeSound() {
            std::cout << "Meow!" << std::endl;
        }
};
```

- In the example above, the `Animal` class is an abstract class that has a pure virtual function `makeSound()`.
- The `Dog` and `Cat` classes are derived from the `Animal` class and implement the `makeSound()` function.
- The `makeSound()` function is a virtual function that is overridden by the `Dog` and `Cat` classes.

### Abstract Classes

- An abstract class is a class that is designed and intended to be used as a base class. This last is not meant to be instantiated.
- Abstract means that it's not complete and missing functionality that needs to be implemented by derived classes.
- Abstract classes can have pure virtual functions, which are functions that have no implementation and must be overridden by derived classes.

#### Virtual Keyword

- The `virtual` keyword is used to declare a member function as virtual.
- Virtual functions are functions that can be overridden by derived classes.
- Virtual functions are used to achieve polymorphism.

#### Pure Virtual Functions

- A pure virtual function is a virtual function that has no implementation.
- Pure virtual functions are declared using the `= 0` syntax.
```
class Animal {
    public:
        virtual void makeSound() = 0;
};
```

- A class that contains at least one pure virtual function is called an abstract class, which means that it cannot be instantiated. And the compiler will throw an error if we try to do so.

### Interfaces

- An interface is a class that contains only pure virtual functions.
- An interface is used to define a contract for classes that implement it.
- Interfaces are used to achieve polymorphism and code reusability.

Example:
```
class Device {
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
};
 
class Phone : public Device {
    public:
        void turnOn() {
            std::cout << "Phone is turning on" << std::endl;
        }
        void turnOff() {
            std::cout << "Phone is turning off" << std::endl;
        }
};

class TV : public Device {
    public:
        void turnOn() {
            std::cout << "TV is turning on" << std::endl;
        }
        void turnOff() {
            std::cout << "TV is turning off" << std::endl;
        }
};
```

## Module 05: Exceptions

### Exceptions 

- Exceptions are a new way of handling errors and exceptional conditions in C++, it allows us to seperate error handling code from the normal code. Moreover, it allows us to write cleaner and more maintainable code.
- Exceptions are thrown when an error occurs and are caught by an exception handler.

The syntax for doing so is:
```
try 
{
    // code that may throw an exception
    throw 10; // throw an exception
}
catch (int e) 
{
    // exception handler
    std::cout << "An exception occurred. Exception number: " << e << std::endl;
}
```

- The `try` block contains the code that may throw an exception, this block is necessary for exception handling.
- The `throw` keyword is used to throw an exception. In case an error occurs, we can throw an exception of any type.
- The `catch` block is used to catch the exception and handle it. The catch block takes an argument that specifies the type of exception that it can catch. Note that the catch block cannot catch an exception unless there is a try before it.

In case we want to catch all exceptions, we can use the `catch` block without any arguments:
```
try 
{
    // code that may throw an exception
    throw 10; // throw an exception
}
catch (...) 
{
    // catch all exceptions
    std::cout << "An exception occurred." << std::endl;
}
```

## Module 06: C++ Casts

- Casting is the process of converting one data type to another without changing the actual value.
- We can use type casting to convert one data type to another, from an integer to a float, from a float to an integer, and so on.
- This works by telling the compiler to treat a variable as a different type of variable.

Example:

- Let's say we have an char variable `c` and we want to convert it to an int variable `i`. this will will work by telling the compiler to treat the char variable as an int variable. Since the ascii value of the char variable is 65, the int variable will be 65.

- There are four types of casts in C++:
    - Static Cast
    - Dynamic Cast
    - Const Cast
    - Reinterpret Cast

### Static Cast

- Static cast is the most commonly used cast in C++.
- Static cast is used at compile time to convert one data type to another, it is used to convert between related types only. For example, converting an int to a float, or a float to an int. It cannot be used to convert between let's say a pointer to an integer. By related types, we mean types that are compatible with each other in terms of data representation.
- Static cast is not safe, it does not perform any runtime checks to ensure that the conversion is valid.

- The syntax for static cast is:
```
int i = 10;
float f = static_cast<float>(i);
```

### Dynamic Cast

- Dynamic cast is used to perform safe downcasting of pointers and references.
- Dynamic cast is a runtime cast, it can be thought of as a function that checks if the conversion is valid before performing it.
- Dynamic cast is used to convert a base class pointer or reference to a derived class pointer or reference.
- Dynamic cast returns a null pointer if the conversion is not valid.
- Dynamic cast is safe

- The syntax for dynamic cast is:
```
Base *base = new Derived();
Derived *derived = dynamic_cast<Derived*>(base);
```

### Const Cast

- Const cast is used to add or remove the const qualifier from a variable.
- Const cast is used to cast away the constness of a variable.
- Const cast is not safe, it can be used to modify a const variable.

- The syntax for const cast is:
```
const int x = 10;
int y = const_cast<int>(x);
```

### Reinterpret Cast

- Reinterpret cast is used to convert one pointer type to another pointer type, it is used to convert between unrelated types.
- Reinterpret cast is not safe, it does not perform any checks to ensure that the conversion is valid, it should only be used when we are sure that the conversion is valid.
- Reinterpret cast is used to convert between unrelated types, such as converting a pointer to an integer.

- The syntax for reinterpret cast is:
```
int i = 10;
char *c = reinterpret_cast<char*>(&i);
```
