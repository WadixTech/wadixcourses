# Wadix Technologies

Visit our website: [https://www.wadixtech.com](https://www.wadixtech.com)  
Explore our courses: [https://courses.wadixtech.com](https://courses.wadixtech.com)

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