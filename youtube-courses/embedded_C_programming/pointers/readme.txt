- To clean the project execute command:
  make clean
  The command will remove the folder build and its content
- To build specific example, use teh following command with the example number to build, here we took as example number 01:
- memory configuration to be used eitehr FLASH or RAM, default is FLASH if no MEMORY_CONIFG option is provided to make command  
  make example_number=01 MEMORY_CONFIG=FLASH all