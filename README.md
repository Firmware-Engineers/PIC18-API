# Description
The PIC18 API, part of the M8M APIs package, is a piece of software developed at #Firmware Engineers for the #IoT Solution Demo project.
This API will be used to control the IoT devices based on a PIC18 microcontroller. The map diagram below shows the essential part of this software.
![8 bits PIC MCUs APIs](https://user-images.githubusercontent.com/56833496/216124836-c35804fc-3d32-4546-a4b1-8ea82ccd52b8.png)
# Prerequisites
To use this software you need to:
- Install MPLAB X IDE
- C compiler for PIC 18 microcontrollers (ex. XC8)
- Doxygen generator, to generate documentation from source code (optional)

Note: 
```
This API is being developed using:
- MPLAB X IDE V5.30
- XC8 V1.45, V2.36
```

# Usage
This software can be included in any project that uses the PIC18 controller. 
Just include in the source file the header (.h) file corresponding to the peripheral or library to use, as well
as all the associated dependencies (Including library files). 
All the codes are self documenting and all information required to used the software is specified within.
To use the external interrupt input 0 (INT0) for example to generate an interrupt at every RISING edge, here's the source code:

In main.c file :
```
// Include dependencies
#include "../Inc/GPIO.h"
#include "../Inc/Interrupts.h"

main()
{
    EnableInterrupt(MCU_INT_ENABLE | INT0_INT_ENABLE);      // Enable Global and INT0 interrupts
    SetINTxEdgeRising(INT0_INT_EDGE);                       // Generate interrupts on every rising edge on INT0 
    
    while(1)
    {
        
        
    }
 }
```

In ISR.c file:
```
// Include dependencies
#include "../Inc/Interrupts.h"

void interrupt Isr(void)
{
    if(GetInterruptFlag(INT0_INT_FLAG) == INT0_INT_FLAG)
    {
        // Interrupt occured, do something about it
    }
}
```

# Team

This file is currently being developed by the #Firmware-Engineers team. Contributions,
recommendations and any sort of feedback are more than welcome.

# License