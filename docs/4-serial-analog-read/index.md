---
date: '2025-10-01T08:37:00+03:30'
draft: false
title: 'Serial and Analog read'
description: "Explaining about Serial port and Analog read in Arduino Uno"
weight: 50
tags: [ "Arduino", "Cpp", "PlatformIO" ]
image: "serial-analog-read.webp"
code: "https://github.com/LiterallyTheOne/Arduino-Tutorial/blob/master/src/4-serial-analog-read"
---

# Serial and Analog read

## Introduction

In the previous tutorial, we learned how to work with **LCD** and **Keypad**.
In this tutorial, at first, we are going to learn about **Serial Communication**.
Then we are going to learn how to read **Analog** data in **Arduino** instead of only **0** and **1**.

## Serial communication

**Serial communication** is a way that a microcontroller can send and receive data one bit at a time. 
You can use it to communicate with computers, microcontrollers, and modules (e.g., GPS, Bluetooth, ESP8266).
**Serial communication** is one of the most important concepts in microcontrollers.
**Arduino Uno** uses **UART** (Universal Asynchronous Receiver-Transmitter) to handle the **Serial communication**.
**UART** needs two pins, one for receiving data (RX) and one for transmitting data (TX). 
These two pins are available in **Arduino Uno** in **pin 0** (RX) and **pin 1** (TX).
Also, we can have **Serial Communication** with **USB** as well.
One of the most important things in having a **Serial Communication** is setting the correct **baud rate** for both
of the devices that are trying to communicate.
**Baud rate** indicates the speed of data transfer.
The reason that **baud rate** should be the same for both devices is that, we have an **asynchronous** communication.
The start and the end of the communication are determined with **start bit** and **end bit**. 

### Serial Terminal on SimulIDE

One of the ways that we can use **Serial communication** is by using a **Serial Terminal**.
You can access a **Serial Terminal** in **Micro/Peripherals/Serial Terminal**.
Now, let's put a **Serial Terminal** on the board and connect it to an **Arduino Uno**.
To do that, we should wire them like below:

* **TX** of **Arduino** -> **RX** of **Serial Terminal**
* **RX** of **Arduino** -> **TX** of **Serial Terminal**

You should have something like this:

![Serial Terminal](serial-terminal.webp)


