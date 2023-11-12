# *CPP-Module06*
---
## **Navigation Table:**
---
1. [Type Conversion in C++.](#type-conversion-in-c)
    1. [Implicite Type Conversion.](#implicite-type-conversion)
    1. [Explicit Type Conversion.](#explicit-type-conversion)
1. [Cast operator in C++.](#cast-operators-in-c)
    1. [Static Cast.](#static-cast)
    1. [Reinterpret Cast.](#reinterpret-cast)
    1. [Dynamic Cast](#dynamic-cast)
---
## **Type Conversion in C++:**
A type cast is basically a conversion from one type to another. There are two types of type conversion:
### ***Implicite Type Conversion:***
The Implicit Type Conversion is where the type conversion is done automatically by the compiler. It does not require any effort from the programmer. The compiler automatically converts one data type to another based on these rules. Therefore, implicit type conversion is also known as **automatic type conversion**.

For example:
```c++
#include<iostream>
using namespace std;
int main(){
    int x = 65;
    char y = x;
    cout << x << endl << y;
    return 0;
}
```
this code above will output:
```shell
    $> 65
       A
```
**NOTICE:**
> When there is more than one data type present in an expression, there is a possibility of data loss because different data types are incompatible. Data loss occurs if a variable converts from a higher data type to a lower data type. To avoid data loss, the compiler automatically converts all the data types to the highest data type present in the expression. This is called promotion. The precedence of different data types is given below.

![data-grade](https://scaler.com/topics/images/data-loss-chart.webp)

---
### ***Explicit Type Conversion:***
This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type.
In C++, it can be done by two ways:

+ **Converting by assignment:**
>This is done by explicitly defining the required type in front of the expression in parenthesis. This can be also considered as forceful casting. Also known as **C-style type casting**.
>
>**Syntax:**
>```c++
>    (type)variable_name;
>```
>
>where type indicates the data type to which the final result is converted.
>
>For example:
>```c++
>#include<iostream>
>
>using namespace std;
>
>int main() {
>    int x = 65;
>    cout << x << endl << (char)x;
>    return 0;
>}
>```
>this code above will output:
>```shell
>    $> 65
>       A
>```

+ **Conversion using Cast operators:**
> A Cast operator is an unary operator which forces one data type to be converted into another data type which we will cover in the next part.
---
## **Cast operators in C++:**
As we said befour cast operators are unary operators which forces one data type to be converted into another data type.

In C++ supports 4 types of casting:
### ***Static Cast:***
The Static Cast is the simplest among all four types of cast operators. The static cast can perform all the conversions that are done implicitly. The typecasting using this is done at compile time. This means that no checks are made at the run-time to ensure that the cast performed is valid. Hence, the programmer must ensure the conversion is valid using the static cast.

The Static cast can perform conversions between the pointers of classes related to each other. It can perform upcast (conversion from a derived class to a base class) operations and downcast (conversion from a base class to a derived class) operations.

**Syntax:**
```c++
    static_cast<dest_type>(source);
```
The return type will be the destination data type.

For example:
```c++
#include<iostream>

using namespace std;

int main() {
    float x = 1.2f;
    int y = static_cast<int>(f);
    cout << y;
    return 0;
}
```

This code above will output:
```shell
    $> 1
```
**NOTICE:**
> While using the static cast, we must ensure that the datatype being typecasted must be compatible with the new data type. Otherwise, we will get an error.
---
### ***Reinterpret Cast:***

It is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different. as well as to convert pointers to integers and vice versa. It allows you to interpret the binary representation of an object of one type as another type.That is why reinterpret cast should not be used unless required.

**Syntax:**
```c++
    reinterpret_cast<dest_type>(source);
```
For example:
```c++
#include<iostream>
#include<string>

using namespace std;

typedef data {
    string str;
    int nbr;
    data(string s, int n){
        str = s;
        nbr = n;
    }
} data;

int main() {
    data *ptr = new data("hello", 10);
    string *s = reinterpret_cast<string *>(ptr);
    cout << s << endl;
    s++;
    int *n = reinterpret_cast<int *>(s);
    cout << *i;
    return 0;
}
```
This code above will output:
```shell
    $> hello
       10
```
**NOTICE:**
> It is important to exercise caution when using reinterpret_cast, as it bypasses the standard type system and can lead to potential errors if misused. It should only be used when absolutely necessary and with a thorough understanding of the implications, also note that reinterpret_cast should be used sparingly, and it is generally recommended to use more specific casting operators (such as static_cast or dynamic_cast) when possible, as they provide more type safety and are easier to reason about.
---
### ***Dynamic Cast:***
In C++, dynamic casting is mainly used for safe downcasting at run time. To work on dynamic_cast there must be one virtual function in the base class. A dynamic_cast works only polymorphic base class because it uses this information to decide safe downcasting. The dynamic cast uses the Run-Time Type Identification (RTTI) mechanism to make all information about the data type of an object available at the run-time. The information is available only for classes with at least one virtual function.
**Syntax:**
```c++
    dynamic_cast<dest_type>(source);
```
For example:
```c++
#include <iostream>
using namespace std;

class Base {
  public:
    virtual void print() {}
};

class Derived: public Base {};

int main() {
  Base* b = new Derived;
  Derived* d = dynamic_cast <Derived*> (b);

  if (d != NULL) {
    cout << "dynamic_cast done" << endl;
  } else {
    cout << "dynamic_cast not done" << endl;
  }

  return 0;
}
```
The code above will output:
```shell
    $> dynamic_cast done
```
**NOTICE:**
> If the conversion is not possible, dynamic_cast returns a null pointer (for pointer conversions) or throws a bad_cast exception (for reference conversions).
