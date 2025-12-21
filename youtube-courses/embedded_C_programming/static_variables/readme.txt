- To clean the project execute command:
  make clean
  The command will remove the folder build and its content
- To build specific example, use teh following command with the example number to build, here we took as example number 00:
  make example_number=00 all
  
- To extract the symbols from and elf image and get the qualifer of each symbol, ex: if a symbol is global or local then:
  arm-none-eabi-readelf -sW example_02.elf > example_02.elf.symbols