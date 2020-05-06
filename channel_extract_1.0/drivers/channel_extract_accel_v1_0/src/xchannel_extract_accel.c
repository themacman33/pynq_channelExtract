// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xchannel_extract_accel.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XChannel_extract_accel_CfgInitialize(XChannel_extract_accel *InstancePtr, XChannel_extract_accel_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XChannel_extract_accel_Start(XChannel_extract_accel *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_AP_CTRL) & 0x80;
    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XChannel_extract_accel_IsDone(XChannel_extract_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XChannel_extract_accel_IsIdle(XChannel_extract_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XChannel_extract_accel_IsReady(XChannel_extract_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XChannel_extract_accel_EnableAutoRestart(XChannel_extract_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XChannel_extract_accel_DisableAutoRestart(XChannel_extract_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_AP_CTRL, 0);
}

void XChannel_extract_accel_Set_src_rows(XChannel_extract_accel *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_SRC_ROWS_DATA, Data);
}

u32 XChannel_extract_accel_Get_src_rows(XChannel_extract_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_SRC_ROWS_DATA);
    return Data;
}

void XChannel_extract_accel_Set_src_cols(XChannel_extract_accel *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_SRC_COLS_DATA, Data);
}

u32 XChannel_extract_accel_Get_src_cols(XChannel_extract_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_SRC_COLS_DATA);
    return Data;
}

void XChannel_extract_accel_Set_dst_rows(XChannel_extract_accel *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_DST_ROWS_DATA, Data);
}

u32 XChannel_extract_accel_Get_dst_rows(XChannel_extract_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_DST_ROWS_DATA);
    return Data;
}

void XChannel_extract_accel_Set_dst_cols(XChannel_extract_accel *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_DST_COLS_DATA, Data);
}

u32 XChannel_extract_accel_Get_dst_cols(XChannel_extract_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_DST_COLS_DATA);
    return Data;
}

void XChannel_extract_accel_InterruptGlobalEnable(XChannel_extract_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_GIE, 1);
}

void XChannel_extract_accel_InterruptGlobalDisable(XChannel_extract_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_GIE, 0);
}

void XChannel_extract_accel_InterruptEnable(XChannel_extract_accel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_IER);
    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_IER, Register | Mask);
}

void XChannel_extract_accel_InterruptDisable(XChannel_extract_accel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_IER);
    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_IER, Register & (~Mask));
}

void XChannel_extract_accel_InterruptClear(XChannel_extract_accel *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XChannel_extract_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_ISR, Mask);
}

u32 XChannel_extract_accel_InterruptGetEnabled(XChannel_extract_accel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_IER);
}

u32 XChannel_extract_accel_InterruptGetStatus(XChannel_extract_accel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XChannel_extract_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XCHANNEL_EXTRACT_ACCEL_AXILITES_ADDR_ISR);
}

