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