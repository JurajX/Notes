# Proxy Design Pattern

A proxy pattern provides a surogate or a placeholder for another object in order to control access to it. I.e. a proxy is a class functioning as an interface to something else, e.g. a network connection, a large object in memory, a file, or some other resource that is expensive or impossible to duplicate. In the proxy, extra functionality can be provided, for example caching when operations on the real object are resource intensive, or checking preconditions before operations on the real object are invoked. For the client, usage of a proxy object is similar to using the real object, because both implement the same interface.

[(Modified, from Wiki.)](https://en.wikipedia.org/wiki/Proxy_pattern)

## Class Diagram

![Class Diagram](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/JurajX/Notes/master/DesignPatterns/Proxy/theory.puml)
