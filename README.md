![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# Device Manager

A small C++ learning project about managing electronic devices using object-oriented programming.

This project was created as a learning task to practice core C++ OOP concepts:

- polymorphism
- upcasting and downcasting
- diamond inheritance
- virtual functions and virtual destructors

## Overview

The program models different kinds of devices through inheritance:

- `Device` base class
- `Computer` derived from `Device`
- `Smartphone` derived from `Device`
- `SmartComputer` derived from `Computer` and `Smartphone`

## Class Diagram

```text
          Device
         /      \
   Computer    Smartphone
         \      /
       SmartComputer
```

With virtual inheritance:
- `Computer : virtual public Device`
- `Smartphone : virtual public Device`

This prevents `SmartComputer` from containing two separate `Device` base objects.
