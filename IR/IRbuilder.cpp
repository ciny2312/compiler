#include "IRbuilder.h"
#include "AST/ASTVisitor.h"
#include "IR/IRType.h"
#include "IR/val.h"
#include "IRNode.h"

#include "../AST/ArrayNode.h"
#include "../AST/PrimaryNode.h"
#include "../AST/RootNode.h"
#include "../AST/TypeNode.h"

#include "../AST/DefNode/DefNode.h"
#include "../AST/DefNode/classDefNode.h"
#include "../AST/DefNode/funcDefNode.h"
#include "../AST/DefNode/varDefNode.h"

#include "../AST/ExprNode/ExprNode.h"
#include "../AST/ExprNode/arrayAccessExprNode.h"
#include "../AST/ExprNode/assignExprNode.h"
#include "../AST/ExprNode/atomExprNode.h"
#include "../AST/ExprNode/binaryExprNode.h"
#include "../AST/ExprNode/classMemExprNode.h"
#include "../AST/ExprNode/formatStringExprNode.h"
#include "../AST/ExprNode/funcallExprNode.h"
#include "../AST/ExprNode/oneExprNode.h"
#include "../AST/ExprNode/threeExprNode.h"

#include "../AST/StmtNode/StmtNode.h"
#include "../AST/StmtNode/constructorStmtNode.h"
#include "../AST/StmtNode/emptyStmtNode.h"
#include "../AST/StmtNode/exprStmtNode.h"
#include "../AST/StmtNode/forStmtNode.h"
#include "../AST/StmtNode/ifStmtNode.h"
#include "../AST/StmtNode/returnStmtNode.h"
#include "../AST/StmtNode/suiteStmtNode.h"
#include "../AST/StmtNode/varDefStmtNode.h"
#include "../AST/StmtNode/whileStmtNode.h"
#include "util/type.h"
#include <memory>
#include <string>
#include <utility>

void basicBlockNode::print(std::string &out) const {
  out = out + label + ":\n";
  for (auto it : phi) {
    out = out + '\t';
    it.second->print(out);
    out = out + '\n';
  }
  for (auto it : stmt) {
    out = out + '\t';
    it->print(out);
    out = out + '\n';
  }
}
std::shared_ptr<stringVar>
IRbuilder::register_literal_str(const std::string &str) {
  if (!literal_strings[str]) {
    auto v = std::make_shared<stringVar>(
        IRstringType, ".str." + std::to_string(literal_strings.size()), str);
    literal_strings[str] = v;
  }
  return literal_strings[str];
}

boolConst get_const(bool val) { return boolConst(IRboolType, val); }
intConst get_const(int val) { return intConst(IRintType, val); }

const std::string emptyString = "";

const std::shared_ptr<boolConst> defaultBool =
    std::make_shared<boolConst>(IRboolType, false);
const std::shared_ptr<intConst> defaultInt =
    std::make_shared<intConst>(IRintType, 0);
const std::shared_ptr<nullConst> defaultPtr =
    std::make_shared<nullConst>(IRptrType);

void IRbuilder::init_builtin() {
  auto print = std::make_shared<functionNode>(IRvoidType, "print");
  print->arguments.emplace_back(IRstringType, "str");
  module->functions.push_back(print);

  auto println = std::make_shared<functionNode>(IRvoidType, "println");
  println->arguments.emplace_back(IRstringType, "str");
  module->functions.push_back(println);

  auto printInt = std::make_shared<functionNode>(IRvoidType, "printInt");
  print->arguments.emplace_back(IRintType, "n");
  module->functions.push_back(printInt);

  auto printlnInt = std::make_shared<functionNode>(IRvoidType, "printlnInt");
  print->arguments.emplace_back(IRintType, "n");
  module->functions.push_back(printlnInt);

  auto getString = std::make_shared<functionNode>(IRstringType, "getString");
  module->functions.push_back(getString);

  auto getInt = std::make_shared<functionNode>(IRintType, "getInt");
  module->functions.push_back(getInt);

  auto toString = std::make_shared<functionNode>(IRstringType, "toString");
  toString->arguments.emplace_back(IRintType, "n");
  module->functions.push_back(toString);

  auto array_size = std::make_shared<functionNode>(IRintType, "_array.size");
  array_size->arguments.emplace_back(IRptrType, "array");
  module->functions.push_back(array_size);

  auto string_length =
      std::make_shared<functionNode>(IRintType, "string.length");
  string_length->arguments.emplace_back(IRstringType, "str");
  module->functions.push_back(string_length);

  auto substring =
      std::make_shared<functionNode>(IRstringType, "string.substring");
  substring->arguments.emplace_back(IRstringType, "str");
  substring->arguments.emplace_back(IRintType, "left");
  substring->arguments.emplace_back(IRintType, "right");
  module->functions.push_back(substring);

  auto parseInt = std::make_shared<functionNode>(IRintType, "string.parseInt");
  parseInt->arguments.emplace_back(IRstringType, "str");
  module->functions.push_back(parseInt);

  auto ord = std::make_shared<functionNode>(IRintType, "string.ord");
  ord->arguments.emplace_back(IRstringType, "str");
  ord->arguments.emplace_back(IRintType, "pos");
  module->functions.push_back(ord);

  auto str_add = std::make_shared<functionNode>(IRstringType, "string.add");
  str_add->arguments.emplace_back(IRstringType, "lhs");
  str_add->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_add);

  auto str_equal = std::make_shared<functionNode>(IRboolType, "string.equal");
  str_equal->arguments.emplace_back(IRstringType, "lhs");
  str_equal->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_equal);

  auto str_notEqual =
      std::make_shared<functionNode>(IRboolType, "string.notEqual");
  str_notEqual->arguments.emplace_back(IRstringType, "lhs");
  str_notEqual->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_notEqual);

  auto str_less = std::make_shared<functionNode>(IRboolType, "string.less");
  str_less->arguments.emplace_back(IRstringType, "lhs");
  str_less->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_less);

  auto str_greater =
      std::make_shared<functionNode>(IRboolType, "string.greater");
  str_greater->arguments.emplace_back(IRstringType, "lhs");
  str_greater->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_greater);

  auto str_lessEqual =
      std::make_shared<functionNode>(IRboolType, "string.lessEqual");
  str_lessEqual->arguments.emplace_back(IRstringType, "lhs");
  str_lessEqual->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_lessEqual);

  auto str_greaterEqual =
      std::make_shared<functionNode>(IRboolType, "string.greaterEqual");
  str_greaterEqual->arguments.emplace_back(IRstringType, "lhs");
  str_greaterEqual->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_greaterEqual);

  auto malloc_ = std::make_shared<functionNode>(IRptrType, "malloc");
  malloc_->arguments.emplace_back(IRintType, "size");
  module->functions.push_back(malloc_);

  auto array_size_ = std::make_shared<functionNode>(IRintType, "__array.size");
  array_size_->arguments.emplace_back(IRptrType, "array");
  module->functions.push_back(array_size_);

  auto newPtrArray = std::make_shared<functionNode>(IRptrType, "__newPtrArray");
  newPtrArray->arguments.emplace_back(IRintType, "size");
  module->functions.push_back(newPtrArray);

  auto newIntArray = std::make_shared<functionNode>(IRptrType, "__newIntArray");
  newIntArray->arguments.emplace_back(IRintType, "size");
  module->functions.push_back(newIntArray);

  auto newBoolArray =
      std::make_shared<functionNode>(IRptrType, "__newBoolArray");
  newBoolArray->arguments.emplace_back(IRintType, "size");
  module->functions.push_back(newBoolArray);

  for (auto func : module->functions)
    ask_function[func->name] = func;
}

std::shared_ptr<Var> IRbuilder::register_annoy_var(std::shared_ptr<IRType> type,
                                                   const std::string &prefix) {
  auto var = std::make_shared<Var>(
      type, prefix + std::to_string(annoyCounter[prefix]++), false);
  currentFunction->localVars.push_back(var);
  ask_var[var->name] = var;
  return var;
}

std::shared_ptr<ptrVar>
IRbuilder::register_annoy_ptr_var(std::shared_ptr<IRType> obj_type,
                                  const std::string &prefix) {
  auto var = std::make_shared<ptrVar>(
      IRptrType, obj_type, prefix + std::to_string(annoyCounter[prefix]++));
  currentFunction->localVars.push_back(var);
  ask_var[var->name] = var;
  return var;
}

std::shared_ptr<Value>
IRbuilder::remove_variable_pointer(std::shared_ptr<Value> val) {
  return val;
  /*	auto loc = dynamic_cast<PtrVar *>(val);
          auto glo = dynamic_cast<GlobalVar *>(val);

          if (!(loc || glo)) return val;
          auto load = env.createLoadStmt(
                          register_annoy_var(loc ? loc->objType : glo->type,
     (loc ? loc->name : glo->name) + ".val."), loc ? static_cast<Var *>(loc) :
     static_cast<Var *>(glo)); add_stmt(load); return load->res;
    */
}
void IRbuilder::add_terminals(std::shared_ptr<functionNode> func) {
  std::shared_ptr<retStmtNode> return_void =
      std::make_shared<retStmtNode>(nullptr);
  std::shared_ptr<retStmtNode> return_0 =
      std::make_shared<retStmtNode>(defaultInt);

  for (auto it : func->blocks) {
    auto bak = it->stmt.empty() ? nullptr : it->stmt.back();
    if (!(bak && bak->jump)) {
      if (func->name == "main") {
        it->stmt.push_back(return_0);
      } else {
        if (func->type == IRvoidType) {
          it->stmt.push_back(return_void);
        } else {
          it->stmt.push_back(std::make_shared<unreachStmtNode>());
        }
      }
    }
  }
}
void classNode::add_filed(std::shared_ptr<simpleType> mem_type,
                          const std::string &mem_name) {
  type->mem.emplace_back(mem_type);
  index[mem_name] = type->mem.size() - 1;
}
void IRbuilder::init_global_var() {
  if (InitList.empty())
    return;
  auto first_sign =
      std::make_shared<Var>(IRboolType, ".global_var_inited", true);
  module->globalVars.push_back(first_sign);

  auto first_sign_stmt =
      std::make_shared<globalVarStmtNode>(first_sign, defaultBool);
  module->vars.push_back(first_sign_stmt);

  auto func = std::make_shared<functionNode>(IRvoidType, "init-global-var");
  func->blocks.emplace_back(basicBlockNode("entry"));
  currentFunction = func;

  auto init_block = std::make_shared<basicBlockNode>("init");
  auto end_block = std::make_shared<basicBlockNode>("end");

  auto is_first = std::make_shared<condiBrStmtNode>(
      remove_variable_pointer(first_sign), end_block, init_block);

  currentFunction->blocks.back()->stmt.push_back(is_first);
  currentFunction->blocks.push_back(init_block);

  //  auto set_sign = std::make_shared<storeStmtNode>(, first_sign);
  //  currentFunction->blocks.back()->stmt.push_back(set_sign);

  //  auto set_sign = IRcreateStoreStmt(IRliteral(true), first_sign);

  for (auto &it : InitList) {
    it.second->accept(this);
    auto store = std::make_shared<storeStmtNode>(
        remove_variable_pointer(ask_expr[it.second.get()]), nullptr);
    store->point = it.first->result;

    currentFunction->blocks.back()->stmt.push_back(store);
  }
  for (auto &it : InitListString) {
    it.second->accept(this);
    auto store = std::make_shared<storeStmtNode>(
        remove_variable_pointer(ask_expr[it.second.get()]), nullptr);
    store->point = it.first->result;

    currentFunction->blocks.back()->stmt.push_back(store);
  }
  currentFunction->blocks.push_back(end_block);
  add_terminals(func);
  currentFunction = nullptr;

  for (auto f : module->functions)
    if (f->name == "main") {
      auto call = std::make_shared<callStmtNode>(func);
      auto &s = f->blocks[0]->stmt;
      s.insert(s.begin(), call);
      break;
    }
  module->functions.push_back(func);
}
std::shared_ptr<simpleType> get_IRType(std::shared_ptr<TypeNode> node) {
  if (!node)
    return IRvoidType;
  if (node->dim != 0)
    return IRptrType;
  if (node->name == "void")
    return IRvoidType;
  else if (node->name == "bool")
    return IRboolType;
  else if (node->name == "int")
    return IRintType;
  else if (node->name == "string")
    return IRstringType;
  else
    return IRptrType; // string and class
}

void IRbuilder::visit(RootNode *node) {
  //  std::cerr <<(StringTypename->ask_function("length").return_type)<<"
  //  __________init\n";
  module = std::make_shared<moduleNode>();
  init_builtin();
  register_literal_str(emptyString);
  for (auto &def : node->def_nodes) {
    def->accept(this);
  }
  init_global_var();
}

void IRbuilder::visit(varDefNode *node) {
  //  std::cerr << "check varDef\n";
  auto type = get_IRType(node->type_name);

  auto var_name = node->var_name;
  auto expr = node->init_val;
  for (int i = 0; i < var_name.size(); ++i) {
    if (expr[i] != nullptr) {
    }
  }
  //  std::cerr << "return varDef\n";
}

void IRbuilder::visit(funcDefNode *node) {
  //  std::cerr << "check funcDef\n";
  auto func = std::make_shared<functionNode>(
      toIRType(node->return_type),
      currentClass ? currentClass->type->name + "." + node->func_name
                   : node->func_name);
  if (currentClass) {
    func->arguments.push_back(std::make_pair(IRptrType, "this"));
  }
  for (auto it : node->arguments) {
    func->arguments.push_back(std::make_pair(toIRType(it.first), it.second));
  }
  module->functions.push_back(func);
  ask_function[func->name] = func;
  //  std::cerr << "return funcDef\n";
}

void IRbuilder::visit(classDefNode *node) {
  //  std::cerr << "check classDef\n";
  auto c = std::make_shared<classNode>(node->name);
  for (auto it : node->varDef) {
    auto type = get_IRType(it->type_name);
    for (auto var : it->var_name) {
      c->add_filed(type, var);
    }
  }
  module->classes.push_back(c);
  ask_class[node->name] = c;
  currentClass = c;
  for (auto it : node->consDef) {
    it->accept(this);
  }
  for (auto it : node->funcDef) {
    it->accept(this);
  }
  currentClass = nullptr;
  //  std::cerr << "return classDef\n";
}

void IRbuilder::visit(constructorClassStmtNode *node) {
  //  std::cerr << "check constructor\n";

  //  return_type = VoidType;
  //  node->ask_func()->accept(this);
  //  return_type = nullptr;
  auto &constructor = cur_type_->GetConstructor();
  cur_func_ = constructor.lock();
  vars_.EnterNewFunc();
  vars_.CreateVar({cur_type_, 1}, "this", false, false);
  node->GetFunctionBody()->accept(this);
  cur_func_->PushStmt(std::make_unique<RetStmt>());
  cur_func_->LinkInitStmt();
  cur_func_ = nullptr;

  //  std::cerr << "return constructor\n";
}


void IRbuilder::visit(constPrimaryNode *node) {
  //  std::cerr << "check constPrimary\n";
	if (node->valueType.is_null())
		exprResult[node] = env.literal(nullptr);
	else if (node->valueType.is_bool())
		exprResult[node] = env.literal(node->value == "true");
	else if (node->valueType.is_int())
		exprResult[node] = env.literal(std::stoi(node->value));
	else if (node->valueType.is_string()) {
		std::string str;
		str.reserve(node->value.size() - 2);
		for (size_t i = 1, siz = node->value.size(); i + 1 < siz; ++i) {
			if (node->value[i] != '\\')
				str += node->value[i];
			else {
				++i;
				if (node->value[i] == 'n') str += '\n';
				else if (node->value[i] == '"')
					str += '"';
				else if (node->value[i] == '\\')
					str += '\\';
				else
					throw std::runtime_error("unknown escape sequence");
			}
		}
		exprResult[node] = register_literal_str(str);
	}
	else
		throw std::runtime_error("IRBuilder: unknown literal type");
  //  std::cerr << "return constPrimary\n";
}

void IRbuilder::visit(newPrimaryNode *node) {
  //  std::cerr << "check newPrimary\n";
  std::vector<std::shared_ptr<Value>> array_size;
  for (auto it : node->type->arraySize) {
    it->accept(this);
    auto v = remove_variable_pointer(ask_expr[it]);
    array_size.push_back(v);
  }
  ++new_cnt;
  ask_expr[node] = TransformNewToFor(
      array_size, static_cast<int>(node->type->dim), node->type->name);
  //  std::cerr << "return newPrimary\n";
}

void IRbuilder::visit(varPrimaryNode *node) {
  //  std::cerr << "check varPrimary\n";
  auto name = node->name;
  if (!scope.is_var(name)) {
    throw semanticError("Undefined Identifier", node->pos);
  }
  auto var = scope.ask_var(name);
  node->updata_type(std::make_shared<Type>(std::move(var)));
  //  std::cerr << "return varPrimary\n";
}

void IRbuilder::visit(thisPrimaryNode *node) {
  //  std::cerr << "check thisPrimary\n";
  if (!scope.is_var("this")) {
    throw semanticError("Undefined Identifier", node->pos);
  }
  auto var = scope.ask_var("this");
  node->updata_type(std::make_shared<Type>(std::move(var)));
}

void IRbuilder::visit(parenPrimaryNode *node) {
  //  std::cerr << "check parenPrimary\n";
  node->expr->accept(this);
  node->updata_type(std::move(node->expr->get_type()));
  node->assignable = node->expr->assignable;
  node->isnull = node->expr->isnull;
}

void IRbuilder::visit(atomExprNode *node) {
  //  std::cerr << "check atomExpr\n";
  auto pri = node->primary_node;
  pri->accept(this);
  //  std::cerr << "return atomExpr\n";
}

void IRbuilder::visit(assignExprNode *node) {
  //  std::cerr << "check assignExpr\n";
  auto lhs = node->lhs;
  auto rhs = node->rhs;

  lhs->accept(this);
  rhs->accept(this);

  auto st = std::make_shared<storeStmtNode>(
      remove_variable_pointer(ask_expr[rhs.get()]),
      std::make_shared<Var>(ask_expr[lhs.get()]));
  currentFunction->blocks.back()->stmt.push_back(st);
  //  std::cerr << "return assignExpr\n";
}

void IRbuilder::visit(oneExprNode *node) {
  //  std::cerr << "check oneExpr\n";
  node->expr_node->accept(this);
  if (node->op_type == oneExprNode::OpType::PreDecrement ||
      node->op_type == oneExprNode::OpType::SufDecrement ||
      node->op_type == oneExprNode::OpType::PreIncrement ||
      node->op_type ==
          oneExprNode::OpType::SufIncrement) { // A++, A--, ++A, --A

    auto add = std::make_shared<arithStmtNode>(
        (node->op_type == oneExprNode::OpType::PreDecrement ||
         node->op_type == oneExprNode::OpType::SufDecrement)
            ? "add"
            : "sub",
        nullptr, remove_variable_pointer(ask_expr[node->expr_node.get()]),
        get_const(1));
    add->res = register_annoy_var(IRintType, ".arith.");
    currentFunction->blocks.back()->stmt.push_back(add);

    if (!node->assignable)
      ask_expr[node] = add->lhs;
    else
      ask_expr[node] = ask_expr[node->expr_node.get()];

    auto store = std::make_shared<storeStmtNode>(
        add->res, std::make_shared<Var>(ask_expr[node->expr_node.get()]));
    currentFunction->blocks.back()->stmt.push_back(store);
  } else if (node->op_type == oneExprNode::OpType::Minus) {
    auto sub = std::make_shared<arithStmtNode>(
        "sub", nullptr, get_const(0),
        remove_variable_pointer(ask_expr[node->expr_node.get()]));
    sub->res = register_annoy_var(IRintType, ".arith.");
    currentFunction->blocks.back()->stmt.push_back(sub);
    ask_expr[node] = sub->res;
  } else if (node->op_type == oneExprNode::OpType::Not) {
    auto xor_ = std::make_shared<arithStmtNode>(
        "xor", nullptr,
        remove_variable_pointer(ask_expr[node->expr_node.get()]),
        get_const(true));
    xor_->res = register_annoy_var(IRboolType, ".arith.");
    currentFunction->blocks.back()->stmt.push_back(xor_);
    ask_expr[node] = xor_->res;
  } else if (node->op_type == oneExprNode::OpType::Tilde) {
    auto xor_ = std::make_shared<arithStmtNode>(
        "xor", nullptr,
        remove_variable_pointer(ask_expr[node->expr_node.get()]),
        get_const(-1));
    xor_->res = register_annoy_var(IRintType, ".arith.");
    currentFunction->blocks.back()->stmt.push_back(xor_);
    ask_expr[node] = xor_->res;
  } else
    throw std::runtime_error("unknown single expr op");

  //  std::cerr << "return oneExpr\n";
}
void enterAndOrBinaryExprNode(binaryExprNode *node) {}
void enterStringBinaryExprNode(binaryExprNode *node) {}
void IRbuilder::visit(binaryExprNode *node) {
  //  std::cerr << "check binaryExpr\n";

  if (node->opCode == binaryExprNode::OpType::AndAnd ||
      node->opCode == binaryExprNode::OpType::OrOr) {
    enterAndOrBinaryExprNode(node);
    return;
  }
  if (node->lhs->get_type()->type_name->name == "string" &&
      node->lhs->get_type()->dim == 0) {
    enterStringBinaryExprNode(node);
    return;
  }
  std::map<binaryExprNode::OpType, std::string> arth = {
      {binaryExprNode::OpType::Add, "add"},
      {binaryExprNode::OpType::Sub, "sub"},
      {binaryExprNode::OpType::Mul, "mul"},
      {binaryExprNode::OpType::Div, "sdiv"},
      {binaryExprNode::OpType::Mod, "srem"},
      {binaryExprNode::OpType::ShiftL, "shl"},
      {binaryExprNode::OpType::ShiftR, "ashr"},
      {binaryExprNode::OpType::And, "and"},
      {binaryExprNode::OpType::Or, "or"},
      {binaryExprNode::OpType::Xor, "xor"},
  };
  std::map<binaryExprNode::OpType, std::string> cmp = {
      {binaryExprNode::OpType::Equal, "eq"},
      {binaryExprNode::OpType::NotEqual, "ne"},
      {binaryExprNode::OpType::Less, "slt"},
      {binaryExprNode::OpType::Greater, "sgt"},
      {binaryExprNode::OpType::LessEqual, "sle"},
      {binaryExprNode::OpType::GreaterEqual, "sge"},
  };
  node->lhs->accept(this);
  auto l = remove_variable_pointer(ask_expr[node->lhs.get()]);
  node->rhs->accept(this);
  auto r = remove_variable_pointer(ask_expr[node->rhs.get()]);
  if (arth.count(node->opCode) != 0) {
    auto a = std::make_shared<arithStmtNode>(arth[node->opCode], nullptr, l, r);
    ask_expr[node] = a->res = register_annoy_var(IRintType, ".arith.");
    currentFunction->blocks.back()->stmt.push_back(a);
  } else if (cmp.count(node->opCode) != 0) {
    auto c = std::make_shared<cmpStmtNode>(cmp[node->opCode], nullptr, l, r);
    ask_expr[node] = c->res = register_annoy_var(IRboolType, ".cmp.");
    currentFunction->blocks.back()->stmt.push_back(c);
  } else
    throw std::runtime_error("IRBuilder: unknown binary operator: ");

  //  std::cerr << "return binaryExpr\n";
}

void IRbuilder::visit(threeExprNode *node) {
  ++ternary_cnt;
  auto true_expr =
      env.createBasicBlock("ternary_true_" + std::to_string(ternary_cnt));
  auto false_expr =
      env.createBasicBlock("ternary_false_" + std::to_string(ternary_cnt));
  auto end =
      env.createBasicBlock("ternary_end_" + std::to_string(ternary_cnt));

  visit(node->cond);
  auto br_cond = env.createCondBrStmt(
      remove_variable_pointer(ask_expr[node->cond]), true_expr, false_expr);
  add_stmt(br_cond);

  add_block(true_expr);
  visit(node->trueExpr);
  auto true_res = remove_variable_pointer(ask_expr[node->trueExpr]);
  add_stmt(env.createDirectBrStmt(end));
  auto from_true = currentFunction->blocks.back();

  add_block(false_expr);
  visit(node->falseExpr);
  auto false_res = remove_variable_pointer(ask_expr[node->falseExpr]);
  add_stmt(env.createDirectBrStmt(end));
  auto from_false = currentFunction->blocks.back();

  add_block(end);
  if (!node->valueType.is_void()) {
    auto phi = env.createPhiStmt(
        register_annoy_var(toIRType(node->valueType), ".ternary_res."),
        std::map<BasicBlock *, Val *>{{from_true, true_res},
                                      {from_false, false_res}});
    add_phi(phi);
    ask_expr[node] = phi->res;
  }
}

void IRbuilder::visit(classMemExprNode *node) {
  //  std::cerr << "check classMemExpr\n";
	visit(node->object);
	if (node->valueType.is_function()) {
		std::cout << "<TODO: call Class.function>";
	}
	else {
		auto cls = name2class[node->object->valueType.to_string()];
		int index = static_cast<int>(cls->name2index[node->member]);

		auto obj = remove_variable_pointer(exprResult[node->object]);
		auto gep = env.createGetElementPtrStmt("%class." + cls->type.name,
											   register_annoy_ptr_var(cls->type.fields[index], ".gep."),
											   dynamic_cast<Var *>(obj),
											   std::vector<Val *>{env.literal(0), env.literal(index)});
		if (!gep->pointer)
			throw std::runtime_error("IRBuilder: member access on non-variable");
		add_stmt(gep);
		exprResult[node] = gep->res;
	}
  //  std::cerr << "return classMemExpr\n";
}

void IRbuilder::visit(formatStringExprNode *node) {
  //  std::cerr << "check formatStringExpr\n";
  //  std::cerr << "return formatStringExpr\n";
}

void IRbuilder::visit(simpleArrayNode *node) {
  //  std::cerr << "check simpleArray\n";
  auto base = classes_.GetType(node->GetType()->GetTypename()->GetName());
  auto &elements = node->GetElements();
  if (base != kIRStringBase) {
    auto res = vars_.CreateTmpVar({base, 1}, "");
    cur_func_->PushStmt(
        std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.allocArray"),
                                   std::vector<std::shared_ptr<Var>>{vars_.GetInt(static_cast<int>(elements.size()))}));
    for (int i = 0; i < elements.size(); ++i) {
      if (base == kIRIntBase) {
        auto ptr = vars_.CreateTmpVar({base, 1}, "");
        cur_func_->PushStmt(
            std::make_unique<GetElementPtrStmt>(ptr, res, std::vector<std::shared_ptr<Var>>{vars_.GetInt(i)}));
        int val = std::get<int>(std::dynamic_pointer_cast<LiteralPrimaryNode>(elements[i])->GetValue());
        cur_func_->PushStmt(std::make_unique<StoreStmt>(vars_.GetInt(val), ptr));
      } else {
        auto ptr = vars_.CreateTmpVar({base, 1}, "");
        cur_func_->PushStmt(
            std::make_unique<GetElementPtrStmt>(ptr, res, std::vector<std::shared_ptr<Var>>{vars_.GetInt(i)}));
        bool val = std::get<bool>(std::dynamic_pointer_cast<LiteralPrimaryNode>(elements[i])->GetValue());
        cur_func_->PushStmt(std::make_unique<StoreStmt>(vars_.GetBool(val), ptr));
      }
    }
    node->SetVar(res);
  } else {
    auto res = vars_.CreateTmpVar({base, 2}, "");
    cur_func_->PushStmt(
        std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.allocArray"),
                                   std::vector<std::shared_ptr<Var>>{vars_.GetInt(static_cast<int>(elements.size()))}));
    for (int i = 0; i < elements.size(); ++i) {
      auto ptr = vars_.CreateTmpVar({base, 2}, "");
      cur_func_->PushStmt(
          std::make_unique<GetElementPtrStmt>(ptr, res, std::vector<std::shared_ptr<Var>>{vars_.GetInt(i)}));
      std::string str = std::get<std::string>(std::dynamic_pointer_cast<LiteralPrimaryNode>(elements[i])->GetValue());
      auto val = vars_.GetString(str)->GetVar();
      cur_func_->PushStmt(std::make_unique<StoreStmt>(val, ptr));
    }
    node->SetVar(res);
  }
  //  std::cerr << "return simpleArray\n";
}

void IRbuilder::visit(complexArrayNode *node) {
  //  std::cerr << "check complexArray\n";
  auto &elements = node->GetElements();
  auto type = IRType{elements[0]->GetVar()->GetType().GetBaseType(), elements[0]->GetVar()->GetType().GetDim() + 1};
  auto tmp_var = vars_.CreateTmpVar(type, "arrayTmp");
  cur_func_->PushStmt(std::make_unique<CallStmt>(tmp_var, functions_.GetFunction("builtin.allocArray"),
                                                 std::vector<std::shared_ptr<Var>>{elements.size()}));
  for (int i = 0; i < elements.size(); ++i) {
    auto ptr = vars_.CreateTmpVar(type, "arrayTmp");
    elements[i]->accept(this);
    auto val = elements[i]->GetVar();
    cur_func_->PushStmt(
        std::make_unique<GetElementPtrStmt>(ptr, tmp_var, std::vector<std::shared_ptr<Var>>{vars_.GetInt(i)}));
    cur_func_->PushStmt(std::make_unique<StoreStmt>(val, ptr));
  }
  node->SetVar(tmp_var);
}

void IRbuilder::visit(arrayAccessExprNode *node) {
  //  std::cerr << "check arrayAccessExpr\n";
  visit(node->array);
  visit(node->index);
  auto array = remove_variable_pointer(ask_expr[node->array]);
  auto index = remove_variable_pointer(ask_expr[node->index]);
  auto type = toIRType(node->valueType);
  auto gep = env.createGetElementPtrStmt(
      type->to_string(), register_annoy_ptr_var(type, ".arr."),
      dynamic_cast<Var *>(array), std::vector<Val *>{index});
  add_stmt(gep);
  ask_expr[node] = gep->res;

  //  std::cerr << "return arrayAccessExpr\n";
}

void IRbuilder::visit(emptyStmtNode *node) {
  //  std::cerr<<"empty\n";
}

void IRbuilder::visit(suiteStmtNode *node) {
  //  std::cerr << "check suiteStmt\n";
  for (auto it : node->get_stmts())
    it->accept(this);
  //  std::cerr << "return suiteStmt\n";
}

void IRbuilder::visit(ifStmtNode *node) {

  auto after = env.createBasicBlock("if_end_" + std::to_string(ifCounter));

  for (auto &clause : node->ifStmts) {
    ++if_cnt;
    auto true_block =
        env.createBasicBlock("if_true_" + std::to_string(ifCounter));
    auto false_block =
        (&clause != &node->ifStmts.back() || node->elseStmt)
            ? env.createBasicBlock("if_false_" + std::to_string(ifCounter))
            : nullptr;

    visit(clause.first);
    auto br_cond =
        env.createCondBrStmt(remove_variable_pointer(ask_expr[clause.first]),
                             true_block, false_block ? false_block : after);
    add_stmt(br_cond);

    add_block(true_block);
    visit(clause.second);
    add_stmt(env.createDirectBrStmt(after));

    if (false_block)
      add_block(false_block);
  }
  if (node->elseStmt) {
    visit(node->elseStmt);
    add_stmt(env.createDirectBrStmt(after));
  }
  add_block(after);
}

void IRbuilder::visit(exprStmtNode *node) {
  //  std::cerr << "check exprStmt\n";
  for (auto it : node->expr) {
    it->accept(this);
  }
  //  std::cerr << "return exprStmt\n";
}

void IRbuilder::visit(whileStmtNode *node) {
  ++loop_cnt;
  auto condi = std::make_shared<basicBlockNode>("while_cond_" +
                                                std::to_string(loop_cnt));
  auto body = std::make_shared<basicBlockNode>("while_body_" +
                                               std::to_string(loop_cnt));
  auto afterLoop =
      std::make_shared<basicBlockNode>("while_end_" + std::to_string(loop_cnt));

  auto br_condi = std::make_shared<brStmtNode>(condi);
  currentFunction->blocks.back()->stmt.push_back(br_condi);
  currentFunction->blocks.push_back(condi);

  node->condi_expr->accept(this);
  auto br_body = std::make_shared<condiBrStmtNode>(
      remove_variable_pointer(ask_expr[node->condi_expr.get()]), body,
      afterLoop);
  currentFunction->blocks.back()->stmt.push_back(br_body);
  currentFunction->blocks.push_back(body);

  loop_break.push(afterLoop);
  loop_continue.push(condi);

  node->loop_stmt->accept(this);
  currentFunction->blocks.back()->stmt.push_back(br_condi);

  loop_break.pop();
  loop_continue.pop();

  currentFunction->blocks.push_back(afterLoop);
}

void IRbuilder::visit(varDefStmtNode *node) {
  //  std::cerr << "check varDefStmt\n";
  node->var_def->accept(this);
  //  std::cerr << "return varDefStmt\n";
}

void IRbuilder::visit(controlStmtNode *node) {
  //  std::cerr << "check controlStmt\n";
  auto control_type = node->stmt_type;
  switch (control_type) {
  case controlStmtNode::StmtType::Continue: {
    auto br = env.createDirectBrStmt(loopContinueTo.top());
    add_stmt(br);
    auto block = env.createBasicBlock("after_continue_" +
                                      std::to_string(++continueCounter));
    add_block(block);
    break;
  }
  case controlStmtNode::StmtType::Break: {
    auto br = env.createDirectBrStmt(loopBreakTo.top());
    add_stmt(br);
    auto block =
        env.createBasicBlock("after_break_" + std::to_string(++breakCounter));
    add_block(block);
    break;
  }
  case controlStmtNode::StmtType::Return: {
    auto ret = env.createRetStmt();
    if (node->expr) {
      visit(node->expr);
      ret->value = remove_variable_pointer(ask_expr[node->expr]);
    }
    add_stmt(ret);
    auto block =
        env.createBasicBlock("after_return_" + std::to_string(++returnCounter));
    add_block(block);
    break;
  }
  case controlStmtNode::StmtType::Unknown: {
    throw std::runtime_error("Invalid control statement type");
  }
  }
  //  std::cerr << "return controlStmt\n";
}

void IRbuilder::visit(forStmtNode *node) {
  // visit init
  if (node->init)
    visit(node->init);

  // create blocks
  ++loopCounter;
  auto body = env.createBasicBlock("for_body_" + std::to_string(loopCounter));
  auto cond =
      node->cond
          ? env.createBasicBlock("for_cond_" + std::to_string(loopCounter))
          : body;
  auto step =
      node->step
          ? env.createBasicBlock("for_step_" + std::to_string(loopCounter))
          : cond;
  auto afterLoop =
      env.createBasicBlock("for_end_" + std::to_string(loopCounter));

  auto br2cond = env.createDirectBrStmt(cond);
  add_stmt(br2cond);

  // visit cond
  if (node->cond) {
    add_block(cond);
    visit(node->cond);
    auto br2body = env.createCondBrStmt(
        remove_variable_pointer(ask_expr[node->cond]), body, afterLoop);
    add_stmt(br2body);
  }
  // visit body
  add_block(body);
  push_loop(step, afterLoop);
  for (auto stmt : node->body)
    visit(stmt);
  auto br2step = env.createDirectBrStmt(step);
  add_stmt(br2step);
  pop_loop();

  // visit step
  if (node->step) {
    add_block(step);
    visit(node->step);
    add_stmt(br2cond);
  }
  // after loop
  add_block(afterLoop);
}

void IRbuilder::visit(functionCallExprNode *node) {
  //  std::cerr << "check funcall\n";
  //  std::cerr
  //  <<StringTypename->ask_function("length").return_type->type_name<<"
  //  _________funcall\n";
  auto func_class = node->classname;
  auto func_name = node->name;
  auto arguments = node->arguments;
  std::shared_ptr<Function> func(nullptr);
  if (func_class != nullptr) {
    func_class->accept(this);
    //  std::cerr << "funcall class1\n";
    auto fun_class_type = func_class->get_type();
    if (fun_class_type == nullptr) {
      throw semanticError("Invalid Type", node->pos);
    }
    if (fun_class_type->dim > 0) {
      if (func_name == "size" && arguments.empty()) {
        node->updata_type(IntType);
        node->updata_assignable(false);
        node->updata_null(false);
        return;
      }
      throw semanticError("Invalid Type", node->pos);
    }
    if (!fun_class_type->type_name->is_function(func_name)) {
      throw semanticError("Invalid Class Member", node->pos);
    }
    //  std::cerr << "funcall class\n";
    auto real_func = fun_class_type->type_name->ask_function(func_name);
    //  std::cerr <<func_name<<' '<< StringTypename->func.size()<<'\n';
    //  std::cerr
    //  <<StringTypename->ask_function("length").return_type->type_name<<"
    //  funcall class\n";
    if (real_func.return_type->type_name == nullptr) {
      throw semanticError("Missing Return Statement", node->pos);
    }
    //  std::cerr << "funcall class\n";
    func = std::make_shared<Function>(std::move(real_func));
    //    //  std::cerr << "funcall class\n";
  } else {
    if (global_scope.is_function(func_name)) {
      func = std::make_shared<Function>(
          std::move(global_scope.ask_function(func_name)));
    }
    if (current_class != nullptr) {
      if (current_class->is_function(func_name)) {
        func = std::make_shared<Function>(
            std::move(current_class->ask_function(func_name)));
      }
    }
    if (func == nullptr) {
      //      //  std::cerr<<func_name<<"\n";
      throw semanticError("Undefined Identifier", node->pos);
    }
  }
  //  std::cerr << "funcall class3\n";
  if (arguments.size() != func->arguments.size()) {
    throw semanticError("Argument Wrong", node->pos);
  }
  auto func_args = func->arguments;
  for (int i = 0; i < arguments.size(); ++i) {
    arguments[i]->accept(this);
    auto type = arguments[i]->get_type();
    if (type == nullptr &&
            (*func_args[i] == *IntType || *func_args[i] == *BoolType) ||
        type != nullptr && *type != *func_args[i]) {
      throw semanticError("Type Mismatch", node->pos);
    }
  }
  node->updata_type(func->return_type);
  node->updata_assignable(false);
  node->updata_null(false);
  assert(node->get_type()->type_name != nullptr);
  //  std::cerr << "return funcall\n";
}

void IRbuilder::visit(TypeNode *node) {
  //  std::cerr << node->pos.toString() << " check Type\n";
  for (auto it : node->arraySize) {
    it->accept(this);
    if (*it->get_type() != *IntType)
      throw semanticError("Invalid Type", node->pos);
  }
  //  std::cerr << node->pos.toString() << " return Type\n";
}