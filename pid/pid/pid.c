

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from pid.idl using "rtiddsgen".
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

#include "pid.h"

#ifndef NDDS_STANDALONE_TYPE
#include "pidPlugin.h"
#endif

/* ========================================================================= */
const char *pidTYPENAME = "pid";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* pid_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member pid_g_tc_members[3]=
    {

        {
            (char *)"pitch",/* Member name */
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
            (char *)"roll",/* Member name */
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
            (char *)"height",/* Member name */
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
        }
    };

    static DDS_TypeCode pid_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"pid", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            pid_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for pid*/

    if (is_initialized) {
        return &pid_g_tc;
    }

    pid_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    pid_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    pid_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    pid_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    /* Initialize the values for member annotations. */
    pid_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
    pid_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    pid_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    pid_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    pid_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    pid_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    pid_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
    pid_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    pid_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    pid_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    pid_g_tc._data._sampleAccessInfo =
    pid_get_sample_access_info();
    pid_g_tc._data._typePlugin =
    pid_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &pid_g_tc;
}

RTIXCdrSampleAccessInfo *pid_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo pid_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo pid_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &pid_g_sampleAccessInfo;
    }

    pid_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((pid *)NULL)->pitch);

    pid_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((pid *)NULL)->roll);

    pid_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((pid *)NULL)->height);

    pid_g_sampleAccessInfo.memberAccessInfos = 
    pid_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(pid);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            pid_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            pid_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    pid_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &pid_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *pid_get_type_plugin_info()
{
    static RTIXCdrTypePlugin pid_g_typePlugin = 
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
        pid_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        pid_finalize_w_return,
        NULL
    };

    return &pid_g_typePlugin;
}
#endif

RTIBool pid_initialize(
    pid* sample) {
    return pid_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool pid_initialize_ex(
    pid* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return pid_initialize_w_params(
        sample,&allocParams);

}

RTIBool pid_initialize_w_params(
    pid* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->pitch = 0.0f;

    sample->roll = 0.0f;

    sample->height = 0.0f;

    return RTI_TRUE;
}

RTIBool pid_finalize_w_return(
    pid* sample)
{
    pid_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void pid_finalize(
    pid* sample)
{

    pid_finalize_ex(sample,RTI_TRUE);
}

void pid_finalize_ex(
    pid* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    pid_finalize_w_params(
        sample,&deallocParams);
}

void pid_finalize_w_params(
    pid* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void pid_finalize_optional_members(
    pid* sample, RTIBool deletePointers)
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

RTIBool pid_copy(
    pid* dst,
    const pid* src)
{

    if (dst == NULL || src == NULL) {
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
* Configure and implement 'pid' sequence class.
*/
#define T pid
#define TSeq pidSeq

#define T_initialize_w_params pid_initialize_w_params

#define T_finalize_w_params   pid_finalize_w_params
#define T_copy       pid_copy

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

