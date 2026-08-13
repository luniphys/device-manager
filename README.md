![C++](https://img.shields.io/badge/C++-%2300599C.svg?logo=c%2B%2B&logoColor=white)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# Device Manager

A small C++ study project about managing electronic devices using object-oriented programming.

This project was created as a learning task to practice core C++ OOP concepts:

- Polymorphism
- Upcasting and downcasting
- Diamond inheritance
- Virtual functions and virtual destructors

## Overview

The program models different kinds of devices through inheritance:

- `Device` base class
- `Computer` derived from `Device`
- `Smartphone` derived from `Device`
- `SmartComputer` derived from `Computer` and `Smartphone`

### Class Diagram

```text
          Device
         /      \
   Computer    Smartphone
         \      /
       SmartComputer
```

## License

MIT © [luniphy](https://github.com/luniphy)
