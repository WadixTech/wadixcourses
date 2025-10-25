# Wadix Technologies

Visit our website: [https://www.wadixtech.com](https://www.wadixtech.com)  
Explore our courses: [https://courses.wadixtech.com](https://courses.wadixtech.com)

## Secure Image Build & Load Instructions

### 1. Build the Secure Image
This is the image that should be loaded first. (Refer to the example lab description under the `examples` directory.)

- **Clean**:
  ```bash
  make clean
  ```
- **Build**:
  ```bash
  make all
  ```
- **Download to Flash Device**:
  ```bash
  make download
  ```

## Non-Secure Project Instructions

### 2. Clean the Main Non-Secure Project
Removes the `build` folder and its contents:
```bash
make clean
```

### 3. Build a Specific Example in the Main Non-Secure Project
Replace `<example_number>` with the desired example ID. Example: building `01_ns`:
```bash
make example_number=01_ns all
```

### 4. Load a Specific Example into the Device
Replace `<example_number>` with the desired example ID. Example: loading `01_ns`:
```bash
make example_number=01_ns download
```
