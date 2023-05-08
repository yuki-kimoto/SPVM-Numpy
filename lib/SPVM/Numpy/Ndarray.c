#include "spvm_native.h"

static const char* FILE_NAME = "Numpy/Ndarray.c";

int32_t SPVM__Numpy__Ndarray__new_ones(SPVM_ENV* env, SPVM_VALUE* stack) {
  (void)env;
  (void)stack;
  
  int32_t e = 0;
  
  void* obj_shape = stack[0].oval;
  
  if (!obj_shape) {
    return env->die(env, stack, "The $shape must be defined", __func__, FILE_NAME, __LINE__);
  }
  
  int32_t dtype = stack[1].ival;
  
  if (dtype == -1) {
    e = env->call_class_method_by_name(env, stack, "Numpy::Constant::Dtype", "FLOAT64", 0, __func__, FILE_NAME, __LINE__);
    if (e) { return e; }
    dtype = stack[0].ival;
  }

  int32_t nbytes;
  {
    stack[0].oval = obj_shape;
    stack[1].ival = dtype;
    e = env->call_class_method_by_name(env, stack, "Numpy::Util", "calc_ndarray_nbytes", 2, __func__, FILE_NAME, __LINE__);
    if (e) { return e; }
    nbytes = stack[0].ival;
  }
  
  void* obj_data = env->new_string(env, stack, NULL, nbytes);
  int32_t data_nbytes = env->length(env, stack, obj_data);
  int32_t itemsize;
  {
    stack[0].ival = dtype;
    e = env->call_class_method_by_name(env, stack, "Numpy::Util", "get_ndarray_itemsize", 1, __func__, FILE_NAME, __LINE__);
    if (e) { return e; }
    itemsize = stack[0].ival;
  }
  
  switch (dtype) {
    case BOOL8: {
      int8_t* data = (int8_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    INT8: {
      int8_t* data = (int8_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    INT16: {
      int16_t* data = (int16_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    INT32: {
      int32_t* data = (int32_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    INT64: {
      int64_t* data = (int64_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    UINT8: {
      uint8_t* data = (uint8_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    UINT16: {
      uint16_t* data = (uint16_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    UINT32: {
      uint32_t* data = (uint32_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    UINT64: {
      uint64_t* data = (uint64_t*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    INTP: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
    UINTP: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
    FLOAT16: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
    FLOAT32: {
      float* data = (float*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    FLOAT64: {
      double* data = (double*)env->get_chars(env, stack, obj_data);
      for (int32_t i = 0; i < data_nbytes / itemsize; i++) {
        data[i] = 1;
      }
      break;
    }
    FLOAT96: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
    FLOAT128: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
    COMPLEX64: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
    COMPLEX128: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
    COMPLEX192: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
    COMPLEX256: {
      return env->die(env, stack, "Not implemented", __func__, FILE_NAME, __LINE__);
      break;
    }
  }
  
  void* obj_self = env->new_object_by_name(env, stack, "Numpy::Ndarray", &e, __func__, FILE_NAME, __LINE__);
  if (e) { return e; }
  
  env->set_field_byte_by_name(env, stack, obj_data, "dtype", dtype, &e, __func__, FILE_NAME, __LINE__);
  if (e) { return e; }
  
  env->set_field_object_by_name(env, stack, obj_data, "data", obj_data, &e, __func__, FILE_NAME, __LINE__);
  if (e) { return e; }
  
  stack[0].oval = obj_self;
  
  return 0;
}
