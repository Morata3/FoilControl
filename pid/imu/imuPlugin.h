

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from imu.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef imuPlugin_1928709962_h
#define imuPlugin_1928709962_h

#include "imu.h"

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

#define imuPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

#define imuPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define imuPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define imuPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define imuPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern imu*
imuPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern imu*
imuPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern imu*
imuPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
imuPluginSupport_copy_data(
    imu *out,
    const imu *in);

NDDSUSERDllExport extern void 
imuPluginSupport_destroy_data_w_params(
    imu *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
imuPluginSupport_destroy_data_ex(
    imu *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
imuPluginSupport_destroy_data(
    imu *sample);

NDDSUSERDllExport extern void 
imuPluginSupport_print_data(
    const imu *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
imuPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
imuPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
imuPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
imuPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
imuPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    imu *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
imuPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    imu *out,
    const imu *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
imuPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const imu *sample); 

NDDSUSERDllExport extern RTIBool
imuPlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const imu *sample,
    DDS_DataRepresentationId_t representation);

NDDSUSERDllExport extern RTIBool 
imuPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    imu **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
imuPlugin_deserialize_from_cdr_buffer(
    imu *sample,
    const char * buffer,
    unsigned int length);    
#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport extern DDS_ReturnCode_t
imuPlugin_data_to_string(
    const imu *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    
#endif

NDDSUSERDllExport extern unsigned int 
imuPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
imuPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
imuPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
imuPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
imuPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    imu ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern
struct RTIXCdrInterpreterPrograms *imuPlugin_get_programs();

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
imuPlugin_new(void);

NDDSUSERDllExport extern void
imuPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* imuPlugin_1928709962_h */

