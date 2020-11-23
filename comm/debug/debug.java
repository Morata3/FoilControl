

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

public class debug   implements Copyable, Serializable{

    public float pitch = (float)0;
    public float roll = (float)0;
    public float height = (float)0;
    public float speed = (float)0;

    public debug() {

    }
    public debug (debug other) {

        this();
        copy_from(other);
    }

    public static Object create() {

        debug self;
        self = new  debug();
        self.clear();
        return self;

    }

    public void clear() {

        pitch = (float)0;
        roll = (float)0;
        height = (float)0;
        speed = (float)0;
    }

    public boolean equals(Object o) {

        if (o == null) {
            return false;
        }        

        if(getClass() != o.getClass()) {
            return false;
        }

        debug otherObj = (debug)o;

        if(pitch != otherObj.pitch) {
            return false;
        }
        if(roll != otherObj.roll) {
            return false;
        }
        if(height != otherObj.height) {
            return false;
        }
        if(speed != otherObj.speed) {
            return false;
        }

        return true;
    }

    public int hashCode() {
        int __result = 0;
        __result += (int)pitch;
        __result += (int)roll;
        __result += (int)height;
        __result += (int)speed;
        return __result;
    }

    /**
    * This is the implementation of the <code>Copyable</code> interface.
    * This method will perform a deep copy of <code>src</code>
    * This method could be placed into <code>debugTypeSupport</code>
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

        debug typedSrc = (debug) src;
        debug typedDst = this;

        typedDst.pitch = typedSrc.pitch;
        typedDst.roll = typedSrc.roll;
        typedDst.height = typedSrc.height;
        typedDst.speed = typedSrc.speed;

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
        strBuffer.append("pitch: ").append(pitch).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("roll: ").append(roll).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("height: ").append(height).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("speed: ").append(speed).append("\n");  

        return strBuffer.toString();
    }

}
