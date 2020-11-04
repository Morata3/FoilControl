

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

public class heightSensor   implements Copyable, Serializable{

    public String msg= (String)""; /* maximum length = (128) */

    public heightSensor() {

    }
    public heightSensor (heightSensor other) {

        this();
        copy_from(other);
    }

    public static Object create() {

        heightSensor self;
        self = new  heightSensor();
        self.clear();
        return self;

    }

    public void clear() {

        msg = (String)"";
    }

    public boolean equals(Object o) {

        if (o == null) {
            return false;
        }        

        if(getClass() != o.getClass()) {
            return false;
        }

        heightSensor otherObj = (heightSensor)o;

        if(!msg.equals(otherObj.msg)) {
            return false;
        }

        return true;
    }

    public int hashCode() {
        int __result = 0;
        __result += msg.hashCode(); 
        return __result;
    }

    /**
    * This is the implementation of the <code>Copyable</code> interface.
    * This method will perform a deep copy of <code>src</code>
    * This method could be placed into <code>heightSensorTypeSupport</code>
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

        heightSensor typedSrc = (heightSensor) src;
        heightSensor typedDst = this;

        typedDst.msg = typedSrc.msg;

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
        strBuffer.append("msg: ").append(msg).append("\n");  

        return strBuffer.toString();
    }

}
