---
date: '2025-09-24T08:37:00+03:30'
draft: false
title: 'LCD and Keypad'
description: "Explaining LCD and Keypad and how to use them in Arduino"
weight: 40
tags: [ "Arduino", "Cpp", "PlatformIO" ]
image: "lcd-and-keypad.webp"
code: "https://github.com/LiterallyTheOne/Arduino-Tutorial/blob/master/src/3-lcd-and-keypad"
---

# LCD and Keypad

## Introduction

In the previous tutorial, we have discussed **7-segment**.
Now, we are going to learn how to work with **LCD** and **Keypad**.

## LCD

LCD is used to write parameters and status.
We have a `16x2 LCD` (16 columns and 2 rows).
It has 16-pins.

| VSS    | VCC | VEE              |
|--------|-----|------------------|
| Ground | 5V+ | Contrast Control |

| RS              | RW           | E      |
|-----------------|--------------|--------|
| Register select | Read / Write | Enable |

| D0         | D1         | D2         | D3         | D4         | D5         | D6         | D7         |
|------------|------------|------------|------------|------------|------------|------------|------------|
| Data pin 0 | Data pin 1 | Data pin 2 | Data pin 3 | Data pin 4 | Data pin 5 | Data pin 6 | Data pin 7 |

| LED+    | LED-       |
|---------|------------|
| LED 5V+ | LED Ground |

![LCD Arduino](lcd-arduino.webp)

## Connect an LCD to an Arduino in SimulIDE

Let's put an **LCD** on the board.
To do that we can use **Outputs/Displays/HD44780**.
After putting that on the board, we should connect the pins of it like below:

* RS: 12
* RW: ground
* E: 11
* D4: 5
* D6: 4
* D7: 3
* D8: 2

The result should be something like below:

![LCD Arduino SimulIDE](lcd-arduino-simulide.webp)

## Liquid Crystal

**Liquid Crystal** is a well-known package that helps us to work with **LCD**.
This package contain so many great and useful functions.
You can see the list of all functions in 
[this link](https://docs.arduino.cc/libraries/liquidcrystal/).

### Add LiquidCrystal to PlatformIO

To add **LiquidCrystal** to a **PlatformIO** project we should add this code
to `platformio.ini`.

```ini
lib_deps =
  arduino-libraries/LiquidCrystal
```

This code will download the **LiquidCrystal** and then you can import it
in your `main.cpp` like below:

```cpp
#include <LiquidCrystal.h>
```

### Make an LCD Object

Now, let's make an **LCD** object using **LiquidCrystal**.
To do so, we can use the code below:

```cpp
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
```

In the code above, at first we defined the pins in a way that we connected them to our **Arduino Uno**.
Then, we made an object of `LiquidCrystal` with those pins with the name of `lcd`.
We put that code on top of the `setup` and `loop` function to be global.
Now, let's talk about the functions that we can use for this object.

### `begin`

This function initializes the **LCD**.
It automatically sets all the pin modes and should be called before any other **LCD** commands.

The usual syntax that we use:

```cpp
lcd.begin(cols, rows);
```

Example:

```cpp
lcd.begin(16, 2);
```

### `write`

Write a character on the **LCD**.

Syntax:

```cpp
lcd.write(ch);
```

Example:

```cpp
lcd.write('h');
```

### `print`

Write a text on the **LCD**.

Syntax:

```cpp
lcd.print(text);
```

Example:

```cpp
lcd.print("Hello World!");
```

### `setCursor`

Jumps to the given column and row.

Syntax:

```cpp
lcd.setCursor(col, row);
```

Example:

```cpp
lcd.setCursor(5, 1);
```

### `clear`
