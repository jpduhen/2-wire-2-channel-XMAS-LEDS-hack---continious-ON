## XMAS tree with 2 ATTiny's, a WS2812 LED strip and MAX7219 4x8x8 Matrix

parts used:
2 x Digispark ATTiny85
WS2812 LED strip (56 LEDs)
MAX7219 4x8x8 LED Matrix board

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
