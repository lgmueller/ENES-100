#include <Enes100Simulation.h>
#include <TankSimulation.h>
#include <math.h>

void setup() 
{
  // put your setup code here, to run once:
  TankSimulation.begin();

  while (!Enes100Simulation.begin()) 
  {
    //Enes100Simulation.println("Unable to start");
  }

  while (!Enes100Simulation.updateLocation())
  {
    Enes100Simulation.println("Unable to update location");
  }

  Enes100Simulation.println(Enes100Simulation.destination.y);
  
  int targetRow = checkRowLocation(Enes100Simulation.destination.y);
  Enes100Simulation.updateLocation();
  moveToRow(targetRow);
  go();
}

void loop() 
{

  //Keep moving forward until you reach an obstacle  
  Enes100Simulation.updateLocation();
  while(Enes100Simulation.readDistanceSensor(1) > .15) 
  {
    Enes100Simulation.updateLocation();
    if (Enes100Simulation.location.x > Enes100Simulation.destination.x)
    {
      stop();
      faceDestination();
      go();
      while (Enes100Simulation.location.y < (Enes100Simulation.destination.y - .125) || Enes100Simulation.location.y > (Enes100Simulation.destination.y + .125))
      {
        Enes100Simulation.updateLocation();
      }
      stop();
      Enes100Simulation.println("Arrived at mission site");
      while(1);
    }
  }
  
  Enes100Simulation.updateLocation();
//Check location of OSV and move based on row location
//Row 1 is top, row 2 is middle, row 3 is bottom
  int row = checkRowLocation(Enes100Simulation.location.y);
  Enes100Simulation.println(Enes100Simulation.location.y);
  if (row == 1)
  {
    moveToRow(2);
  }

  if (row == 2)
  {
    moveToRow(3);
  }

  if (row == 3)
  {
    moveToRow(2);
  }

  Enes100Simulation.updateLocation();
  go();
}

void go()
{
  Enes100Simulation.println("go");
  TankSimulation.setLeftMotorPWM(255);
  TankSimulation.setRightMotorPWM(255);

  Enes100Simulation.updateLocation();
}

int checkRowLocation(double y)
{
  //This function will tell you whether you are in the top, middle, or bottom row
  int row;
  Enes100Simulation.println("check row ");
  if (y <= .667)
  {
    row = 3;
  }

  if (y >= 1.333)
  {
    row = 1;
  }

  if (y < 1.333 && y > .667)
  {
    row = 2;
  }
  Enes100Simulation.println(row);
  return row;
}

void moveToRow(int row)
{
  Enes100Simulation.println("Moving to ");
  Enes100Simulation.println(row);
  
  if (row == 1)
  {
    turn('u');
    go();
    Enes100Simulation.updateLocation();
    while (Enes100Simulation.location.y < 1.5)
    {
      Enes100Simulation.updateLocation();
    }
  }

  if (row == 2)
  {
    if ((Enes100Simulation.location.y) > 1)
    {
      Enes100Simulation.println("MOVING DOWNWARDS");
      turn('d');
      go();
      Enes100Simulation.updateLocation();
      while (Enes100Simulation.location.y > 1)
      {
        Enes100Simulation.updateLocation();
      }
    }

    else
    {
      Enes100Simulation.println("MOVING UPWARDS");
      turn('u');
      go();
      Enes100Simulation.updateLocation();
      while (Enes100Simulation.location.y < 1)
      {
        Enes100Simulation.updateLocation();
      }
    }
  }
  
  if (row == 3)
  {
    turn('d');
    go();
    while (Enes100Simulation.location.y > .5)
    {
      Enes100Simulation.updateLocation();
    }
  }
  
  turn('r');
  Enes100Simulation.println("arrived at ");
  Enes100Simulation.println(checkRowLocation(Enes100Simulation.location.y));

}

void turn(char direction)
{
  Enes100Simulation.println("IMPORTANT");
  int dir = turnDirection(direction);
  int r = 0;
  int l = 0;
  
  if (dir == 0)
  //counter
  {
    r = 255;
    l = -255;
  }
  else if (dir == 1)
  //clock
  {
    r = -255;
    l = 255;
  }
  
  Enes100Simulation.println("Turning ");
  if (direction == 'u')
  {
    TankSimulation.setLeftMotorPWM(r);
    TankSimulation.setRightMotorPWM(l);
    
    while((Enes100Simulation.location.theta) > (3.14 / 2 + .2) || (Enes100Simulation.location.theta) < (3.14 / 2 - .2))
    {
      Enes100Simulation.updateLocation();
    }
  
  }
  
 if (direction == 'd')
  {
    TankSimulation.setLeftMotorPWM(r);
    TankSimulation.setRightMotorPWM(l);

    while((Enes100Simulation.location.theta) < -1 * (3.14 / 2 + .2) || (Enes100Simulation.location.theta) > -1 * (3.14 / 2 - .2))
    {
      Enes100Simulation.updateLocation();
    }
  }

  if (direction == 'l')
  {
    TankSimulation.setLeftMotorPWM(r);
    TankSimulation.setRightMotorPWM(l);

    while((Enes100Simulation.location.theta) > (3.14 + .2) || (Enes100Simulation.location.theta) < (3.14 - .2))
    {
      Enes100Simulation.updateLocation();
    }
  }

  if (direction == 'r')
  {
    TankSimulation.setLeftMotorPWM(r);
    TankSimulation.setRightMotorPWM(l);
    
    while(abs(Enes100Simulation.location.theta) > 0.2)
    {
      Enes100Simulation.updateLocation();
    }
  }

stop();

}

void stop()
{
  TankSimulation.turnOffMotors();
}

int turnDirection(char orientation)
{
  int dir;
  double thetaOSV = convertToLogicalRadians(Enes100Simulation.location.theta);
  double thetaTarget = 0;
  
  if (orientation == 'u')
  {
    thetaTarget = 3.14 / 2;
  }
  else if (orientation == 'l')
  {
    thetaTarget = 3.14;
  }
  
  else if (orientation == 'd')
  {
    thetaTarget = 3.14 / 2 + 3.14;
  }
  
  else if (orientation == 'r')
  {
    thetaTarget = 6.28;
  }
  
  
  Enes100Simulation.println(thetaTarget);
  if (thetaTarget > thetaOSV)
    {
      if ((thetaTarget - thetaOSV) <= 3.14)
      {
        dir = 1;
      }
    
      if ((thetaTarget - thetaOSV) > 3.14)
      {
        dir = 0;
      }
    }

  else
  {
    if ((thetaOSV - thetaTarget) <= 3.14)
    {
      dir = 0;
    }

    else
    {
      dir = 1;
    }
  }
    Enes100Simulation.println(dir);
    return dir;
}
double convertToLogicalRadians(double theta)
{
  if (theta < 0)
  {
    theta = 6.28 - abs(theta);
  }
  else
  {
    theta = theta;
  }
  return theta;
}

void faceDestination()
{
  stop();
  double theta = -1*atan((Enes100Simulation.location.y - Enes100Simulation.destination.y) / (Enes100Simulation.location.x - Enes100Simulation.destination.x));
  while((Enes100Simulation.location.theta) > theta + .2 || (Enes100Simulation.location.theta) < theta - .2)
  {
    TankSimulation.setLeftMotorPWM(255);
    TankSimulation.setRightMotorPWM(-255);
    Enes100Simulation.updateLocation();
  }
}
