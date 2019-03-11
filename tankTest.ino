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
}

void loop() 
{
  int targetRow = checkRowLocation(Enes100Simulation.destination.y);
  Enes100Simulation.updateLocation();
  moveToRow(targetRow);
  Enes100Simulation.updateLocation();
  //Keep moving forward until you reach an obstacle  
  go();
  while(Enes100Simulation.readDistanceSensor(1) > .15) 
  {
    Enes100Simulation.updateLocation(); 
  }

//Check location of OSV and move based on row location
//Row 1 is top, row 2 is middle, row 3 is bottom
  int row = checkRowLocation(Enes100Simulation.location.y);
  Enes100Simulation.println(row);
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
}

void go()
{
  TankSimulation.setLeftMotorPWM(255);
  TankSimulation.setRightMotorPWM(255);

  Enes100Simulation.updateLocation();
}

int checkRowLocation(int y)
{
  //This function will tell you whether you are in the top, middle, or bottom row
  int row = 0;

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
    Enes100Simulation.println(y);
  return row;
}

void moveToRow(int row)
{
  if (row == 1)
  {
    turn("up");
    go();
    while (Enes100Simulation.location.y < 1.334)
    {
      Enes100Simulation.updateLocation();
    }
  }

  if (row == 2)
  {
    if (checkRowLocation(Enes100Simulation.location.y) > 1)
    {
      turn("down");
      go();
      while (Enes100Simulation.location.y > 1)
      {
        Enes100Simulation.updateLocation();
      }
    }

  else
    {
      turn("up");
      go();
      while (Enes100Simulation.location.y < 1)
      {
        Enes100Simulation.updateLocation();
      }
    }

    turn("right");
  }
  
  if (row == 3)
  {
    turn("down");
    go();
    while (Enes100Simulation.location.y > .667)
    {
      Enes100Simulation.updateLocation();
    }
    turn("right");
  }
}

void turn(String direction)
{
  
  if (direction == "up")
  {
    while((Enes100Simulation.location.theta) > (3.14 / 2 + .2) || (Enes100Simulation.location.theta) < (3.14 / 2 - .2))
    {
      TankSimulation.setLeftMotorPWM(255);
      TankSimulation.setRightMotorPWM(-255);

      Enes100Simulation.updateLocation();
    }
  
  }
  
 if (direction == "down")
  {
    while((Enes100Simulation.location.theta) < -1 * (3.14 / 2 + .2) || (Enes100Simulation.location.theta) > -1 * (3.14 / 2 - .2))
    {
      TankSimulation.setLeftMotorPWM(255);
      TankSimulation.setRightMotorPWM(-255);

      Enes100Simulation.updateLocation();

    }
  }

  if (direction == "left")
  {
    while((Enes100Simulation.location.theta) > (3.14 + .2) || (Enes100Simulation.location.theta) < (3.14 - .2))
    {
      TankSimulation.setLeftMotorPWM(255);
      TankSimulation.setRightMotorPWM(-255);

      Enes100Simulation.updateLocation();

    }
  }

  if (direction == "right")
  {
    while(abs(Enes100Simulation.location.theta) > 0.2)
    {
      TankSimulation.setLeftMotorPWM(255);
      TankSimulation.setRightMotorPWM(-255);
      Enes100Simulation.updateLocation();

    }
  }

TankSimulation.turnOffMotors();

}
