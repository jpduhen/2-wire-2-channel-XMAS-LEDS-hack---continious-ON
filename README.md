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

To prevent shorting anything, I used Caplan-tape to insulate the ATTiny85-board. As you can see, I used PB1 and PB2 to drive the circuit DVR1 and DRV2 (I leave PB0 because it is used to program the ATTiny85 with the new alternative bootloader, see further down).

![IMG_8565](https://user-images.githubusercontent.com/45515609/209936201-0c2c3915-3cb4-4993-bf12-870d0fa1ef59.jpeg)

I programmed the ATTiny with the code provided here. Out-of-the-box the ATTiny has a 5 sec delay before starting it's program, caused by the micronucleus bootloader waiting in programming mode.
So if you use a standard ATTiny85 the LEDs turn on with a 5 sec delay. I removed the delay by burning a alternative bootloader onto the ATTiny85, by following these steps: 

- Upload Software, download the right tar.gz for your OS:
https://github.com/digistump/DigistumpArduino/tree/master/tools
- unpak thetar.gz file into a folder.
- Download the new bootloader into that unpacked folder also:
https://github.com/micronucleus/micronucleus/blob/v1.11/upgrade/releases/micronucleus-1.11-entry-jumper-pb0-upgrade.hex

To upload the new bootloader in mac OS/Linux open Terminal and change to the unpacked folder and type:

'''
chmod +x micronucleus

./micronucleus micronucleus-1.11-entry-jumper-pb0-upgrade.hex
'''

You now are asked to connect the ATTiny85 and the new bootloader will be installed. To be able to program it, just short pin0 to ground while connecting it to your PC. After programming is succesful, remove the GND-P0 and the program will start without the 5 sec delay. So the lights wil turn on immediately after power on.


### Thanks to 
David Duffy/David_AVD and https://www.da-share.com/circuits/2-wire-led-strings/ for much of this information, and https://bytelude.de/2018/04/20/wie-man-das-5-sekunden-boot-delay-beim-digispark-digistump-attiny85-entfernt/
