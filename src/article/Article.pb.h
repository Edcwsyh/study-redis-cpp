// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Article.proto

#ifndef PROTOBUF_INCLUDED_Article_2eproto
#define PROTOBUF_INCLUDED_Article_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_Article_2eproto 

namespace protobuf_Article_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_Article_2eproto
namespace Edc {
class Article;
class ArticleDefaultTypeInternal;
extern ArticleDefaultTypeInternal _Article_default_instance_;
class ArticleData;
class ArticleDataDefaultTypeInternal;
extern ArticleDataDefaultTypeInternal _ArticleData_default_instance_;
}  // namespace Edc
namespace google {
namespace protobuf {
template<> ::Edc::Article* Arena::CreateMaybeMessage<::Edc::Article>(Arena*);
template<> ::Edc::ArticleData* Arena::CreateMaybeMessage<::Edc::ArticleData>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace Edc {

// ===================================================================

class ArticleData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Edc.ArticleData) */ {
 public:
  ArticleData();
  virtual ~ArticleData();

  ArticleData(const ArticleData& from);

  inline ArticleData& operator=(const ArticleData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ArticleData(ArticleData&& from) noexcept
    : ArticleData() {
    *this = ::std::move(from);
  }

  inline ArticleData& operator=(ArticleData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ArticleData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ArticleData* internal_default_instance() {
    return reinterpret_cast<const ArticleData*>(
               &_ArticleData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ArticleData* other);
  friend void swap(ArticleData& a, ArticleData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ArticleData* New() const final {
    return CreateMaybeMessage<ArticleData>(NULL);
  }

  ArticleData* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ArticleData>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ArticleData& from);
  void MergeFrom(const ArticleData& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ArticleData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string title = 2;
  void clear_title();
  static const int kTitleFieldNumber = 2;
  const ::std::string& title() const;
  void set_title(const ::std::string& value);
  #if LANG_CXX11
  void set_title(::std::string&& value);
  #endif
  void set_title(const char* value);
  void set_title(const char* value, size_t size);
  ::std::string* mutable_title();
  ::std::string* release_title();
  void set_allocated_title(::std::string* title);

  // string content = 3;
  void clear_content();
  static const int kContentFieldNumber = 3;
  const ::std::string& content() const;
  void set_content(const ::std::string& value);
  #if LANG_CXX11
  void set_content(::std::string&& value);
  #endif
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  ::std::string* mutable_content();
  ::std::string* release_content();
  void set_allocated_content(::std::string* content);

  // string autor = 4;
  void clear_autor();
  static const int kAutorFieldNumber = 4;
  const ::std::string& autor() const;
  void set_autor(const ::std::string& value);
  #if LANG_CXX11
  void set_autor(::std::string&& value);
  #endif
  void set_autor(const char* value);
  void set_autor(const char* value, size_t size);
  ::std::string* mutable_autor();
  ::std::string* release_autor();
  void set_allocated_autor(::std::string* autor);

  // uint64 createTime = 1;
  void clear_createtime();
  static const int kCreateTimeFieldNumber = 1;
  ::google::protobuf::uint64 createtime() const;
  void set_createtime(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:Edc.ArticleData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr title_;
  ::google::protobuf::internal::ArenaStringPtr content_;
  ::google::protobuf::internal::ArenaStringPtr autor_;
  ::google::protobuf::uint64 createtime_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_Article_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Article : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Edc.Article) */ {
 public:
  Article();
  virtual ~Article();

  Article(const Article& from);

  inline Article& operator=(const Article& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Article(Article&& from) noexcept
    : Article() {
    *this = ::std::move(from);
  }

  inline Article& operator=(Article&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Article& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Article* internal_default_instance() {
    return reinterpret_cast<const Article*>(
               &_Article_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Article* other);
  friend void swap(Article& a, Article& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Article* New() const final {
    return CreateMaybeMessage<Article>(NULL);
  }

  Article* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Article>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Article& from);
  void MergeFrom(const Article& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Article* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .Edc.ArticleData articleData = 3;
  bool has_articledata() const;
  void clear_articledata();
  static const int kArticleDataFieldNumber = 3;
  private:
  const ::Edc::ArticleData& _internal_articledata() const;
  public:
  const ::Edc::ArticleData& articledata() const;
  ::Edc::ArticleData* release_articledata();
  ::Edc::ArticleData* mutable_articledata();
  void set_allocated_articledata(::Edc::ArticleData* articledata);

  // uint64 articleID = 1;
  void clear_articleid();
  static const int kArticleIDFieldNumber = 1;
  ::google::protobuf::uint64 articleid() const;
  void set_articleid(::google::protobuf::uint64 value);

  // uint64 score = 2;
  void clear_score();
  static const int kScoreFieldNumber = 2;
  ::google::protobuf::uint64 score() const;
  void set_score(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:Edc.Article)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::Edc::ArticleData* articledata_;
  ::google::protobuf::uint64 articleid_;
  ::google::protobuf::uint64 score_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_Article_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ArticleData

// uint64 createTime = 1;
inline void ArticleData::clear_createtime() {
  createtime_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 ArticleData::createtime() const {
  // @@protoc_insertion_point(field_get:Edc.ArticleData.createTime)
  return createtime_;
}
inline void ArticleData::set_createtime(::google::protobuf::uint64 value) {
  
  createtime_ = value;
  // @@protoc_insertion_point(field_set:Edc.ArticleData.createTime)
}

// string title = 2;
inline void ArticleData::clear_title() {
  title_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ArticleData::title() const {
  // @@protoc_insertion_point(field_get:Edc.ArticleData.title)
  return title_.GetNoArena();
}
inline void ArticleData::set_title(const ::std::string& value) {
  
  title_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Edc.ArticleData.title)
}
#if LANG_CXX11
inline void ArticleData::set_title(::std::string&& value) {
  
  title_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Edc.ArticleData.title)
}
#endif
inline void ArticleData::set_title(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  title_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Edc.ArticleData.title)
}
inline void ArticleData::set_title(const char* value, size_t size) {
  
  title_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Edc.ArticleData.title)
}
inline ::std::string* ArticleData::mutable_title() {
  
  // @@protoc_insertion_point(field_mutable:Edc.ArticleData.title)
  return title_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ArticleData::release_title() {
  // @@protoc_insertion_point(field_release:Edc.ArticleData.title)
  
  return title_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ArticleData::set_allocated_title(::std::string* title) {
  if (title != NULL) {
    
  } else {
    
  }
  title_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), title);
  // @@protoc_insertion_point(field_set_allocated:Edc.ArticleData.title)
}

// string content = 3;
inline void ArticleData::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ArticleData::content() const {
  // @@protoc_insertion_point(field_get:Edc.ArticleData.content)
  return content_.GetNoArena();
}
inline void ArticleData::set_content(const ::std::string& value) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Edc.ArticleData.content)
}
#if LANG_CXX11
inline void ArticleData::set_content(::std::string&& value) {
  
  content_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Edc.ArticleData.content)
}
#endif
inline void ArticleData::set_content(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Edc.ArticleData.content)
}
inline void ArticleData::set_content(const char* value, size_t size) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Edc.ArticleData.content)
}
inline ::std::string* ArticleData::mutable_content() {
  
  // @@protoc_insertion_point(field_mutable:Edc.ArticleData.content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ArticleData::release_content() {
  // @@protoc_insertion_point(field_release:Edc.ArticleData.content)
  
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ArticleData::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    
  } else {
    
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:Edc.ArticleData.content)
}

// string autor = 4;
inline void ArticleData::clear_autor() {
  autor_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ArticleData::autor() const {
  // @@protoc_insertion_point(field_get:Edc.ArticleData.autor)
  return autor_.GetNoArena();
}
inline void ArticleData::set_autor(const ::std::string& value) {
  
  autor_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Edc.ArticleData.autor)
}
#if LANG_CXX11
inline void ArticleData::set_autor(::std::string&& value) {
  
  autor_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Edc.ArticleData.autor)
}
#endif
inline void ArticleData::set_autor(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  autor_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Edc.ArticleData.autor)
}
inline void ArticleData::set_autor(const char* value, size_t size) {
  
  autor_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Edc.ArticleData.autor)
}
inline ::std::string* ArticleData::mutable_autor() {
  
  // @@protoc_insertion_point(field_mutable:Edc.ArticleData.autor)
  return autor_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ArticleData::release_autor() {
  // @@protoc_insertion_point(field_release:Edc.ArticleData.autor)
  
  return autor_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ArticleData::set_allocated_autor(::std::string* autor) {
  if (autor != NULL) {
    
  } else {
    
  }
  autor_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), autor);
  // @@protoc_insertion_point(field_set_allocated:Edc.ArticleData.autor)
}

// -------------------------------------------------------------------

// Article

// uint64 articleID = 1;
inline void Article::clear_articleid() {
  articleid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Article::articleid() const {
  // @@protoc_insertion_point(field_get:Edc.Article.articleID)
  return articleid_;
}
inline void Article::set_articleid(::google::protobuf::uint64 value) {
  
  articleid_ = value;
  // @@protoc_insertion_point(field_set:Edc.Article.articleID)
}

// uint64 score = 2;
inline void Article::clear_score() {
  score_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Article::score() const {
  // @@protoc_insertion_point(field_get:Edc.Article.score)
  return score_;
}
inline void Article::set_score(::google::protobuf::uint64 value) {
  
  score_ = value;
  // @@protoc_insertion_point(field_set:Edc.Article.score)
}

// .Edc.ArticleData articleData = 3;
inline bool Article::has_articledata() const {
  return this != internal_default_instance() && articledata_ != NULL;
}
inline void Article::clear_articledata() {
  if (GetArenaNoVirtual() == NULL && articledata_ != NULL) {
    delete articledata_;
  }
  articledata_ = NULL;
}
inline const ::Edc::ArticleData& Article::_internal_articledata() const {
  return *articledata_;
}
inline const ::Edc::ArticleData& Article::articledata() const {
  const ::Edc::ArticleData* p = articledata_;
  // @@protoc_insertion_point(field_get:Edc.Article.articleData)
  return p != NULL ? *p : *reinterpret_cast<const ::Edc::ArticleData*>(
      &::Edc::_ArticleData_default_instance_);
}
inline ::Edc::ArticleData* Article::release_articledata() {
  // @@protoc_insertion_point(field_release:Edc.Article.articleData)
  
  ::Edc::ArticleData* temp = articledata_;
  articledata_ = NULL;
  return temp;
}
inline ::Edc::ArticleData* Article::mutable_articledata() {
  
  if (articledata_ == NULL) {
    auto* p = CreateMaybeMessage<::Edc::ArticleData>(GetArenaNoVirtual());
    articledata_ = p;
  }
  // @@protoc_insertion_point(field_mutable:Edc.Article.articleData)
  return articledata_;
}
inline void Article::set_allocated_articledata(::Edc::ArticleData* articledata) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete articledata_;
  }
  if (articledata) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      articledata = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, articledata, submessage_arena);
    }
    
  } else {
    
  }
  articledata_ = articledata;
  // @@protoc_insertion_point(field_set_allocated:Edc.Article.articleData)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Edc

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_Article_2eproto
