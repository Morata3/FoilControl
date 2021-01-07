import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Arrays;

import com.rti.dds.domain.*;
import com.rti.dds.infrastructure.*;
import com.rti.dds.publication.*;
import com.rti.dds.topic.*;
import com.rti.dds.subscription.*;
import com.rti.ndds.config.*;

// ==========  JAVA ARDUINO CONECTION ====
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
	private static OutputStream output = null;
	private static BufferedReader input;

	private static SerialPort serialPort;
	private static String PUERTO; // LINUX 
	private static final int TIMEOUT = 2000; // Milisegundos
	private static final int DATA_RATE = 9600;

	private static String prefijo, speed, longitud, latitud, pitch, roll, altura;


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

    public communicator() {
        super();
    }

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
			serialPort = (SerialPort) puertoID.open("communicator", TIMEOUT);
			
			// Parámetros puerto serie
			serialPort.setSerialPortParams(DATA_RATE, SerialPort.DATABITS_8, SerialPort.STOPBITS_1,SerialPort.PARITY_NONE);

			output = serialPort.getOutputStream();
			input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
		} catch (Exception e) {
			System.out.println("ERROR CON PUERTO");

		}
	}

	private static class commListener extends DataReaderAdapter {

        	commSeq _dataSeq = new commSeq();
	        SampleInfoSeq _infoSeq = new SampleInfoSeq();

        	public void on_data_available(DataReader reader) {
	            commDataReader commReader =
            		(commDataReader)reader;

	            try {
        	        commReader.take(
                	    _dataSeq, _infoSeq,
	                    ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
	                    SampleStateKind.ANY_SAMPLE_STATE,
	                    ViewStateKind.ANY_VIEW_STATE,
	                    InstanceStateKind.ANY_INSTANCE_STATE);

	                for(int i = 0; i < _dataSeq.size(); ++i) {
	                    SampleInfo info = (SampleInfo)_infoSeq.get(i);

	                    if (info.valid_data) {
				  String salida_control = ((comm)_dataSeq.get(i)).toString();
				  
		                  String[] datos = salida_control.split("\n");
				  System.out.println("DDS_CONTROL: " + salida_control);
				  String speed = datos[1].split(":")[1];
				  String longitud = datos[2].split(":")[1];
				  String latitud = datos[3].split(":")[1];
				  String pitch = datos[4].split(":")[1];
				  String roll = datos[5].split(":")[1];
				  String height = datos[6].split(":")[1];

                                  String outputLine=new String("01"+pitch
                                      	    +"#02"+roll
                                      	    +"#03"+height+ "#04"+speed+"\n");
				  System.out.println("SALIDA CONTROL: " +outputLine);
                                  try{
                                         // System.out.println(outputLine.getBytes());
                                         output.write(outputLine.getBytes());
                                  }catch (IOException e){
                                          e.printStackTrace();
                                  }
	                    }
        	        }
	            } catch (RETCODE_NO_DATA noData) {
        	        // No data to process
	            } finally {
        	        commReader.return_loan(_dataSeq, _infoSeq);
	            }
        	}
    }

    public static void publisherMain(int domainId, int sampleCount) {
        
	DomainParticipant participant = null;
        Publisher publisher = null;
        Topic topic = null;
        commDataWriter writer = null;

	Subscriber subscriber = null;
        Topic topic_subscriber = null;
        DataReaderListener listener = null;
        commDataReader reader = null;

        try {
	
	    			// **** PUBLISHER DATA **** //
			        //--------------------------//
	    
	    // --- Create participant --- //
            participant = DomainParticipantFactory.TheParticipantFactory.
            create_participant(
                domainId, DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant == null) {
                System.err.println("create_participant error\n");
                return;
            }        

            // --- Create publisher --- //
            publisher = participant.create_publisher(
                DomainParticipant.PUBLISHER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (publisher == null) {
                System.err.println("create_publisher error\n");
                return;
            }                   

            // --- Create topics --- //
            String typeName = commTypeSupport.get_type_name();
            commTypeSupport.register_type(participant, typeName);

            topic = participant.create_topic(
                "DataComm",
                typeName, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic == null) {
                System.err.println("create_topic error PUBLISHER\n");
                return;
            }             
          
            // --- Create writer --- //
            writer = (commDataWriter)
            publisher.create_datawriter(
                topic, Publisher.DATAWRITER_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (writer == null) {
                System.err.println("create_datawriter error\n");
                return;
            }           

            // --- Write --- //
            /* Create data sample for writing */
            comm instance = new comm();
            InstanceHandle_t instance_handle = InstanceHandle_t.HANDLE_NIL;


				    // **** SUBSCRIBER DATA **** //
			            //--------------------------//		
		
	     // --- Create subscriber --- //
            subscriber = participant.create_subscriber(
                DomainParticipant.SUBSCRIBER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (subscriber == null) {
                System.err.println("create_subscriber error\n");
                return;
            }     
	
	    // --- Create topic --- //
	    topic_subscriber = participant.create_topic(
		      	    "DataControl",
		      	    typeName, DomainParticipant.TOPIC_QOS_DEFAULT,
		      	    null /* listener */, StatusKind.STATUS_MASK_NONE);
	    if (topic == null) {
	      	    System.err.println("create_topic error SUBSCRIBER\n");
	      	    return;
	    }


	    // --- Create reader --- //
            listener = new commListener();
            reader = (commDataReader)
            subscriber.create_datareader(
                topic_subscriber, Subscriber.DATAREADER_QOS_DEFAULT, listener,
                StatusKind.STATUS_MASK_ALL);
            if (reader == null) {
                System.err.println("create_datareader error\n");
                return;
            }         

			    // *** PUBLICANDO *** //
			    //--------------------//

            final long sendPeriodMillis = 400; // 400 mili-seconds
	    String[] datosSensores = new String[10];    		    

	    int printDebug = 0;
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
			}
			else System.out.println("******** DATOS ARDUINO *********\n" + inputLine);
				
			instance.speed = Float.parseFloat(speed);
			instance.longitud = Float.parseFloat(longitud);
			instance.latitud = Float.parseFloat(latitud);
			instance.height = Float.parseFloat(altura);
			instance.pitch = Float.parseFloat(pitch); 		
                        instance.roll = Float.parseFloat(roll);
			writer.write(instance, instance_handle);

			System.out.println("*****************************");
                        System.out.println("VELOCIDADE: "+instance.speed);
                        System.out.println("LONGITUD: "+instance.longitud);
                        System.out.println("LATITUD: "+instance.latitud);
                        System.out.println("ALTURA: "+instance.height);
                        System.out.println("PITCH: "+instance.pitch);
                        System.out.println("ROLL: "+instance.roll);
			System.out.println("*****************************");
	
		}catch (Exception e){
			System.out.println(e);
	    	}
		
                try {
                    Thread.sleep(sendPeriodMillis);
		    printDebug ++;
                } catch (InterruptedException ix) {
                    System.err.println("INTERRUPTED");
                    break;
                }
            }
	 

        } finally {

            // --- Shutdown --- //

            if(participant != null) {
                participant.delete_contained_entities();

                DomainParticipantFactory.TheParticipantFactory.
                delete_participant(participant);
            }
        }
    }
}

