/****************************** Module Header ******************************\
* Module Name: cmd.res
*
* Copyright (c) 1985-91, Microsoft Corporation
*
* Constants
*
* History:
* 10-24-91      Created.
* 6-24-25       Updated to res (wuigi)
\***************************************************************************/

#include <windows.h>
#include <ntverp.h>

IDI_APPICON             ICON    "console.ico"

#define VER_FILETYPE    VFT_APP
#define VER_FILESUBTYPE VFT2_UNKNOWN
#define VER_FILEDESCRIPTION_STR     "Windows Command Processor"
#define VER_INTERNALNAME_STR        "cmd\0"
#define VER_ORIGINALFILENAME_STR    "Cmd.Exe"

#include "common.ver"

RCINCLUDE cmdmsg.rc