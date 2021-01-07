

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from heightSensor.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef heightSensor_638766898_h
#define heightSensor_638766898_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *heightSensorTYPENAME;

typedef struct heightSensor {

    DDS_Char *   msg ;

} heightSensor ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* heightSensor_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *heightSensor_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *heightSensor_get_sample_access_info(void);
#endif

DDS_SEQUENCE(heightSensorSeq, heightSensor);

NDDSUSERDllExport
RTIBool heightSensor_initialize(
    heightSensor* self);

NDDSUSERDllExport
RTIBool heightSensor_initialize_ex(
    heightSensor* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool heightSensor_initialize_w_params(
    heightSensor* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool heightSensor_finalize_w_return(
    heightSensor* self);

NDDSUSERDllExport
void heightSensor_finalize(
    heightSensor* self);

NDDSUSERDllExport
void heightSensor_finalize_ex(
    heightSensor* self,RTIBool deletePointers);

NDDSUSERDllExport
void heightSensor_finalize_w_params(
    heightSensor* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void heightSensor_finalize_optional_members(
    heightSensor* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool heightSensor_copy(
    heightSensor* dst,
    const heightSensor* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* heightSensor */

