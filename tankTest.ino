#include <Enes100Simulation.h>
#include <TankSimulation.h>

void setup() {
  // put your setup code here, to run once:
  TankSimulation.begin();

  while (!Enes100Simulation.begin()) 
  {
    Enes100Simulation.println("Unable to start");
  }

  while (!Enes100Simulation.updateLocation())
  {
    Enes100Simulation.println("Unable to update location");
  }

  //while (!Enes100Simulation.retrieveDestination())
  //{
   // Enes100Simulation.println("Unable to get destination"); 
 // }

}

void loop() {
  // put your main code here, to run repeatedly:
  Enes100Simulation.println(Enes100Simulation.location.x);
  while(abs(Enes100Simulation.location.theta) > 0.05) 
  {
  
    TankSimulation.setLeftMotorPWM(255);
    TankSimulation.setRightMotorPWM(-255);

    Enes100Simulation.updateLocation();
    
  }

  TankSimulation.turnOffMotors();

  //Go straight
  TankSimulation.setLeftMotorPWM(255);
  TankSimulation.setRightMotorPWM(255);
 
  while(Enes100Simulation.readDistanceSensor(1) > .3) 
  {
   
    Enes100Simulation.println(Enes100Simulation.readDistanceSensor(1));
    Enes100Simulation.updateLocation();
    
  }

  TankSimulation.turnOffMotors();

  if (Enes100Simulation.location.y > 2)
    {
     
     while(!(Enes100Simulation.location.theta) > -1 * (3.14 / 2 + .05) && !(Enes100Simulation.location.theta) < (3.14 / 2 - .05)) 
       
        {
  
          TankSimulation.setLeftMotorPWM(200);
          TankSimulation.setRightMotorPWM(-200);

          Enes100Simulation.updateLocation();
    
        }

    TankSimulation.turnOffMotors();
    while(Enes100Simulation.location.y > 2)

       {
          TankSimulation.setRightMotorPWM(255);
          TankSimulation.setLeftMotorPWM(255);

          Enes100Simulation.updateLocation();
       }

    while(abs(Enes100Simulation.location.theta) > 0.05) 
       {
  
          TankSimulation.setLeftMotorPWM(255);
          TankSimulation.setRightMotorPWM(-255);

          Enes100Simulation.updateLocation();
    
       }
    }

   else if (Enes100Simulation.location.y < 2)
    {
     
     while(abs(Enes100Simulation.location.theta) > abs(3.14 / 2 + .05)) 
       
        {
  
          TankSimulation.setLeftMotorPWM(255);
          TankSimulation.setRightMotorPWM(-255);

          Enes100Simulation.updateLocation();
    
        }

     while(Enes100Simulation.location.y < 2)

       {
          TankSimulation.setRightMotorPWM(255);
          TankSimulation.setLeftMotorPWM(255);

          Enes100Simulation.updateLocation();
       }

     while(abs(Enes100Simulation.location.theta) > 0.05) 
       
       {
  
          TankSimulation.setLeftMotorPWM(255);
          TankSimulation.setRightMotorPWM(-255);

          Enes100Simulation.updateLocation();
    
       }

     
    }

    
  TankSimulation.setLeftMotorPWM(255);
  TankSimulation.setRightMotorPWM(255);

  while(1);

  TankSimulation.turnOffMotors();
}
