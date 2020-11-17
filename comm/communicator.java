import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Arrays;

import com.rti.dds.domain.*;
import com.rti.dds.infrastructure.*;
import com.rti.dds.publication.*;
import com.rti.dds.topic.*;
import com.rti.ndds.config.*;

//==========  JAVA ARDUINO CONECTION ====
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.Enumeration;
import java.util.Scanner;



// ===========================================================================

public class communicator {
    // -----------------------------------------------------------------------
    // Public Methods
    // -----------------------------------------------------------------------
	///// ** MACROS ** //////
	private static final int domain_height = 0;
	private static final int domain_imu = 1;
	private static final int domain_gps = 2;
	///////////////////////////////
	
	private static String msg = new String();
	private static OutputStream output = null;
	private static BufferedReader input;

	private static SerialPort serialPort;
	private static final String PUERTO = "/dev/ttyUSB0"; // LINUX 

	private static final int TIMEOUT = 2000; // Milisegundos

	private static final int DATA_RATE = 9600;

    public static void main(String[] args) {
        // --- Get domain ID --- //
        int domainId = 0;
        if (args.length >= 1) {
            domainId = Integer.valueOf(args[0]).intValue();
        }

        // -- Get max loop count; 0 means infinite loop --- //
        int sampleCount = 0;
        if (args.length >= 2) {
            sampleCount = Integer.valueOf(args[1]).intValue();
        }
	
        /* Uncomment this to turn on additional logging
            Logger.get_instance().set_verbosity_by_category(
            LogCategory.NDDS_CONFIG_LOG_CATEGORY_API,
            LogVerbosity.NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
        */

        // --- Run --- //
	inicializarConexion();
        publisherMain(domainId, sampleCount);

    }



    // -----------------------------------------------------------------------
    // Private Methods
    // -----------------------------------------------------------------------

    // --- Constructors: -----------------------------------------------------

    public communicator() {
        super();
    }

    // -----------------------------------------------------------------------
	public static void inicializarConexion() {
		CommPortIdentifier puertoID = null;
		Enumeration puertoEnum = CommPortIdentifier.getPortIdentifiers();

		while (puertoEnum.hasMoreElements()) {
			CommPortIdentifier actualPuertoID = (CommPortIdentifier) puertoEnum.nextElement();
			if (PUERTO.equals(actualPuertoID.getName())) {
				puertoID = actualPuertoID;
				break;
			}
		}

		if (puertoID == null) {
			System.out.println("ERROR ID PUERTO");
		}

		try {
			serialPort = (SerialPort) puertoID.open("heightSensor", TIMEOUT);
			
			// Parámetros puerto serie
			serialPort.setSerialPortParams(DATA_RATE, SerialPort.DATABITS_8, SerialPort.STOPBITS_1,SerialPort.PARITY_NONE);

			output = serialPort.getOutputStream();
			input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
		} catch (Exception e) {
			System.out.println("ERROR CON PUERTO");

		}
	}


    public static void publisherMain(int domainId, int sampleCount) {
       
        DomainParticipant participant_height = null;
        Publisher publisher_height = null;
        Topic topic_height = null;
        heightSensorDataWriter writer_height = null;
        
	DomainParticipant participant_imu = null;
        Publisher publisher_imu = null;
        Topic topic_imu = null;
        imuDataWriter writer_imu = null;

        try {
	
	    			// **** HEIGHT **** //
			        //-----------------//
	
            // --- Create participant --- //
            participant_height = DomainParticipantFactory.TheParticipantFactory.
            create_participant(
                domain_height, DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant_height == null) {
                System.err.println("create_participant error\n");
                return;
            }       

            // --- Create publisher --- //
            publisher_height = participant_height.create_publisher(
                DomainParticipant.PUBLISHER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (publisher_height == null) {
                System.err.println("create_publisher error\n");
                return;
            }                   

            // --- Create topic --- //
            /* Register type before creating topic */
            String typeName_height = heightSensorTypeSupport.get_type_name();
            heightSensorTypeSupport.register_type(participant_height, typeName_height);

            topic_height = participant_height.create_topic(
                "heightSensor",
                typeName_height, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic_height == null) {
                System.err.println("create_topic error\n");
                return;
            }           
	    
	    // --- Create writer --- //      
            writer_height = (heightSensorDataWriter)
            publisher_height.create_datawriter(
                topic_height, Publisher.DATAWRITER_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (writer_height == null) {
                System.err.println("create_datawriter error\n");
                return;
            }           

            // --- Write HEIGHT--- //
            /* Create data sample for writing */
            heightSensor instance_height = new heightSensor();
            InstanceHandle_t instance_handle_height = InstanceHandle_t.HANDLE_NIL;

	   			 // **** IMU **** //
				//---------------//
	    
	    // --- Create participant --- //
            participant_imu = DomainParticipantFactory.TheParticipantFactory.
            create_participant(
                domain_imu, DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant_imu == null) {
                System.err.println("create_participant error\n");
                return;
            }        

            // --- Create publisher --- //
            publisher_imu = participant_imu.create_publisher(
                DomainParticipant.PUBLISHER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (publisher_imu == null) {
                System.err.println("create_publisher error\n");
                return;
            }                   

            // --- Create topic --- //
            /* Register type before creating topic */
            String typeName_imu = imuTypeSupport.get_type_name();
            imuTypeSupport.register_type(participant_imu, typeName_imu);

            topic_imu = participant_imu.create_topic(
                "imu",
                typeName_imu, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic_imu == null) {
                System.err.println("create_topic error\n");
                return;
            }           

            // --- Create writer --- //
            writer_imu = (imuDataWriter)
            publisher_imu.create_datawriter(
                topic_imu, Publisher.DATAWRITER_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (writer_imu == null) {
                System.err.println("create_datawriter error\n");
                return;
            }           

            // --- Write --- //

            /* Create data sample for writing */
            imu instance_imu = new imu();
            InstanceHandle_t instance_handle_imu = InstanceHandle_t.HANDLE_NIL;

	    /////////// PUBLICAR ////////
	    ////////////////////////////

            final long sendPeriodMillis = 400; // 400 mili-seconds
            String height;
	    String imu;

	    for (int count = 0;
            (sampleCount == 0) || (count < sampleCount);
            ++count) {

                /* Leyendo del ARDUINO y publicando */
		try{    
			String inputLine = input.readLine();	
			if(inputLine.startsWith("Height")){
				instance_height.msg = inputLine;
				writer_height.write(instance_height, instance_handle_height);
				System.out.println(instance_height.msg);
			}
			else if(inputLine.startsWith("IMU")){
				instance_imu.name = "Roll&Pitch";
				instance_imu.datos = inputLine;
				writer_imu.write(instance_imu, instance_handle_imu);
				System.out.println(instance_imu.datos);
			}
			else System.out.println("ERROR: Linea con formato erroneo");
		
		}catch (Exception e){
			System.out.println(e);
	    	}
		
                try {
                    Thread.sleep(sendPeriodMillis);
                } catch (InterruptedException ix) {
                    System.err.println("INTERRUPTED");
                    break;
                }
            }

           //writer.unregister_instance(instance, instance_handle);

        } finally {

            // --- Shutdown --- //

            if(participant_height != null) {
                participant_height.delete_contained_entities();

                DomainParticipantFactory.TheParticipantFactory.
                delete_participant(participant_height);
            }
	    else if(participant_imu != null) {
                participant_imu.delete_contained_entities();

                DomainParticipantFactory.TheParticipantFactory.
                delete_participant(participant_imu);
            }
            /* RTI Data Distribution Service provides finalize_instance()
            method for people who want to release memory used by the
            participant factory singleton. Uncomment the following block of
            code for clean destruction of the participant factory
            singleton. */
           //DomainParticipantFactory.finalize_instance();
        }
    }
}

