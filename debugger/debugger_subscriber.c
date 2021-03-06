#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_c.h"
#include "debugger.h"
#include "debuggerSupport.h"

void debuggerListener_on_requested_deadline_missed(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_RequestedDeadlineMissedStatus *status)
{
}

void debuggerListener_on_requested_incompatible_qos(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_RequestedIncompatibleQosStatus *status)
{
}

void debuggerListener_on_sample_rejected(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_SampleRejectedStatus *status)
{
}

void debuggerListener_on_liveliness_changed(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_LivelinessChangedStatus *status)
{
}

void debuggerListener_on_sample_lost(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_SampleLostStatus *status)
{
}

void debuggerListener_on_subscription_matched(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
}

void debuggerListener_on_data_available(
    void* listener_data,
    DDS_DataReader* reader)
{
    debuggerDataReader *debugger_reader = NULL;
    struct debuggerSeq data_seq = DDS_SEQUENCE_INITIALIZER;
    struct DDS_SampleInfoSeq info_seq = DDS_SEQUENCE_INITIALIZER;
    const char * topic_name;
    DDS_ReturnCode_t retcode;
    int i;
    FILE *log;

    debugger_reader = debuggerDataReader_narrow(reader);
    if (debugger_reader == NULL) {
        fprintf(stderr, "DataReader narrow error\n");
        return;
    }

    // Save name of topic
    topic_name = DDS_TopicDescription_get_name(DDS_DataReader_get_topicdescription(reader));
  	
    log = fopen("../logs/DDS.log","ab+");

    retcode = debuggerDataReader_take(
        debugger_reader,
        &data_seq, &info_seq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);
    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    } else if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "take error %d\n", retcode);
        return;
    }
    
    for (i = 0; i < debuggerSeq_get_length(&data_seq); ++i) {
        if (DDS_SampleInfoSeq_get_reference(&info_seq, i)->valid_data) {
		float pitch = debuggerSeq_get_reference(&data_seq, i)->pitch;
		float roll = debuggerSeq_get_reference(&data_seq, i)->roll;
		float height = debuggerSeq_get_reference(&data_seq, i)->height;
		float speed = debuggerSeq_get_reference(&data_seq, i)->speed;

	    	if(strcmp("DataControl",topic_name)==0){
		       	fprintf(log,"\n*** SALIDAS *** \n");	
			fprintf(log,"Left Angle: %.2f\n",roll);	
			fprintf(log,"Right Angle: %.2f\n",pitch);	
			fprintf(log,"Back Angle: %.2f\n",height);	
			fprintf(log,"Speed: %.2f\n",speed);	
		}
	    	else{
		       	fprintf(log,"\n*** ENTRADAS *** \n");
			fprintf(log,"Pitch: %.2f\n",pitch);	
			fprintf(log,"Roll: %.2f\n",roll);	
			fprintf(log,"Height: %.2f\n",height);	
			fprintf(log,"Speed: %.2f\n",speed);	
		}
        }
    }

    fclose(log);

    retcode = debuggerDataReader_return_loan(
        debugger_reader,
        &data_seq, &info_seq);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
}

/* Delete all entities */
static int subscriber_shutdown(
    DDS_DomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = DDS_DomainParticipant_delete_contained_entities(participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDS_DomainParticipantFactory_delete_participant(
            DDS_TheParticipantFactory, participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Data Distribution Service provides the finalize_instance() method on
    domain participant factory for users who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*
    retcode = DDS_DomainParticipantFactory_finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d\n", retcode);
        status = -1;
    }
    */

    return status;
}

int subscriber_main(int domainId, int sample_count)
{
    DDS_DomainParticipant *participant = NULL;
    DDS_Subscriber *subscriber = NULL;
    DDS_Topic *topic_comm = NULL;
    DDS_Topic *topic_control = NULL;
    struct DDS_DataReaderListener reader_listener =
    DDS_DataReaderListener_INITIALIZER;
    DDS_DataReader *reader_comm = NULL;
    DDS_DataReader *reader_control = NULL;
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    int count = 0;
    struct DDS_Duration_t poll_period = {4,0};

    participant = DDS_DomainParticipantFactory_create_participant(
        DDS_TheParticipantFactory, domainId, &DDS_PARTICIPANT_QOS_DEFAULT,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        fprintf(stderr, "create_participant error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    subscriber = DDS_DomainParticipant_create_subscriber(
        participant, &DDS_SUBSCRIBER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        fprintf(stderr, "create_subscriber error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    type_name = debuggerTypeSupport_get_type_name();
    retcode = debuggerTypeSupport_register_type(participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d\n", retcode);
        subscriber_shutdown(participant);
        return -1;
    }

    topic_comm = DDS_DomainParticipant_create_topic(
        participant, "DataComm",
        type_name, &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic_comm == NULL) {
        fprintf(stderr, "create_topic error\n");
        subscriber_shutdown(participant);
        return -1;
    }

 
    topic_control = DDS_DomainParticipant_create_topic(
    	participant, "DataControl",
	type_name, &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
    	DDS_STATUS_MASK_NONE);
    if (topic_control == NULL) {
    	fprintf(stderr, "create_topic error\n");
    	subscriber_shutdown(participant);
    	return -1;
    }



    /* Set up a data reader listener */
    reader_listener.on_requested_deadline_missed  =
    debuggerListener_on_requested_deadline_missed;
    reader_listener.on_requested_incompatible_qos =
    debuggerListener_on_requested_incompatible_qos;
    reader_listener.on_sample_rejected =
    debuggerListener_on_sample_rejected;
    reader_listener.on_liveliness_changed =
    debuggerListener_on_liveliness_changed;
    reader_listener.on_sample_lost =
    debuggerListener_on_sample_lost;
    reader_listener.on_subscription_matched =
    debuggerListener_on_subscription_matched;
    reader_listener.on_data_available =
    debuggerListener_on_data_available;

    /*READER COMM */
    reader_comm = DDS_Subscriber_create_datareader(
        subscriber, DDS_Topic_as_topicdescription(topic_comm),
        &DDS_DATAREADER_QOS_DEFAULT, &reader_listener, DDS_STATUS_MASK_ALL);
    if (reader_comm == NULL) {
        fprintf(stderr, "create_datareader error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /*READER CONTROL */
    reader_control = DDS_Subscriber_create_datareader(
        subscriber, DDS_Topic_as_topicdescription(topic_control),
        &DDS_DATAREADER_QOS_DEFAULT, &reader_listener, DDS_STATUS_MASK_ALL);
    if (reader_control == NULL) {
        fprintf(stderr, "create_datareader error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        NDDS_Utility_sleep(&poll_period);
    }

    /* Cleanup and delete all entities */ 
    return subscriber_shutdown(participant);
}

int main(int argc, char *argv[])
{
    int domain_id = 0;
    int sample_count = 0; /* infinite loop */
    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    /* Uncomment this to turn on additional logging
    NDDS_Config_Logger_set_verbosity_by_category(
        NDDS_Config_Logger_get_instance(),
        NDDS_CONFIG_LOG_CATEGORY_API, 
        NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */

    return subscriber_main(domain_id, sample_count);
}

