# UML basics

## Aggregation

Aggregation ("is part of" or "has a") shows that one or more classes are part of another class, or are contained by it. However, the existence of the the contained classes is independent of the container. E.g. Library and Books.

## Composition

Composition ("is entirely made of") is a stronger relationship than aggregation. It indicates that the classes contained depend upon the existence of the container. If the container class is removed, they cannot persist.

## Inheritance

When a particular class is considered to be a child of another class, it will extend it. I.e. inherit the same functionalities of the parent class, and possibly add new or modify the inherited functionalities.

## Implementation

This indicates that a particular class is responsible for the implementation of some of the functionality of another class. The relationship defines this functionality for the class that is implementing it.

## Association

An Association reflects relation between two classes. One class has access to some instances of the other class, but not vice versa. E.g. Player has a HelathBar but the later doesn't know about the former.
Association relationship is stronger than Dependency relationship, it implies a closer connection between entities.

## Dependency

Dependency indicates that one class depends on another, in that a change in one class may result in changes in the other. It is used to reflect that one class interacts with another one or receives an instance of it as a method parameter.
Compared to Association, Dependency relationship is weaker.

## Class Diagram Arrow Types

![Class Diagram](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/JurajX/Notes/design-patterns/DesignPatterns/UmlBasics/arrowTypes.puml)
