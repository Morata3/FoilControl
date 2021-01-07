

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dataControl.idl using "rtiddsgen".
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

#include "dataControl.h"

#ifndef NDDS_STANDALONE_TYPE
#include "dataControlPlugin.h"
#endif

/* ========================================================================= */
const char *controlTYPENAME = "control";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* control_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member control_g_tc_members[6]=
    {

        {
            (char *)"speed",/* Member name */
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
        }, 
        {
            (char *)"longitud",/* Member name */
            {
                1,/* Representation ID */
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
        }, 
        {
            (char *)"latitud",/* Member name */
            {
                2,/* Representation ID */
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
        }, 
        {
            (char *)"pitch",/* Member name */
            {
                3,/* Representation ID */
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
        }, 
        {
            (char *)"roll",/* Member name */
            {
                4,/* Representation ID */
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
        }, 
        {
            (char *)"height",/* Member name */
            {
                5,/* Representation ID */
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

    static DDS_TypeCode control_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"control", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            control_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for control*/

    if (is_initialized) {
        return &control_g_tc;
    }

    control_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    control_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    control_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    control_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    control_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    control_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    control_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    /* Initialize the values for member annotations. */
    control_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
    control_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    control_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    control_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    control_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    control_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    control_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
    control_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    control_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    control_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    control_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    control_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    control_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[4]._annotations._defaultValue._u.float_value = 0.0f;
    control_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[4]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    control_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[4]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    control_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[5]._annotations._defaultValue._u.float_value = 0.0f;
    control_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[5]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    control_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    control_g_tc_members[5]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    control_g_tc._data._sampleAccessInfo =
    control_get_sample_access_info();
    control_g_tc._data._typePlugin =
    control_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &control_g_tc;
}

RTIXCdrSampleAccessInfo *control_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo control_g_memberAccessInfos[6] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo control_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &control_g_sampleAccessInfo;
    }

    control_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((control *)NULL)->speed);

    control_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((control *)NULL)->longitud);

    control_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((control *)NULL)->latitud);

    control_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((control *)NULL)->pitch);

    control_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((control *)NULL)->roll);

    control_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((control *)NULL)->height);

    control_g_sampleAccessInfo.memberAccessInfos = 
    control_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(control);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            control_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            control_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    control_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &control_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *control_get_type_plugin_info()
{
    static RTIXCdrTypePlugin control_g_typePlugin = 
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
        control_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        control_finalize_w_return,
        NULL
    };

    return &control_g_typePlugin;
}
#endif

RTIBool control_initialize(
    control* sample) {
    return control_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool control_initialize_ex(
    control* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return control_initialize_w_params(
        sample,&allocParams);

}

RTIBool control_initialize_w_params(
    control* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->speed = 0.0f;

    sample->longitud = 0.0f;

    sample->latitud = 0.0f;

    sample->pitch = 0.0f;

    sample->roll = 0.0f;

    sample->height = 0.0f;

    return RTI_TRUE;
}

RTIBool control_finalize_w_return(
    control* sample)
{
    control_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void control_finalize(
    control* sample)
{

    control_finalize_ex(sample,RTI_TRUE);
}

void control_finalize_ex(
    control* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    control_finalize_w_params(
        sample,&deallocParams);
}

void control_finalize_w_params(
    control* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void control_finalize_optional_members(
    control* sample, RTIBool deletePointers)
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

RTIBool control_copy(
    control* dst,
    const control* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyFloat (
        &dst->speed, &src->speed)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->longitud, &src->longitud)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->latitud, &src->latitud)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->pitch, &src->pitch)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->roll, &src->roll)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->height, &src->height)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'control' sequence class.
*/
#define T control
#define TSeq controlSeq

#define T_initialize_w_params control_initialize_w_params

#define T_finalize_w_params   control_finalize_w_params
#define T_copy       control_copy

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

