

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from debugger.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef debuggerPlugin_839615754_h
#define debuggerPlugin_839615754_h

#include "debugger.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define debuggerPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

#define debuggerPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define debuggerPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define debuggerPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define debuggerPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern debugger*
debuggerPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern debugger*
debuggerPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern debugger*
debuggerPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
debuggerPluginSupport_copy_data(
    debugger *out,
    const debugger *in);

NDDSUSERDllExport extern void 
debuggerPluginSupport_destroy_data_w_params(
    debugger *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
debuggerPluginSupport_destroy_data_ex(
    debugger *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
debuggerPluginSupport_destroy_data(
    debugger *sample);

NDDSUSERDllExport extern void 
debuggerPluginSupport_print_data(
    const debugger *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
debuggerPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
debuggerPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
debuggerPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
debuggerPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
debuggerPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    debugger *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
debuggerPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    debugger *out,
    const debugger *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
debuggerPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const debugger *sample); 

NDDSUSERDllExport extern RTIBool
debuggerPlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const debugger *sample,
    DDS_DataRepresentationId_t representation);

NDDSUSERDllExport extern RTIBool 
debuggerPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    debugger **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
debuggerPlugin_deserialize_from_cdr_buffer(
    debugger *sample,
    const char * buffer,
    unsigned int length);    
#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport extern DDS_ReturnCode_t
debuggerPlugin_data_to_string(
    const debugger *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    
#endif

NDDSUSERDllExport extern unsigned int 
debuggerPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
debuggerPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
debuggerPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
debuggerPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
debuggerPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    debugger ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern
struct RTIXCdrInterpreterPrograms *debuggerPlugin_get_programs();

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
debuggerPlugin_new(void);

NDDSUSERDllExport extern void
debuggerPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* debuggerPlugin_839615754_h */

