#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_c.h"
#include "pid.h"
#include "pidSupport.h"

DDS_DomainParticipant *participant = NULL;
DDS_Publisher *publisher = NULL;
DDS_Topic *topic = NULL;
DDS_DataWriter *writer = NULL;
pidDataWriter *pid_writer = NULL;
pid *instance = NULL;
DDS_ReturnCode_t retcode;
DDS_InstanceHandle_t instance_handle; 
const char *type_name = NULL;
int count = 0;  
struct DDS_Duration_t send_period = {4,0};

/* Delete all entities */
int pid_shutdown()
{

    DDS_ReturnCode_t retcode;
    int status = 0;

    retcode = pidTypeSupport_delete_data_ex(instance, DDS_BOOLEAN_TRUE);
    if (retcode != DDS_RETCODE_OK) {
       fprintf(stderr, "pidTypeSupport_delete_data error %d\n", retcode);
  
    }
   
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

    /* RTI Data Distribution Service provides finalize_instance() method on
    domain participant factory for people who want to release memory used
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

int setUp_pid(int domainId, int sample_count)
{
    instance_handle=DDS_HANDLE_NIL;

    /* To customize participant QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    participant = DDS_DomainParticipantFactory_create_participant(
        DDS_TheParticipantFactory, domainId, &DDS_PARTICIPANT_QOS_DEFAULT,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        fprintf(stderr, "create_participant error\n");
        pid_shutdown();
        return -1;
    }

    /* To customize publisher QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    publisher = DDS_DomainParticipant_create_publisher(
        participant, &DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        fprintf(stderr, "create_publisher error\n");
        pid_shutdown();
        return -1;
    }

    /* Register type before creating topic */
    type_name = pidTypeSupport_get_type_name();
    retcode = pidTypeSupport_register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d\n", retcode);
        pid_shutdown();
        return -1;
    }

    /* To customize topic QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    topic = DDS_DomainParticipant_create_topic(
        participant, "Example pid",
        type_name, &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        fprintf(stderr, "create_topic error\n");
        pid_shutdown();
        return -1;
    }

    /* To customize data writer QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    writer = DDS_Publisher_create_datawriter(
        publisher, topic,
        &DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        fprintf(stderr, "create_datawriter error\n");
        pid_shutdown();
        return -1;
    }
    pid_writer = pidDataWriter_narrow(writer);
    if (pid_writer == NULL) {
        fprintf(stderr, "DataWriter narrow error\n");
        pid_shutdown();
        return -1;
    }

    /* Create data sample for writing */
    instance = pidTypeSupport_create_data_ex(DDS_BOOLEAN_TRUE);
    if (instance == NULL) {
        fprintf(stderr, "pidTypeSupport_create_data error\n");
        pid_shutdown();
        return -1;
    }
    return 0;
}
    /* For a data type that has a key, if the same instance is going to be
    written multiple times, initialize the key here
    and register the keyed instance prior to writing */
    /*
    instance_handle = pidDataWriter_register_instance(
        pid_writer, instance);
    */
    /* Main loop */
   // for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

void publisher_pid(float pitch, float roll, float height){

        printf("Writing pid, count %d\n", count);

        /* Modify the data to be written here */

        /* Write data */
        retcode = pidDataWriter_write(
            pid_writer, instance, &instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "write error %d\n", retcode);
        }

        NDDS_Utility_sleep(&send_period);

//    }
}
    /*
    retcode = pidDataWriter_unregister_instance(
        pid_writer, instance, &instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "unregister instance error %d\n", retcode);
    }
    */
    /* Delete data sample */
 /*   retcode = pidTypeSupport_delete_data_ex(instance, DDS_BOOLEAN_TRUE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "pidTypeSupport_delete_data error %d\n", retcode);
    }*/
    /* Cleanup and delete delete all entities */         
   // return publisher_shutdown(participant);


/*int main(int argc, char *argv[])
{
    int domain_id = 0;
    int sample_count = 0; 

    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

     Uncomment this to turn on additional logging
    NDDS_Config_Logger_set_verbosity_by_category(
        NDDS_Config_Logger_get_instance(),
        NDDS_CONFIG_LOG_CATEGORY_API, 
        NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    

    return publisher_main(domain_id, sample_count);
}*/

