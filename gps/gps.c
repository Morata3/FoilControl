

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from gps.idl using "rtiddsgen".
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

#include "gps.h"

#ifndef NDDS_STANDALONE_TYPE
#include "gpsPlugin.h"
#endif

/* ========================================================================= */
const char *gpsTYPENAME = "gps";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* gps_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode gps_g_tc_name_string = DDS_INITIALIZE_STRING_TYPECODE((255));
    static DDS_TypeCode gps_g_tc_datos_string = DDS_INITIALIZE_STRING_TYPECODE((128));

    static DDS_TypeCode_Member gps_g_tc_members[2]=
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

    static DDS_TypeCode gps_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"gps", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            gps_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for gps*/

    if (is_initialized) {
        return &gps_g_tc;
    }

    gps_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    gps_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&gps_g_tc_name_string;
    gps_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&gps_g_tc_datos_string;

    /* Initialize the values for member annotations. */
    gps_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    gps_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    gps_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    gps_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    gps_g_tc._data._sampleAccessInfo =
    gps_get_sample_access_info();
    gps_g_tc._data._typePlugin =
    gps_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &gps_g_tc;
}

RTIXCdrSampleAccessInfo *gps_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo gps_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo gps_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &gps_g_sampleAccessInfo;
    }

    gps_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((gps *)NULL)->name);

    gps_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((gps *)NULL)->datos);

    gps_g_sampleAccessInfo.memberAccessInfos = 
    gps_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(gps);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            gps_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            gps_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    gps_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &gps_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *gps_get_type_plugin_info()
{
    static RTIXCdrTypePlugin gps_g_typePlugin = 
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
        gps_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        gps_finalize_w_return,
        NULL
    };

    return &gps_g_typePlugin;
}
#endif

RTIBool gps_initialize(
    gps* sample) {
    return gps_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool gps_initialize_ex(
    gps* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return gps_initialize_w_params(
        sample,&allocParams);

}

RTIBool gps_initialize_w_params(
    gps* sample, const struct DDS_TypeAllocationParams_t * allocParams)
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

RTIBool gps_finalize_w_return(
    gps* sample)
{
    gps_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void gps_finalize(
    gps* sample)
{

    gps_finalize_ex(sample,RTI_TRUE);
}

void gps_finalize_ex(
    gps* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    gps_finalize_w_params(
        sample,&deallocParams);
}

void gps_finalize_w_params(
    gps* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
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

void gps_finalize_optional_members(
    gps* sample, RTIBool deletePointers)
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

RTIBool gps_copy(
    gps* dst,
    const gps* src)
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
* Configure and implement 'gps' sequence class.
*/
#define T gps
#define TSeq gpsSeq

#define T_initialize_w_params gps_initialize_w_params

#define T_finalize_w_params   gps_finalize_w_params
#define T_copy       gps_copy

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

