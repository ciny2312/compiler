#pragma once
#include <string>

class Val {
public:
  [[nodiscard]] virtual std::string to_string() const = 0;
};

class Imm : public Val {};

class ImmI32 : public Imm {
public:
  int val = 0;
  [[nodiscard]] std::string to_string() const override {
    return std::to_string(val);
  }
};

class StackVal;

class OffsetOfStackVal : public Imm {
public:
  friend class StackVal;
  [[nodiscard]] std::string to_string() const override;

private:
  explicit OffsetOfStackVal(StackVal *stackVal) : stackVal(stackVal) {}
  StackVal *stackVal = nullptr;
};

class StackVal : public Val {
public:
  StackVal() = default;
  int offset = 0;
  OffsetOfStackVal *get_offset();
  [[nodiscard]] std::string to_string() const override {
    return "stack[" + std::to_string(offset) + ']';
  }

private:
  OffsetOfStackVal *offsetOfStackVal = nullptr;
};

class GlobalVal;

class RelocationFunction : public Imm {
public:
  friend class GlobalVal;
  [[nodiscard]] std::string to_string() const override;

private:
  explicit RelocationFunction(std::string type, GlobalVal *globalVal)
      : type(std::move(type)), globalVal(globalVal) {}
  std::string type;
  GlobalVal *globalVal = nullptr;
};

class GlobalPosition : public Imm {
public:
  friend class GlobalVal;
  [[nodiscard]] std::string to_string() const override;

private:
  explicit GlobalPosition(GlobalVal *globalVal) : globalVal(globalVal) {}
  GlobalVal *globalVal = nullptr;
};

class GlobalVal : public Val {
public:
  explicit GlobalVal(std::string name) : name(std::move(name)) {}
  [[nodiscard]] std::string to_string() const override { return name; }
  RelocationFunction *get_hi();
  RelocationFunction *get_lo();
  GlobalPosition *get_pos();

public:
  std::string name;

private:
  RelocationFunction *hi = nullptr, *lo = nullptr;
  GlobalPosition *gp = nullptr;
};