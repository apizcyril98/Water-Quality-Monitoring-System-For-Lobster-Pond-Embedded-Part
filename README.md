# Water-Quality-Monitoring-System-For-Lobster-Pond-Embedded-Part
Embedded part for my Final Year Project which is "Water Quality Monitoring System for Lobster Pond"

### Problem Statement
Implementing the traditional method where farmers use the cultivation kit and 
equipment, and measure the water quality manually is very inefficient. Since water 
quality needs to be monitored regularly, the manual operation takes a lot of time for 
cultivators to do every day. It also costs more when farmers need to collect and send 
the water sample to a laboratory to be tested. Water testing should be done regularly 
to ensure that the water quality is maintained for a high yield, as well as the health and 
safety of the aquatic life.

### List of Materials
#### PH Sensor
The first sensor that will be used in this project is Lab Grade pH probe from 
Atlas Scientific. This sensor is able to measure precise and accurate reading of pH 
level without a problem, and completely submersible in water.
<div align="center">
  <img src="https://i.ibb.co/q5Nb577/Screenshot-2023-09-03-222315.png" alt="PH Sensor">
</div>


#### DO Sensor
Next is the dissolved oxygen probe where it is capable of measuring the 
concentration of oxygen in water. As lobsters need 10mg/L of oxygen to live in good 
condition, this sensor is important in order to maintain the water quality.
<div align="center">
  <img src="https://i.ibb.co/JxTc5RT/Screenshot-2023-09-03-222336.png" alt="DO Sensor">
</div>


#### Whitebox
Whitebox T2 is a device that works as Arduino shield and it is designed to be 
directly mounted on top of Arduino Uno R3 board. By utilizing this device, Sensors 
will not interfere with one other, and most outside electrical noises that can affect the 
data readings is reduced thanks to the built-in electrical isolation on the board.
<div align="center">
  <img src="https://i.ibb.co/4jJsKc9/Screenshot-2023-09-03-222418.png" alt="Whitebox">
</div>

#### Arduino Uno
In this project, an Arduino Uno board which is based on the 
ATmega328P microcontroller is used.
<div align="center">
  <img src="https://i.ibb.co/D7b891x/Screenshot-2023-09-03-222351.png" alt="Arduino">
</div>

#### NodeMCU
Node MicroController Unit or known as NodeMCU is an open-source software 
and hardware development environment based on the ESP8266, which is a low-cost 
System-on-a-Chip (SoC) device.
<div align="center">
  <img src="https://i.ibb.co/2KqKfTr/Screenshot-2023-09-03-222430.png" alt="nodeMCU">
</div>

### Architectural Design of the system
This section is divided into four subsections, each of which is based on the 
architectural design of the system, and the technologies required for its development
are presented. The sensor node, IoT gateway, cloud, and lastly the data visualization, 
which includes a functional description, are all described. The system architecture 
design presented here is the combination of the four subsections that will complete a 
full IoT-based water quality monitoring system that can read data and send the data to 
a mobile app via the cloud using an internet connection
<div align="center">
  <img src="https://i.ibb.co/TWdbcxK/Screenshot-2023-09-03-224833.png" alt="Architectural Design of the system">
</div>

### IoT Gateway
This section focuses on the connectivity between the microcontroller and the 
internet. As a consequence of Arduino Uno R3 not having integrated wifi module chip, 
external Nodemcu ESP8266 is used in this project to connect the microcontroller to 
the cloud server, Firebase, in the process of sending data. In order to use the Nodemcu 
as wifi module and transmit dissolved oxygen data from Arduino to the device, D2 
and D3 pins of the Nodemcu need to be connected to pin 10 and pin 11 of Arduino 
board respectively. Other than that, D6 and D7 pins of Nodemcu board also need to be 
connected to pin 12 and 13 of the Arduino board to transmit pH data. This connection 
is called Port 2 while the prior connection is called Port 1. Since the Arduino is 
powered up from the USB-B port, pin 3.3V of Arduino is connected directly to the Vin 
pin of Nodemcu as a means to supply the power source to the ESP8266 board. GND 
pins on both boards are connected with each other as ground. Figure 3.5 below shows 
the circuit connection between the two boards
<div align="center">
  <img src="https://i.ibb.co/rHVtTsr/Screenshot-2023-09-03-225851.png" alt="IoT Gateway">
</div>

