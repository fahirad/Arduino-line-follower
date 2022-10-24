# Arduino-line-follower
Arduino car robot following a black line. 


This is a small project I have finished with my friends in preparation for a competition of this kind.
The goal was to have a car robot that was able to follow a black line on the floor.

## The equipment we used:

~ Arduino uno
~ 2 x DC motor
~ 2 x those generic yellow wheels & one flexible wheel in the front (to move along the ones actually powered by motors)
~ l298n H-bridge
~ 2 x IR sensors
~ Batteries (for the arduino 6V one, and another power supply fashioned in a serial connection of batteries for the power to the bridge, that is the motors)

The idea is very simple. The two IR sensors are mounted at the front side of the car, one on each side (to the width a bit bigger than that of the black line), and in each loop we read the sensors' outputs (that serve as inputs to the arduino). 
If one of them is reading "HIGH" the robot must move in appropriate direction, if none spots black, the robot simply moves forward, and if both spot the black line, the robot should stop. 

