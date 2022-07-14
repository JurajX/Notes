# Composite Design Pattern

The composite pattern describes a group of objects that are treated the same way as a single instance of the same type of object. I.e. it composes objects into a tree structures to represent part-whole hirarchies. Composite lets clients treat individual objects and composition of objects uniformly.

There is several problem with placing the `add()` and `remove()` methods. I.e. haiving them:

- only in the Composite introduces problems with compiling and down-casting of pointers;
- in Component introduces problems with Leaf having to implement them.

[(Modified, from Wiki.)](https://en.wikipedia.org/wiki/Composite_pattern)

## Class Diagram

![Class Diagram](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/JurajX/Notes/master/DesignPatterns/Composite/theory.puml)
