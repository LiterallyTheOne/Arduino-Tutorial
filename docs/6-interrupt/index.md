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

## Conclusion
