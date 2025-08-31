# TinyML with TensorFlow Lite Micro & Ethos-NPU  
**Wadix Technologies – Courses, Labs, and Example Projects**

This folder contains the setup and scripts to build and run the **Alif Semiconductor TinyML example projects** using **TensorFlow Lite Micro (TFLM)** with **Arm Ethos-U NPU** acceleration.

---

## 📂 Repository Setup

### 1. Clone Alif Examples Repository
Clone the official Alif example projects into `C:\Alif\`:

```bash
git clone https://github.com/alifsemi/alif_ml-embedded-evaluation-kit.git
```

### 2. Clone Wadix Technologies Labs Repository
Clone Wadix Technologies labs and examples:

```bash
git clone https://github.com/WadixTech/wadixcourses.git
```

---

## 🔧 Project Build Instructions

### Copy Build Scripts
From this folder (`wadixcourses\TinyML-tflm-ethos-npu`), copy the following build directories into the Alif repository (`C:\Alif\alif_ml-embedded-evaluation-kit\`):

- `build_m55_kws_he`  
- `build_m55_img_class_hp`  

---

### 🗣️ KWS (Keyword Spotting) Example Build

1. Navigate to the build directory:
   ```
   C:\Alif\build_m55_kws_he
   ```
2. Run the batch script:
   ```
   cmake_config.bat
   ```
   → Runs the CMake configuration stage and generates Ninja build files.  

3. Build the project:
   ```
   ninja
   ```
   → Builds the project using Ninja build system.  

4. Build artifacts will be generated under:
   ```
   C:\Alif\build_m55_kws_he\bin
   ```
   - `ethos-u-alif_kws.axf`  
   - `ethos-u-alif_kws.bin`  

---

### 🖼️ Image Classification Example Build

1. Navigate to the build directory:
   ```
   C:\Alif\build_m55_img_class_hp
   ```
2. Run the batch script:
   ```
   cmake_config.bat
   ```
   → Runs the CMake configuration stage and generates Ninja build files.  

3. Build the project:
   ```
   ninja
   ```
   → Builds the project using Ninja build system.  

4. Build artifacts will be generated under:
   ```
   C:\Alif\build_m55_img_class_hp\bin
   ```
   - `ethos-u-alif_img_class.axf`  
   - `ethos-u-alif_img_class.bin`  

---

## ▶️ Running the Examples

### Run Prebuilt Images
To quickly run prebuilt images included with this repo:

- **KWS Example:**  
  ```
  wadixcourses\TinyML-tflm-ethos-npu\ethos-u-alif_kws_appkit.bat
  ```

- **Image Classification Example:**  
  ```
  wadixcourses\TinyML-tflm-ethos-npu\ethos-u-alif_img_class_appkit.bat
  ```

### Run Locally Built Images
If you built the projects yourself, copy the generated binaries to the prebuilt images folder:

```
wadixcourses\TinyML-tflm-ethos-npu\Prebuild_images\images
```

Replace the existing files with your freshly built versions:  
- `ethos-u-alif_kws.bin`  
- `ethos-u-alif_img_class.bin`  

---

## 📚 Learn More

Explore more labs, demos, and embedded systems training at:  
- 🌐 [www.wadixtech.com](https://www.wadixtech.com)  
- 🎓 [courses.wadixtech.com](https://courses.wadixtech.com)  
