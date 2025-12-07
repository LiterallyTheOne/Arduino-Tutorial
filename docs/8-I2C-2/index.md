---
date: '2025-12-07T08:09:00+03:30'
draft: false
title: 'I2C: Part 2'
description: "Second part of explaining about Inter-Integrated Circuit (I2C)"
weight: 90
tags: [ "Arduino", "Cpp", "PlatformIO" ]
image: "I2C-part2.webp"
code: "https://github.com/LiterallyTheOne/Arduino-Tutorial/blob/master/src/8-I2C-2"
---

# I2C: part 2

## Introduction

In the previous tutorial, we learned about the **I2C Communication**.
Also, we introduced two components and learned how to communicate with them.
To understand this way of communication better,
let's work with another component and define an **Arduino** as a **slave**.

## Temperature: DS1621

![DS1621](temperature_ds1621.webp)

![Command Table](command-table.webp)

![Register byte](register-configuration.webp)

![output of temperature](output-of-temperature.webp)

> [Link to the Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/DS1621.pdf)
>
> [Command Table](https://www.analog.com/media/en/technical-documentation/data-sheets/DS1621.pdf#page=10.84)
>
> [Configuration registers](https://www.analog.com/media/en/technical-documentation/data-sheets/DS1621.pdf#page=5.58)

![temperature OLED](temperature-oled.webp)
![temperature OLED gif](temperature-oled-gif.gif)

## Arduino as an I2C Slave

## LCD: Aip31068

## Conclusion
