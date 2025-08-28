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

### 3. 🔧 Toolchain Course — Understanding the Embedded Compilation Flow

This course provides a deep dive into how a compiler toolchain transforms human-readable code into a final executable image ready to run on embedded systems.  
You will gain both theoretical and hands-on knowledge of each compilation stage and the tools used to inspect the final build output.

#### 🛠️ Compilation Stages Covered
1. **Preprocessing**  
   - Handling macros, includes, and conditional compilation.  
   - Understanding how header files are expanded before compilation.

2. **Compiling**  
   - Translating preprocessed source code into target-specific assembly.  
   - Exploring how optimization levels (`-O0` to `-O3`) affect the generated code.

3. **Assembling**  
   - Converting assembly instructions into machine code.  
   - Producing relocatable object files (`.o`).

4. **Linking**  
   - Combining multiple object files and libraries into a single executable (`.elf`).  
   - Understanding symbol resolution, relocation, and memory mapping.  
   - Using linker scripts to control memory layout in embedded systems.

#### 🔍 Exploring the Final Image
Beyond building the executable, the course also covers **analysis tools** that help you verify and understand the generated binary, including:
- Inspecting **symbols** and memory addresses.  
- Viewing **disassembly** of the final image.  
- Exploring how functions, variables, and sections are laid out in memory.  

This knowledge is essential for debugging, optimization, and ensuring the reliability of embedded applications.
