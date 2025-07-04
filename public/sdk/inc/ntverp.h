/****************************************************************************
 *                                                                          *
 *      ntverp.H        -- Version information for internal builds          *
 *                                                                          *
 *      This file is only modified by the official builder to update the    *
 *      VERSION, VER_PRODUCTVERSION, VER_PRODUCTVERSION_STR and             *
 *      VER_PRODUCTBETA_STR values.                                         *
 *                                                                          *
 ****************************************************************************
/*--------------------------------------------------------------*/
/* the following values should be modified by the official      */
/* builder for each build                                       */
/*                                                              */
/* the VER_PRODUCTBUILD lines must contain the product          */
/* comments and end with the build#<CR><LF>                     */
/*                                                              */
/* the VER_PRODUCTBETA_STR lines must  contain the product      */
/* comments and end with "some string"<CR><LF>                  */
/*--------------------------------------------------------------*/

#if _MSC_VER > 1000
#pragma once
#endif

#define VER_PRODUCTBUILD            /* NT */   16363
// 16bit integer overflow in productbuild (16384), will change to 27695 once thats fixed
#define VER_PRODUCTBUILD_QFE        0

#if defined(NASHVILLE)
// IE components now use NT's VER_PRODUCTBUILD, but define other different major/minor version #'s
#include <ieverp.h>
#else

#define VER_PRODUCTCYCLEVERSION     "21H2"
#define VER_PRODUCTMAJORVERSION     10
#define VER_PRODUCTMINORVERSION     0

#define VER_PRODUCTBETA_STR         /* NT */     ""

#define VER_PRODUCTVERSION_MAJORMINOR2(x,y) #x "." #y
#define VER_PRODUCTVERSION_MAJORMINOR1(x,y) VER_PRODUCTVERSION_MAJORMINOR2(x, y)
#define VER_PRODUCTVERSION_STRING   VER_PRODUCTVERSION_MAJORMINOR1(VER_PRODUCTMAJORVERSION, VER_PRODUCTMINORVERSION)

#define LVER_PRODUCTVERSION_MAJORMINOR2(x,y) L#x L"." L#y
#define LVER_PRODUCTVERSION_MAJORMINOR1(x,y) LVER_PRODUCTVERSION_MAJORMINOR2(x, y)
#define LVER_PRODUCTVERSION_STRING  LVER_PRODUCTVERSION_MAJORMINOR1(VER_PRODUCTMAJORVERSION, VER_PRODUCTMINORVERSION)

#define VER_PRODUCTVERSION          VER_PRODUCTMAJORVERSION,VER_PRODUCTMINORVERSION,VER_PRODUCTBUILD,VER_PRODUCTBUILD_QFE
#define VER_PRODUCTVERSION_W        (0x0502)
#define VER_PRODUCTVERSION_DW       (0x05020000 | VER_PRODUCTBUILD)

/*--------------------------------------------------------------*/
/* this value is used by third party drivers build with the DDK */
/* and internally, to avoid version number conflicts.           */
/*--------------------------------------------------------------*/
#define VER_DDK_PRODUCTVERSION       5,02
#define VER_DDK_PRODUCTVERSION_STR  "5.02"

#endif

#if     (VER_PRODUCTBUILD < 10)
#define VER_BPAD "000"
#elif   (VER_PRODUCTBUILD < 100)
#define VER_BPAD "00"
#elif   (VER_PRODUCTBUILD < 1000)
#define VER_BPAD "0"
#else
#define VER_BPAD
#endif

#if     (VER_PRODUCTBUILD < 10)
#define LVER_BPAD L"000"
#elif   (VER_PRODUCTBUILD < 100)
#define LVER_BPAD L"00"
#elif   (VER_PRODUCTBUILD < 1000)
#define LVER_BPAD L"0"
#else
#define LVER_BPAD
#endif

#define VER_PRODUCTVERSION_STR2(x,y) VER_PRODUCTVERSION_STRING "." VER_BPAD #x "." #y
#define VER_PRODUCTVERSION_STR1(x,y) VER_PRODUCTVERSION_STR2(x, y)
#define VER_PRODUCTVERSION_STR       VER_PRODUCTVERSION_STR1(VER_PRODUCTBUILD, VER_PRODUCTBUILD_QFE)

#define LVER_PRODUCTVERSION_STR2(x,y) LVER_PRODUCTVERSION_STRING L"." LVER_BPAD L#x L"." L#y
#define LVER_PRODUCTVERSION_STR1(x,y) LVER_PRODUCTVERSION_STR2(x, y)
#define LVER_PRODUCTVERSION_STR       LVER_PRODUCTVERSION_STR1(VER_PRODUCTBUILD, VER_PRODUCTBUILD_QFE)
/*--------------------------------------------------------------*/
/* the following section defines values used in the version     */
/* data structure for all files, and which do not change.       */
/*--------------------------------------------------------------*/

/* default is nodebug */
#if DBG
#define VER_DEBUG                   VS_FF_DEBUG
#else
#define VER_DEBUG                   0
#endif

/* default is prerelease */
#if BETA
#define VER_PRERELEASE              VS_FF_PRERELEASE
#else
#define VER_PRERELEASE              0
#endif

#if OFFICIAL_BUILD
#define VER_PRIVATE                 0
#else
#define VER_PRIVATE                 VS_FF_PRIVATEBUILD
#endif

#define VER_FILEFLAGSMASK           VS_FFI_FILEFLAGSMASK
#define VER_FILEOS                  VOS_NT_WINDOWS32
#define VER_FILEFLAGS               (VER_PRERELEASE|VER_DEBUG|VER_PRIVATE)

// @@BEGIN_DDKSPLIT
#if 0
// @@END_DDKSPLIT
#define VER_COMPANYNAME_STR         "Windows (R) Server 2003 DDK provider"
#define VER_PRODUCTNAME_STR         "Windows (R) Server 2003 DDK driver"
#define VER_LEGALTRADEMARKS_STR     \
"Windows (R) is a registered trademark of Microsoft Corporation."
// @@BEGIN_DDKSPLIT
#else

#define VER_COMPANYNAME_STR         "Microsoft Corporation"
#ifdef RC_INVOKED
#define VER_PRODUCTNAME_STR         L"Microsoft\256 Windows\256 Operating System"
#else
#define VER_PRODUCTNAME_STR         "Microsoft\256 Windows\256 Operating System"
#endif
#define VER_LEGALTRADEMARKS_STR     \
"Microsoft\256 is a registered trademark of Microsoft Corporation. Windows\256 is a registered trademark of Microsoft Corporation."
#endif
// @@END_DDKSPLIT
