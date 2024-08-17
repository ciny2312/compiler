#include "type.h"
#include "function.h"
#include <memory>
std::shared_ptr<Typename> GetStringTypename() {
  Typename t("string");
  Function length(IntType, {});
  t.add_function("length", length);
  Function substring(StringType, {IntType, IntType});
  t.add_function("substring", substring);
  Function parse_int(IntType, {});
  t.add_function("parseInt", parse_int);
  Function ord(IntType, {IntType});
  t.add_function("ord", ord);
  return std::make_shared<Typename>(t);
}