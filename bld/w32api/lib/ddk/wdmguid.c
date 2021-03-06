/***************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2004-2013 The Open Watcom Contributors. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
*  Description: Implementation of the wdmguid.lib library.
*
**************************************************************************/

#include <windows.h>

/* wdmguid.h */
EXTERN_C const GUID GUID_HWPROFILE_QUERY_CHANGE =
    { 0xCB3A4001, 0x46F0, 0x11D0, { 0xB0, 0x8F, 0x00, 0x60, 0x97, 0x13, 0x05, 0x3F } };
EXTERN_C const GUID GUID_HWPROFILE_CHANGE_CANCELLED =
    { 0xCB3A4002, 0x46F0, 0x11D0, { 0xB0, 0x8F, 0x00, 0x60, 0x97, 0x13, 0x05, 0x3F } };
EXTERN_C const GUID GUID_HWPROFILE_CHANGE_COMPLETE =
    { 0xCB3A4003, 0x46F0, 0x11D0, { 0xB0, 0x8F, 0x00, 0x60, 0x97, 0x13, 0x05, 0x3F } };
EXTERN_C const GUID GUID_DEVICE_INTERFACE_ARRIVAL =
    { 0xCB3A4004, 0x46F0, 0x11D0, { 0xB0, 0x8F, 0x00, 0x60, 0x97, 0x13, 0x05, 0x3F } };
EXTERN_C const GUID GUID_DEVICE_INTERFACE_REMOVAL =
    { 0xCB3A4005, 0x46F0, 0x11D0, { 0xB0, 0x8F, 0x00, 0x60, 0x97, 0x13, 0x05, 0x3F } };
EXTERN_C const GUID GUID_TARGET_DEVICE_QUERY_REMOVE =
    { 0xCB3A4006, 0x46F0, 0x11D0, { 0xB0, 0x8F, 0x00, 0x60, 0x97, 0x13, 0x05, 0x3F } };
EXTERN_C const GUID GUID_TARGET_DEVICE_REMOVE_CANCELLED =
    { 0xCB3A4007, 0x46F0, 0x11D0, { 0xB0, 0x8F, 0x00, 0x60, 0x97, 0x13, 0x05, 0x3F } };
EXTERN_C const GUID GUID_TARGET_DEVICE_REMOVE_COMPLETE =
    { 0xCB3A4008, 0x46F0, 0x11D0, { 0xB0, 0x8F, 0x00, 0x60, 0x97, 0x13, 0x05, 0x3F } };
EXTERN_C const GUID GUID_PNP_CUSTOM_NOTIFICATION =
    { 0xACA73F8E, 0x8D23, 0x11D1, { 0xAC, 0x7D, 0x00, 0x00, 0xF8, 0x75, 0x71, 0xD0 } };
EXTERN_C const GUID GUID_PNP_POWER_NOTIFICATION =
    { 0xC2CF0660, 0xEB7A, 0x11D1, { 0xBD, 0x7F, 0x00, 0x00, 0xF8, 0x75, 0x71, 0xD0 } };
EXTERN_C const GUID GUID_PNP_POWER_SETTING_CHANGE =
    { 0x29C69B3E, 0xC79A, 0x43BF, { 0xBB, 0xDE, 0xA9, 0x32, 0xFA, 0x1B, 0xEA, 0x7E } };
EXTERN_C const GUID GUID_TARGET_DEVICE_TRANSPORT_RELATIONS_CHANGED =
    { 0xFCF528F6, 0xA82F, 0x47B1, { 0xAD, 0x3A, 0x80, 0x50, 0x59, 0x4C, 0xAD, 0x28 } };
EXTERN_C const GUID GUID_BUS_INTERFACE_STANDARD =
    { 0x496B8280, 0x6F25, 0x11D0, { 0xBE, 0xAF, 0x08, 0x00, 0x2B, 0xE2, 0x09, 0x2F } };
EXTERN_C const GUID GUID_PCI_BUS_INTERFACE_STANDARD =
    { 0x496B8281, 0x6F25, 0x11D0, { 0xBE, 0xAF, 0x08, 0x00, 0x2B, 0xE2, 0x09, 0x2F } };
EXTERN_C const GUID GUID_ARBITER_INTERFACE_STANDARD =
    { 0xE644F185, 0x8C0E, 0x11D0, { 0xBE, 0xCF, 0x08, 0x00, 0x2B, 0xE2, 0x09, 0x2F } };
EXTERN_C const GUID GUID_TRANSLATOR_INTERFACE_STANDARD =
    { 0x6C154A92, 0xAACF, 0x11D0, { 0x8D, 0x2A, 0x00, 0xA0, 0xC9, 0x06, 0xB2, 0x44 } };
EXTERN_C const GUID GUID_ACPI_INTERFACE_STANDARD =
    { 0xB091A08A, 0xBA97, 0x11D0, { 0xBD, 0x14, 0x00, 0xAA, 0x00, 0xB7, 0xB3, 0x2A } };
EXTERN_C const GUID GUID_INT_ROUTE_INTERFACE_STANDARD =
    { 0x70941BF4, 0x0073, 0x11D1, { 0xA0, 0x9E, 0x00, 0xC0, 0x4F, 0xC3, 0x40, 0xB1 } };
EXTERN_C const GUID GUID_PCMCIA_BUS_INTERFACE_STANDARD =
    { 0x76173AF0, 0xC504, 0x11D1, { 0x94, 0x7F, 0x00, 0xC0, 0x4F, 0xB9, 0x60, 0xEE } };
EXTERN_C const GUID GUID_ACPI_REGS_INTERFACE_STANDARD =
    { 0x06141966, 0x7245, 0x6369, { 0x46, 0x2E, 0x4E, 0x65, 0x6C, 0x73, 0x6F, 0x6E } };
EXTERN_C const GUID GUID_LEGACY_DEVICE_DETECTION_STANDARD =
    { 0x50FEB0DE, 0x596A, 0x11D2, { 0xA5, 0xB8, 0x00, 0x00, 0xF8, 0x1A, 0x46, 0x19 } };
EXTERN_C const GUID GUID_PCI_DEVICE_PRESENT_INTERFACE =
    { 0xD1B82C26, 0xBF49, 0x45EF, { 0xB2, 0x16, 0x71, 0xCB, 0xD7, 0x88, 0x9B, 0x57 } };
EXTERN_C const GUID GUID_MF_ENUMERATION_INTERFACE =
    { 0xAEB895F0, 0x5586, 0x11D1, { 0x8D, 0x84, 0x00, 0xA0, 0xC9, 0x06, 0xB2, 0x44 } };
EXTERN_C const GUID GUID_REENUMERATE_SELF_INTERFACE_STANDARD =
    { 0x2AEB0243, 0x6A6E, 0x486B, { 0x82, 0xFC, 0xD8, 0x15, 0xF6, 0xB9, 0x70, 0x06 } };
EXTERN_C const GUID GUID_AGP_TARGET_BUS_INTERFACE_STANDARD =
    { 0xB15CFCE8, 0x06D1, 0x4D37, { 0x9D, 0x4C, 0xBE, 0xDD, 0xE0, 0xC2, 0xA6, 0xFF } };
EXTERN_C const GUID GUID_ACPI_CMOS_INTERFACE_STANDARD =
    { 0x3A8D0384, 0x6505, 0x40CA, { 0xBC, 0x39, 0x56, 0xC1, 0x5F, 0x8C, 0x5F, 0xED } };
EXTERN_C const GUID GUID_ACPI_PORT_RANGES_INTERFACE_STANDARD =
    { 0xF14F609B, 0xCBBD, 0x4957, { 0xA6, 0x74, 0xBC, 0x00, 0x21, 0x3F, 0x1C, 0x97 } };
EXTERN_C const GUID GUID_ACPI_INTERFACE_STANDARD2 =
    { 0xE8695F63, 0x1831, 0x4870, { 0xA8, 0xCF, 0x9C, 0x2F, 0x03, 0xF9, 0xDC, 0xB5 } };
EXTERN_C const GUID GUID_PNP_LOCATION_INTERFACE =
    { 0x70211B0E, 0x0AFB, 0x47DB, { 0xAF, 0xC1, 0x41, 0x0B, 0xF8, 0x42, 0x49, 0x7A } };
EXTERN_C const GUID GUID_PCI_EXPRESS_LINK_QUIESCENT_INTERFACE =
    { 0x146CD41C, 0xDAE3, 0x4437, { 0x8A, 0xFF, 0x2A, 0xF3, 0xF0, 0x38, 0x09, 0x9B } };
EXTERN_C const GUID GUID_PCI_EXPRESS_ROOT_PORT_INTERFACE =
    { 0x83A7334A, 0x84C7, 0x4161, { 0x9A, 0x98, 0x60, 0x00, 0xED, 0x0C, 0x4A, 0x33 } };
EXTERN_C const GUID GUID_MSIX_TABLE_CONFIG_INTERFACE =
    { 0x1A6A460B, 0x194F, 0x455D, { 0xB3, 0x4B, 0xB8, 0x4C, 0x5B, 0x05, 0x71, 0x2B } };
EXTERN_C const GUID GUID_PROCESSOR_PCC_INTERFACE_STANDARD =
    { 0x37B17E9A, 0xC21C, 0x4296, { 0x97, 0x2D, 0x11, 0xC4, 0xB3, 0x2B, 0x28, 0xF0 } };
EXTERN_C const GUID GUID_BUS_TYPE_INTERNAL =
    { 0x1530EA73, 0x086B, 0x11D1, { 0xA0, 0x9F, 0x00, 0xC0, 0x4F, 0xC3, 0x40, 0xB1 } };
EXTERN_C const GUID GUID_BUS_TYPE_PCMCIA =
    { 0x09343630, 0xAF9F, 0x11D0, { 0x92, 0xE9, 0x00, 0x00, 0xF8, 0x1E, 0x1B, 0x30 } };
EXTERN_C const GUID GUID_BUS_TYPE_PCI =
    { 0xC8EBDFB0, 0xB510, 0x11D0, { 0x80, 0xE5, 0x00, 0xA0, 0xC9, 0x25, 0x42, 0xE3 } };
EXTERN_C const GUID GUID_BUS_TYPE_ISAPNP =
    { 0xE676F854, 0xD87D, 0x11D0, { 0x92, 0xB2, 0x00, 0xA0, 0xC9, 0x05, 0x5F, 0xC5 } };
EXTERN_C const GUID GUID_BUS_TYPE_EISA =
    { 0xDDC35509, 0xF3FC, 0x11D0, { 0xA5, 0x37, 0x00, 0x00, 0xF8, 0x75, 0x3E, 0xD1 } };
EXTERN_C const GUID GUID_BUS_TYPE_MCA =
    { 0x1C75997A, 0xDC33, 0x11D0, { 0x92, 0xB2, 0x00, 0xA0, 0xC9, 0x05, 0x5F, 0xC5 } };
EXTERN_C const GUID GUID_BUS_TYPE_SERENUM =
    { 0x77114A87, 0x8944, 0x11D1, { 0xBD, 0x90, 0x00, 0xA0, 0xC9, 0x06, 0xBE, 0x2D } };
EXTERN_C const GUID GUID_BUS_TYPE_USB =
    { 0x9D7DEBBC, 0xC85D, 0x11D1, { 0x9E, 0xB4, 0x00, 0x60, 0x08, 0xC3, 0xA1, 0x9A } };
EXTERN_C const GUID GUID_BUS_TYPE_LPTENUM =
    { 0xC4CA1000, 0x2DDC, 0x11D5, { 0xA1, 0x7A, 0x00, 0xC0, 0x4F, 0x60, 0x52, 0x4D } };
EXTERN_C const GUID GUID_BUS_TYPE_USBPRINT =
    { 0x441EE000, 0x4342, 0x11D5, { 0xA1, 0x84, 0x00, 0xC0, 0x4F, 0x60, 0x52, 0x4D } };
EXTERN_C const GUID GUID_BUS_TYPE_DOT4PRT =
    { 0x441EE001, 0x4242, 0x11D5, { 0xA1, 0x84, 0x00, 0xC0, 0x4F, 0x60, 0x52, 0x4D } };
EXTERN_C const GUID GUID_BUS_TYPE_1394 = 
    { 0xF74E73EB, 0x9AC5, 0x45EB, { 0xBE, 0x4D, 0x77, 0x2C, 0xC7, 0x1D, 0xDF, 0xB3 } };
EXTERN_C const GUID GUID_BUS_TYPE_HID =
    { 0xEEAF37D0, 0x1963, 0x47C4, { 0xAA, 0x48, 0x72, 0x47, 0x6D, 0xB7, 0xCF, 0x49 } };
EXTERN_C const GUID GUID_BUS_TYPE_AVC =
    { 0xC06FF265, 0xAE09, 0x48F0, { 0x81, 0x2C, 0x16, 0x75, 0x3D, 0x7C, 0xBA, 0x83 } };
EXTERN_C const GUID GUID_BUS_TYPE_IRDA =
    { 0x7AE17DC1, 0xC944, 0x44D6, { 0x88, 0x1F, 0x4C, 0x2E, 0x61, 0x05, 0x3B, 0xC1 } };
EXTERN_C const GUID GUID_BUS_TYPE_SD =
    { 0xE700CC04, 0x4036, 0x4E89, { 0x95, 0x79, 0x89, 0xEB, 0xF4, 0x5F, 0x00, 0xCD } };
EXTERN_C const GUID GUID_POWER_DEVICE_ENABLE =
    { 0x827C0A6F, 0xFEB0, 0x11D0, { 0xBD, 0x26, 0x00, 0xAA, 0x00, 0xB7, 0xB3, 0x2A } };
EXTERN_C const GUID GUID_POWER_DEVICE_TIMEOUTS =
    { 0xA45DA735, 0xFEB0, 0x11D0, { 0xBD, 0x26, 0x00, 0xAA, 0x00, 0xB7, 0xB3, 0x2A } };
EXTERN_C const GUID GUID_POWER_DEVICE_WAKE_ENABLE =
    { 0xA9546A82, 0xFEB0, 0x11D0, { 0xBD, 0x26, 0x00, 0xAA, 0x00, 0xB7, 0xB3, 0x2A } };
EXTERN_C const GUID GUID_WUDF_DEVICE_HOST_PROBLEM =
    { 0xC43D25BD, 0x9346, 0x40EE, { 0xA2, 0xD2, 0xD7, 0x0C, 0x15, 0xF8, 0xB7, 0x5B } };
EXTERN_C const GUID GUID_PARTITION_UNIT_INTERFACE_STANDARD =
    { 0x52363F5B, 0xD891, 0x429B, { 0x81, 0x95, 0xAE, 0xC5, 0xFE, 0xF6, 0x85, 0x3C } };
