package io.opentimeline.opentimelineio;

import io.opentimeline.OTIONative;

public class SerializableObject extends OTIONative {

    public SerializableObject() {
        this.initObject();
    }

    public SerializableObject(long nativeHandle) {
        this.nativeHandle = nativeHandle;
    }

    private void initObject() {
        this.className = this.getClass().getCanonicalName();
        this.initialize();
    }

    private native void initialize();

    public native boolean toJSONFile(String fileName, ErrorStatus errorStatus);

    public native boolean toJSONFile(String fileName, ErrorStatus errorStatus, int indent);

    public native String toJSONString(ErrorStatus errorStatus);

    public native String toJSONString(ErrorStatus errorStatus, int indent);

    public static native SerializableObject fromJSONFile(String fileName, ErrorStatus errorStatus);

    public static native SerializableObject fromJSONString(String input, ErrorStatus errorStatus);

    public native boolean isEquivalentTo(SerializableObject serializableObject);

    public native SerializableObject clone(ErrorStatus errorStatus);

    public native AnyDictionary dynamicFields();

    public native boolean isUnknownSchema();

    public native String schemaName();

    public native int schemaVersion();

    public class Retainer extends OTIONative {

        public Retainer(SerializableObject value) {
            this.initialize(value);
        }

        public Retainer(Retainer retainer) {
            this.initialize(retainer.value());
        }

        private native void initialize(SerializableObject value);

        public native SerializableObject value();

        public native SerializableObject takeValue();

        private native void dispose();

        @Override
        public void close() throws Exception {
            dispose();
        }
    }

    public native int currentRefCount();

    private native void possiblyDispose();

    @Override
    public void close() throws Exception {
        possiblyDispose();
    }
}
