
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dataControl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "dataControlSupport.h"
#include "dataControlPlugin.h"

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'control' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   controlTYPENAME

/* Defines */
#define TDataWriter controlDataWriter
#define TData       control

#define ENABLE_TDATAWRITER_DATA_CONSTRUCTOR_METHODS
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#undef ENABLE_TDATAWRITER_DATA_CONSTRUCTOR_METHODS

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   controlTYPENAME

/* Defines */
#define TDataReader controlDataReader
#define TDataSeq    controlSeq
#define TData       control

#define ENABLE_TDATAREADER_DATA_CONSISTENCY_CHECK_METHOD
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#undef ENABLE_TDATAREADER_DATA_CONSISTENCY_CHECK_METHOD

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    controlTYPENAME
#define TPlugin_new  controlPlugin_new
#define TPlugin_delete  controlPlugin_delete

/* Defines */
#define TTypeSupport controlTypeSupport
#define TData        control
#define TDataReader  controlDataReader
#define TDataWriter  controlDataWriter
#define TGENERATE_SER_CODE
#ifndef NDDS_STANDALONE_TYPE
#define TGENERATE_TYPECODE
#endif

#include "dds_c/generic/dds_c_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#ifndef NDDS_STANDALONE_TYPE
#undef TGENERATE_TYPECODE
#endif
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

