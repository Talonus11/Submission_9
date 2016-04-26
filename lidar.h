/* *****************************************************************************************************
 * FILE NAME: lidar.h
 * Description: This is the header file for 'Lidar' Class. It contains the declaration of the class and it members
 * RITESH KUMAR - 11656978
 * 41012 PROGRAMMING FOR MECHATRONIC SYSTEM
 * ASSESSMENT 1: DEVELOPING SENSOR CLASS
 * UTS 2016 SESSION 1
 *
 * OBJECTIVE: DEVELOP A MOCK SENSOR CLASS THAT ENCAPSULATES ATTRIBUTES OF A SPECIFIC SENSOR
 *
 * *****************************************************************************************************/

#ifndef LIDAR_H
#define LIDAR_H

using namespace std;
#include <string>		/* string, c_str()*/
#include <cstdio>		/* puts(), printf() */
#include <iostream>		/* cout, cin, */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>		/* clock_t, time_t, clock()*/


#define PORT_PREFIX "/dev/ttyACM"

class Lidar
{
    /*********************************************************************************
     * PRIVATE CLASS DATA MEMBERS and METHODS
     *
     * ******************************************************************************/

    std::string model_;
    unsigned int baud_;
    unsigned int port_;
    unsigned int fieldOfView_;
    double angRes_;
    unsigned int scanningTime_;
    double maxDistance_;          // Maximum D
    double minDistance_;          // Minimum Distance for the Sensor
    unsigned int sampleSize_;           // Sample Size of the generated scan data

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::random_double_generator - This is private class Method used for generating random double numbers within the set sensor range
    /// \return - (double) random value within range of the sensor minimum and maximum distance (in meters)
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    double random_double_generator();

    /***********************************************************************************
     *  LiDAR Sensor accptable values
     *
     * These private varibles can modified in the headers files rather than going through
     * the implementation source files for differnt functions if the this class was to be
     * with a different sensor.
     *
     * NOTE: -variable name ending with *1_ are used as defualt value
     *       -these are constant variable
     * *********************************************************************************/
    const std::string  model1_ = "UTM-XXL";     // Default Model of the Sensor
    const unsigned int baud1_ = 38400;          // Default Baud Rate of the Sensor
    const unsigned int baud2_ = 115200;
    const unsigned int port1_ = 0;              // Default Port of the Sensor
    const unsigned int port2_ = 1;
    const unsigned int port3_ = 2;
    const unsigned int fieldOfView1_ = 180;     // Field of View (in degrees) of the UTM-XXL sensor
    const double angRes1_ = 0.5;                // Default Angular Resolution (in degrees) of the the sensor
    const double angRes2_ = 1.0;
    const unsigned int scanningTime1_ = 50;     // Default Scanning Time (in millisecond/scan) of the sensor
    const unsigned int scanningTime2_ = 25;
    const double minRange = 0.2;                //
    const double maxRange = 8.0;

public:

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
    Lidar();


    /******************************************************************************************************
     * ---------------------------- SETTER ClASS METHODS---------------------------------------------------
     * ***************************************************************************************************/

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::setPort - This function sets the Port of the sensor
    /// \param port - (unsigned int argument) this value  has to be either 0,1 or 2
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    void setPort(unsigned int port);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::setBaud - This function sets the Baud of the sensor
    /// \param baud - (unsigned int argument) this value has to be either 38400 or 115200
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void setBaud(unsigned int baud);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::setAngRes - this class method sets the angle resolution of the sensor
    /// \param angRes - (double argument) angle resolution of the sensor (in degrees). should be either 0.5 or 1.0
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    void setAngRes(double angRes);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::setScanningTime - this class method set the scanning time of the sensor (time required to complete 1 scan)
    /// \param scanningTime - (unsigned int argument) scanning time of the sensor (in milliseconds) should be either 25 or 50
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void setScanningTime(unsigned int scanningTime);

    /******************************************************************************************************
     * ---------------------------- GETTER ClASS METHODS---------------------------------------------------
     * ***************************************************************************************************/

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getModel - This method returns the Model of the Sensor
    /// \return - (std::string) sensor Model
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    std::string getModel() const;

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getBaud - This method returns the Baud Rate Parameter of the Sensor
    /// \return - (unsigned int) Buad Rate for the Sensor (either 38400 or 115000)
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int getBaud() const;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getPort - This method returns the Port Parameter of the Sensor
    /// \return - (unsigned int) Port of the Sensor (either 0, 1 or 2 )
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int getPort() const;

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getFieldOfView - This method returns the Field of View Parameter of the Sensor
    /// \return - (unsigned int) Sensors field of veiw in degress
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int getFieldOfView() const;

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getAngRes - This method returns the Angular Resolution Parameter of the Sensor
    /// \return - (double) Sensors angular resolution in degrees
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    double getAngRes() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getScanningTime - This method returns the Scanning Time Parameter of the Sensor
    /// \return - (unsigned int) Sensors scanning time (in milliscond)
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int getScanningTime() const;

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getMinRange - This method returns the minimum Distance Parameter of the Sensor
    /// \return - (double) Sensors minimum range (in meters)
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    double getMinRange() const;

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getMaxRange - This method returns the maximum Distance Parameter of the Sensor
    /// \return - (double) Sensors maximum range (in meters)
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    double getMaxRange() const;

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getSampleSize - This method returns the sample size of data produced by the Sensor
    /// \return - (unsigned int) sample size of the data produced by the sensor
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int getSampleSize() const;

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Lidar::getScanData - This method is used for populating the sensors data array
    /// \param arr - (double*) This argument is pointer to an array for storing scan data
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    void getScanData(double* array);

};

#endif // LIDAR_H
