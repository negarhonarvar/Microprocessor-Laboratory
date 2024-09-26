# Microprocessor Lab Series

This project contains solutions for a series of microprocessor labs using the 8086/8088 processor, STM32 microcontroller, and ARM Cortex-M4 architecture. The goal of these labs is to provide hands-on experience with assembly language programming, memory management, interfacing with external devices, and using simulators for debugging.

### Table of Contents

<table style="width:100%">
 <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB1">Lab 1</a></th>
    <th>Assembly program design for 8086/8088: Writing, debugging, and executing an assembly program to calculate the difference between the squares of two numbers, implementing insertion sort, and handling system interrupts.</th>
  </tr>
   <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB2/A">Lab 2 - A</a></th>
    <th>Introduction to 8086/8088 memory management: Understanding 8-bit and 16-bit memory operations, assembly programming to read from and write to specific memory addresses, and familiarizing with the 74138 decoder.</th>
  </tr>
   <tr>
     <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB2/B">Lab 2 - B</a></th>
     <th>Designing an 8086-based system to interface with I/O devices using assembly language. The system captures user input, processes it, and displays results on the output device using the 8255 chip.</th>
  </tr>
  <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB3/A">Lab 3 - A</a></th>
    <th>Working with the 8253 Timer in 8086: Implementing a system that controls LEDs with start/stop buttons and setting timers using the 8253 Timer chip.</th>
  </tr>
   <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB3/B">Lab 3 - B</a></th>
    <th>Using the 8259 Interrupt Controller: Developing an 8086-based system that handles external interrupts to control the speed of LED blinking using buttons.</th>
  </tr>
   <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB4/A">Lab 4 - A</a></th>
    <th>Introduction to ARM Cortex-M4 programming: Using Keil MDK to write and debug assembly programs on ARM, focusing on the architecture and system registers.</th>
  </tr>
  <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB4/B">Lab 4 - B</a></th>
    <th>GPIO programming on STM32F401: Configuring GPIO pins for input/output, connecting to 7-segment displays, and writing a C program to control the display of values on the 7-segment display.</th>
  </tr>
  <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB5/A">Lab 5 - A</a></th>
    <th>LCD Interfacing with STM32F401: Connecting an alphanumeric LCD display to the STM32 board and programming it to display messages and monitor pulse frequency.</th>
  </tr>
  <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB5/B">Lab 5 - B</a></th>
    <th>External interrupts and GPIO on STM32: Configuring external interrupts on GPIO pins and writing a program that reacts to button presses by toggling LED states and adjusting PWM signals.</th>
  </tr>
  <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB6/A">Lab 6 - A</a></th>
    <th>Implementing timers on STM32: Writing a program that uses a timer to display elapsed time on an LCD and resets the time on button press. GPIO interrupt handling is also demonstrated.</th>
  </tr>
  <tr>
    <th><a href="https://github.com/negarhonarvar/Microprocessor-Laboratory/blob/main/LAB6/B">Lab 6 - B</a></th>
    <th>Using the STM32 Timer and GPIO interrupts: A program that adjusts PWM duty cycles based on button inputs, showing the effect on connected LEDs.</th>
  </tr>
</table>

---

### Objective of Each Lab

- **Lab 1**: Focuses on basic assembly programming for the 8086 processor, introducing concepts such as register operations, addressing modes, and system interrupts.
- **Lab 2**: Delves into memory management and interfacing I/O devices with 8086, including the use of decoders and the 8255 programmable peripheral interface.
- **Lab 3**: Explores the use of hardware timers (8253) and interrupt controllers (8259) with 8086, focusing on controlling external devices like LEDs.
- **Lab 4**: Introduces the ARM Cortex-M4 architecture, working with assembly programming and GPIO interfacing on the STM32F401.
- **Lab 5**: Covers interfacing an LCD with the STM32 microcontroller, alongside generating and controlling PWM signals.
- **Lab 6**: Demonstrates the use of timers and external interrupts on STM32, combining them with LCD displays and PWM control for real-time applications.

Each lab builds on core concepts of microprocessor and microcontroller programming, preparing students for real-world embedded systems development.
