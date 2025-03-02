# 📬 Smart Post Box

### © by Thevapriyan

---

## 📖 Project Overview

The **Smart Post Box** is an IoT-based system that uses a **NodeMCU ESP8266** and **Arduino Mega** to detect letters or parcels placed inside the post box. It utilizes an **Ultrasonic Sensor** to measure the distance, and when an object is detected (mail inserted), the system updates the status on the **Blynk App**. 

---

## ⚙️ Hardware Components

| Component          | Description                 |
|------------------|---------------------|
| NodeMCU ESP8266   | WiFi Module & Main Controller |
| Arduino Mega      | Connected to NodeMCU for power |
| Ultrasonic Sensor | Measures distance (Detects mail) |
| LED                | Status indicator (optional) |

---

## 📡 Wiring Diagram

| NodeMCU Pin | Connected To     |
|------------|------------------|
| Vin         | Mega 5V          |
| Gnd         | Mega Gnd         |
| D3          | Ultrasonic Echo Pin |
| D4          | Ultrasonic Trig Pin |
| D5          | Optional LED (Indicator) |

---

## 📱 Blynk App Setup

1. Download and install the [Blynk App](https://blynk.io/en/getting-started).
2. Create a new project and select **ESP8266** as the device.
3. Add a **Display Widget** on virtual pin **V1** to show the mail count.
4. Get the **Auth Token** from Project Settings (nut icon).

---

## 🔗 WiFi and Blynk Configuration

Replace these placeholders in the code with your actual credentials:

```cpp
char auth[] = "Your_Blynk_Auth_Token";  // From Blynk App
char ssid[] = "Your_WiFi_SSID";          // Your WiFi network name
char pass[] = "Your_WiFi_Password";      // Your WiFi password
