/*
Devansh Vaid, Shahzaib Gill, Md Tahsin Sharif, Mark Rakov

~~~~~~~~~~~Grab and Retrieve Autonomous Lego~~~~~~~~~~~~~
-Robot searches for block
-Upon detection it begins to approach the object
-After clamping onto the object, the robot searches for the disposal site
-Subsequently, after reaching the desired location, the block is dropped
 and the robot continues to search for more blocks
-If no block are found for several rotation or after 10 seconds, the robot
 shuts down as the task has been completed
 
*/
 
 
//speeds change to ensure functionality as needed at each step
void turn()
{
    int n = 0;
    do
    {
        time1[T1] = 0;
        motor[motorA] = -25;
        motor[motorB] = 25;
        while (SensorValue[S1] == 255 && time1[T1] < 15000)
        {}
        n = 0;
        while (SensorValue[S1] != 255 && n<4)
        {
            time1[T1] = 0;
            n = 0;
            nxtDisplayString(1,"%i",SensorValue[S1]);
            wait1Msec(500);
            motor[motorA] = 0;
            motor[motorB] = 0;
            wait1Msec(200);
            if(SensorValue[S1] != 255) /display used for testing
            {
                n++;
                nxtDisplayString(2,"%i",SensorValue[S1]);
                wait1Msec(200);
                if(SensorValue[S1] != 255)
                {
                    n++;
                    nxtDisplayString(3,"%i",SensorValue[S1]);
                    wait1Msec(200);
                    if(SensorValue[S1] != 255)
                    {
                        n++;
                        nxtDisplayString(4,"%i",SensorValue[S1]);
                        wait1Msec(200);
                        if (SensorValue[S1] != 255)
                        {
                            n++;
                            nxtDisplayString(5,"%i",SensorValue[S1]);
                            wait1Msec(200);
                        }
                    }
                }
                wait1Msec(200);
            }
        }
    }while( n < 4  && time1[T1] < 15000);
    //debouncing sensors if false repeat  - and shut off check
}

bool Approach(int objectDistance)
{
    motor[motorA] = -15;//15 to ensure detection accuracy
    motor[motorB] = -15;
    while(SensorValue[S1] > objectDistance &&
          SensorValue[S3] !=1 && SensorValue[S4] !=1)
    {}
    nxtDisplayString(2,"%i",SensorValue[S1]);
    //if stopped due to object then continues in main otherwise false
    if(SensorValue[S3] !=1 && SensorValue[S4] !=1)
    {
        motor[motorA] = 0;
        motor[motorB] = 0;
        wait1Msec(500);
        return true;
    }
    else
    {
        motor[motorA] = 0;
        motor[motorB] = 0;
        wait1Msec(500);
        return false;
    }
}

void clampLift()
{
    nMotorEncoder[motorC] = 0;
    while(nMotorEncoder[motorC] <= 220)
    {
        motor[motorC]=10;
    }
    motor[motorC]= 0;
    wait1Msec(800);
}

void findFlag(int flagDistance)
{
    int i = 0;
    do{
        motor[motorA] = -15;
        motor[motorB] = 15;
        while(SensorValue[S2] == 255)
        {}
        i = 0;
        
        while(SensorValue[S2] != 255 & i==0)
        {
            wait1Msec(1000);
            motor[motorA] = 0;
            motor[motorB] = 0;
            wait1Msec(300);
            
            if (SensorValue[S2] != 255)
            {
                nxtDisplayString(3, "%i",SensorValue[S2]);
                i++;
                wait1Msec(300);
                
                if (SensorValue[S2] != 255)
                {
                    wait1Msec(200);
                    i++;
                    if (SensorValue[S2] != 255)
                    {
                        wait1Msec(200);
                        i++;
                    }
                }
            }
            nxtDisplayString(3, "%i",SensorValue[S2]);
        }
    }while(i < 3);
    
    motor[motorA] = 0;
    motor[motorB] = 0;
    wait1Msec(100);
    motor[motorA] = 20;
    motor[motorB] = 20;
    while(SensorValue[S2] > flagDistance1
          {}
          motor[motorA] = 0;
          motor[motorB] = 0;
          wait1Msec(200);
          }
          void unclamp()
    {
        motor[motorA] = 0;
        motor[motorB] = 0;
        wait1Msec(500);
        while (nMotorEncoder[motorC] >= 0)
        {
            motor[motorC] = -10;
        }
        motor[motorC] = 0;
        wait1Msec(1000);
    }
          
          void Drop()
          //prevent robot from falling into hole -color sensor on front
    {
        motor[motorA] = -25;
        motor[motorB] = 25;
        wait1Msec(3500);
        
        motor[motorA] = -20;
        motor[motorB] = -20;
        
        while(SensorValue[S3] != 1 && SensorValue[S4] != 1);
    }
          
          //////////////////////MAIN///////////////////////
          
          task main()
        {
        SensorType [S1] = sensorSONAR ;
        SensorType [S2] = sensorSONAR	;
        SensorType [S3] = sensorCOLORFULL	;
        SensorType [S4] = sensorCOLORFULL	;
        
        int objectDistance = 12;
        int flagDistance = 35;
        motor[motorA] = 0;
        motor[motorB] = 0;
        
        while (nNxtButtonPressed != 3);
        while (nNxtButtonPressed == 3);
        
        bool robot = true;
        
        do
        {
            turn();
            if (time1[T1]>=10000)
            {
                motor[motorA] = 0;
                motor[motorB] = 0;
                robot=false;
            }
            
            if (robot == true)
            {Approach(objectDistance);
                
                if(Approach(objectDistance))
                {
                    clampLift();
                    findFlag(flagDistance);
                    Drop();
                    unclamp();
                    
                    motor[motorA] = 25;
                    motor[motorB] = 25;
                    wait1Msec (1000);
                    
                    motor[motorA] = -25;
                    motor[motorB] = 25;
                    wait1Msec (1000);
                }
                
                
                else
                {
                    motor[motorA] = 25;
                    motor[motorB] = 25;
                    wait1Msec (1000);
                    
                    motor[motorA] = -25;
                    motor[motorB] = 25;
                    wait1Msec (1000);
                }
            }
            
        }	while (robot == true);
        
        motor[motorA] = 0;
        motor[motorB] = 0;
        wait1Msec(200);
    }
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          

