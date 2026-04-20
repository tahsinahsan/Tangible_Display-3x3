# Tangible Display 3x3 (L298N + Bluetooth Controlled)
Youtube Link (https://youtu.be/eHOGDgq4bJI?si=fzmKej1PD4ZZnf2O)
A 3×3 tangible physical pixel display built using 9 stepper motors, each independently driven by an L298N motor driver and controlled via Arduino Mega. The system supports wireless control using an HC-05 Bluetooth module and is designed for future integration with real-time depth inputs (e.g., Kinect).

---

## 🔷 System Overview

This project converts digital height values into physical motion using a 3×3 grid of actuated pixels. Each pixel moves vertically to create a dynamic 3D surface.

* 9 independent stepper motors
* 9 L298N motor driver modules (one per motor)
* Arduino Mega as main controller
* HC-05 Bluetooth for wireless control
* Expandable to sensor-driven input (Kinect / depth camera)

---

## ⚙️ Features

* 3×3 physical resolution display
* Individual motor control per pixel
* Wireless Bluetooth command interface
* Auto motor shutdown to reduce heat
* Scalable architecture for higher resolution grids

---

## 🧠 How It Works

Each pixel is controlled by a stepper motor driven through an L298N H-bridge driver. The Arduino interprets incoming Bluetooth commands and converts them into step sequences that move each pixel up or down.

Commands are received in real-time and mapped directly to motor motion.

---

## 🔌 Hardware Used

* Arduino Mega 2560
* 9 × Stepper Motors
* 9 × L298N Motor Driver Modules
* HC-05 Bluetooth Module
* External power supply (required for motors)
* Mechanical linkage system (brake cable + vertical pin system)

---

## 📡 Communication (Bluetooth)

The system uses an HC-05 Bluetooth module connected to Arduino Serial1.

### Connection:

* HC-05 TX → Arduino RX1 (Pin 19)
* HC-05 RX → Arduino TX1 (Pin 18)
* VCC → 5V
* GND → GND

---

## 📲 Command Format

Send commands via Bluetooth terminal app:

### Move individual pixel:

```
S0:100
```

Move motor 0 by 100 steps.

```
S1:-50
```

Move motor 1 in reverse.

```
S8:200
```

Move motor 8 upward.

---

## 🔥 Power & Safety System

* Motors powered by external supply
* Each L298N enabled only during movement
* Automatic shutdown after inactivity to reduce heat
* Common ground required between all components

---

## 🧩 System Architecture

* Arduino Mega handles motor control logic
* Bluetooth module receives commands wirelessly
* Each motor operates independently
* Designed for future Kinect / depth mapping integration

---

## 🚀 Future Improvements

* Kinect / depth camera integration
* Real-time 3D surface rendering
* Smoother motion interpolation
* Higher resolution grids (5×5, 10×10)
* Mobile or web control interface

---

## 📌 Notes

This is a hardware-intensive research prototype. It requires careful wiring, stable external power for motors, and proper grounding across all driver modules.
