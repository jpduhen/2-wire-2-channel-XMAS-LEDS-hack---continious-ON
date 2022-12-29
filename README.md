# Stop 2-wire-2-channel XMAS LEDs from flickering after power off


## Parts used:

1 x Digispark ATTiny85 https://nl.aliexpress.com/item/1005004996090616.html

XMAS LEDs set:
- CZJUTAI powersupply, model JT-ELIFC31V6W-H6-IP44 https://en.jutai.com/Product/72WxlogGSCElsclddsgndy.html
- 2-wire-2-channel LEDstring with 1000 LEDs

![IMG_8564](https://user-images.githubusercontent.com/45515609/209928261-e8caef38-934a-46cf-b2b6-46beef2f015f.jpeg)

The CZJUTAI powersupply has 8 different flicker/blink modes and the (only) one I want, steady ON mode, is selection 8. So every time I turn of the power, next time I turn the power on again I have to manually push the selection-butten 8 times (outside in het wind and rain). I wanted the LEDs to be steady-on, every time I switched on the lights. Should be simple, right?

The 2-wire 2-channel system works by alternating the voltage (in this case 31 VDC). Half of the LEDs are wired one-way, the other half reversed. 

![2-wire-led-type2-300x87](https://user-images.githubusercontent.com/45515609/209933412-566f2e65-3161-4cde-aec2-fed80e0a6c06.png)

By alternating the frequency of the voltage-switching all the different lighteffects are generated. So if you put just a steady 31 VDC on te wires, only half of the LEDs burn. This also means that I have to put a fast alternating voltage on the 2 wires to get all the LEDs burning simultaniously.

![IMG_8548](https://user-images.githubusercontent.com/45515609/209929129-59ca7d4f-bb9b-4bb0-a428-47b8ed94e803.JPG)

After opening up the power supply, this is the bottom side of the PSU / MFC combo PCB. There’s a good amount of clearance between the mains and ELV sides. The IC on the bottom right is a small microcontroller. The voltage switching circuit is like this one (T1 = Q1):

![2-wire-led-driver-300x194](https://user-images.githubusercontent.com/45515609/209936331-91063e6b-cb74-4e8e-ba67-3057bef5965c.png)

It’s a discrete H-bridge employing bipolar transistors. L1 and L2 are the output to the 2-wire LED string. DRV1 and DRV2 are fed from the microcontroller. 
Reprogramming the microcontroller is not an option, I replaced it with the Digispark ATTiny85 board.
The +31 V, -31 V and DRV1 and DRV2 connections are shown in this picture:

![IMG_8554](https://user-images.githubusercontent.com/45515609/209938024-f14ec0bd-b8fb-47d4-87a9-39553bc58920.png)

To prevent shorting anything, I used Caplan-tape to insulate the ATTiny85-board.

![IMG_8565](https://user-images.githubusercontent.com/45515609/209936201-0c2c3915-3cb4-4993-bf12-870d0fa1ef59.jpeg)

I programmed the ATTiny with the code above. Standard there is a 5 sec delay caused by the micronucleus bootloader.
So the LEDs turn on after 5 sec. I removed the delay by burning a alternative bootloader onto the ATTiny85, by following these steps: https://bytelude.de/2018/04/20/wie-man-das-5-sekunden-boot-delay-beim-digispark-digistump-attiny85-entfernt/

New Bootloader (you can upload new programs to the ATTiny85 by shorting pin0 to gnd):

https://github.com/micronucleus/micronucleus/blob/v1.11/upgrade/releases/micronucleus-1.11-entry-jumper-pb0-upgrade.hex

Upload Software:

https://github.com/digistump/DigistumpArduino/tree/master/tools

Download the right tar.gz for your OS and copy the upgrade.hex file in the unzipped tar.gz folder.
To upload the new bootloader in mac OS/Linux open Terminal and change to this directory:
'chmod +x micronucleus



