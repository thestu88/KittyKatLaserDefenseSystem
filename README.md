# KittyKatLaserDefenseSystem
A quick way to distract your cats so you can work.

With the coronavirus outbreak, a lot of people (espeically programmers) are working from home.
This becomes a problem if you have one or more cats that won't leave you alone during the day,
though.  If you have an extra arduino, two servos, and a 5V laser diode available, this can
help.

Attach one servo to the arm of the other.  Attach the laser diode to the second servo's arm.
Wire up the servos to 5V and GND pins, then the signal wires on D9 and D10.
Wire the laser diode's GND to any GND pin, and the power wire to D12 on the arduino.
Power the arduino either via USB or a battery.

The Kitty Kat Lazer Defense System will draw patterns on the ground with the laser to
distract your cats so you can get some work done (or take a nap in peace).

The parameter you pass to zigzag(), square(), etc. is the speed that the servos will move.
Be careful not to pass too low of a value, else the servos might be strained.
