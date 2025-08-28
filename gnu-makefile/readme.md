# Wadix Technologies

Visit our website: [https://www.wadixtech.com](https://www.wadixtech.com)  
Explore our courses: [https://courses.wadixtech.com](https://courses.wadixtech.com)

---

### 1. Supported Makefile Build Rules

- **Clean the project and delete the build directory**:
  ```bash
  make clean
  ```
- **Build the Project**:
  ```bash
  make all
  ```
- **Parallel Build with -jN: N is number of threads to run**:
  ```bash
  make all -j4
  ```

---

### 2. Tools Path to Update
Update the tools path `tools` in `tools.mk`

---

### 3. 📘 Makefile Course Labs — Building Embedded Projects with Make

This lab series is designed to give you practical, hands-on experience with **GNU Make** in the context of embedded systems development.  
You will learn not only the syntax and keywords of Makefiles, but also how to organize and automate builds for real-world embedded projects.

#### 🛠️ What You’ll Learn
1. **Your First Makefile**  
   - Writing a simple Makefile for a minimal embedded project.  
   - Understanding targets, dependencies, and commands.

2. **Makefile Syntax and Keywords**  
   - Variables, functions, pattern rules, and conditionals.  
   - How these constructs simplify repetitive tasks.  

3. **Designing a Minimal Build System**  
   - Structuring a project with multiple source files.  
   - Handling compiler, assembler, and linker calls through Makefile rules.  
   - Using `make` to manage incremental builds and save compilation time.  

#### 🔍 Learning Outcomes
By the end of these labs, you will be able to:
- Write and extend Makefiles tailored for embedded systems.  
- Automate compilation, assembly, and linking steps.  
- Manage dependencies and build options efficiently.  
- Design a clean and minimal build system for embedded projects.  

This course bridges theory with practical lab work, ensuring you can confidently apply Makefile techniques in professional embedded development.
