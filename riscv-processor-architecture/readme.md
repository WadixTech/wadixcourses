# Wadix Technologies

Visit our website: [https://www.wadixtech.com](https://www.wadixtech.com)  
Explore our courses: [https://courses.wadixtech.com](https://courses.wadixtech.com)

# RISC-V Processor Architecture Labs and Examples

This section provides source code and projects demonstrating **RISC-V
processor architecture concepts** on the **HiFive Rev B board** (32-bit
RISC-V core).\
All projects are **Makefile-based** and can be compiled using the RISC-V
GCC toolchain. Debugging is performed with **Segger Ozone**.

------------------------------------------------------------------------

## 🔐 Example 1 -- Physical Memory Protection (PMP)

This example shows how to **configure and test the RISC-V PMP (Physical
Memory Protection)** unit:

### Key Concepts:

-   Configure PMP registers to create secure memory regions.\
-   Restrict **read / write / execute** access on specific memory
    regions.\
-   Debugging PMP violations to see how the CPU reacts when a
    non-allowed access is attempted.

------------------------------------------------------------------------

## 🔐 Example 2 -- Privilege Mode Switching

This example demonstrates **switching between RISC-V privilege levels**:

### Key Concepts:

-   Transition from **Machine Mode (M-mode)** to **User Mode
    (U-mode)**.\
-   Execute user-level code safely in U-mode.\
-   Return from U-mode back to M-mode via **trap handlers**.\
-   Observe mode switching behavior in the debugger.

------------------------------------------------------------------------

## 🛠️ Development Setup

-   **Board:** HiFive Rev B (RISC-V 32-bit processor)\
-   **Build System:** Makefile projects (`make` based builds)\
-   **Compiler Toolchain:** RISC-V GCC (e.g.,
    `riscv32-unknown-elf-gcc`)\
-   **Debugger/Flashing Tool:** Segger Ozone

------------------------------------------------------------------------

## ⚙️ Project Build Instructions

1.  **Clean the Project**\
    Removes the build folder and its contents:

    ``` bash
    make clean
    ```

2.  **Build a Specific Example**\
    Replace `<example_number>` with the desired example ID. Example:
    building example **01**:

    ``` bash
    make example_number=01 all
    ```

3.  **Download and Debug**\
    Use **Segger Ozone** to load the generated binaries and debug
    execution on the HiFive Rev B board.

------------------------------------------------------------------------

## 🧩 Learning Outcomes

By completing these labs, you will:\
- Understand **how PMP enforces memory protection** in RISC-V.\
- Learn how to **switch between different privilege levels** (M-mode and
U-mode).\
- Gain hands-on experience building and debugging RISC-V baremetal
applications.\
- See how **low-level RISC-V instructions** control system execution and
protection.

------------------------------------------------------------------------
