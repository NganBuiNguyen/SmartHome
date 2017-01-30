#include "Timer.h"

char* getTime ()
{
    char* pTime = new char[30];
    memset(pTime, 0, 30 * sizeof(char));
    time_t rawtime;
    tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int year = 1900+timeinfo->tm_year;
    int mon = 1+timeinfo->tm_mon;
    int day = timeinfo->tm_mday;
    int sec = timeinfo->tm_sec;   
    int min = timeinfo->tm_min;   
    int hour =timeinfo->tm_hour;

    std::string yearStr = std::to_string(year);
    std::string monStr = std::to_string(mon);
    std::string dayStr = std::to_string(day);
    std::string secStr = std::to_string(sec);
    std::string minStr = std::to_string(min);
    std::string hourStr = std::to_string(hour);

    strcat(pTime,dayStr.c_str());
    strcat(pTime,"/");
    strcat(pTime,monStr.c_str());
    strcat(pTime,"/");
    strcat(pTime,yearStr.c_str());
    
    
    strcat(pTime,"-");
   
    strcat(pTime,hourStr.c_str());
    strcat(pTime,":");
    strcat(pTime,minStr.c_str());
    strcat(pTime,":");
    strcat(pTime,secStr.c_str());

    return pTime;
}