

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dataControl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef dataControl_1450633175_h
#define dataControl_1450633175_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *controlTYPENAME;

typedef struct control {

    DDS_Float   speed ;
    DDS_Float   longitud ;
    DDS_Float   latitud ;
    DDS_Float   pitch ;
    DDS_Float   roll ;
    DDS_Float   height ;

} control ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* control_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *control_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *control_get_sample_access_info(void);
#endif

DDS_SEQUENCE(controlSeq, control);

NDDSUSERDllExport
RTIBool control_initialize(
    control* self);

NDDSUSERDllExport
RTIBool control_initialize_ex(
    control* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool control_initialize_w_params(
    control* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool control_finalize_w_return(
    control* self);

NDDSUSERDllExport
void control_finalize(
    control* self);

NDDSUSERDllExport
void control_finalize_ex(
    control* self,RTIBool deletePointers);

NDDSUSERDllExport
void control_finalize_w_params(
    control* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void control_finalize_optional_members(
    control* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool control_copy(
    control* dst,
    const control* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* dataControl */

