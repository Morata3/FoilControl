import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Arrays;

import com.rti.dds.domain.*;
import com.rti.dds.infrastructure.*;
import com.rti.dds.publication.*;
import com.rti.dds.topic.*;
import com.rti.dds.subscription.*;
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
	private static final int domain_pid = 3;
	private static final int domain_debug = 4;
	///////////////////////////////

	private static String prefijo, speed, longitud, latitud, pitch, roll, altura;

	private static OutputStream output = null;
	private static BufferedReader input;

	private static SerialPort serialPort;
	private static String PUERTO; // LINUX 

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
    	
	public static String getPortName(){
		CommPortIdentifier port=null;
		Enumeration<?> puerto =CommPortIdentifier.getPortIdentifiers();
		while (puerto.hasMoreElements()) {
			port= (CommPortIdentifier) puerto.nextElement();
			
		}
		System.out.println("PUERTO: " + port.getName());
		return port.getName();

	}

	public static void inicializarConexion() {
		CommPortIdentifier puertoID = null;
		Enumeration puertoEnum = CommPortIdentifier.getPortIdentifiers();
		PUERTO = getPortName();
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

     private static class pidListener extends DataReaderAdapter {

        pidSeq _dataSeq = new pidSeq();
        SampleInfoSeq _infoSeq = new SampleInfoSeq();
	static int indexLeftAngle = 1;
	static int indexRightAngle = 2;
	static int indexBackAngle = 3;

        public void on_data_available(DataReader reader) {
            pidDataReader pidReader =
            (pidDataReader)reader;

            try {
                pidReader.take(
                    _dataSeq, _infoSeq,
                    ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
                    SampleStateKind.ANY_SAMPLE_STATE,
                    ViewStateKind.ANY_VIEW_STATE,
                    InstanceStateKind.ANY_INSTANCE_STATE);

                for(int i = 0; i < _dataSeq.size(); ++i) {
                    SampleInfo info = (SampleInfo)_infoSeq.get(i);

                    if (info.valid_data) {
			    String salida_pid = ((pid)_dataSeq.get(i)).toString();
			    String datos[] = salida_pid.split("\n");
			    
			    String outputLine=new String("01"+datos[indexLeftAngle].split(":")[1]
					    +"#02"+datos[indexRightAngle].split(":")[1]
					    +"#03"+datos[indexBackAngle].split(":")[1]+"\n");
			    try{
		    		    output.write(outputLine.getBytes());
		    	    }catch (IOException e){
		    		    e.printStackTrace();
		    	    }
		    }
		}
            } catch (RETCODE_NO_DATA noData) {
                // No data to process
            } finally {
                pidReader.return_loan(_dataSeq, _infoSeq);
            }
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

	DomainParticipant participant_gps = null;
        Publisher publisher_gps = null;
        Topic topic_gps = null;
        gpsDataWriter writer_gps = null;

	DomainParticipant participant_debug = null;
        Publisher publisher_debug = null;
        Topic topic_debug = null;
        debugDataWriter writer_debug = null;

	//Subscriber PID
	DomainParticipant participant = null;
        Subscriber subscriber = null;
        Topic topic = null;
        DataReaderListener listener = null;
        pidDataReader reader = null;


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
		
    				// *** GPS *** //
				//-------------//
	    
	    // --- Create participant --- //
            participant_gps = DomainParticipantFactory.TheParticipantFactory.
            create_participant(
                domain_gps, DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant_gps == null) {
                System.err.println("create_participant error GPS\n");
                return;
            }        

            // --- Create publisher --- //
            publisher_gps = participant_gps.create_publisher(
                DomainParticipant.PUBLISHER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (publisher_gps == null) {
                System.err.println("create_publisher error\n");
                return;
            }                   

            // --- Create topic --- //
            String typeName_gps = gpsTypeSupport.get_type_name();
            gpsTypeSupport.register_type(participant_gps, typeName_gps);

            topic_gps = participant_gps.create_topic(
                "gps",
                typeName_gps, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic_gps == null) {
                System.err.println("create_topic error\n");
                return;
            }           

            // --- Create writer --- //
            writer_gps = (gpsDataWriter)
            publisher_gps.create_datawriter(
                topic_gps, Publisher.DATAWRITER_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (writer_gps == null) {
                System.err.println("create_datawriter error\n");
                return;
            }           

            // --- Write --- //
            gps instance_gps = new gps();
            InstanceHandle_t instance_handle_gps = InstanceHandle_t.HANDLE_NIL;
				
	    			// *** DEBUGGER *** //
				// ---------------- //
	
		// --- Create participant --- //
            participant_debug = DomainParticipantFactory.TheParticipantFactory.
            create_participant(
                domain_debug, DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant_debug == null) {
                System.err.println("create_participant error\n");
                return;
            }        

            // --- Create publisher --- //

            publisher_debug = participant_debug.create_publisher(
                DomainParticipant.PUBLISHER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (publisher_debug == null) {
                System.err.println("create_publisher error\n");
                return;
            }                   

            // --- Create topic --- //

            /* Register type before creating topic */
            String typeName_debug = debugTypeSupport.get_type_name();
            debugTypeSupport.register_type(participant_debug, typeName_debug);

            topic_debug = participant_debug.create_topic(
                "debug",
                typeName_debug, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic_debug == null) {
                System.err.println("create_topic error\n");
                return;
            }           

            // --- Create writer --- //

            writer_debug = (debugDataWriter)
            publisher_debug.create_datawriter(
                topic_debug, Publisher.DATAWRITER_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (writer_debug == null) {
                System.err.println("create_datawriter error\n");
                return;
            }           

            // --- Write --- //

            debug instance_debug = new debug();
            InstanceHandle_t instance_handle_debug = InstanceHandle_t.HANDLE_NIL;


				// *** PID Subscriber *** //
				//-----------------------//
		
	    // --- Create participant --- //

            participant = DomainParticipantFactory.TheParticipantFactory.
            create_participant(
                domain_pid, DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant == null) {
                System.err.println("create_participant error PID\n");
                return;
            }                         

            // --- Create subscriber --- //       

            subscriber = participant.create_subscriber(
                DomainParticipant.SUBSCRIBER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (subscriber == null) {
                System.err.println("create_subscriber error\n");
                return;
            }     

            // --- Create topic --- //

            String typeName = pidTypeSupport.get_type_name(); 
            pidTypeSupport.register_type(participant, typeName); 
            
            topic = participant.create_topic(
                "pid",
                typeName, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic == null) {
                System.err.println("create_topic error\n");
                return;
            }                     

            // --- Create reader --- //

            listener = new pidListener(); 

            reader = (pidDataReader)
            subscriber.create_datareader(
                topic, Subscriber.DATAREADER_QOS_DEFAULT, listener,
                StatusKind.STATUS_MASK_ALL);
            if (reader == null) {
                System.err.println("create_datareader error\n");
                return;
            }                         


	    /////////// PUBLICAR ////////
	    ////////////////////////////

            final long sendPeriodMillis = 400; // 400 mili-seconds
	    String[] datosSensores = new String[10];    		    

	    //sampleCount = 4;	    
	    //while(true){
	    for (int count = 0;
            (sampleCount == 0) || (count < sampleCount);
            ++count) {

                /* Leyendo del ARDUINO y publicando */
		try{    
			String inputLine = input.readLine();
	    		String[] componentes = inputLine.split("#");
			prefijo = componentes[0]; 
	    		if (prefijo.equals("000")) {
		    		speed = componentes[1]; 
				longitud = componentes[2];
	    			latitud = componentes[3]; 
		    		pitch = componentes[4]; 
				roll = componentes[5]; 
	    			altura = componentes[6]; 
			}else System.out.println("******** DATOS ARDUINO *********\n" + inputLine);
				
			instance_height.msg = altura;
			instance_debug.height = Float.parseFloat(altura);

			writer_height.write(instance_height, instance_handle_height);
			writer_debug.write(instance_debug, instance_handle_debug);
			
			System.out.println("****** DATOS RASPI ********");
			System.out.println("ALTURA: "+instance_height.msg);
				
			instance_imu.name = "Roll&Pitch";
			instance_imu.datos = new String(pitch+" "+roll);
			instance_debug.pitch = Float.parseFloat(pitch);
			instance_debug.roll = Float.parseFloat(roll);

			writer_imu.write(instance_imu, instance_handle_imu);
			writer_debug.write(instance_debug, instance_handle_debug);

			System.out.println("IMU: "+instance_imu.datos);

			instance_gps.name = "Speed";
                        instance_gps.datos = speed;
			instance_debug.speed = Float.parseFloat(speed);
			writer_gps.write(instance_gps, instance_handle_gps);

                        System.out.println("VELOCIDADE: "+instance_gps.datos);
	
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
         
        }
    }
}

