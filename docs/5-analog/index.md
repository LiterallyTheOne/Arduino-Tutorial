---
date: '2025-11-02T09:24:00+03:30'
draft: false
title: 'Analog'
description: "Explaining about analog read and write"
weight: 60
tags: [ "Arduino", "Cpp", "PlatformIO" ]
image: "analog.webp"
code: "https://github.com/LiterallyTheOne/Arduino-Tutorial/blob/master/src/5-analog"
---

# Analog

## Introduction

In the previous tutorials, we were focusing on **digital** read and write.
We could only write and read **0** and **1** from a pin.
In this tutorial, we will discuss how to write and read values between **0**
and **1**.

## Analog Read

In the previous tutorials, we were working with **digital** input and output.
As you recall, to read a **digital** input, we had a function called `digitalRead`.
To read **analog** input, we have a function as well.
This function is called `analogRead`.
The syntax of it is pretty similar to the `digitalRead`, the only exception is that it returns a number
in a range of $[0, 1023]$.
As you might have guessed from the range, `Arduino Uno` allocates `10 bits` for reading analog data.

In `Arduino Uno`, we have $6$ pins that we can use to read **Analog** input.
These pins are labeled as **A0** to **A5**.
In the image below, we show them by drawing a yello rectangle over them.

![Analog pins](../1-gpio/arduino-gpio.webp)

For reading digital values, $5V$ indicates $1$ and $0V$ indicates $0$.
For analog values, $5V$ indicates $1023$ and $0V$ indicates $0$.
As you can see, we divide the values between $5V$ and $0V$ into $1024$ parts.
With using this technique, we are being able to read voltage between $5V$ and $0V$.

### Potentiometer

To create a voltage between $5V$ and $0V$, we can use a device called **Potentiometer**.
You can find it at **Passive/Resistors/Potentiometer** in **SimulIDE**.
As you can see, a **Potentiometer** has $3$ pins and a button to control the output voltage.
**Potentiometer** creates voltage with increasing and decreasing the resistance. 
Let's connect a **Potentiometer** to a fixed voltage to see how it works.
To do so, we can follow these steps:

* Put a **Potentiometer** on the board (**Passive/Resistors/Potentiometer**).
* Connect the pin that is closer to a red line, to a **Fixed Voltage**.
* Connect the other pin to the **Ground**.
* Put a **VoltMeter** on the board (**Meters/VoltMeter**).
* Connect the output pin of the **Potentiometer** (the pin with the arrow on it) to the **red pin** of the **VoltMeter**.
* Connect the other pin of the **VoltMeter** (the pin beside the red pin) to the ground.

Your connection, should look like as following:

![Potentiometer](potentiometer.webp)

Now, let's start the simulation and rotate the button on the **Potentiometer**.

![Potentiometer gif](potentiometer-gif.gif)

As you can see, we can make voltages between $5V$ and $0V$.

### Potentiometer and Arduino

Now, let's connect our **Potentiometer** to the Arduino.
The steps are pretty much the same.

* Connect the pin closer to the red line to a **5V**. 
* Connect the pin on the opposite of the red line to the **Ground**.
* Connect the output pin (pin with an arrow on it) to **A0**.

Your connection should look like this:

![Analog Read](analog-read.webp)

Now, let's write a code to read the analog data.

```cpp
#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int our_input = analogRead(A0);
  Serial.println(String(our_input));
  delay(1000);
}
```

The code above, reads the analog input from `A0`.
Then, it prints the read value into Serial terminal.
The output looks like as following:

![Analog Read gif](analog-read-gif.gif)

## PWM

Before we get to work with **Analog Write**, let's learn about **PWM**.
Because **Arduino Uno** uses **PWM** to write **Analog** data.
**PWM** (Pulse Width Modulation), is a technique for controlling the power delivered to a component.  
In this technique we use different width of pulses in a signal.
These signals switch between $0$ and $1$.
The percentage of the time that a pulse is $1$ is called **duty cycle**.
The pictures below show two examples of 100Hz **PWM**, one with the 30% duty cycle and the other 60%.

![PWM 100hz 30d](pwm_100hz_30d.webp)

![PWM 100hz 60d](pwm_100hz_60d.webp)

## Analog Write

Now, that we know about **PWM**, let's connect talk about writing analog data in **Arduino uno**.
In **Arduino Uno** we have $6$ pins that we can create **PWM** on them.
Including: $3$, $5$, $6$, $9$, $10$, and $11$
These pins are shown in the board with a **~** beside them
and in **SimulIDE** with **PWM**.
To create our **duty cycles**, we can use the numbers in range $[0, 255]$.
$255$ means $100%$ and $0$ means $0%$ duty cycles.

For writing **digital** values, we had a function called `digitalWrite`.
We have a similar function for **analog** values as well, and it is called:
`analogWrite`.
Their syntax is similar, with the exception that `analogWrite` accepts an
integer for its second argument.

Now, let's connect an **LED** to pin $3$.
Your connection should look like below:

![Analog Write](analog-write.webp)

Now, let's write a code to write analog data on pin $3$.

```cpp
#include <Arduino.h>

void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 256; i++)
  {
    analogWrite(3, i);
    delay(10);
  }
}
```

In the code above, first we set the pin mode of pin 3 as output.
Then, we have a for loop that starts from $0$ and goes until $256$.
So, we expect the brightness of our **LED** changes from dark to light.
As you can see in the output below, this is the exact thing that is happening.

![Analog Write gif](analog-write-gif.gif)

If we want to see the **PWM** that we are generating, we can connect an
**Oscope** to our output.
To do so, we can follow these steps:

* Put an **Oscope** on the board (**Meters/Oscope**)
* Connect the bottom pin to the ground
* Connect any other pin to the output of pin $3$.

Your output should look like as following:

![Analog Write Oscope gif](analog-write-oscope.gif)

## Combining both

![Combining Both](combining-both.webp)

![Combining Both gif](combining-both.gif)

![Combining Both Oscope gif](combining-both-oscope.gif)

## DC motor

![DC Motor](dc-motor.webp)

![DC Motor gif](dc-motor-gif.gif)

## Servo Motor

![Servo motor](servo-motor.webp)

![Servo motor gif](servo-motor-gif.gif)

## Conclusion
