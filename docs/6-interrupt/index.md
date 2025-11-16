---
date: '2025-11-16T08:26:00+03:30'
draft: false
title: 'Interrupt'
description: "Explaining about the Interrupts in Arduino and opening up the External Interrupts with more details"
weight: 70
tags: [ "Arduino", "Cpp", "PlatformIO" ]
image: "interrupt.webp"
code: "https://github.com/LiterallyTheOne/Arduino-Tutorial/blob/master/src/6-interrupt"
---

# Interrupt

## Introduction

In the previous session, we learned how to work with analog values in **Arduino Uno**.
In this session we will learn about one of the most important aspects of microcontrollers,
which is called **Interrupt**.
We have different kinds of **Interrupts**, but in this tutorial, we are going to focus on the **External Interrupt**,
which we will explain very soon.

## What is an External Interrupt?

**Interrupt** is a special signal. 
It tells the microcontroller to stop (halt) what he is doing right now and execute the given code.
This code, should be in a function called **Interrupt Service Routine Function**.
In **Arduino Uno**, we have 2 external **interrupts**.
These **interrupts** are connected to **pin 2** and **pin 3**.
So, if we want to work with these interrupts, we should connect a button to one of these two pins.

## Setup LEDs

To understand the concept of interrupts better, let's make a routine.
The routine that we are going to make, includes $8$ LEDs, which are connected like the image below:

![led setup](led-setup.webp)

You are free to connect the LEDs to any pin that you want, except pins $0$ to $3$.
We connected our LEDs to pin $6$ to $13$.
Now, let's write a code for these LEDs to turn on in a sequence.

```cpp
#include <Arduino.h>

int led_pins[8] = {6, 7, 8, 9, 10, 11, 12, 13};

int current_led = 0;

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop()
{
  digitalWrite(led_pins[current_led], HIGH);
  delay(200);
  digitalWrite(led_pins[current_led], LOW);

  current_led++;
  current_led %= 8;
}
```

In the code above, first we have defined which pins we have for our LEDs in a variable called `led_pins`.
Then, we have defined a variable called `current_led`.
`current_led` indicates which led should be on at the moment.
In the `setup` we have defined all of our `led_pins` to `OUTPUT`, because we want to write values in them.
Then, in the `loop` at first we have turned on the first LED and keep it on for `200ms`.
After that, we turned that LED off.
For the next step, we increment the value of `current_led` and make sure that it doesn't go more than $8$.
Our output looks like the following:

![led setup gif](led-setup-gif.gif)

Now, we are ready to add an interrupt and see its effect.

## Conclusion
