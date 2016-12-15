# cast

downcast:
  from base to derived; (can not be done naturally)

upcast:
  from derived to base

Code samples:

```cpp
class Base {};
class Derived {};

Base b = Derived(); // upcast
Derived c = Base(); // downcast

Base b = Base();
(Derived) b;

Derived d = Derived();
(Base) d;
```