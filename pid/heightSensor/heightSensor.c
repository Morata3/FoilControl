

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from heightSensor.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "heightSensor.h"

#ifndef NDDS_STANDALONE_TYPE
#include "heightSensorPlugin.h"
#endif

/* ========================================================================= */
const char *heightSensorTYPENAME = "heightSensor";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* heightSensor_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode heightSensor_g_tc_msg_string = DDS_INITIALIZE_STRING_TYPECODE((128));

    static DDS_TypeCode_Member heightSensor_g_tc_members[1]=
    {

        {
            (char *)"msg",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode heightSensor_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"heightSensor", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            heightSensor_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for heightSensor*/

    if (is_initialized) {
        return &heightSensor_g_tc;
    }

    heightSensor_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    heightSensor_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&heightSensor_g_tc_msg_string;

    /* Initialize the values for member annotations. */
    heightSensor_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    heightSensor_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    heightSensor_g_tc._data._sampleAccessInfo =
    heightSensor_get_sample_access_info();
    heightSensor_g_tc._data._typePlugin =
    heightSensor_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &heightSensor_g_tc;
}

RTIXCdrSampleAccessInfo *heightSensor_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo heightSensor_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo heightSensor_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &heightSensor_g_sampleAccessInfo;
    }

    heightSensor_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((heightSensor *)NULL)->msg);

    heightSensor_g_sampleAccessInfo.memberAccessInfos = 
    heightSensor_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(heightSensor);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            heightSensor_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            heightSensor_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    heightSensor_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &heightSensor_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *heightSensor_get_type_plugin_info()
{
    static RTIXCdrTypePlugin heightSensor_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        heightSensor_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        heightSensor_finalize_w_return,
        NULL
    };

    return &heightSensor_g_typePlugin;
}
#endif

RTIBool heightSensor_initialize(
    heightSensor* sample) {
    return heightSensor_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool heightSensor_initialize_ex(
    heightSensor* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return heightSensor_initialize_w_params(
        sample,&allocParams);

}

RTIBool heightSensor_initialize_w_params(
    heightSensor* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->msg = DDS_String_alloc((128));
        RTICdrType_copyStringEx(
            &sample->msg,
            "",
            (128),
            RTI_FALSE);
        if (sample->msg == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->msg != NULL) {
            RTICdrType_copyStringEx(
                &sample->msg,
                "",
                (128),
                RTI_FALSE);
            if (sample->msg == NULL) {
                return RTI_FALSE;
            }
        }
    }

    return RTI_TRUE;
}

RTIBool heightSensor_finalize_w_return(
    heightSensor* sample)
{
    heightSensor_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void heightSensor_finalize(
    heightSensor* sample)
{

    heightSensor_finalize_ex(sample,RTI_TRUE);
}

void heightSensor_finalize_ex(
    heightSensor* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    heightSensor_finalize_w_params(
        sample,&deallocParams);
}

void heightSensor_finalize_w_params(
    heightSensor* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->msg != NULL) {
        DDS_String_free(sample->msg);
        sample->msg=NULL;

    }
}

void heightSensor_finalize_optional_members(
    heightSensor* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool heightSensor_copy(
    heightSensor* dst,
    const heightSensor* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyStringEx (
        &dst->msg, src->msg, 
        (128) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'heightSensor' sequence class.
*/
#define T heightSensor
#define TSeq heightSensorSeq

#define T_initialize_w_params heightSensor_initialize_w_params

#define T_finalize_w_params   heightSensor_finalize_w_params
#define T_copy       heightSensor_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

