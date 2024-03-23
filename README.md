# C++ Modules Documentation

## Module 1: Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff

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

## Module 2: Memory allocation, pointers to members, references, switch statements

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

## Module 3: Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

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

