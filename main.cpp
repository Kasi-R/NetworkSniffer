#include "main.h"

Sniffer RSSniffer;

extern "C" DLL_EXPORT void SetupSniffer()
{
    RSSniffer = Sniffer();
}

extern "C" DLL_EXPORT void SetInterface(int Interf)
{
    RSSniffer.SetInterface(Interf);
}

extern "C" DLL_EXPORT int GetInterface()
{
    return RSSniffer.GetInterface();
}

extern "C" DLL_EXPORT bool Initialize()
{
    return RSSniffer.Initialize();
}

extern "C" DLL_EXPORT void DeInitialize()
{
    RSSniffer.DeInitialize();
}

extern "C" DLL_EXPORT void Start()
{
    RSSniffer.Start();
}

extern "C" DLL_EXPORT void Stop()
{
    RSSniffer.Stop();
}

extern "C" DLL_EXPORT std::string GetIP(std::string Address)
{
    return RSSniffer.GetIP(Address);
}

extern "C" DLL_EXPORT void RemoveDestinationIP(std::string OldIP)
{
    RSSniffer.RemoveDestinationIP(OldIP);
}

extern "C" DLL_EXPORT void RemoveSourceIP(std::string OldIP)
{
    RSSniffer.RemoveSourceIP(OldIP);
}

extern "C" DLL_EXPORT void AddDestinationIP(std::string NewIP)
{
    RSSniffer.AddDestinationIP(NewIP);
}

extern "C" DLL_EXPORT void AddSourceIP(std::string NewIP)
{
    RSSniffer.AddSourceIP(NewIP);
}

extern "C" DLL_EXPORT void FilterIP(bool FilterIPs)
{
    RSSniffer.FilterIP(FilterIPs);
}

extern "C" DLL_EXPORT void ListenSource(bool Listen)
{
    RSSniffer.ListenSource(Listen);
}

extern "C" DLL_EXPORT void ListenDestination(bool Listen)
{
    RSSniffer.ListenDestination(Listen);
}

/*extern "C" DLL_EXPORT void Test()
{
    RSSniffer.Test();
}*/

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
