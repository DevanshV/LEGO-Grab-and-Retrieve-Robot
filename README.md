# LEGO Grab and Retrieve Robot
Autonomous Grab and Retrieve Robot made using LEGO Mindstorms and C

![ScreenShot](https://raw.githubusercontent.com/DevanshV/LEGO-Grab-and-Retrieve-Robot/master/Lego%20Robot%20Pictures/full%20robot%202.jpg)

## Tasks Preformed by the Robot
1. Robot searches for blocks by rotating
2. Upon detection it begins to approach the object
3. After clamping onto the object, the robot searches for the disposal site
4. Subsequently, after reaching the desired location, the block is dropped and the robot continues to search for more blocks
6. If no block are found for several rotation or after 10 seconds, the robot shuts down as the task has been completed

## Sensor Configuration
* The code is designed to work with 2 ultrasonic sensors and 2 light intensity sensors
* The ultrasonic sensors should be placed so that one can detect **blocks** _(Placed lower and closer to the ground)_, while the other can detect the **disposal location** _(location marked by a flag 30cm high)_

### Contraints and Limitation 
The Lego MindStorms limited the number of motors that can be connected and operated at one time. Thus, to operate the clamp mechanism with one motor
a gear system was designed to operate two clamps symmetrically. <br />
![ScreenShot](https://raw.githubusercontent.com/DevanshV/LEGO-Grab-and-Retrieve-Robot/master/Lego%20Robot%20Pictures/Clamping%20mechanism%202.jpg)
![ScreenShot](https://raw.githubusercontent.com/DevanshV/LEGO-Grab-and-Retrieve-Robot/master/Lego%20Robot%20Pictures/Clamping%20mechanism.jpg)
![ScreenShot](https://raw.githubusercontent.com/DevanshV/LEGO-Grab-and-Retrieve-Robot/master/Lego%20Robot%20Pictures/Clamping%20mechanism.jpg)
![ScreenShot](https://raw.githubusercontent.com/DevanshV/LEGO-Grab-and-Retrieve-Robot/master/Lego%20Robot%20Pictures/robot%20after%20clamp%20.jpg)

## Block designs
Various block designs were tested to optimize sensor detection. Overall, flat surfaces are best detected by the ultrasonic sensors as expected
![ScreenShot](https://raw.githubusercontent.com/DevanshV/LEGO-Grab-and-Retrieve-Robot/master/Lego%20Robot%20Pictures/various%20clamp%20designs.jpg)
