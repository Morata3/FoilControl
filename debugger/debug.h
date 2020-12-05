

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from debug.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef debug_199379947_h
#define debug_199379947_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *debugTYPENAME;

typedef struct debug {

    DDS_Float   pitch ;
    DDS_Float   roll ;
    DDS_Float   height ;
    DDS_Float   speed ;
    DDS_Float   LeftAngle ;
    DDS_Float   RightAngle ;
    DDS_Float   BackAngle ;

} debug ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* debug_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *debug_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *debug_get_sample_access_info(void);
#endif

DDS_SEQUENCE(debugSeq, debug);

NDDSUSERDllExport
RTIBool debug_initialize(
    debug* self);

NDDSUSERDllExport
RTIBool debug_initialize_ex(
    debug* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool debug_initialize_w_params(
    debug* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool debug_finalize_w_return(
    debug* self);

NDDSUSERDllExport
void debug_finalize(
    debug* self);

NDDSUSERDllExport
void debug_finalize_ex(
    debug* self,RTIBool deletePointers);

NDDSUSERDllExport
void debug_finalize_w_params(
    debug* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void debug_finalize_optional_members(
    debug* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool debug_copy(
    debug* dst,
    const debug* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* debug */

