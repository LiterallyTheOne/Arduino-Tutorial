---
marp: true
theme: uncover
footer: By Ramin Zarebidoky (LiterallyTheOne)
header: Arduino Tutorial, 7-segment
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

## 2: 7-segment

![bg right:33% w:400](qr-code-1.webp)

---
<!-- paginate: true -->

## Introduction

* Previous tutorial: GPIO
* This tutorial: 7-segment

![bg right:33% w:400](../../docs/1-gpio/traffic-light-two-buttons.gif)

---

## What is a 7-segment?

* Set of 7 leds + dp
* Show numbers and letters
* a to g + dp

![bg right:33% w:300 h:500](../../docs/2-7-segment/7segment.webp)

---

## Connect a 7-segment to fixed voltage

![numbers 7-segment](../../docs/2-7-segment/7segment-fixed-voltage.webp)

---

## Create a number

![numbers 7-segment](../../docs/2-7-segment/7segment-0.webp)

---

## Store the number

| dp | g | f | e | d | c | b | a |
|----|---|---|---|---|---|---|---|
| 0  | 0 | 1 | 1 | 1 | 1 | 1 | 1 |

---

## Connect 7-segment to an Arduino

![numbers 7-segment w:600](../../docs/2-7-segment/arduino-7segment.webp)

---

## Store our numbers in our code

```cpp
char digits[10] = {
    0b00111111, // 0
    ...
};
```

---

## Show digit function

```cpp
void show_digit(int digit)
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(i, (digits[digit] >> i) & 0b0000'0001);
  }
}
```

---

## Counter

![w:600](../../docs/2-7-segment/arduino-7segment-counter.gif)

---

## Counter with pause

![w:600](../../docs/2-7-segment/arduino-7segment-counter-pause.gif)

---

## Counter with pause and reverse

![w:600](../../docs/2-7-segment/arduino-7segment-counter-pause-reverse.gif)

---

## Link to the tutorial and materials

![w:400](qr-code-1.webp)
