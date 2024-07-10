#ifndef _PARSE_DESCRIPTOR_H_
#define _PARSE_DEXCRIPTOR_H_
#include "ch559.h"
#include "type.h"
#include "usbhost.h"
#include "usbdef.h"
extern BOOL ParseDeviceDescriptor(USB_DEV_DESCR *pDevDescr, UINT8 len, USB_HUB_PORT *pUsbDevice);
extern BOOL ParseConfigDescriptor(USB_CFG_DESCR *pCfgDescr, UINT16 len, USB_HUB_PORT *pUsbDevice);
BOOL ParseReportDescriptor(uint8_t *pDescriptor, UINT16 len, INTERFACE *pHidSegStruct);

#endif

