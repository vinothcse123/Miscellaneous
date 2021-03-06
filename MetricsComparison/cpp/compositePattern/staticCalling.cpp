
#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <sys/resource.h>
#include<vector>
#include<algorithm>

/* ================ Start of Metrics measurement code ==================*/

/*
Currently it is supported for linux, for others os it is not supported.
In order for easy copying to measure metrics, all class definitions are handled in single file 
*/

class ElapsedTime
{
private:
    std::string m_startMsg;

public:
    std::chrono::time_point<std::chrono::steady_clock> begin, end;
    unsigned long int m_elapsedTime;

    void start()
    {
        m_elapsedTime = 0;
        begin = std::chrono::steady_clock::now();
    }

    void startAccumulate(const std::string &s)
    {
        m_startMsg = s;
        begin = std::chrono::steady_clock::now();
    }

    void start(const std::string &s)
    {
        m_startMsg = s;
        start();
    }

    ElapsedTime()
    {
        start();
        m_elapsedTime = 0;
    }

    void printTime()
    {
        std::cout << "Elapsed time[" << m_startMsg << "](microseconds): " << m_elapsedTime << std::endl;
    }

    void stop()
    {
        end = std::chrono::steady_clock::now();
        m_elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        std::cout << "Elapsed time[" << m_startMsg <<"](microseconds): " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    }

    void stopAccumulate()
    {
        end = std::chrono::steady_clock::now();
        m_elapsedTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    }

    ~ElapsedTime()
    {
    }
};

class CppMemoryMetrics
{
public:
    //Returns the peak memory usage so far in bytes
    size_t getPeakMemoryUsageInBytes()
    {
        struct rusage rusage;
        getrusage(RUSAGE_SELF, &rusage);
        // rusage.ru_maxrss returns in KB, so coverting to bytes
        return (size_t)(rusage.ru_maxrss * 1024L);
    }

    void printMemoryUsageInKb()
    {
        //V6P - change to macro
        std::cout << "Memory usage(KB): " << getPeakMemoryUsageInBytes() / 1024 << std::endl;
    }
};

class CppCpuMetrics
{
private:
    struct rusage cpuResUsage;
    clock_t m_startCpuTime, m_endCpuTime;
    unsigned long long m_totalCpuTime;

public:
    CppCpuMetrics()
    {
        m_startCpuTime = 0;
        m_endCpuTime = 0;
        m_totalCpuTime = 0;
    }

    // Returns user cpu time from beginning of program to this point
    double getUserCpuTimeInSeconds()
    {
        getrusage(RUSAGE_SELF, &cpuResUsage);
        //tv_usec is microseconds, so dividing by 1000000
        // V6P - change to macro, and use c++ cast
           return (cpuResUsage.ru_utime.tv_sec +  (cpuResUsage.ru_utime.tv_usec / (double)1000000));
    }

    void printUserCpuTimeInSeconds()
    {
        std::cout << "User CPU time(Seconds): " << getUserCpuTimeInSeconds() << std::endl;
    }

    // Returns system cpu time from beginning of program to this point
    double getSystemCpuTimeInSeconds()
    {
        getrusage(RUSAGE_SELF, &cpuResUsage);
        //tv_usec is microseconds, so dividing by 1000000
        // V6P - change to macro, and use c++ cast
           return (cpuResUsage.ru_stime.tv_sec +  (cpuResUsage.ru_stime.tv_usec / (double)1000000));
    }

    void printSystemCpuTimeInSeconds()
    {
        std::cout << "System CPU time(Seconds): " << getSystemCpuTimeInSeconds() << std::endl;
    }

    // Starts the cpu time when this function is called
    void startCpuTime()
    {
        m_startCpuTime = clock();
    }

    // stops the cpu time calculation when this function is called

    void stopCpuTime()
    {
        m_endCpuTime = clock();
        m_totalCpuTime = (m_endCpuTime - m_startCpuTime) / CLOCKS_PER_SEC;
        std::cout << "CPU Time :" << m_totalCpuTime << " seconds" << std::endl;
    }
};

class CppProgramMetrics
{
private:
    ElapsedTime elapsedObj;
    CppCpuMetrics cpuMetrics;
    CppMemoryMetrics memMetrics;

public:
    CppProgramMetrics()
    {
    }

    void start(std::string metricsName)
    {
        elapsedObj.start(metricsName);
    }

    void stop()
    {
        elapsedObj.stop();
        cpuMetrics.printUserCpuTimeInSeconds();
        cpuMetrics.printSystemCpuTimeInSeconds();
        memMetrics.printMemoryUsageInKb();
    }
};

/* ================ End of Metrics measurement code ==================*/



class MyClass1 
{   
    public: 
	void myFunc() {}
};

class MyClass2 
{
    public:
	void myFunc() {}
};


// Driver function
int main()
{

    CppProgramMetrics mainPgmMetrics;
    mainPgmMetrics.start("Main Elapsed Time");

    for(int i=0; i < 100000; i++)
    {
        // Main code goes here
        MyClass1 obj1;
        MyClass2 obj2;
        obj1.myFunc();
        obj2.myFunc();
    }

    mainPgmMetrics.stop();
}
