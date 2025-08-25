# ARMv8-M TrustZone Labs and Examples

This section provides source code and projects demonstrating **ARMv8-M
TrustZone** concepts on the **NXP LPC55S69 board**.\
All projects are built with **Makefiles** and compiled using
**arm-none-eabi-gcc** to generate secure and non-secure images.

------------------------------------------------------------------------

## 🔐 Project 1 -- Secure ↔ Non-Secure State Transitions

This project demonstrates how execution transitions between **secure**
and **non-secure** states.

### Structure:

-   **Secure Project** -- compiled to generate the **secure image**.\
-   **Non-Secure Project** -- compiled to generate the **non-secure
    image**.

### Key Concepts:

-   Initial state transition from **Secure → Non-Secure** and then back
    to **Secure**.\
-   Debugging low-level TrustZone instructions:
    -   `BXNS` -- branch from secure to non-secure state\
    -   `BLXNS` -- branch with link from secure to non-secure\
    -   `SG` -- secure gateway instruction to return to secure state\
-   Usage of the **SAU (Security Attribution Unit)** to partition memory
    regions and allocate secure vs. non-secure code execution.

------------------------------------------------------------------------

## 🔐 Project 2 -- Non-Secure Requesting Secure Services

This project demonstrates how a **non-secure application** can request
services from the **secure application** running in the secure state.

### Structure:

-   **Secure Service Project** -- implements service functions
    accessible to non-secure code.\
-   **Non-Secure Application Project** -- invokes secure functions
    through the TrustZone gateway.

### Key Concepts:

-   Secure function export and controlled entry from the non-secure
    state.\
-   Usage of the **Secure Gateway (SG)** instruction.\
-   Debugger tracing of non-secure → secure calls.\
-   Memory segmentation configured by **SAU** to ensure proper isolation
    of secure and non-secure regions.

------------------------------------------------------------------------

## ⚙️ Build & Run Instructions

1.  Clone the repository and navigate to the TrustZone labs folder.\

2.  Build the **secure image**:

    ``` bash
    make -C secure
    ```

3.  Build the **non-secure image**:

    ``` bash
    make -C non_secure
    ```

4.  Flash both images to the **NXP LPC55S69 board** using your preferred
    flashing tool.\

5.  Debug the binaries to step through state transitions and verify
    `BXNS`, `BLXNS`, and `SG` instruction execution.

------------------------------------------------------------------------

## 🧩 Learning Outcomes

By completing these labs, you will:\
- Understand **TrustZone security state transitions**.\
- Learn how to configure the **SAU** for memory partitioning.\
- Gain experience debugging **low-level TrustZone instructions**.\
- See how **non-secure code** safely requests services from **secure
applications**.

------------------------------------------------------------------------

# Wadix Technologies
Visit our website: [https://www.wadixtech.com](https://www.wadixtech.com)  
Explore our courses: [https://courses.wadixtech.com](https://courses.wadixtech.com)

