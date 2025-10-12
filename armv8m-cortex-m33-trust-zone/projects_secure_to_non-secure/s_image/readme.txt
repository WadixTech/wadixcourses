1- Build the non-secure image to be loaded first (please see the example lab description under examples directory)
   command to clean: make clean
   command to build: make all
   command to download the secure image to the flash device: make download

2- To clean the main secure project execute command:
  make clean
  The command will remove the folder build and its content
  
3- To build specific example in main secure project, use the following command with the example number to build, here we took as example number 01_s: 
  make example_number=01_s all
  
4- To load main secure project into device (example 01_s)
  make example_number=01_s download
  
 