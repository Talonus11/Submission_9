/* *****************************************************************************************************
 * FILE NAME: lidar.cpp
 * Description: This is the implementation file for the 'Lidar' Class
 * RITESH KUMAR - 11656978
 * 41012 PROGRAMMING FOR MECHATRONIC SYSTEM
 * ASSESSMENT 1: DEVELOPING SENSOR CLASS
 * UTS 2016 SESSION 1
 *
 * OBJECTIVE: DEVELOP A MOCK SENSOR CLASS THAT ENCAPSULATES ATTRIBUTES OF A SPECIFIC SENSOR
 *
 * ****************************************************************************************************/

#include <cstdio>		/* puts(), printf() */
#include <iostream>		/* cout, cin, */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>		/* clock_t, time_t, clock()*/
#include <string>		/* string, c_str()*/
#include <unistd.h>     /* usleep() */
#include "lidar.h"      /* Lidar Class*/

/******************************************************************************************************
 * -----------------------------------CLASS CONSTRUCTOR-----------------------------------------------
 * ***************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::Lidar - defualt constructor - defualt values are assigned to the object parameters.
///
/// ASSUMPTION: The defualt LiDAR is the UTM-XXL Model with
///             - 38400 Buad Rate
///             - Connected to Port /dev/ttyACM0
///             - 180 degree field of view
///             - 0.5 degrees angular resolution
///             - 50 milliseconds/scan scanning time
///             - 0.2 meters minimum range
///             - 8.0 meters maximum range
///
/// NOTE: Default Values can be changed on the header file it self
////////////////////////////////////////////////////////////////////////////////////////////////
Lidar::Lidar()
{
    model_ = model1_;
    baud_ = baud1_;
    port_ = port1_;
    fieldOfView_ = fieldOfView1_;
    angRes_ = angRes1_;
    scanningTime_ = scanningTime1_;
    minDistance_ = minRange;
    maxDistance_ = maxRange;
    sampleSize_ =  (double)fieldOfView_ / angRes_;
}

/******************************************************************************************************
 * ---------------------------- SETTER ClASS METHODS---------------------------------------------------
 * ***************************************************************************************************/

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::setPort - This function sets the Port of the sensor
/// \param port - (unsigned int argument) this value  has to be either 0,1 or 2
//////////////////////////////////////////////////////////////////////////////////////////////////////
void Lidar::setPort(unsigned int port)
{
    if((port_ != port) && ((port == port1_)|| (port == port2_)||(port == port3_))) //checks if new values is not same as old value AND checks if the new value is one of the required value
    {
        port_ = port;   // assigne the passed argument to the class member
    }
    else
    {
        if((port != port1_) && (port != port2_)&& (port != port3_))     //check if the value is NOT any of the acceptable values
        {
           port_ = port1_;      //Assign Default Value;
           printf("Input is NOT 0, 1 or 2\n");  //Print Message
           printf("Default Port %s%d has been selected\n",PORT_PREFIX,port1_);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::setBaud - This function sets the Baud of the sensor
/// \param baud - (unsigned int argument) this value has to be either 38400 or 115200
////////////////////////////////////////////////////////////////////////////////////////////////////
void Lidar::setBaud(unsigned int baud)
{
    if((baud_ != baud) && ((baud == baud1_)|| (baud == baud2_))) //checks if new values is not same as old value AND checks if the new value is one of the required value
    {
        baud_ = baud;       // assigne the passed argument to the class member
    }
    else
    {
        if((baud != baud1_) && (baud != baud2_))        //check if the value is NOT any of the acceptable values
        {
           baud_ = baud1_;      //Assign Default Value;
           printf("Input is NOT 38400 or 115000\n");  //Print Message
           printf("Default Baud Rate of %d has been selected\n",baud1_);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::setAngRes - this class method sets the angle resolution of the sensor
/// \param angRes - (double argument) angle resolution of the sensor (in degrees). should be either 0.5 or 1.0
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Lidar::setAngRes(double angRes)
{
    if((angRes_ != angRes) && ((angRes == angRes1_)|| (angRes == angRes2_))) //checks if new values is not same as old value AND checks if the new value is one of the required value
    {
        angRes_ = angRes;       // assigne the passed argument to the class member
        sampleSize_ = ((double)fieldOfView_) / angRes_;   // sample size (used random data generation) is determined based on angle resolution
    }
    else
    {
        if((angRes != angRes1_) && (angRes != angRes2_))    //check if the value is NOT any of the acceptable values
        {
           angRes_ = angRes1_;      //Assign Default Value;
           printf("Input is NOT 0.5 degrees or 1.0 degrees \n");  //Print Message
           printf("Default Angular Resolution %0.1f degree has been selected\n",angRes1_);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::setScanningTime - this class method set the scanning time of the sensor (time required to complete 1 scan)
/// \param scanningTime - (unsigned int argument) scanning time of the sensor (in milliseconds) should be either 25 or 50
////////////////////////////////////////////////////////////////////////////////////////////////////
void Lidar::setScanningTime(unsigned int scanningTime)
{
    if((scanningTime_ != scanningTime) && ((scanningTime == scanningTime1_) || (scanningTime == scanningTime2_))) //checks if new values is not same as old value AND checks if the new value is one of the required value
    {
        scanningTime_ = scanningTime;       // assigne the passed argument to the class member
    }
    else
    {
        if(scanningTime != scanningTime1_ && scanningTime != scanningTime2_)    //check if the value is NOT any of the acceptable values
        {
           scanningTime_ = scanningTime1_;      //Assign Default Value;
           printf("Input is NOT 50 ms/scan or 25 ms/scan \n");       //Print Message
           printf("Default value of %d milliseconds per scan has been selected\n",scanningTime1_);
        }
    }
}

/******************************************************************************************************
 * ---------------------------- GETTER ClASS METHODS---------------------------------------------------
 * ***************************************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getModel - This method returns the Model of the Sensor
/// \return - (std::string) sensor Model
///////////////////////////////////////////////////////////////////////////////////////////////////////
std::string Lidar::getModel() const
{
    return model_;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getBaud - This method returns the Baud Rate Parameter of the Sensor
/// \return - (unsigned int) Buad Rate for the Sensor (either 38400 or 115000)
//////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int Lidar::getBaud() const
{
    return baud_;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getPort - This method returns the Port Parameter of the Sensor
/// \return - (unsigned int) Port of the Sensor (either 0, 1 or 2 )
//////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int Lidar::getPort() const
{
    return port_;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getFieldOfView - This method returns the Field of View Parameter of the Sensor
/// \return - (unsigned int) Sensors field of veiw in degress
/////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int Lidar::getFieldOfView() const
{
    return fieldOfView_;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getAngRes - This method returns the Angular Resolution Parameter of the Sensor
/// \return - (double) Sensors angular resolution in degrees
////////////////////////////////////////////////////////////////////////////////////////////////////
double Lidar::getAngRes() const
{
    return angRes_;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getScanningTime - This method returns the Scanning Time Parameter of the Sensor
/// \return - (unsigned int) Sensors scanning time (in milliscond)
///////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int Lidar::getScanningTime() const
{
    return scanningTime_;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getMinRange - This method returns the minimum Distance Parameter of the Sensor
/// \return - (double) Sensors minimum range (in meters)
///////////////////////////////////////////////////////////////////////////////////////////////////
double Lidar::getMinRange() const
{
    return minDistance_;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getMaxRange - This method returns the maximum Distance Parameter of the Sensor
/// \return - (double) Sensors maximum range (in meters)
///////////////////////////////////////////////////////////////////////////////////////////////////
double Lidar::getMaxRange() const
{
    return maxDistance_;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getSampleSize - This method returns the sample size of data produced by the Sensor
/// \return - (unsigned int) sample size of the data produced by the sensor
///////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int Lidar::getSampleSize() const
{
    return sampleSize_;
}

/******************************************************************************************************
 * ---------------------------- PRIVATE ClASS METHOD--------------------------------------------------
 * ***************************************************************************************************/


////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::random_double_generator - This is private class Method used for generating random double numbers within the set sensor range
/// \return - (double) random value within range of the sensor minimum and maximum distance (in meters)
///////////////////////////////////////////////////////////////////////////////////////////////////
double Lidar::random_double_generator()
{
    double i = (rand() % 4096);         // i equals a value between 0-4095
    i = (i / 4095) * maxDistance_;      // i is scaled to the maximum range of the sensor (in meters)
    if (i <= minDistance_)              // check if i is less than the minium sensor range
    {
        i = minDistance_;               // If less than, then set i = minimum range of the sensor (in meters)
    }
    return i;                           // return i value
}

/******************************************************************************************************
 * ---------------------------- OTHER ClASS METHOD----------------------------------------------------
 * ***************************************************************************************************/

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Lidar::getScanData - This method is used for populating the sensors data array
/// \param arr - (double*) This argument is pointer to an array for storing scan data
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Lidar::getScanData(double* array)
{
    for(unsigned int i = 0; i <= sampleSize_ ; i++)
    {
        array[i] = random_double_generator();     //Populating required number of elements with random generated double number
    }
    usleep(scanningTime_*1000);     // (usleep() takes in microsecond argument). This delays function so it acts like the sensor is in poll mode.
}
