/* *****************************************************************************************************
 * FILE NAME: main.cpp
 * DESCRIPTION: This file contains main program source code.
 * RITESH KUMAR - 11656978
 * 41012 PROGRAMMING FOR MECHATRONIC SYSTEM
 * ASSESSMENT 1: DEVELOPING SENSOR CLASS
 * UTS 2016 SESSION 1
 *
 * OBJECTIVE: DEVELOP A MOCK SENSOR CLASS THAT ENCAPSULATES ATTRIBUTES OF A SPECIFIC SENSOR
 *
 * *************************************************************************************************** */

#include <cstdio>		/* puts(), printf() */
#include <iostream>		/* cout, cin, */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>		/* clock_t, time_t, clock()*/
#include <string>		/* string, c_str()*/
#include <unistd.h>     /* usleep() */
#include "lidar.h"      /* Lidar Class */

using namespace std;

int main()
{
    Lidar myLidar;   // Initialise a default instance of the class Lidar using default constructor

    puts("----------------------------------------------------------------------------------------\n");
    puts("************************** Default Sensor Parameters **********************************\n");
    puts("----------------------------------------------------------------------------------------\n");

    printf("Model: %s \n",myLidar.getModel().c_str());              // Display the Model of the Sensor
    printf("Field of View: %d degrees\n",myLidar.getFieldOfView()); // Display the field of view of the Sensor
    printf("Minimum Distance: %0.1f meters\n", myLidar.getMinRange());  // Display the Minimum Range of the Sensor
    printf("Maximum Distance: %0.1f meters \n", myLidar.getMaxRange()); // Display the Maximum Range of the Sensor
    printf("\n");

    unsigned int uinput = 0;  //variable for saving int user input
    double dinput = 0;        // variable for saving double user input


    puts("----------------------------------------------------------------------------------------\n");
    puts("************************ Sensor Parameter Specification *******************************\n");
    puts("----------------------------------------------------------------------------------------\n");

    puts("Please specify the Sensor Baud Rate: 38400 or 115200");      //Display Message
    cout << "Baud Rate: ";       // Display Message
    cin >> uinput;      //save user input into variable
    myLidar.setBaud(uinput);        // pass in user input to class method of the object
    //printf("Baud Rate is set to %d\n",myLidar.getBaud()); //Displays
    printf("\n");       //Print line break

    printf("Please specify (X) the Port (%sX) of the Sensor: Where X = 0, 1 or 2\n",PORT_PREFIX);       //Display Message with arguments
    cout << "Port: "<<PORT_PREFIX;        //Display Message
    cin >> uinput;      //save user input into variable
    myLidar.setPort(uinput);        // pass in user input to class method of the object
    //printf("Port is set to %s%d \n",PORT_PREFIX,myLidar.getPort());
    printf("\n");       //Print line break

    puts("Please specify the Angular Resolution (degrees) of the Sensor: 0.5 degrees or 1.0 degrees");      //Display Message
    cout << "Angular Resolution: ";      //Display Message
    cin >> dinput;      //save user input into variable
    myLidar.setAngRes(dinput);      // pass in user input to class method of the object
    //printf("Angular Resolution is set to %0.1f degrees\n",myLidar.getAngRes());
    printf("\n");       //Print line break

    puts("Please specify the Scanning Time (ms - milliseconds) of the Sensor: 50 ms/scan or 25 ms/scan");       //Display Message
    cout << "Scanning Time: ";       //Display Message
    cin >> uinput;      //save user input into variable
    myLidar.setScanningTime(uinput);        // pass in user input to class method of the object
    //printf("Scanning Time is set to %d ms\n",myLidar.getScanningTime());
    printf("\n");       //Print line break    

    puts("----------------------------------------------------------------------------------------\n");
    puts("****************************** Sensor Parameters **************************************\n");
    puts("----------------------------------------------------------------------------------------\n");

    printf("Model: %s \n",myLidar.getModel().c_str());              // Display the Model of the Sensor
    printf("Baud Rate: %d \n", myLidar.getBaud());                  // Displat the Baud Rate of the Sensor
    printf("Port: %s%d\n",PORT_PREFIX,myLidar.getPort());           // Display the port address on which the sensor is connected
    printf("Field of View: %d degrees\n",myLidar.getFieldOfView()); // Display the field of view of the Sensor
    printf("Angular Resolution: %0.1f degrees \n", myLidar.getAngRes()); // Display the angular resolution of the sensor
    printf("Scanning Time: %d ms/scan \n",myLidar.getScanningTime());   // Display the scanning time of the scan sensor
    printf("Minimum Distance: %0.1f meters\n", myLidar.getMinRange());  // Display the Minimum Range of the Sensor
    printf("Maximum Distance: %0.1f meters \n", myLidar.getMaxRange()); // Display the Maximum Range of the Sensor
    printf("\n");

    puts("----------------------------------------------------------------------------------------\n");
    puts("**** Please press ENTER key to start to continuously query and display sensor data *****\n");
    puts("----------------------------------------------------------------------------------------\n");

    cin.ignore();       // Clear input steam buffer to ensure it checks keyboard input
    cin.get();          // Wait untill ENTER key is pressed

    double dataArray[361];      //An Array of  361 Elements to hold sensor data
    unsigned int initialisedElements = myLidar.getSampleSize();       // variable to hold the value of number elements intialised during scan
    unsigned long int sequenceNumber = 1;       // variable for trakcing the number of scans
    double angle = 0;                           // Variable
    double angleIncrement = myLidar.getAngRes();        //Veriable to store the Angular Resolution of the Sensor

    while(1)        // loop which continuously queries scan data and displays in on screen
    {
        srand(time(NULL));

        myLidar.getScanData(dataArray); //

        puts("---------------------------------------------------------------------------------\n");
        printf("***************** Sequence Number: %lu Scan DATA STARTING ************************\n",sequenceNumber);
        puts("---------------------------------------------------------------------------------\n");

        for(int i = 0; i <= initialisedElements; i++)       //iterate through the data array for the required number of initialised
        {
            printf("Sequence#: %lu, Element#: %d, Angle: %0.1f [Degrees], Distance: %0.2f [meters]\n",sequenceNumber,i,angle,dataArray[i]);
            angle += angleIncrement;
        }
        puts("---------------------------------------------------------------------------------\n");
        printf("***************** Sequence Number: %lu Scan DATA COMPLETED ***********************\n",sequenceNumber);
        puts("---------------------------------------------------------------------------------\n");


        angle = 0;          // set angle to 0
        sequenceNumber++;   //increment the sequence number after displaying scan data
    }

    return 0;
}

