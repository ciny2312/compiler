// Generated from /home/ciny2312/bighomework_1_3/compiler/Mx.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MxParser}.
 */
public interface MxListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MxParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(MxParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(MxParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#main}.
	 * @param ctx the parse tree
	 */
	void enterMain(MxParser.MainContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#main}.
	 * @param ctx the parse tree
	 */
	void exitMain(MxParser.MainContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#classDef}.
	 * @param ctx the parse tree
	 */
	void enterClassDef(MxParser.ClassDefContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#classDef}.
	 * @param ctx the parse tree
	 */
	void exitClassDef(MxParser.ClassDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#varDef}.
	 * @param ctx the parse tree
	 */
	void enterVarDef(MxParser.VarDefContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#varDef}.
	 * @param ctx the parse tree
	 */
	void exitVarDef(MxParser.VarDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#funcDef}.
	 * @param ctx the parse tree
	 */
	void enterFuncDef(MxParser.FuncDefContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#funcDef}.
	 * @param ctx the parse tree
	 */
	void exitFuncDef(MxParser.FuncDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#consDef}.
	 * @param ctx the parse tree
	 */
	void enterConsDef(MxParser.ConsDefContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#consDef}.
	 * @param ctx the parse tree
	 */
	void exitConsDef(MxParser.ConsDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#functionParameterList}.
	 * @param ctx the parse tree
	 */
	void enterFunctionParameterList(MxParser.FunctionParameterListContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#functionParameterList}.
	 * @param ctx the parse tree
	 */
	void exitFunctionParameterList(MxParser.FunctionParameterListContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#suite}.
	 * @param ctx the parse tree
	 */
	void enterSuite(MxParser.SuiteContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#suite}.
	 * @param ctx the parse tree
	 */
	void exitSuite(MxParser.SuiteContext ctx);
	/**
	 * Enter a parse tree produced by the {@code block}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterBlock(MxParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by the {@code block}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitBlock(MxParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by the {@code vardefStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterVardefStmt(MxParser.VardefStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code vardefStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitVardefStmt(MxParser.VardefStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ifStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterIfStmt(MxParser.IfStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ifStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitIfStmt(MxParser.IfStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code whileStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterWhileStmt(MxParser.WhileStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code whileStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitWhileStmt(MxParser.WhileStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code forStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterForStmt(MxParser.ForStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code forStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitForStmt(MxParser.ForStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code breakStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterBreakStmt(MxParser.BreakStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code breakStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitBreakStmt(MxParser.BreakStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code continueStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterContinueStmt(MxParser.ContinueStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code continueStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitContinueStmt(MxParser.ContinueStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code returnStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterReturnStmt(MxParser.ReturnStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code returnStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitReturnStmt(MxParser.ReturnStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code pureExprStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterPureExprStmt(MxParser.PureExprStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code pureExprStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitPureExprStmt(MxParser.PureExprStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code emptyExprStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterEmptyExprStmt(MxParser.EmptyExprStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code emptyExprStmt}
	 * labeled alternative in {@link MxParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitEmptyExprStmt(MxParser.EmptyExprStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#exprlist}.
	 * @param ctx the parse tree
	 */
	void enterExprlist(MxParser.ExprlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#exprlist}.
	 * @param ctx the parse tree
	 */
	void exitExprlist(MxParser.ExprlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#ifstmt}.
	 * @param ctx the parse tree
	 */
	void enterIfstmt(MxParser.IfstmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#ifstmt}.
	 * @param ctx the parse tree
	 */
	void exitIfstmt(MxParser.IfstmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#whilestmt}.
	 * @param ctx the parse tree
	 */
	void enterWhilestmt(MxParser.WhilestmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#whilestmt}.
	 * @param ctx the parse tree
	 */
	void exitWhilestmt(MxParser.WhilestmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#forstmt}.
	 * @param ctx the parse tree
	 */
	void enterForstmt(MxParser.ForstmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#forstmt}.
	 * @param ctx the parse tree
	 */
	void exitForstmt(MxParser.ForstmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(MxParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(MxParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code bitExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBitExpr(MxParser.BitExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code bitExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBitExpr(MxParser.BitExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code arrayAccessPrimary}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterArrayAccessPrimary(MxParser.ArrayAccessPrimaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code arrayAccessPrimary}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitArrayAccessPrimary(MxParser.ArrayAccessPrimaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code oneExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterOneExpr(MxParser.OneExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code oneExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitOneExpr(MxParser.OneExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code formatStmt}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterFormatStmt(MxParser.FormatStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code formatStmt}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitFormatStmt(MxParser.FormatStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code logicExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterLogicExpr(MxParser.LogicExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code logicExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitLogicExpr(MxParser.LogicExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atomExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAtomExpr(MxParser.AtomExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atomExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAtomExpr(MxParser.AtomExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code binaryExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBinaryExpr(MxParser.BinaryExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code binaryExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBinaryExpr(MxParser.BinaryExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code assignExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAssignExpr(MxParser.AssignExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code assignExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAssignExpr(MxParser.AssignExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code usefunc}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterUsefunc(MxParser.UsefuncContext ctx);
	/**
	 * Exit a parse tree produced by the {@code usefunc}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitUsefunc(MxParser.UsefuncContext ctx);
	/**
	 * Enter a parse tree produced by the {@code compareExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterCompareExpr(MxParser.CompareExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code compareExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitCompareExpr(MxParser.CompareExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code threeExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterThreeExpr(MxParser.ThreeExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code threeExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitThreeExpr(MxParser.ThreeExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code pointExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterPointExpr(MxParser.PointExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code pointExpr}
	 * labeled alternative in {@link MxParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitPointExpr(MxParser.PointExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code parenPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void enterParenPrimary(MxParser.ParenPrimaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code parenPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void exitParenPrimary(MxParser.ParenPrimaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code indentifierPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void enterIndentifierPrimary(MxParser.IndentifierPrimaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code indentifierPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void exitIndentifierPrimary(MxParser.IndentifierPrimaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code constPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void enterConstPrimary(MxParser.ConstPrimaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code constPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void exitConstPrimary(MxParser.ConstPrimaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code thisPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void enterThisPrimary(MxParser.ThisPrimaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code thisPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void exitThisPrimary(MxParser.ThisPrimaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code newPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void enterNewPrimary(MxParser.NewPrimaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code newPrimary}
	 * labeled alternative in {@link MxParser#primary}.
	 * @param ctx the parse tree
	 */
	void exitNewPrimary(MxParser.NewPrimaryContext ctx);
}