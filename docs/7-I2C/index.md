---
date: '2025-11-29T09:30:00+03:30'
draft: false
title: 'I2C'
description: "Explaining about Inter-Integrated Circuit (I2C)"
weight: 80
tags: [ "Arduino", "Cpp", "PlatformIO" ]
image: "I2C.webp"
code: "https://github.com/LiterallyTheOne/Arduino-Tutorial/blob/master/src/7-I2C"
---

# I2C

## Introduction

In the previous Tutorial, we learned about **Interrupt**.
In this tutorial we will learn about **I2C** communication.

## I2C Communication

**Inter-Integrated Circuit** (**I2C**), is a two-wire communication protocol.
This protocol is designed for **short-distance communication** between
microcontrollers and peripherals.
It uses two pins to set up the communication:

* **SDA**: Serial Data
* **SCL**: Serial Clock

This way of communication, allows us to connect more than 1 component to the same 2 pins.
For **I2C** every component has its own address.
These addresses are mostly `7-bit`.

**I2C** is a master and slave protocol.
It means that one device (Our Arduino) is a **master**, and the other devices are **slaves**.
A **master** device controls the **clock** created in **SCL**.
Also, **master** decides that if it wants to communicate with a **slave** or not.
Each message of **master** is like below:

| Field         | Bit Count | Description                                                         |
|---------------|-----------|---------------------------------------------------------------------|
| START         | —         | SDA goes LOW while SCL is HIGH → begins communication               |
| Slave Address | 7 bits    | Unique address of target device (0–127)                             |
| R/W Bit       | 1 bit     | 0 = Write, 1 = Read                                                 |
| ACK/NACK      | 1 bit     | Receiver pulls SDA LOW to acknowledge (ACK), HIGH for no-ack (NACK) |
| Data Byte 1   | 8 bits    | First byte of data to write or read                                 |
| ACK/NACK      | 1 bit     | Receiver acknowledges the byte                                      |
| Data Byte 2…N | 8 bits    | Additional data bytes (optional, depends on protocol)               |
| ACK/NACK      | 1 bit     | Acknowledge after each data byte                                    |
| STOP          | —         | SDA goes HIGH while SCL is HIGH → ends communication                |

In the table above, you can see the message structure in **I2C**.
First, **master** puts the **SDA** to low.
This indicates that all **slaves** should listen.
After that, it tells which **slave address** it wants to talk to.
Then, with `1 bit` tells the **slave** if it wants to read or write.
Next, there would be an acknowledgement bit.
If **slave** was available, it would set the acknowledgement bit to `0`.
(The default value of SDA is always `1`).
After that, there would be a byte of data.
Respect to the mode (read or write), **master** can send or receive that byte.
Then, whoever receives the data, should set the acknowledgement bit to `0`.
These byte transfer and acknowledgement can be repeated multiple times, until a stop signal.
Stop signal can be created when we put the SDA to `1`.

## Wire

To control the **I2C** communication, **Arduino** has a library called `Wire`.
We can include `Wire` in our code like below:

```cpp
#include <Wire.h>
```

To set up the **I2C** communication, we can use `.begin()` function, like below:

```cpp
Wire.begin();
```

## Temperature: DS1621

## Finding I2C address

## OLED: SSD1306

## Clock: DS1307

## LCD: Aip31068

## Arduino as an I2C Slave

## Project

## Conclusion
