

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

import com.rti.dds.infrastructure.*;
import com.rti.dds.infrastructure.Copyable;
import java.io.Serializable;
import com.rti.dds.cdr.CdrHelper;

public class comm   implements Copyable, Serializable{

    public float speed = (float)0;
    public float longitud = (float)0;
    public float latitud = (float)0;
    public float pitch = (float)0;
    public float roll = (float)0;
    public float height = (float)0;

    public comm() {

    }
    public comm (comm other) {

        this();
        copy_from(other);
    }

    public static Object create() {

        comm self;
        self = new  comm();
        self.clear();
        return self;

    }

    public void clear() {

        speed = (float)0;
        longitud = (float)0;
        latitud = (float)0;
        pitch = (float)0;
        roll = (float)0;
        height = (float)0;
    }

    public boolean equals(Object o) {

        if (o == null) {
            return false;
        }        

        if(getClass() != o.getClass()) {
            return false;
        }

        comm otherObj = (comm)o;

        if(speed != otherObj.speed) {
            return false;
        }
        if(longitud != otherObj.longitud) {
            return false;
        }
        if(latitud != otherObj.latitud) {
            return false;
        }
        if(pitch != otherObj.pitch) {
            return false;
        }
        if(roll != otherObj.roll) {
            return false;
        }
        if(height != otherObj.height) {
            return false;
        }

        return true;
    }

    public int hashCode() {
        int __result = 0;
        __result += (int)speed;
        __result += (int)longitud;
        __result += (int)latitud;
        __result += (int)pitch;
        __result += (int)roll;
        __result += (int)height;
        return __result;
    }

    /**
    * This is the implementation of the <code>Copyable</code> interface.
    * This method will perform a deep copy of <code>src</code>
    * This method could be placed into <code>commTypeSupport</code>
    * rather than here by using the <code>-noCopyable</code> option
    * to rtiddsgen.
    * 
    * @param src The Object which contains the data to be copied.
    * @return Returns <code>this</code>.
    * @exception NullPointerException If <code>src</code> is null.
    * @exception ClassCastException If <code>src</code> is not the 
    * same type as <code>this</code>.
    * @see com.rti.dds.infrastructure.Copyable#copy_from(java.lang.Object)
    */
    public Object copy_from(Object src) {

        comm typedSrc = (comm) src;
        comm typedDst = this;

        typedDst.speed = typedSrc.speed;
        typedDst.longitud = typedSrc.longitud;
        typedDst.latitud = typedSrc.latitud;
        typedDst.pitch = typedSrc.pitch;
        typedDst.roll = typedSrc.roll;
        typedDst.height = typedSrc.height;

        return this;
    }

    public String toString(){
        return toString("", 0);
    }

    public String toString(String desc, int indent) {
        StringBuffer strBuffer = new StringBuffer();        

        if (desc != null) {
            CdrHelper.printIndent(strBuffer, indent);
            strBuffer.append(desc).append(":\n");
        }

        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("speed: ").append(speed).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("longitud: ").append(longitud).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("latitud: ").append(latitud).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("pitch: ").append(pitch).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("roll: ").append(roll).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("height: ").append(height).append("\n");  

        return strBuffer.toString();
    }

}
