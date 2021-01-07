

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from pid.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef pid_578915440_h
#define pid_578915440_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *pidTYPENAME;

typedef struct pid {

    DDS_Float   pitch ;
    DDS_Float   roll ;
    DDS_Float   height ;

} pid ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* pid_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *pid_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *pid_get_sample_access_info(void);
#endif

DDS_SEQUENCE(pidSeq, pid);

NDDSUSERDllExport
RTIBool pid_initialize(
    pid* self);

NDDSUSERDllExport
RTIBool pid_initialize_ex(
    pid* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool pid_initialize_w_params(
    pid* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool pid_finalize_w_return(
    pid* self);

NDDSUSERDllExport
void pid_finalize(
    pid* self);

NDDSUSERDllExport
void pid_finalize_ex(
    pid* self,RTIBool deletePointers);

NDDSUSERDllExport
void pid_finalize_w_params(
    pid* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void pid_finalize_optional_members(
    pid* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool pid_copy(
    pid* dst,
    const pid* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* pid */

