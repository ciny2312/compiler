#pragma once
#include "AST/DefNode/classDefNode.h"
#include "AST/RootNode.h"

#include "AST/ASTVisitor.h"
#include "util/scope.h"

#include "util/error.h"

class ClassCollector : public ASTVisitor {
public:
  ClassCollector(GlobalScope &_global_scope) : global_scope(_global_scope){};
  void visit(RootNode *node) final {
    for (auto &it : node->def_nodes) {
      it->accept(this);
    }
  };

private:
  void visit(complexArrayNode *node) final {}
  void visit(simpleArrayNode *node) final {}
  void visit(classDefNode *node) final {
    global_scope.add_type(node->name, std::make_shared<Typename>(node->name),
                          node->pos);
  }
  void visit(funcDefNode *node) final {}
  void visit(varDefNode *node) final {}
  void visit(assignExprNode *node) final {}
  void visit(atomExprNode *node) final {}
  void visit(binaryExprNode *node) final {}
  void visit(formatStringExprNode *node) final {}
  void visit(functionCallExprNode *node) final {}
  void visit(classMemExprNode *node) final {}
  void visit(arrayAccessExprNode *node) final {}
  void visit(threeExprNode *node) final {}
  void visit(oneExprNode *node) final {}
  void visit(constPrimaryNode *node) final {}
  void visit(newPrimaryNode *node) final {}
  void visit(thisPrimaryNode *node) final {}
  void visit(varPrimaryNode *node) final {}
  void visit(controlStmtNode *node) final {}
  void visit(exprStmtNode *node) final {}
  void visit(emptyStmtNode *node) final {}
  void visit(forStmtNode *node) final {}
  void visit(ifStmtNode *node) final {}
  void visit(suiteStmtNode *node) final {}
  void visit(varDefStmtNode *node) final {}
  void visit(whileStmtNode *node) final {}
  void visit(constructorClassStmtNode *node) final {}
  void visit(functionDefClassStmtNode *node) final {}
  void visit(varDefClassStmtNode *node) final {}
  void visit(TypeNode *node) final {}
  GlobalScope &global_scope;
};

std::pair<Scope, GlobalScope> CollectSymbol(RootNode *node);

class SymbolCollector : public ASTVisitor {
  friend std::pair<Scope, GlobalScope> CollectSymbol(RootNode *node);

public:
  SymbolCollector(): scope(nullptr) {};
  void CollectClass(RootNode *node){
  ClassCollector collector(global_scope);
  collector.visit(node);
};
  void visit(RootNode *node){
  for (auto &it : node->def_nodes) {
    it->accept(this);
  }
};

private:
  void visit(complexArrayNode *node) final {}
  void visit(simpleArrayNode *node) final {}
  void visit(classDefNode *node) final {
  auto &name = node->name;
  current_class = global_scope.ask_type(name);
  for (const auto &it : node->consDef) {
    it->accept(this);
  }
  for (const auto &it : node->varDef) {
    it->accept(this);
  }
  for (const auto &it : node->funcDef) {
    it->accept(this);
  }
  current_class = nullptr;
}
  void visit(funcDefNode *node) final {
  auto &func_name = node->func_name;
  auto &[ret_name, dim] = node->GetReturnType();
  auto return_typename = global_scope_.GetType(ret_name);
  if (!return_typename.has_value()) {
    throw UndefinedIdentifier(node->GetPos());
  }
  auto return_type = CreateType(std::move(return_typename.value()), dim);
  std::vector<Type> args;
  for (const auto &item : node->arguments) {
    auto [arg_name, arg_dim] = item.first;
    auto arg_typename = global_scope.ask_type(arg_name);
    if (!arg_typename.has_value()) {
      throw UndefinedIdentifier(node->pos);
    }
    auto arg_type = CreateType(std::move(arg_typename.value()), arg_dim);
    args.push_back(std::move(arg_type));
  }
  Function func(std::move(return_type), std::move(args));
  if (scope.is_var(func_name)) {
    throw MultipleDef(node->pos);
  }
  global_scope.add_function(func_name, func, {node->pos});
}
  void visit(varDefNode *node) final {}
  void visit(assignExprNode *node) final {}
  void visit(atomExprNode *node) final {}
  void visit(binaryExprNode *node) final {}
  void visit(formatStringExprNode *node) final {}
  void visit(functionCallExprNode *node) final {}
  void visit(classMemExprNode *node) final {}
  void visit(arrayAccessExprNode *node) final {}
  void visit(threeExprNode *node) final {}
  void visit(oneExprNode *node) final {}
  void visit(constPrimaryNode *node) final {}
  void visit(newPrimaryNode *node) final {}
  void visit(thisPrimaryNode *node) final {}
  void visit(varPrimaryNode *node) final {}
  void visit(controlStmtNode *node) final {}
  void visit(exprStmtNode *node) final {}
  void visit(emptyStmtNode *node) final {}
  void visit(forStmtNode *node) final {}
  void visit(ifStmtNode *node) final {}
  void visit(suiteStmtNode *node) final {}
  void visit(varDefStmtNode *node) final {}
  void visit(whileStmtNode *node) final {}
  void visit(constructorClassStmtNode *node) final {
  auto &name = node->type;
  if (name != current_class->name) {
    throw InvalidContructor(node->pos);
  }
  if (current_class->is_function(name)) {
    throw MultipleDef(node->pos);
  }
  Function constructor(VoidType, {});
  current_class->add_function(name, std::move(constructor));
}
  void visit(functionDefClassStmtNode *node) final {}
  void visit(varDefClassStmtNode *node) final {}
  void visit(TypeNode *node) final {}
  Scope scope;
  GlobalScope global_scope;
  std::shared_ptr<Typename> current_class;
};

std::pair<Scope, GlobalScope> CollectSymbol(RootNode *node) {
  SymbolCollector collector;
  collector.CollectClass(node);
  collector.visit(node);
  return {std::move(collector.scope), std::move(collector.global_scope)};
}