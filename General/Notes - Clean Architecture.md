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

### Reuse/Release Equivalence Principle

The granule of reuse is the granule of release.

People who want to reuse software components cannot, and will not, do so unless those components are tracked through a release process and are given release numbers.

### Common Closure Principle

Gather into components those classes that change for the same reasons and at the same times. Separate into different components those classes that change at different times and for different reasons.

This is the Single Responsibility Principle restated for components.

For most applications, maintainability is more important than reusability.

### Common Reuse Principle

Don’t depend on things you don’t need.

### Acyclic Dependencies Principle

Allow no cycles in the component dependency graph.

In medium-sized projects, it's common to have a weakly build. I.e. Monday to Thursday everyone works on a copy of their code, on Friday all changes are integrated and built.

In large-sized projects, it's advisable to partition the development environment into releasable components that become units of work  with responsibility of a single developer, or a team of developers. When developers get a component working, they release it for use by the other developers.

To break cycles in the dependency graph, one can either use dependency inversion principle and create an interface or create a new component that factors out the classes to break the cycle.

### Top-Down Design

The component structure cannot be designed from the top down.

Large-grained decompositions, like components, are not high-level functional decompositions.

Component dependency diagrams have very little do to with describing the function of the application. Instead, they are a map to the buildability and maintainability of the application. It is usually created later in the development.

### Stable Dependencies Principle

Depend in the direction of stability.

Modules that are intended to be easy to change are not depended on by modules that are harder to change.

### Stable Abstractions Principle

A component should be as abstract as it is stable.

## Architecture

A good architect maximizes the number of decisions not made.

### Indepencence

A good architecture must support:

- The use cases and operation of the system.
- The maintenance of the system.
- The development of the system.
- The deployment of the system.

USE CASES: Behaviors will be first-class elements visible at the top level of the system. Those elements will be classes, functions or modules that have prominent positions within the architecture, and they will have names that clearly describe their function.

OPERATION: An architecture that maintains the proper isolation of its components, and does not assume the means of communication between those components, will be much easier to transition through the spectrum of threads, processes, and services as the operational needs of the system change over time.

DEVELOPMENT: Any organization that designs a system will produce a design whose structure is a copy of the organization’s communication structure.

DEPLOYMENT: A good architecture does not rely on dozens of little configuration scripts and property file tweaks. A good architecture helps the system to be immediately deployable after build.

### Boundaries

The less relevant component depends on the more relevant component. E.g. Database and GUI are less relevant components than Business Rules, and hence should depend on the rules (with some stable interface between them).

This pattern is the same one that is used by systems that allow third-party plugins.

### Humble Object Pattern

This is a design pattern that was originally identified as a way to help unit testers to separate behaviors that are hard to test from behaviors that are easy to test.

E.g., GUIs are hard to unit test because of  difficultt to write tests to see the screen and check the appropriate elements. Humble Object pattern separates the two behaviors into two different classes, Presenter and the View.

The Presenter would format the data into an appropriate string, this is easy to test, and place it in a simple data structure, the View Model. Nothing is left for the View to do other than to load the data from the View Model into the screen. Thus the View is humble.

One is likely to find the Humble Object pattern at each architectural boundary, because communication across a boundary will almost always involve a simple data structure. The boundary will then divide something that is hard to test from something that is easy to test.

### Partial Boundaries

Architectural boundaries are expensive. They require reciprocal polymorphic Boundary interfaces, Input and Output data structures, and all of the dependency management necessary to isolate the two sides into independently compilable and deployable components.

Ommiting some of the steps might create a parial boundary.

### The Main Component

Main is the dirtiest of all the dirty components. Think of Main as a plugin to the application — a plugin that sets up the initial conditions and configurations, gathers all the outside resources, and then hands control over to the high-level policy of the application.

### The Test Bonudary

The tests are part of the system, and they participate in the architecture just like every other part of the system does. Changes to common system components can cause hundreds, or even thousands, of tests to break; e.g. tests depending on GUI. This is known as the Fragile Tests Problem.

The system, and the tests, should be designed so that business rules can be tested without using the GUI. This can be accomplished by creating a testing API that should have superpowers to avoid security constraints, bypass expensive resources, and force the system into particular testable states. I.e. the purpose of the testing API is to decouple the tests from the application.

### Clean Embedded Architecture

Firmware is a specific class of computer software that provides the low-level control for a device's specific hardware. It is firmware because of what it depends on and how hard it is to change as hardware evolves.

Letting all code become firmware is not good for your product’s long-term health. Being able to test only in the target hardware is not good for your product’s long-term health.

The three activities in building software:

- First make it work (You are out of business if it doesn’t work.)
- Then make it right (Refactor the code so that you and others can understand it and evolve it as needs change or are better understood.)
- Then make it fast (Refactor the code for “needed” performance.)

The boundary between the software and the firmware is the hardware abstraction layer (HAL). In many cases, HAL is a software component that acts as an interface between the hardware and the operating system. In such case, a clean embedded architecture isolates software from the operating system, through an operating system abstraction layer (OSAL).

## Details

### Database is a detail

The organizational structure of data, the data model, is architecturally significant. The technologies and systems that move data on and off a rotating magnetic surface are not. The database is really nothing more than a big bucket of bits where we store our data on a long-term basis. But we seldom use the data in that form. The data is significant. The database is a detail.
