#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_c.h"
#include "debug.h"
#include "debugSupport.h"

DDS_DomainParticipant *participant_debug = NULL;
DDS_Publisher *publisher_debug = NULL;
DDS_Topic *topic_debug = NULL;
DDS_DataWriter *writer_debug = NULL;
debugDataWriter *debug_writer = NULL;
debug *instance_debug = NULL;
DDS_ReturnCode_t retcode;
DDS_InstanceHandle_t instance_handle;
const char *type_name_debug = NULL;

/* Delete all entities */
int debug_shutdown(
    DDS_DomainParticipant *participant_debug)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant_debug != NULL) {
        retcode = DDS_DomainParticipant_delete_contained_entities(participant_debug);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDS_DomainParticipantFactory_delete_participant(
            DDS_TheParticipantFactory, participant_debug);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    return status;
}

int setUp_debug(int domainId, int sample_count)
{	

    instance_handle = DDS_HANDLE_NIL;

    /* To customize participant QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    participant_debug = DDS_DomainParticipantFactory_create_participant(
        DDS_TheParticipantFactory, domainId, &DDS_PARTICIPANT_QOS_DEFAULT,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant_debug == NULL) {
        fprintf(stderr, "create_participant error\n");
        debug_shutdown(participant_debug);
        return -1;
    }

    /* To customize publisher QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    publisher_debug = DDS_DomainParticipant_create_publisher(
        participant_debug, &DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (publisher_debug == NULL) {
        fprintf(stderr, "create_publisher error\n");
        debug_shutdown(participant_debug);
        return -1;
    }

    /* Register type before creating topic */
    type_name_debug = debugTypeSupport_get_type_name();
    retcode = debugTypeSupport_register_type(
        participant_debug, type_name_debug);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d\n", retcode);
        debug_shutdown(participant_debug);
        return -1;
    }

    /* To customize topic QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    topic_debug = DDS_DomainParticipant_create_topic(
        participant_debug, "debug",
        type_name_debug, &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic_debug == NULL) {
        fprintf(stderr, "create_topic error\n");
        debug_shutdown(participant_debug);
        return -1;
    }

    /* To customize data writer QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    writer_debug = DDS_Publisher_create_datawriter(
        publisher_debug, topic_debug,
        &DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (writer_debug == NULL) {
        fprintf(stderr, "create_datawriter error\n");
        debug_shutdown(participant_debug);

        return -1;
    }
    debug_writer = debugDataWriter_narrow(writer_debug);
    if (debug_writer == NULL) {
        fprintf(stderr, "DataWriter narrow error\n");
        debug_shutdown(participant_debug);
        return -1;
    }

    /* Create data sample for writing */
    instance_debug = debugTypeSupport_create_data_ex(DDS_BOOLEAN_TRUE);
    if (instance_debug == NULL) {
        fprintf(stderr, "debugTypeSupport_create_data error\n");
        debug_shutdown(participant_debug);
        return -1;
    }
}

void publisher_debugger(float pitch, float roll, float height, float leftAngle, float rightAngle, float backAngle){

	instance_debug->pitch = pitch;
	instance_debug->roll = roll;
	instance_debug->height = height;
	instance_debug->LeftAngle = leftAngle;
	instance_debug->RightAngle = rightAngle;
	instance_debug->BackAngle = backAngle;
        
	/* Write data */
        retcode = debugDataWriter_write(
            debug_writer, instance_debug, &instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "write error %d\n", retcode);
        }

}
