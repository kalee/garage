# garage_sensor_rpi
rpi project using garage door sensors to detect movement, and trigger an event, such as play a sound file.

A lot of this project comes from a post on the rpi forums that can be found here:
https://www.raspberrypi.org/forums/viewtopic.php?t=209270

Initially, I wanted to create a scare-a-tron.  Something that would detect trick-or-treaters walking up to the porch, and then play some kind of growling noise, triggered by their passing the garage door sensors.  That is pretty much what is done here.

There are many improvements that can be made.  I am make a system call to call mpg123 to play the mp3 sound file.  This could be C code that interacts with music libraries directly.  This was just easy to implement on a raspberry pi, and quick too.

The call to mpg123 is much quicker than other music players.  Also, when implemented in python code, this seemed to queue the changes, and would play the sound file repeatedly.  In the C implementation, the file plays once, then only again when the beam is interrupted after that, which was the desired result.

I purchased a set of Chamberlin garage door sensors from ebay for about 11 US dollars that included shipping.  I had the other parts for the Model 1B raspberry pi available.

You could do the same with a pi zero, but you would need to add something like a https://www.adafruit.com/product/4037 Adafruit i2c sound bonnet to get sound through an AUX port.
