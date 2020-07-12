#include <handle.h>
#include <io_opentimeline_opentimelineio_AnyDictionary.h>
#include <utilities.h>

#include <opentimelineio/anyDictionary.h>
#include <opentimelineio/version.h>

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_AnyDictionary_initialize(JNIEnv *env,
                                                             jobject thisObj) {
  OTIO_NS::AnyDictionary *anyDictionary = new OTIO_NS::AnyDictionary();
  setHandle(env, thisObj, anyDictionary);
}

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    containsKeyNative
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_opentimeline_opentimelineio_AnyDictionary_containsKeyNative(
    JNIEnv *env, jobject thisObj, jstring keyStr) {
  auto thisHandle = getHandle<OTIO_NS::AnyDictionary>(env, thisObj);
  if (thisHandle->find(env->GetStringUTFChars(keyStr, 0)) ==
      thisHandle->end()) {
    return false;
  }
  return true;
}

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    getNative
 * Signature: (Ljava/lang/String;)Lio/opentimeline/opentimelineio/Any;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_AnyDictionary_getNative(JNIEnv *env,
                                                            jobject thisObj,
                                                            jstring keyStr) {
  auto thisHandle = getHandle<OTIO_NS::AnyDictionary>(env, thisObj);
  auto result = thisHandle->at(env->GetStringUTFChars(keyStr, 0));
  return anyFromNative(env, new OTIO_NS::any(result));
}

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    size
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_size(
    JNIEnv *env, jobject thisObj) {
  auto thisHandle = getHandle<OTIO_NS::AnyDictionary>(env, thisObj);
  return thisHandle->size();
}

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    putNative
 * Signature:
 * (Ljava/lang/String;Lio/opentimeline/opentimelineio/Any;)Lio/opentimeline/opentimelineio/Any;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_AnyDictionary_putNative(
    JNIEnv *env, jobject thisObj, jstring keyStr, jobject valueAnyObj) {
  auto thisHandle = getHandle<OTIO_NS::AnyDictionary>(env, thisObj);
  auto valueAnyHandle = getHandle<OTIO_NS::any>(env, valueAnyObj);
  std::pair<OTIO_NS::AnyDictionary::iterator, bool> resultPair =
      thisHandle->insert(std::pair<std::string, OTIO_NS::any>(
          env->GetStringUTFChars(keyStr, 0), *valueAnyHandle));
  if (resultPair.second) {
    return nullptr;
  } else {
    return anyFromNative(env, new OTIO_NS::any(resultPair.first->second));
  }
}

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    replaceNative
 * Signature:
 * (Ljava/lang/String;Lio/opentimeline/opentimelineio/Any;)Lio/opentimeline/opentimelineio/Any;
 */
JNIEXPORT jobject JNICALL
Java_io_opentimeline_opentimelineio_AnyDictionary_replaceNative(
    JNIEnv *env, jobject thisObj, jstring keyStr, jobject valueAnyObj) {
  auto thisHandle = getHandle<OTIO_NS::AnyDictionary>(env, thisObj);
  auto valueAnyHandle = getHandle<OTIO_NS::any>(env, valueAnyObj);
  if (thisHandle->find(env->GetStringUTFChars(keyStr, 0)) ==
      thisHandle->end()) {
    return nullptr;
  } else {
    auto prev =
        new OTIO_NS::any((*thisHandle)[env->GetStringUTFChars(keyStr, 0)]);
    (*thisHandle)[env->GetStringUTFChars(keyStr, 0)] = *valueAnyHandle;
    return anyFromNative(env, prev);
  }
}

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    clear
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_clear(
    JNIEnv *env, jobject thisObj) {
  auto thisHandle = getHandle<OTIO_NS::AnyDictionary>(env, thisObj);
  thisHandle->clear();
}

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    remove
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_io_opentimeline_opentimelineio_AnyDictionary_remove(
    JNIEnv *env, jobject thisObj, jstring keyStr) {
  auto thisHandle = getHandle<OTIO_NS::AnyDictionary>(env, thisObj);
  return thisHandle->erase(env->GetStringUTFChars(keyStr, 0));
}

/*
 * Class:     io_opentimeline_opentimelineio_AnyDictionary
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_io_opentimeline_opentimelineio_AnyDictionary_dispose(JNIEnv *env,
                                                          jobject thisObj) {
  OTIO_NS::AnyDictionary *anyDictionary =
      getHandle<OTIO_NS::AnyDictionary>(env, thisObj);
  setHandle<OTIO_NS::AnyDictionary>(env, thisObj, nullptr);
  delete anyDictionary;
}
