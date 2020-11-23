

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from debug.idl using "rtiddsgen".
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

#include "debug.h"

#ifndef NDDS_STANDALONE_TYPE
#include "debugPlugin.h"
#endif

/* ========================================================================= */
const char *debugTYPENAME = "debug";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* debug_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member debug_g_tc_members[4]=
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
        }, 
        {
            (char *)"speed",/* Member name */
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
        }
    };

    static DDS_TypeCode debug_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"debug", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            debug_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for debug*/

    if (is_initialized) {
        return &debug_g_tc;
    }

    debug_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    debug_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    debug_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    debug_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    debug_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    /* Initialize the values for member annotations. */
    debug_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
    debug_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debug_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debug_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    debug_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debug_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debug_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
    debug_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debug_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debug_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    debug_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debug_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debug_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debug_g_tc._data._sampleAccessInfo =
    debug_get_sample_access_info();
    debug_g_tc._data._typePlugin =
    debug_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &debug_g_tc;
}

RTIXCdrSampleAccessInfo *debug_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo debug_g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo debug_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &debug_g_sampleAccessInfo;
    }

    debug_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debug *)NULL)->pitch);

    debug_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debug *)NULL)->roll);

    debug_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debug *)NULL)->height);

    debug_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debug *)NULL)->speed);

    debug_g_sampleAccessInfo.memberAccessInfos = 
    debug_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(debug);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            debug_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            debug_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    debug_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &debug_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *debug_get_type_plugin_info()
{
    static RTIXCdrTypePlugin debug_g_typePlugin = 
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
        debug_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        debug_finalize_w_return,
        NULL
    };

    return &debug_g_typePlugin;
}
#endif

RTIBool debug_initialize(
    debug* sample) {
    return debug_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool debug_initialize_ex(
    debug* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return debug_initialize_w_params(
        sample,&allocParams);

}

RTIBool debug_initialize_w_params(
    debug* sample, const struct DDS_TypeAllocationParams_t * allocParams)
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

    sample->speed = 0.0f;

    return RTI_TRUE;
}

RTIBool debug_finalize_w_return(
    debug* sample)
{
    debug_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void debug_finalize(
    debug* sample)
{

    debug_finalize_ex(sample,RTI_TRUE);
}

void debug_finalize_ex(
    debug* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    debug_finalize_w_params(
        sample,&deallocParams);
}

void debug_finalize_w_params(
    debug* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void debug_finalize_optional_members(
    debug* sample, RTIBool deletePointers)
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

RTIBool debug_copy(
    debug* dst,
    const debug* src)
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
    if (!RTICdrType_copyFloat (
        &dst->speed, &src->speed)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'debug' sequence class.
*/
#define T debug
#define TSeq debugSeq

#define T_initialize_w_params debug_initialize_w_params

#define T_finalize_w_params   debug_finalize_w_params
#define T_copy       debug_copy

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

