

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from gps.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef gps_237743012_h
#define gps_237743012_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *gpsTYPENAME;

typedef struct gps {

    DDS_Char *   name ;
    DDS_Char *   datos ;

} gps ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* gps_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *gps_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *gps_get_sample_access_info(void);
#endif

DDS_SEQUENCE(gpsSeq, gps);

NDDSUSERDllExport
RTIBool gps_initialize(
    gps* self);

NDDSUSERDllExport
RTIBool gps_initialize_ex(
    gps* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool gps_initialize_w_params(
    gps* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool gps_finalize_w_return(
    gps* self);

NDDSUSERDllExport
void gps_finalize(
    gps* self);

NDDSUSERDllExport
void gps_finalize_ex(
    gps* self,RTIBool deletePointers);

NDDSUSERDllExport
void gps_finalize_w_params(
    gps* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void gps_finalize_optional_members(
    gps* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool gps_copy(
    gps* dst,
    const gps* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* gps */

