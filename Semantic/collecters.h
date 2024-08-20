#pragma once
#include "AST/DefNode/classDefNode.h"
#include "AST/DefNode/funcDefNode.h"
#include "AST/RootNode.h"
#include "AST/TypeNode.h"

#include "AST/ASTVisitor.h"
#include "util/scope.h"

#include "util/error.h"
#include <memory>

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
  void visit(parenPrimaryNode *node) final {}
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
//  void visit(functionDefClassStmtNode *node) final {}
//  void visit(varDefClassStmtNode *node) final {}
  void visit(TypeNode *node) final {}
  GlobalScope &global_scope;
};

std::pair<Scope, GlobalScope> CollectSymbol(RootNode *node);

class SymbolCollector : public ASTVisitor {
  friend std::pair<Scope, GlobalScope> CollectSymbol(RootNode *node) {
    SymbolCollector collector;
    collector.CollectClass(node);
    collector.visit(node);
    return {std::move(collector.scope), std::move(collector.global_scope)};
  }

public:
  SymbolCollector() : scope(nullptr){};
  void CollectClass(RootNode *node) {
    ClassCollector collector(global_scope);
    collector.visit(node);
  };
  void visit(RootNode *node) {
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
      get_class_var(it);
    }
    for (auto &it : node->funcDef) {
      get_class_func(it);
    }
    current_class = nullptr;
  }
  void get_class_func(std::shared_ptr<funcDefNode> node) {
    auto &name = node->func_name;
    if (name == current_class->name) {
      throw semanticError("Invalid Class Constructor",node->pos);
    }
    if (current_class->is_function(name)) {
      throw semanticError("Multiple Definitions",node->pos);
    }
    auto return_name=node->return_type->name;
    auto return_dim=node->return_type->dim;

    if (!global_scope.is_type(return_name)) {
      throw semanticError("Invalid Type",node->pos);
    }
    auto return_typename = global_scope.ask_type(return_name);
    auto return_type =std::make_shared<Type>(std::move(return_typename), return_dim);
    auto &args = node->arguments;
    std::vector<std::shared_ptr<Type> > ret_args;
    for (const auto &it : args) {
      auto arg_name = it.first->name;
      auto arg_dim = it.first->dim;
      if (!global_scope.is_type(arg_name)) {
        throw semanticError("Invalid Type",node->pos);
      }
      auto arg_typename = global_scope.ask_type(arg_name);
      auto arg_type =std::make_shared<Type>(std::move(arg_typename), arg_dim);
      ret_args.push_back(std::move(arg_type));
    }
    Function func(std::move(return_type), std::move(ret_args));
    //  std::cerr<<"collect func"<<func.return_type->type_name<<'\n';
    current_class->add_function(name, func);
    //  std::cerr<<"collect func"<<name<<' '<<current_class->ask_function(name).return_type->type_name<<'\n';
  }

  void get_class_var(std::shared_ptr<varDefNode> node) {
    auto type_str= node->type_name->name;
    auto dim=node->type_name->dim;
    if (!global_scope.is_type(type_str)) {
      throw semanticError("Invalid Type",node->pos);
    }
    auto type_name = global_scope.ask_type(type_str);
    auto type = Type(std::move(type_name), dim);
    auto &var_name = node->var_name;
    for (const auto &it : var_name) {
      if (current_class->is_member(it)) {
        throw semanticError("Multiple Definitions",node->pos);
      }
      current_class->add_member(it, type);
    }
  }
  void visit(funcDefNode *node) final {
    auto &func_name = node->func_name;
    auto ret_name = node->return_type->name;
    auto dim = node->return_type->dim;
    if (!global_scope.is_type(ret_name)) {
      throw semanticError("Undefined Identifier",node->pos);
    }
    auto return_typename = global_scope.ask_type(ret_name);
    auto return_type = std::make_shared<Type>(std::move(return_typename), dim);
    std::vector<std::shared_ptr<Type> > args;
    for (const auto &it : node->arguments) {
      auto arg_name = it.first->name;
      auto arg_dim = it.first->dim;
      if (!global_scope.is_type(arg_name)) {
        throw semanticError("Undefined Identifier",node->pos);
      }
      auto arg_typename = global_scope.ask_type(arg_name);
      auto arg_type = std::make_shared<Type>(std::move(arg_typename), arg_dim);
      args.push_back(std::move(arg_type));
    }
    Function func(std::move(return_type), std::move(args));
    if (scope.is_var(func_name)) {
      throw semanticError("Multiple Definitions",node->pos);
    }
    global_scope.add_function(func_name, func, {node->pos});
    std::cerr<<func_name<<' '<<node->arguments.size()<<"in collect\n";
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
  void visit(parenPrimaryNode *node) final {}
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
      throw semanticError("Invalid Class Constructor",node->pos);
    }
    if (current_class->is_function(name)) {
      throw semanticError("Multiple Definitions",node->pos);
    }
    Function constructor(VoidType, {});
    current_class->add_function(name, std::move(constructor));
  }
//  void visit(functionDefClassStmtNode *node) final {}
//  void visit(varDefClassStmtNode *node) final {}
  void visit(TypeNode *node) final {}
  Scope scope;
  GlobalScope global_scope;
  std::shared_ptr<Typename> current_class;
};
