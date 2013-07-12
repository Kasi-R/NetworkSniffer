#include <iostream>
#include <windows.h>
#include <stdexcept>

typedef void __stdcall (*ptr_SetupSniffer)();
typedef void __stdcall (*ptr_SetInterface)(int Interf);
typedef int __stdcall (*ptr_GetInterface)();
typedef bool __stdcall (*ptr_Initialize)();
typedef void __stdcall (*ptr_DeInitialize)();
typedef void __stdcall (*ptr_Start)();
typedef void __stdcall (*ptr_Stop)();
typedef void __stdcall (*ptr_RemoveSourceIP)(std::string OldIP);
typedef void __stdcall (*ptr_RemoveDestinationIP)(std::string OldIP);
typedef void __stdcall (*ptr_AddDestinationIP)(std::string NewIP);
typedef void __stdcall (*ptr_AddSourceIP)(std::string NewIP);
typedef void __stdcall (*ptr_FilterIP)(bool FilterIPs);
typedef void __stdcall (*ptr_ListenSource)(bool Listen);
typedef void __stdcall (*ptr_ListenDestination)(bool Listen);
typedef std::string __stdcall (*ptr_GetIP)(std::string Address);

typedef void __stdcall (*ptr_Test)();

int main()
{
    HMODULE SockDll = LoadLibrary("NetworkSniffer.dll");
    if (SockDll != NULL)
    {
        ptr_SetupSniffer SetupSniffer = (ptr_SetupSniffer)GetProcAddress(SockDll, "SetupSniffer");
        ptr_SetInterface SetInterface = (ptr_SetInterface)GetProcAddress(SockDll, "SetInterface");
        ptr_GetInterface GetInterface = (ptr_GetInterface)GetProcAddress(SockDll, "GetInterface");
        ptr_Initialize Initialize = (ptr_Initialize)GetProcAddress(SockDll, "Initialize");
        ptr_DeInitialize DeInitialize = (ptr_DeInitialize)GetProcAddress(SockDll, "DeInitialize");
        ptr_Start Start = (ptr_Start)GetProcAddress(SockDll, "Start");
        ptr_Stop Stop = (ptr_Stop)GetProcAddress(SockDll, "Stop");
        ptr_GetIP GetIP = (ptr_GetIP)GetProcAddress(SockDll, "GetIP");
        ptr_RemoveSourceIP RemoveSourceIP = (ptr_RemoveSourceIP)GetProcAddress(SockDll, "RemoveSourceIP");
        ptr_RemoveDestinationIP RemoveDestinationIP = (ptr_RemoveDestinationIP)GetProcAddress(SockDll, "RemoveDestinationIP");
        ptr_AddDestinationIP AddDestinationIP = (ptr_AddDestinationIP)GetProcAddress(SockDll, "AddDestinationIP");
        ptr_AddSourceIP AddSourceIP = (ptr_AddSourceIP)GetProcAddress(SockDll, "AddSourceIP");
        ptr_FilterIP FilterIP = (ptr_FilterIP)GetProcAddress(SockDll, "FilterIP");
        ptr_ListenSource ListenSource = (ptr_ListenSource)GetProcAddress(SockDll, "ListenSource");
        ptr_ListenDestination ListenDestination = (ptr_ListenDestination)GetProcAddress(SockDll, "ListenDestination");
        if (SetupSniffer != nullptr)
        {
            try
            {
                SetupSniffer();
                SetInterface(0);
                Initialize();
                AddSourceIP(GetIP("127.0.0.1"));
                AddSourceIP(GetIP("en.wikipedia.org"));
                AddDestinationIP(GetIP("en.wikipedia.org"));
                AddDestinationIP(GetIP("127.0.0.1"));
                ListenSource(true);
                ListenDestination(true);
                FilterIP(true);
                Start();

            }
            catch (std::exception &e)
            {
                std::cout<<"\nERROR: "<<e.what();
                Stop();
                DeInitialize();
            }
        }
    }
    return 0;
}
