#pragma once

#include <windows.h>
#include <Kinect.h>

bool LoadV2DLL();
HRESULT WINAPI lGetDefaultKinectSensor(_COM_Outptr_ IKinectSensor** defaultKinectSensor);


