

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from debugger.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef debugger_839615754_h
#define debugger_839615754_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *debuggerTYPENAME;

typedef struct debugger {

    DDS_Float   speed ;
    DDS_Float   longitud ;
    DDS_Float   latitud ;
    DDS_Float   pitch ;
    DDS_Float   roll ;
    DDS_Float   height ;

} debugger ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* debugger_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *debugger_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *debugger_get_sample_access_info(void);
#endif

DDS_SEQUENCE(debuggerSeq, debugger);

NDDSUSERDllExport
RTIBool debugger_initialize(
    debugger* self);

NDDSUSERDllExport
RTIBool debugger_initialize_ex(
    debugger* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool debugger_initialize_w_params(
    debugger* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool debugger_finalize_w_return(
    debugger* self);

NDDSUSERDllExport
void debugger_finalize(
    debugger* self);

NDDSUSERDllExport
void debugger_finalize_ex(
    debugger* self,RTIBool deletePointers);

NDDSUSERDllExport
void debugger_finalize_w_params(
    debugger* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void debugger_finalize_optional_members(
    debugger* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool debugger_copy(
    debugger* dst,
    const debugger* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* debugger */

