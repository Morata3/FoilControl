

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from imu.idl using "rtiddsgen".
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

#include "imu.h"

#ifndef NDDS_STANDALONE_TYPE
#include "imuPlugin.h"
#endif

/* ========================================================================= */
const char *imuTYPENAME = "imu";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* imu_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode imu_g_tc_name_string = DDS_INITIALIZE_STRING_TYPECODE((255));
    static DDS_TypeCode imu_g_tc_datos_string = DDS_INITIALIZE_STRING_TYPECODE((128));

    static DDS_TypeCode_Member imu_g_tc_members[2]=
    {

        {
            (char *)"name",/* Member name */
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
            (char *)"datos",/* Member name */
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
        }
    };

    static DDS_TypeCode imu_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"imu", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            imu_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for imu*/

    if (is_initialized) {
        return &imu_g_tc;
    }

    imu_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    imu_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&imu_g_tc_name_string;
    imu_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&imu_g_tc_datos_string;

    /* Initialize the values for member annotations. */
    imu_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    imu_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    imu_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    imu_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    imu_g_tc._data._sampleAccessInfo =
    imu_get_sample_access_info();
    imu_g_tc._data._typePlugin =
    imu_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &imu_g_tc;
}

RTIXCdrSampleAccessInfo *imu_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo imu_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo imu_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &imu_g_sampleAccessInfo;
    }

    imu_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((imu *)NULL)->name);

    imu_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((imu *)NULL)->datos);

    imu_g_sampleAccessInfo.memberAccessInfos = 
    imu_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(imu);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            imu_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            imu_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    imu_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &imu_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *imu_get_type_plugin_info()
{
    static RTIXCdrTypePlugin imu_g_typePlugin = 
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
        imu_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        imu_finalize_w_return,
        NULL
    };

    return &imu_g_typePlugin;
}
#endif

RTIBool imu_initialize(
    imu* sample) {
    return imu_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool imu_initialize_ex(
    imu* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return imu_initialize_w_params(
        sample,&allocParams);

}

RTIBool imu_initialize_w_params(
    imu* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->name = DDS_String_alloc((255));
        RTICdrType_copyStringEx(
            &sample->name,
            "",
            (255),
            RTI_FALSE);
        if (sample->name == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->name != NULL) {
            RTICdrType_copyStringEx(
                &sample->name,
                "",
                (255),
                RTI_FALSE);
            if (sample->name == NULL) {
                return RTI_FALSE;
            }
        }
    }

    if (allocParams->allocate_memory) {
        sample->datos = DDS_String_alloc((128));
        RTICdrType_copyStringEx(
            &sample->datos,
            "",
            (128),
            RTI_FALSE);
        if (sample->datos == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->datos != NULL) {
            RTICdrType_copyStringEx(
                &sample->datos,
                "",
                (128),
                RTI_FALSE);
            if (sample->datos == NULL) {
                return RTI_FALSE;
            }
        }
    }

    return RTI_TRUE;
}

RTIBool imu_finalize_w_return(
    imu* sample)
{
    imu_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void imu_finalize(
    imu* sample)
{

    imu_finalize_ex(sample,RTI_TRUE);
}

void imu_finalize_ex(
    imu* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    imu_finalize_w_params(
        sample,&deallocParams);
}

void imu_finalize_w_params(
    imu* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->name != NULL) {
        DDS_String_free(sample->name);
        sample->name=NULL;

    }
    if (sample->datos != NULL) {
        DDS_String_free(sample->datos);
        sample->datos=NULL;

    }
}

void imu_finalize_optional_members(
    imu* sample, RTIBool deletePointers)
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

RTIBool imu_copy(
    imu* dst,
    const imu* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyStringEx (
        &dst->name, src->name, 
        (255) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }
    if (!RTICdrType_copyStringEx (
        &dst->datos, src->datos, 
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
* Configure and implement 'imu' sequence class.
*/
#define T imu
#define TSeq imuSeq

#define T_initialize_w_params imu_initialize_w_params

#define T_finalize_w_params   imu_finalize_w_params
#define T_copy       imu_copy

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

