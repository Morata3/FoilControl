

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from debugger.idl using "rtiddsgen".
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

#include "debugger.h"

#ifndef NDDS_STANDALONE_TYPE
#include "debuggerPlugin.h"
#endif

/* ========================================================================= */
const char *debuggerTYPENAME = "debugger";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* debugger_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member debugger_g_tc_members[6]=
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

    static DDS_TypeCode debugger_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"debugger", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            debugger_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for debugger*/

    if (is_initialized) {
        return &debugger_g_tc;
    }

    debugger_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    debugger_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    debugger_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    debugger_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    debugger_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    debugger_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    debugger_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    /* Initialize the values for member annotations. */
    debugger_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
    debugger_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debugger_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debugger_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    debugger_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debugger_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debugger_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
    debugger_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debugger_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debugger_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    debugger_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debugger_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debugger_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[4]._annotations._defaultValue._u.float_value = 0.0f;
    debugger_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[4]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debugger_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[4]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debugger_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[5]._annotations._defaultValue._u.float_value = 0.0f;
    debugger_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[5]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    debugger_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    debugger_g_tc_members[5]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    debugger_g_tc._data._sampleAccessInfo =
    debugger_get_sample_access_info();
    debugger_g_tc._data._typePlugin =
    debugger_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &debugger_g_tc;
}

RTIXCdrSampleAccessInfo *debugger_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo debugger_g_memberAccessInfos[6] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo debugger_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &debugger_g_sampleAccessInfo;
    }

    debugger_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debugger *)NULL)->speed);

    debugger_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debugger *)NULL)->longitud);

    debugger_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debugger *)NULL)->latitud);

    debugger_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debugger *)NULL)->pitch);

    debugger_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debugger *)NULL)->roll);

    debugger_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((debugger *)NULL)->height);

    debugger_g_sampleAccessInfo.memberAccessInfos = 
    debugger_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(debugger);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            debugger_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            debugger_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    debugger_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &debugger_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *debugger_get_type_plugin_info()
{
    static RTIXCdrTypePlugin debugger_g_typePlugin = 
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
        debugger_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        debugger_finalize_w_return,
        NULL
    };

    return &debugger_g_typePlugin;
}
#endif

RTIBool debugger_initialize(
    debugger* sample) {
    return debugger_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool debugger_initialize_ex(
    debugger* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return debugger_initialize_w_params(
        sample,&allocParams);

}

RTIBool debugger_initialize_w_params(
    debugger* sample, const struct DDS_TypeAllocationParams_t * allocParams)
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

RTIBool debugger_finalize_w_return(
    debugger* sample)
{
    debugger_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void debugger_finalize(
    debugger* sample)
{

    debugger_finalize_ex(sample,RTI_TRUE);
}

void debugger_finalize_ex(
    debugger* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    debugger_finalize_w_params(
        sample,&deallocParams);
}

void debugger_finalize_w_params(
    debugger* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void debugger_finalize_optional_members(
    debugger* sample, RTIBool deletePointers)
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

RTIBool debugger_copy(
    debugger* dst,
    const debugger* src)
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
* Configure and implement 'debugger' sequence class.
*/
#define T debugger
#define TSeq debuggerSeq

#define T_initialize_w_params debugger_initialize_w_params

#define T_finalize_w_params   debugger_finalize_w_params
#define T_copy       debugger_copy

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

