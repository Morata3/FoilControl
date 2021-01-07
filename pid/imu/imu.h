

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from imu.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef imu_1928709962_h
#define imu_1928709962_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *imuTYPENAME;

typedef struct imu {

    DDS_Char *   name ;
    DDS_Char *   datos ;

} imu ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* imu_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *imu_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *imu_get_sample_access_info(void);
#endif

DDS_SEQUENCE(imuSeq, imu);

NDDSUSERDllExport
RTIBool imu_initialize(
    imu* self);

NDDSUSERDllExport
RTIBool imu_initialize_ex(
    imu* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool imu_initialize_w_params(
    imu* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool imu_finalize_w_return(
    imu* self);

NDDSUSERDllExport
void imu_finalize(
    imu* self);

NDDSUSERDllExport
void imu_finalize_ex(
    imu* self,RTIBool deletePointers);

NDDSUSERDllExport
void imu_finalize_w_params(
    imu* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void imu_finalize_optional_members(
    imu* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool imu_copy(
    imu* dst,
    const imu* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* imu */

