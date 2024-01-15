# Clean Architecture

The goal of software architecture is to minimize the human resources required to build and maintain the required system.

Software systems provide two different values, behaviour and structure. The difficulty of making a change should be proportional only to the scope of the change, not the shape of the change.

- If you give me a program that works perfectly but is impossible to change, then it won’t work when the requirements change, and I won’t be able to make it work. Therefore the program will become useless.
- If you give me a program that does not work but is easy to change, then I can make it work, and keep it working as requirements change. Therefore the program will remain continually useful.

## Paradigms

Each of the paradigms removes capabilities from the programmer. They align with the three big concerns of architecture: function, separation of components, and data management.

### Structured Programming

Structured programming imposes discipline on direct transfer of control.

Dijkstra showed that the use of unrestrained jumps (goto statements) is harmful to program structure. He replaced those jumps with the more familiar *if/then/else* and *do/while/until* constructs.

These control sturctures were proven to be the only necessary structures to create any program (sequence, selection, and iteration); and the only structures that allowed programs or modules to be provable. I.e. they alowed large-scale problem statements to be decomposed into high-level functions, and those in turn into lower-level functions, etc.

### Object Oriented Programming

Object-oriented programming imposes discipline on indirect transfer of control.

Dahl and Nygaard noticed that the function call stack frame could be moved to a heap. The function became a constructor for a class, the local variables became instance variables, and the nested functions became methods. This led inevitably to the discovery of polymorphism through the disciplined use of function pointers.

Encapsulation, inheritance, and polymorphism were there even before OOP. But OOP makes these more convenient, especially they remove the need to use pointers to functions to create polymorphism, and they made inheritance more convinient by removing the need to order members in the same way as base structures.

OOP allows the plugin architecture to be used anywhere and for anything, and provides a safe and convenient polymorphism allowing any dependency to be inverted.

### Functional Programming

Functional programming imposes discipline upon variable assignment.

Church invented lambda-calculus which foundation is immutability. This effectively means that a functional language has no assignment statement.

Immutability is important as an archtectural consideration as all race conditions, deadlocks, and concurrent update problems are caused by mutability.

## Design Principles

### Single Responsibility Principle

A module should be responsible to one, and only one, actor. The term actor refers to a group that requires a change in the module.

In other words, gather together the things that change for the same reasons. Separate those things that change for different reasons. Another way at looking at this is as a corollary to Conway's law: Organizations which design systems are constrained to produce designs which are copies of the communication structures of these organizations.

### Opened-Closed Principle

A software artifact should be open for extension but closed for modification.

The behaviour of a software should be extendible, without having to modify it. I.e. software should be extendible by adding a new code without the need to re-write parts of the software.

This goal is accomplished by partitioning the system into components, and arranging those components into a dependency hierarchy that protects higher-level components from changes in lower-level components.

### Liskov Substitution Principle

Objects of a superclass should be able to be replaced with objects of a subclass without affecting the correctness of the program.

In other words, implementations of interfaces should be substitutable.

### Interface Segregation Prinbiple

No code should be forced to depend on methods it does not use.

### Dependency Inversion Principle

- High-level modules should not import anything from low-level modules. Both should depend on abstractions (e.g., interfaces).
- Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.

Violations cannot be entirely removed, but they can be gathered into a small number of concrete components and kept separate from the rest of the system. Most systems will contain at least one such concrete component, often called main, because it contains the main function.

## Component Principles

### Components
