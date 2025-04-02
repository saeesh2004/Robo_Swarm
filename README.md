# Robosoc_Swarm
## Introduction
Swarm robotics is a rapidly evolving field within robotics that explores the collective behaviour of multiple robots working together.  Drawing inspiration from the natural world, swarm robotics systems are characterized by decentralized control, simple individual robots, and emergent collective intelligence.  This project investigates the potential of swarm robotics with a focus on decentralized control, where a central unit (mother bot) coordinates smaller worker bots to achieve a common goal.
![](https://github.com/groot-sambh/Robosoc_Swarm/blob/main/images/WhatsApp%20Image%202024-04-11%20at%2017.06.07.jpeg?raw=true)
## Objectives
The primary objective of this project is to design and implement a swarm robotics system with decentralized control.  The project aims to achieve the following objectives:
* Develop a system consisting of a mother bot and worker bots capable of communication and collaboration.
* Implement a decentralized control scheme where the mother bot directs the worker bots based on user commands.
* Explore the use of HTTP commands for user-friendly control of the swarm robotics system.
* Demonstrate the potential applications of the system through practical tasks.
## Advantages
Swarm robotics with decentralized control offers several advantages over traditional robotic approaches:
* Scalability:  The system can be easily scaled by adding more worker bots, making it suitable for tasks requiring a large number of robots.
* Robustness:  The loss of a single robot does not cripple the entire system, as the remaining robots can continue the task.
* Adaptability:  The decentralized nature allows the swarm to adapt to changing environments and unforeseen obstacles.
* Cost-effectiveness:  Individual robots can be simpler and less expensive compared to complex single robots performing the same task.
## Challenges
### Hardware Integration
The ESP32 modules have limited resources and memory, which made it difficult to run. We had to optimize the code and to make it work.
### Communication
We had to use a custom protocol that was optimized for the ESP32 modules. This required a lot of  debugging to ensure that the communication was reliable and efficient.
## Components used:
* Basic Chassis: Provides the structural foundation for the robot, housing the motors, wheels, and other components.
* N20 Motors: Power the movement of the robot, offering a balance between size, torque, and power consumption.
* ESP32 Microcontroller: Controls the robot's behavior, processing sensor data and sending commands to the motor driver for movement.
* L298N Motor Driver: Interfaces between the ESP32 and the N20 motors, regulating the voltage and current to drive the motors smoothly and efficiently.

## Working Video(gif)
![](https://github.com/groot-sambh/Robosoc_Swarm/blob/main/images/right%20triangle.gif?raw=true)
![](https://github.com/groot-sambh/Robosoc_Swarm/blob/main/images/scatter.gif?raw=true)
