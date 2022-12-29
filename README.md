## Stop 2-wire-2-channel XMAS LEDs from random flickering after power off

parts used:

1 x Digispark ATTiny85

XMAS LEDs set:
- CZJUTAI powersupply, model JT-ELIFC31V6W-H6-IP44 https://en.jutai.com/Product/72WxlogGSCElsclddsgndy.html
- 2-wire-2-channel LEDstring with 1000 LEDs

![IMG_8564](https://user-images.githubusercontent.com/45515609/209928261-e8caef38-934a-46cf-b2b6-46beef2f015f.jpeg)

The CZJUTAI powersupply has 8 different flicker/blink modes and the (only) one I want, steady ON mode, is selection 8. So every time I turn of the power, next time I turn the power on again I have to manually push the selection-butten 8 times (outside in het wind and rain). I wanted the LEDs to be steady-on, every time I switched on the lights. Should be simple, right?

The 2-wire 2-channel system works by alternating the voltage (in this case 31 VDC). Half of the LEDs are wired one-way, the other half reversed. So by alternating the frequency of the voltage-switching all the different lighteffects are generated. So if you put just a steady 31 VDC on te wires, only half of the LEDs burn. This also means that I have to put a fast alternating voltage on the 2 wires to get all the LEDs burning simultaniously.

After opening up the powersupply, I removed the microcontroller from the circuitboard and replaced it with a Digispark ATTiny85 board.

![IMG_8548](https://user-images.githubusercontent.com/45515609/209929129-59ca7d4f-bb9b-4bb0-a428-47b8ed94e803.JPG)


This is my first project on GitHub. For Xmas I made a nice LED-tree with scrolling best wishes

Problem was how to keep both sketches small enough to be usable in the tiny...ATTiny85
Because it has just 512 bytes of EEPROM memory, I could only use capital letters for scrolling

Scrolling the text itself was an other hurdle to take. The max7219 Matrix board I used has a 90 degree rotation.
So I had to combine serveral sketches to finaly get the job done. Yeeehaah!

I'm using this library
; https://github.com/wayoda/LedControl


The second sketch is used for the second ATTiny connected to the LED strip to make the outline of the xmas tree.
It has some nice patterns to get everyone's attention.

Hope you like it!

![img_8080](https://user-images.githubusercontent.com/45515609/50308323-2ba22780-049b-11e9-9527-6db87fddcc79.jpg)


![img_8075](https://user-images.githubusercontent.com/45515609/50308214-e4b43200-049a-11e9-99c8-837cc73728cb.jpg)


![img_8070](https://user-images.githubusercontent.com/45515609/50307274-3d360000-0498-11e9-997c-61528e27ea76.JPG)
