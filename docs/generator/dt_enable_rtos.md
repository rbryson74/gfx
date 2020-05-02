\page EnableRtos Enable RTOS
[TOC]

In an RTOS-based system, the Aria Graphics Library can be configured to run as a stand-alone task that blocks and waits for external events from the input/touch task or the application task. This offers a couple of advantages: (1) this allows the Aria Graphics library to run efficiently by relinquishing CPU time to other tasks when the UI is idle, (2) the Aria Graphics library can be run as a high priority task and be more responsive to user input since it can preempt lower priority tasks. 

To create a Harmony Graphics project with RTOS, the initial configuration is similar to a bare-metal Graphics project. The following Harmony components must be added to the project: 

1. Display 

2. Display controller interface peripheral and driver 

3. Touch interface peripheral and driver 

4. GFX Core (Hardware Abstraction Layer) 

5. Input System Service 

6. Harmony Core 

7. Aria Graphics Library 

The project graph for this initial (bare-metal) configuration would look something like the one below: 