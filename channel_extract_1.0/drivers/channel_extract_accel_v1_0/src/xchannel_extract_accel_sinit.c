// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xchannel_extract_accel.h"

extern XChannel_extract_accel_Config XChannel_extract_accel_ConfigTable[];

XChannel_extract_accel_Config *XChannel_extract_accel_LookupConfig(u16 DeviceId) {
	XChannel_extract_accel_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCHANNEL_EXTRACT_ACCEL_NUM_INSTANCES; Index++) {
		if (XChannel_extract_accel_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XChannel_extract_accel_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XChannel_extract_accel_Initialize(XChannel_extract_accel *InstancePtr, u16 DeviceId) {
	XChannel_extract_accel_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XChannel_extract_accel_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XChannel_extract_accel_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

