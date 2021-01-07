

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from gps.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef gpsPlugin_237743012_h
#define gpsPlugin_237743012_h

#include "gps.h"

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

#define gpsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

#define gpsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define gpsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define gpsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define gpsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern gps*
gpsPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern gps*
gpsPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern gps*
gpsPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
gpsPluginSupport_copy_data(
    gps *out,
    const gps *in);

NDDSUSERDllExport extern void 
gpsPluginSupport_destroy_data_w_params(
    gps *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
gpsPluginSupport_destroy_data_ex(
    gps *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
gpsPluginSupport_destroy_data(
    gps *sample);

NDDSUSERDllExport extern void 
gpsPluginSupport_print_data(
    const gps *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
gpsPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
gpsPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
gpsPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
gpsPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
gpsPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    gps *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
gpsPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    gps *out,
    const gps *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
gpsPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const gps *sample); 

NDDSUSERDllExport extern RTIBool
gpsPlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const gps *sample,
    DDS_DataRepresentationId_t representation);

NDDSUSERDllExport extern RTIBool 
gpsPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    gps **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
gpsPlugin_deserialize_from_cdr_buffer(
    gps *sample,
    const char * buffer,
    unsigned int length);    
#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport extern DDS_ReturnCode_t
gpsPlugin_data_to_string(
    const gps *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    
#endif

NDDSUSERDllExport extern unsigned int 
gpsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
gpsPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
gpsPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
gpsPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
gpsPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    gps ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern
struct RTIXCdrInterpreterPrograms *gpsPlugin_get_programs();

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
gpsPlugin_new(void);

NDDSUSERDllExport extern void
gpsPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* gpsPlugin_237743012_h */

