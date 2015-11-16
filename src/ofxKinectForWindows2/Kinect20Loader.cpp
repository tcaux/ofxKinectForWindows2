#include "Kinect20Loader.h"
#include <assert.h>

HRESULT(WINAPI* __GetDefaultKinectSensor)(_COM_Outptr_ IKinectSensor** defaultKinectSensor) = NULL;

bool LoadV2DLL()
{
    HMODULE kinect20Handle = LoadLibraryW(L"Kinect20.dll");
    if (kinect20Handle == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    __GetDefaultKinectSensor = (HRESULT(WINAPI*)(_COM_Outptr_ IKinectSensor**))GetProcAddress(
        kinect20Handle, "GetDefaultKinectSensor");
    if (__GetDefaultKinectSensor == NULL)
    {
        return false;
    }

    return true;
}

HRESULT WINAPI lGetDefaultKinectSensor(_COM_Outptr_ IKinectSensor** defaultKinectSensor)
{
    if (__GetDefaultKinectSensor == NULL)
    {
        if (!LoadV2DLL())
        {
            assert(false);
            return E_FAIL;
        }
    }

    return __GetDefaultKinectSensor(defaultKinectSensor);
}
