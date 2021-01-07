
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

import com.rti.dds.typecode.*;

public class  commTypeCode {
    public static final TypeCode VALUE = getTypeCode();

    private static TypeCode getTypeCode() {
        TypeCode tc = null;
        int __i=0;
        StructMember sm[]=new StructMember[6];
        Annotations memberAnnotation;

        memberAnnotation = new Annotations();
        memberAnnotation.default_annotation(AnnotationParameterValue.ZERO_FLOAT);
        memberAnnotation.min_annotation(AnnotationParameterValue.MIN_FLOAT);
        memberAnnotation.max_annotation(AnnotationParameterValue.MAX_FLOAT);
        sm[__i] = new  StructMember("speed", false, (short)-1,  false, TypeCode.TC_FLOAT, 0, false, memberAnnotation);__i++;
        memberAnnotation = new Annotations();
        memberAnnotation.default_annotation(AnnotationParameterValue.ZERO_FLOAT);
        memberAnnotation.min_annotation(AnnotationParameterValue.MIN_FLOAT);
        memberAnnotation.max_annotation(AnnotationParameterValue.MAX_FLOAT);
        sm[__i] = new  StructMember("longitud", false, (short)-1,  false, TypeCode.TC_FLOAT, 1, false, memberAnnotation);__i++;
        memberAnnotation = new Annotations();
        memberAnnotation.default_annotation(AnnotationParameterValue.ZERO_FLOAT);
        memberAnnotation.min_annotation(AnnotationParameterValue.MIN_FLOAT);
        memberAnnotation.max_annotation(AnnotationParameterValue.MAX_FLOAT);
        sm[__i] = new  StructMember("latitud", false, (short)-1,  false, TypeCode.TC_FLOAT, 2, false, memberAnnotation);__i++;
        memberAnnotation = new Annotations();
        memberAnnotation.default_annotation(AnnotationParameterValue.ZERO_FLOAT);
        memberAnnotation.min_annotation(AnnotationParameterValue.MIN_FLOAT);
        memberAnnotation.max_annotation(AnnotationParameterValue.MAX_FLOAT);
        sm[__i] = new  StructMember("pitch", false, (short)-1,  false, TypeCode.TC_FLOAT, 3, false, memberAnnotation);__i++;
        memberAnnotation = new Annotations();
        memberAnnotation.default_annotation(AnnotationParameterValue.ZERO_FLOAT);
        memberAnnotation.min_annotation(AnnotationParameterValue.MIN_FLOAT);
        memberAnnotation.max_annotation(AnnotationParameterValue.MAX_FLOAT);
        sm[__i] = new  StructMember("roll", false, (short)-1,  false, TypeCode.TC_FLOAT, 4, false, memberAnnotation);__i++;
        memberAnnotation = new Annotations();
        memberAnnotation.default_annotation(AnnotationParameterValue.ZERO_FLOAT);
        memberAnnotation.min_annotation(AnnotationParameterValue.MIN_FLOAT);
        memberAnnotation.max_annotation(AnnotationParameterValue.MAX_FLOAT);
        sm[__i] = new  StructMember("height", false, (short)-1,  false, TypeCode.TC_FLOAT, 5, false, memberAnnotation);__i++;

        Annotations annotation = new Annotations();
        annotation.allowed_data_representation_mask(5);

        tc = TypeCodeFactory.TheTypeCodeFactory.create_struct_tc("comm",ExtensibilityKind.EXTENSIBLE_EXTENSIBILITY,  sm , annotation);        
        return tc;
    }
}

