// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XCHANNEL_EXTRACT_ACCEL_H
#define XCHANNEL_EXTRACT_ACCEL_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xchannel_extract_accel_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XChannel_extract_accel_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XChannel_extract_accel;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XChannel_extract_accel_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XChannel_extract_accel_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XChannel_extract_accel_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XChannel_extract_accel_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XChannel_extract_accel_Initialize(XChannel_extract_accel *InstancePtr, u16 DeviceId);
XChannel_extract_accel_Config* XChannel_extract_accel_LookupConfig(u16 DeviceId);
int XChannel_extract_accel_CfgInitialize(XChannel_extract_accel *InstancePtr, XChannel_extract_accel_Config *ConfigPtr);
#else
int XChannel_extract_accel_Initialize(XChannel_extract_accel *InstancePtr, const char* InstanceName);
int XChannel_extract_accel_Release(XChannel_extract_accel *InstancePtr);
#endif

void XChannel_extract_accel_Start(XChannel_extract_accel *InstancePtr);
u32 XChannel_extract_accel_IsDone(XChannel_extract_accel *InstancePtr);
u32 XChannel_extract_accel_IsIdle(XChannel_extract_accel *InstancePtr);
u32 XChannel_extract_accel_IsReady(XChannel_extract_accel *InstancePtr);
void XChannel_extract_accel_EnableAutoRestart(XChannel_extract_accel *InstancePtr);
void XChannel_extract_accel_DisableAutoRestart(XChannel_extract_accel *InstancePtr);

void XChannel_extract_accel_Set_src_rows(XChannel_extract_accel *InstancePtr, u32 Data);
u32 XChannel_extract_accel_Get_src_rows(XChannel_extract_accel *InstancePtr);
void XChannel_extract_accel_Set_src_cols(XChannel_extract_accel *InstancePtr, u32 Data);
u32 XChannel_extract_accel_Get_src_cols(XChannel_extract_accel *InstancePtr);
void XChannel_extract_accel_Set_dst_rows(XChannel_extract_accel *InstancePtr, u32 Data);
u32 XChannel_extract_accel_Get_dst_rows(XChannel_extract_accel *InstancePtr);
void XChannel_extract_accel_Set_dst_cols(XChannel_extract_accel *InstancePtr, u32 Data);
u32 XChannel_extract_accel_Get_dst_cols(XChannel_extract_accel *InstancePtr);

void XChannel_extract_accel_InterruptGlobalEnable(XChannel_extract_accel *InstancePtr);
void XChannel_extract_accel_InterruptGlobalDisable(XChannel_extract_accel *InstancePtr);
void XChannel_extract_accel_InterruptEnable(XChannel_extract_accel *InstancePtr, u32 Mask);
void XChannel_extract_accel_InterruptDisable(XChannel_extract_accel *InstancePtr, u32 Mask);
void XChannel_extract_accel_InterruptClear(XChannel_extract_accel *InstancePtr, u32 Mask);
u32 XChannel_extract_accel_InterruptGetEnabled(XChannel_extract_accel *InstancePtr);
u32 XChannel_extract_accel_InterruptGetStatus(XChannel_extract_accel *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
