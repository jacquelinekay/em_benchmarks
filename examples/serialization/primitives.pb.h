// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: primitives.proto

#ifndef PROTOBUF_primitives_2eproto__INCLUDED
#define PROTOBUF_primitives_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace em_benchmarks {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_primitives_2eproto();
void protobuf_AssignDesc_primitives_2eproto();
void protobuf_ShutdownFile_primitives_2eproto();

class Primitives;

// ===================================================================

class Primitives : public ::google::protobuf::Message {
 public:
  Primitives();
  virtual ~Primitives();

  Primitives(const Primitives& from);

  inline Primitives& operator=(const Primitives& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Primitives& default_instance();

  void Swap(Primitives* other);

  // implements Message ----------------------------------------------

  Primitives* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Primitives& from);
  void MergeFrom(const Primitives& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 int32_value = 1;
  inline bool has_int32_value() const;
  inline void clear_int32_value();
  static const int kInt32ValueFieldNumber = 1;
  inline ::google::protobuf::int32 int32_value() const;
  inline void set_int32_value(::google::protobuf::int32 value);

  // required uint32 uint32_value = 2;
  inline bool has_uint32_value() const;
  inline void clear_uint32_value();
  static const int kUint32ValueFieldNumber = 2;
  inline ::google::protobuf::uint32 uint32_value() const;
  inline void set_uint32_value(::google::protobuf::uint32 value);

  // required int64 int64_value = 3;
  inline bool has_int64_value() const;
  inline void clear_int64_value();
  static const int kInt64ValueFieldNumber = 3;
  inline ::google::protobuf::int64 int64_value() const;
  inline void set_int64_value(::google::protobuf::int64 value);

  // required uint64 uint64_value = 4;
  inline bool has_uint64_value() const;
  inline void clear_uint64_value();
  static const int kUint64ValueFieldNumber = 4;
  inline ::google::protobuf::uint64 uint64_value() const;
  inline void set_uint64_value(::google::protobuf::uint64 value);

  // required double double_value = 5;
  inline bool has_double_value() const;
  inline void clear_double_value();
  static const int kDoubleValueFieldNumber = 5;
  inline double double_value() const;
  inline void set_double_value(double value);

  // required float float_value = 6;
  inline bool has_float_value() const;
  inline void clear_float_value();
  static const int kFloatValueFieldNumber = 6;
  inline float float_value() const;
  inline void set_float_value(float value);

  // required bool bool_value = 7;
  inline bool has_bool_value() const;
  inline void clear_bool_value();
  static const int kBoolValueFieldNumber = 7;
  inline bool bool_value() const;
  inline void set_bool_value(bool value);

  // required string string_value = 8;
  inline bool has_string_value() const;
  inline void clear_string_value();
  static const int kStringValueFieldNumber = 8;
  inline const ::std::string& string_value() const;
  inline void set_string_value(const ::std::string& value);
  inline void set_string_value(const char* value);
  inline void set_string_value(const char* value, size_t size);
  inline ::std::string* mutable_string_value();
  inline ::std::string* release_string_value();
  inline void set_allocated_string_value(::std::string* string_value);

  // @@protoc_insertion_point(class_scope:em_benchmarks.Primitives)
 private:
  inline void set_has_int32_value();
  inline void clear_has_int32_value();
  inline void set_has_uint32_value();
  inline void clear_has_uint32_value();
  inline void set_has_int64_value();
  inline void clear_has_int64_value();
  inline void set_has_uint64_value();
  inline void clear_has_uint64_value();
  inline void set_has_double_value();
  inline void clear_has_double_value();
  inline void set_has_float_value();
  inline void clear_has_float_value();
  inline void set_has_bool_value();
  inline void clear_has_bool_value();
  inline void set_has_string_value();
  inline void clear_has_string_value();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 int32_value_;
  ::google::protobuf::uint32 uint32_value_;
  ::google::protobuf::int64 int64_value_;
  ::google::protobuf::uint64 uint64_value_;
  double double_value_;
  float float_value_;
  bool bool_value_;
  ::std::string* string_value_;
  friend void  protobuf_AddDesc_primitives_2eproto();
  friend void protobuf_AssignDesc_primitives_2eproto();
  friend void protobuf_ShutdownFile_primitives_2eproto();

  void InitAsDefaultInstance();
  static Primitives* default_instance_;
};
// ===================================================================


// ===================================================================

// Primitives

// required int32 int32_value = 1;
inline bool Primitives::has_int32_value() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Primitives::set_has_int32_value() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Primitives::clear_has_int32_value() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Primitives::clear_int32_value() {
  int32_value_ = 0;
  clear_has_int32_value();
}
inline ::google::protobuf::int32 Primitives::int32_value() const {
  // @@protoc_insertion_point(field_get:em_benchmarks.Primitives.int32_value)
  return int32_value_;
}
inline void Primitives::set_int32_value(::google::protobuf::int32 value) {
  set_has_int32_value();
  int32_value_ = value;
  // @@protoc_insertion_point(field_set:em_benchmarks.Primitives.int32_value)
}

// required uint32 uint32_value = 2;
inline bool Primitives::has_uint32_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Primitives::set_has_uint32_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Primitives::clear_has_uint32_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Primitives::clear_uint32_value() {
  uint32_value_ = 0u;
  clear_has_uint32_value();
}
inline ::google::protobuf::uint32 Primitives::uint32_value() const {
  // @@protoc_insertion_point(field_get:em_benchmarks.Primitives.uint32_value)
  return uint32_value_;
}
inline void Primitives::set_uint32_value(::google::protobuf::uint32 value) {
  set_has_uint32_value();
  uint32_value_ = value;
  // @@protoc_insertion_point(field_set:em_benchmarks.Primitives.uint32_value)
}

// required int64 int64_value = 3;
inline bool Primitives::has_int64_value() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Primitives::set_has_int64_value() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Primitives::clear_has_int64_value() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Primitives::clear_int64_value() {
  int64_value_ = GOOGLE_LONGLONG(0);
  clear_has_int64_value();
}
inline ::google::protobuf::int64 Primitives::int64_value() const {
  // @@protoc_insertion_point(field_get:em_benchmarks.Primitives.int64_value)
  return int64_value_;
}
inline void Primitives::set_int64_value(::google::protobuf::int64 value) {
  set_has_int64_value();
  int64_value_ = value;
  // @@protoc_insertion_point(field_set:em_benchmarks.Primitives.int64_value)
}

// required uint64 uint64_value = 4;
inline bool Primitives::has_uint64_value() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Primitives::set_has_uint64_value() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Primitives::clear_has_uint64_value() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Primitives::clear_uint64_value() {
  uint64_value_ = GOOGLE_ULONGLONG(0);
  clear_has_uint64_value();
}
inline ::google::protobuf::uint64 Primitives::uint64_value() const {
  // @@protoc_insertion_point(field_get:em_benchmarks.Primitives.uint64_value)
  return uint64_value_;
}
inline void Primitives::set_uint64_value(::google::protobuf::uint64 value) {
  set_has_uint64_value();
  uint64_value_ = value;
  // @@protoc_insertion_point(field_set:em_benchmarks.Primitives.uint64_value)
}

// required double double_value = 5;
inline bool Primitives::has_double_value() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Primitives::set_has_double_value() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Primitives::clear_has_double_value() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Primitives::clear_double_value() {
  double_value_ = 0;
  clear_has_double_value();
}
inline double Primitives::double_value() const {
  // @@protoc_insertion_point(field_get:em_benchmarks.Primitives.double_value)
  return double_value_;
}
inline void Primitives::set_double_value(double value) {
  set_has_double_value();
  double_value_ = value;
  // @@protoc_insertion_point(field_set:em_benchmarks.Primitives.double_value)
}

// required float float_value = 6;
inline bool Primitives::has_float_value() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Primitives::set_has_float_value() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Primitives::clear_has_float_value() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Primitives::clear_float_value() {
  float_value_ = 0;
  clear_has_float_value();
}
inline float Primitives::float_value() const {
  // @@protoc_insertion_point(field_get:em_benchmarks.Primitives.float_value)
  return float_value_;
}
inline void Primitives::set_float_value(float value) {
  set_has_float_value();
  float_value_ = value;
  // @@protoc_insertion_point(field_set:em_benchmarks.Primitives.float_value)
}

// required bool bool_value = 7;
inline bool Primitives::has_bool_value() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Primitives::set_has_bool_value() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Primitives::clear_has_bool_value() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Primitives::clear_bool_value() {
  bool_value_ = false;
  clear_has_bool_value();
}
inline bool Primitives::bool_value() const {
  // @@protoc_insertion_point(field_get:em_benchmarks.Primitives.bool_value)
  return bool_value_;
}
inline void Primitives::set_bool_value(bool value) {
  set_has_bool_value();
  bool_value_ = value;
  // @@protoc_insertion_point(field_set:em_benchmarks.Primitives.bool_value)
}

// required string string_value = 8;
inline bool Primitives::has_string_value() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Primitives::set_has_string_value() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Primitives::clear_has_string_value() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Primitives::clear_string_value() {
  if (string_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    string_value_->clear();
  }
  clear_has_string_value();
}
inline const ::std::string& Primitives::string_value() const {
  // @@protoc_insertion_point(field_get:em_benchmarks.Primitives.string_value)
  return *string_value_;
}
inline void Primitives::set_string_value(const ::std::string& value) {
  set_has_string_value();
  if (string_value_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    string_value_ = new ::std::string;
  }
  string_value_->assign(value);
  // @@protoc_insertion_point(field_set:em_benchmarks.Primitives.string_value)
}
inline void Primitives::set_string_value(const char* value) {
  set_has_string_value();
  if (string_value_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    string_value_ = new ::std::string;
  }
  string_value_->assign(value);
  // @@protoc_insertion_point(field_set_char:em_benchmarks.Primitives.string_value)
}
inline void Primitives::set_string_value(const char* value, size_t size) {
  set_has_string_value();
  if (string_value_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    string_value_ = new ::std::string;
  }
  string_value_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:em_benchmarks.Primitives.string_value)
}
inline ::std::string* Primitives::mutable_string_value() {
  set_has_string_value();
  if (string_value_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    string_value_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:em_benchmarks.Primitives.string_value)
  return string_value_;
}
inline ::std::string* Primitives::release_string_value() {
  clear_has_string_value();
  if (string_value_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = string_value_;
    string_value_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Primitives::set_allocated_string_value(::std::string* string_value) {
  if (string_value_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete string_value_;
  }
  if (string_value) {
    set_has_string_value();
    string_value_ = string_value;
  } else {
    clear_has_string_value();
    string_value_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:em_benchmarks.Primitives.string_value)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace em_benchmarks

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_primitives_2eproto__INCLUDED
