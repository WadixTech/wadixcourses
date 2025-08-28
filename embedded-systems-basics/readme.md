# Wadix Technologies

Visit our website: [https://www.wadixtech.com](https://www.wadixtech.com)  
Explore our courses: [https://courses.wadixtech.com](https://courses.wadixtech.com)

---

## 📘 Basic Embedded Systems Course Labs

This repository contains the lab examples accompanying the **Embedded Systems Basics Course**.  
The labs provide practical demonstrations of the concepts taught in the course, bridging theory with hands-on work on real microcontrollers.

### 🛠️ Topics and Lab Examples
1. **Debugging a Microcontroller (STM32 MCU)**  
   - Learn to set up a debugger and step through code execution.  
   - Explore how to inspect registers, memory, and variables during runtime.

2. **Configuring and Using the SysTick Timer**  
   - Configure the SysTick peripheral for periodic interrupts.  
   - Generate delays and system ticks for scheduling tasks.

3. **Interrupts on STM32**  
   - Understand interrupt configuration and vector tables.  
   - Generate and handle interrupts in software.  
   - Explore priorities and nested interrupts.

These labs are designed to reinforce the **foundations of embedded programming** while providing direct exposure to hardware-level debugging and peripheral configuration.

---

## Project Build Instructions

### 1. Clean the Project
Removes the `build` folder and its contents:
```bash
make clean
```

### 2. Build a Specific Example
Replace <example_number> with the desired example ID. Example: building 01:
```bash
make example_number=01 all
```

### 3. Memory Configuration
You can specify memory configuration as either `FLASH` or `RAM`.
Default is `FLASH` if no `MEMORY_CONFIG` option is provided:
```bash
make example_number=01 MEMORY_CONFIG=FLASH all
```
