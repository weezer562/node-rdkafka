/*
 * node-rdkafka - Node.js wrapper for RdKafka C/C++ library
 *
 * Copyright (c) 2016 Blizzard Entertainment
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE.txt file for details.
 */

#ifndef SRC_ERRORS_H_
#define SRC_ERRORS_H_

#include <nan.h>
#include <iostream>
#include <string>

#include "deps/librdkafka/src-cpp/rdkafkacpp.h"

#include "src/common.h"

namespace NodeKafka {

class Baton {
 public:
  explicit Baton(const RdKafka::ErrorCode &);
  explicit Baton(void* data);

  template<typename T> T data() {
    return static_cast<T>(m_data);
  }

  RdKafka::ErrorCode err();

  v8::Local<v8::Object> ToObject();

 private:
  void* m_data;
  RdKafka::ErrorCode m_err;
};

v8::Local<v8::Object> RdKafkaError(const RdKafka::ErrorCode &);

}  // namespace NodeKafka

#endif  // SRC_ERRORS_H_
