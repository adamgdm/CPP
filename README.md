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
        void myFunction() {
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
switch (expression) {
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
if (expression == value1) {
    // code here
} else if (expression == value2) {
    // code here
} else {
    // code here
}
```
