---
marp: true
theme: uncover
class: invert
footer: By Ramin Zarebidoky (LiterallyTheOne)
header: Arduino Tutorial, Interrupt
size: 16:9
---


<style scoped>
p {
  color: cyan;
}
</style>

<!-- _header: "" -->
<!-- _footer: "" -->

# Arduino Tutorial

By LiterallyTheOne

## 6: Interrupt

![bg right:33% w:400](qr-code-1.webp)

---
<!-- paginate: true -->

## Introduction

* Previous tutorial: Analog
* This tutorial: Interrupt

![bg right:33% w:400](../../docs/5-analog/combine_all_gif.gif)

---

## External Interrupt

* Special Signal
* Pause the current action
* Run a code in a function
* Interrupt Service Routine Function (ISR Function)

---

## External Interrupt in Arduino Uno

* 2 External Interrupts
* pin 2, 3

---

## Setup LEDs

![setup leds height:450](../../docs/6-interrupt/led-setup.webp)

---

## Write a Routine

<style scoped>
  pre {
    font-size: 17px; /* Adjust this value to your desired size */
  }
</style>

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

---

## Output of LED setup

![LED stup gif height:450](../../docs/6-interrupt/led-setup-gif.gif)

---

## Connect an Interrupt

* Button is **Normally Closed**
* Default: 5V
* Change: 0V

![LED pause bg right:50% height:410](../../docs/6-interrupt/led_pause.webp)

---

## Define Interrupt in Arduino

* `attachInterrupt`
  * pin
  * **ISR** function
  * mode

---

## Define Interrupt pin

* `digitalPinToInterrupt`

```cpp
attachInterrupt(digitalPinToInterrupt(2), ... ,...);
```

---

## Define ISR function

```cpp
void isr_pause()
{
}
```

```cpp
attachInterrupt(digitalPinToInterrupt(2), isr_pause ,...);
```

---

## Modes

<style scoped>
  {
    font-size: 30px; /* Adjust this value to your desired size */
  }
</style>

| Mode    | Description                                           | figure                                                  |
|---------|-------------------------------------------------------|---------------------------------------------------------|
| LOW     | trigger the interrupt whenever the pin is low.        | ![interrupt-stage-low](../../docs/6-interrupt/interrupt-stages-low.webp)       |
| CHANGE  | trigger the interrupt whenever the pin changes value. | ![interrupt-stage-change](../../docs/6-interrupt/interrupt-stages-change.webp) |
| RISING  | trigger when the pin goes from low to high.           | ![interrupt-stage-rise](../../docs/6-interrupt/interrupt-stages-rise.webp)     |
| FALLING | trigger when the pin goes from high to low.           | ![interrupt-stage-fall](../../docs/6-interrupt/interrupt-stages-fall.webp)     |

---

## Add mode

```cpp
attachInterrupt(digitalPinToInterrupt(2), isr_pause, RISING);
```

---

## Fill the isr function

<style scoped>
  pre {
    font-size: 13px; /* Adjust this value to your desired size */
  }
</style>

```cpp
#include <Arduino.h>

int led_pins[8] = {6, 7, 8, 9, 10, 11, 12, 13};

int current_led = 0;
int x = 1;

void isr_pause()
{
  x = 1 - x;
}

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(led_pins[i], OUTPUT);
  }

  attachInterrupt(digitalPinToInterrupt(2), isr_pause, RISING);
}

void loop()
{
  digitalWrite(led_pins[current_led], HIGH);
  delay(200);
  digitalWrite(led_pins[current_led], LOW);

  current_led += x;
  current_led %= 8;
}
```

---

## Output of pause interrupt

![pause interrupt h:450](../../docs/6-interrupt/led-pause-gif.gif)

---

## Volatile in Cpp

* Stops Compiler optimazation for a variable

```cpp
volatile int v;
```

---

## Reset with Interrupt

![Interrupt reset height:450](../../docs/6-interrupt/reset-with-interrupt.gif)

---

## Increment pattern

![Incerement pattern height:450](../../docs/6-interrupt/increment-pattern.gif)

---

## LEDS dance

![LEDs dance height:450](../../docs/6-interrupt/leds-dance.gif)

---

## Link to the tutorial and materials

![w:400](qr-code-1.webp)
