// Generated from /home/ciny2312/bighomework_1_3/compiler/parser/Mx.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class MxParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, FormatString1=2, FormatString2=3, FormatString3=4, FormatString4=5, 
		Int=6, If=7, Else=8, Return=9, Void=10, Bool=11, String=12, New=13, Class=14, 
		Null=15, True=16, False=17, This=18, For=19, While=20, Break=21, Continue=22, 
		LeftParen=23, RightParen=24, LeftBracket=25, RightBracket=26, LeftBrace=27, 
		RightBrace=28, Less=29, LessEqual=30, Greater=31, GreaterEqual=32, LeftShift=33, 
		RightShift=34, Plus=35, Minus=36, Mul=37, Div=38, Mod=39, And=40, Or=41, 
		AndAnd=42, OrOr=43, Caret=44, Not=45, Tilde=46, Question=47, Colon=48, 
		Semi=49, Comma=50, Assign=51, Equal=52, NotEqual=53, SelfPlus=54, SelfMinus=55, 
		Belong=56, Yinghao=57, IntegerConst=58, BoolConst=59, StringConst=60, 
		Identifier=61, Whitespace=62, Newline=63, BlockComment=64, LineComment=65;
	public static final int
		RULE_program = 0, RULE_main = 1, RULE_classDef = 2, RULE_varDef = 3, RULE_funcDef = 4, 
		RULE_consDef = 5, RULE_suite = 6, RULE_statement = 7, RULE_exprlist = 8, 
		RULE_ifstmt = 9, RULE_whilestmt = 10, RULE_forstmt = 11, RULE_type = 12, 
		RULE_expression = 13, RULE_primary = 14, RULE_mxconst = 15, RULE_array = 16;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "main", "classDef", "varDef", "funcDef", "consDef", "suite", 
			"statement", "exprlist", "ifstmt", "whilestmt", "forstmt", "type", "expression", 
			"primary", "mxconst", "array"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'main'", null, null, null, null, "'int'", "'if'", "'else'", "'return'", 
			"'void'", "'bool'", "'string'", "'new'", "'class'", "'null'", "'true'", 
			"'false'", "'this'", "'for'", "'while'", "'break'", "'continue'", "'('", 
			"')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", "'<<'", 
			"'>>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'&'", "'|'", "'&&'", "'||'", 
			"'^'", "'!'", "'~'", "'?'", "':'", "';'", "','", "'='", "'=='", "'!='", 
			"'++'", "'--'", "'.'", "'\"'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, "FormatString1", "FormatString2", "FormatString3", "FormatString4", 
			"Int", "If", "Else", "Return", "Void", "Bool", "String", "New", "Class", 
			"Null", "True", "False", "This", "For", "While", "Break", "Continue", 
			"LeftParen", "RightParen", "LeftBracket", "RightBracket", "LeftBrace", 
			"RightBrace", "Less", "LessEqual", "Greater", "GreaterEqual", "LeftShift", 
			"RightShift", "Plus", "Minus", "Mul", "Div", "Mod", "And", "Or", "AndAnd", 
			"OrOr", "Caret", "Not", "Tilde", "Question", "Colon", "Semi", "Comma", 
			"Assign", "Equal", "NotEqual", "SelfPlus", "SelfMinus", "Belong", "Yinghao", 
			"IntegerConst", "BoolConst", "StringConst", "Identifier", "Whitespace", 
			"Newline", "BlockComment", "LineComment"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Mx.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MxParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public MainContext main() {
			return getRuleContext(MainContext.class,0);
		}
		public TerminalNode EOF() { return getToken(MxParser.EOF, 0); }
		public List<ClassDefContext> classDef() {
			return getRuleContexts(ClassDefContext.class);
		}
		public ClassDefContext classDef(int i) {
			return getRuleContext(ClassDefContext.class,i);
		}
		public List<FuncDefContext> funcDef() {
			return getRuleContexts(FuncDefContext.class);
		}
		public FuncDefContext funcDef(int i) {
			return getRuleContext(FuncDefContext.class,i);
		}
		public List<VarDefContext> varDef() {
			return getRuleContexts(VarDefContext.class);
		}
		public VarDefContext varDef(int i) {
			return getRuleContext(VarDefContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(39);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					setState(37);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
					case 1:
						{
						setState(34);
						classDef();
						}
						break;
					case 2:
						{
						setState(35);
						funcDef();
						}
						break;
					case 3:
						{
						setState(36);
						varDef();
						}
						break;
					}
					} 
				}
				setState(41);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			}
			setState(42);
			main();
			setState(48);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 2305843009213717568L) != 0)) {
				{
				setState(46);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
				case 1:
					{
					setState(43);
					classDef();
					}
					break;
				case 2:
					{
					setState(44);
					funcDef();
					}
					break;
				case 3:
					{
					setState(45);
					varDef();
					}
					break;
				}
				}
				setState(50);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(51);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class MainContext extends ParserRuleContext {
		public TerminalNode Int() { return getToken(MxParser.Int, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public MainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_main; }
	}

	public final MainContext main() throws RecognitionException {
		MainContext _localctx = new MainContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_main);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(53);
			match(Int);
			setState(54);
			match(T__0);
			setState(55);
			match(LeftParen);
			setState(56);
			match(RightParen);
			setState(57);
			suite();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ClassDefContext extends ParserRuleContext {
		public TerminalNode Class() { return getToken(MxParser.Class, 0); }
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public TerminalNode LeftBrace() { return getToken(MxParser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(MxParser.RightBrace, 0); }
		public TerminalNode Semi() { return getToken(MxParser.Semi, 0); }
		public List<VarDefContext> varDef() {
			return getRuleContexts(VarDefContext.class);
		}
		public VarDefContext varDef(int i) {
			return getRuleContext(VarDefContext.class,i);
		}
		public List<FuncDefContext> funcDef() {
			return getRuleContexts(FuncDefContext.class);
		}
		public FuncDefContext funcDef(int i) {
			return getRuleContext(FuncDefContext.class,i);
		}
		public List<ConsDefContext> consDef() {
			return getRuleContexts(ConsDefContext.class);
		}
		public ConsDefContext consDef(int i) {
			return getRuleContext(ConsDefContext.class,i);
		}
		public ClassDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classDef; }
	}

	public final ClassDefContext classDef() throws RecognitionException {
		ClassDefContext _localctx = new ClassDefContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_classDef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			match(Class);
			setState(60);
			match(Identifier);
			setState(61);
			match(LeftBrace);
			setState(67);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 2305843009213701184L) != 0)) {
				{
				setState(65);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
				case 1:
					{
					setState(62);
					varDef();
					}
					break;
				case 2:
					{
					setState(63);
					funcDef();
					}
					break;
				case 3:
					{
					setState(64);
					consDef();
					}
					break;
				}
				}
				setState(69);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(70);
			match(RightBrace);
			setState(71);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarDefContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<TerminalNode> Identifier() { return getTokens(MxParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(MxParser.Identifier, i);
		}
		public TerminalNode Semi() { return getToken(MxParser.Semi, 0); }
		public List<TerminalNode> Assign() { return getTokens(MxParser.Assign); }
		public TerminalNode Assign(int i) {
			return getToken(MxParser.Assign, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(MxParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(MxParser.Comma, i);
		}
		public VarDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDef; }
	}

	public final VarDefContext varDef() throws RecognitionException {
		VarDefContext _localctx = new VarDefContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_varDef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(73);
			type();
			setState(74);
			match(Identifier);
			setState(77);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Assign) {
				{
				setState(75);
				match(Assign);
				setState(76);
				expression(0);
				}
			}

			setState(87);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(79);
				match(Comma);
				setState(80);
				match(Identifier);
				setState(83);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Assign) {
					{
					setState(81);
					match(Assign);
					setState(82);
					expression(0);
					}
				}

				}
				}
				setState(89);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(90);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FuncDefContext extends ParserRuleContext {
		public TypeContext return_type;
		public Token func_name;
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public List<TerminalNode> Identifier() { return getTokens(MxParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(MxParser.Identifier, i);
		}
		public List<TerminalNode> Assign() { return getTokens(MxParser.Assign); }
		public TerminalNode Assign(int i) {
			return getToken(MxParser.Assign, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(MxParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(MxParser.Comma, i);
		}
		public FuncDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcDef; }
	}

	public final FuncDefContext funcDef() throws RecognitionException {
		FuncDefContext _localctx = new FuncDefContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_funcDef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(92);
			((FuncDefContext)_localctx).return_type = type();
			setState(93);
			((FuncDefContext)_localctx).func_name = match(Identifier);
			setState(94);
			match(LeftParen);
			setState(113);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 2305843009213701184L) != 0)) {
				{
				setState(95);
				type();
				setState(96);
				match(Identifier);
				setState(99);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Assign) {
					{
					setState(97);
					match(Assign);
					setState(98);
					expression(0);
					}
				}

				setState(110);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(101);
					match(Comma);
					setState(102);
					type();
					setState(103);
					match(Identifier);
					setState(106);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==Assign) {
						{
						setState(104);
						match(Assign);
						setState(105);
						expression(0);
						}
					}

					}
					}
					setState(112);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(115);
			match(RightParen);
			setState(116);
			suite();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConsDefContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public ConsDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_consDef; }
	}

	public final ConsDefContext consDef() throws RecognitionException {
		ConsDefContext _localctx = new ConsDefContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_consDef);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(118);
			match(Identifier);
			setState(119);
			match(LeftParen);
			setState(120);
			match(RightParen);
			setState(121);
			suite();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SuiteContext extends ParserRuleContext {
		public TerminalNode LeftBrace() { return getToken(MxParser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(MxParser.RightBrace, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public SuiteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_suite; }
	}

	public final SuiteContext suite() throws RecognitionException {
		SuiteContext _localctx = new SuiteContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_suite);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(123);
			match(LeftBrace);
			setState(127);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 3801706657440841420L) != 0)) {
				{
				{
				setState(124);
				statement();
				}
				}
				setState(129);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(130);
			match(RightBrace);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ForStmtContext extends StatementContext {
		public ForstmtContext forstmt() {
			return getRuleContext(ForstmtContext.class,0);
		}
		public ForStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class WhileStmtContext extends StatementContext {
		public WhilestmtContext whilestmt() {
			return getRuleContext(WhilestmtContext.class,0);
		}
		public WhileStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IfStmtContext extends StatementContext {
		public IfstmtContext ifstmt() {
			return getRuleContext(IfstmtContext.class,0);
		}
		public IfStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BlockStmtContext extends StatementContext {
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public BlockStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EmptyExprStmtContext extends StatementContext {
		public TerminalNode Semi() { return getToken(MxParser.Semi, 0); }
		public EmptyExprStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BreakStmtContext extends StatementContext {
		public TerminalNode Break() { return getToken(MxParser.Break, 0); }
		public TerminalNode Semi() { return getToken(MxParser.Semi, 0); }
		public BreakStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ReturnStmtContext extends StatementContext {
		public TerminalNode Return() { return getToken(MxParser.Return, 0); }
		public TerminalNode Semi() { return getToken(MxParser.Semi, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ReturnStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ContinueStmtContext extends StatementContext {
		public TerminalNode Continue() { return getToken(MxParser.Continue, 0); }
		public TerminalNode Semi() { return getToken(MxParser.Semi, 0); }
		public ContinueStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VardefStmtContext extends StatementContext {
		public VarDefContext varDef() {
			return getRuleContext(VarDefContext.class,0);
		}
		public VardefStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PureExprStmtContext extends StatementContext {
		public ExprlistContext exprlist() {
			return getRuleContext(ExprlistContext.class,0);
		}
		public TerminalNode Semi() { return getToken(MxParser.Semi, 0); }
		public PureExprStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_statement);
		int _la;
		try {
			setState(150);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				_localctx = new BlockStmtContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(132);
				suite();
				}
				break;
			case 2:
				_localctx = new VardefStmtContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(133);
				varDef();
				}
				break;
			case 3:
				_localctx = new IfStmtContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(134);
				ifstmt();
				}
				break;
			case 4:
				_localctx = new WhileStmtContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(135);
				whilestmt();
				}
				break;
			case 5:
				_localctx = new ForStmtContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(136);
				forstmt();
				}
				break;
			case 6:
				_localctx = new BreakStmtContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(137);
				match(Break);
				setState(138);
				match(Semi);
				}
				break;
			case 7:
				_localctx = new ContinueStmtContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(139);
				match(Continue);
				setState(140);
				match(Semi);
				}
				break;
			case 8:
				_localctx = new ReturnStmtContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(141);
				match(Return);
				setState(143);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 3801143707479547916L) != 0)) {
					{
					setState(142);
					expression(0);
					}
				}

				setState(145);
				match(Semi);
				}
				break;
			case 9:
				_localctx = new PureExprStmtContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(146);
				exprlist();
				setState(147);
				match(Semi);
				}
				break;
			case 10:
				_localctx = new EmptyExprStmtContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(149);
				match(Semi);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExprlistContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(MxParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(MxParser.Comma, i);
		}
		public ExprlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exprlist; }
	}

	public final ExprlistContext exprlist() throws RecognitionException {
		ExprlistContext _localctx = new ExprlistContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_exprlist);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(152);
			expression(0);
			setState(157);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(153);
				match(Comma);
				setState(154);
				expression(0);
				}
				}
				setState(159);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IfstmtContext extends ParserRuleContext {
		public StatementContext trueStmt;
		public StatementContext falseStmt;
		public TerminalNode If() { return getToken(MxParser.If, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode Else() { return getToken(MxParser.Else, 0); }
		public IfstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifstmt; }
	}

	public final IfstmtContext ifstmt() throws RecognitionException {
		IfstmtContext _localctx = new IfstmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_ifstmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(160);
			match(If);
			setState(161);
			match(LeftParen);
			setState(162);
			expression(0);
			setState(163);
			match(RightParen);
			setState(164);
			((IfstmtContext)_localctx).trueStmt = statement();
			setState(167);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				setState(165);
				match(Else);
				setState(166);
				((IfstmtContext)_localctx).falseStmt = statement();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class WhilestmtContext extends ParserRuleContext {
		public TerminalNode While() { return getToken(MxParser.While, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public WhilestmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whilestmt; }
	}

	public final WhilestmtContext whilestmt() throws RecognitionException {
		WhilestmtContext _localctx = new WhilestmtContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_whilestmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(169);
			match(While);
			setState(170);
			match(LeftParen);
			setState(171);
			expression(0);
			setState(172);
			match(RightParen);
			setState(173);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ForstmtContext extends ParserRuleContext {
		public StatementContext initializeStmt;
		public ExpressionContext condiExpr;
		public ExpressionContext stepExpr;
		public TerminalNode For() { return getToken(MxParser.For, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode Semi() { return getToken(MxParser.Semi, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ForstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forstmt; }
	}

	public final ForstmtContext forstmt() throws RecognitionException {
		ForstmtContext _localctx = new ForstmtContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_forstmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(175);
			match(For);
			setState(176);
			match(LeftParen);
			setState(177);
			((ForstmtContext)_localctx).initializeStmt = statement();
			setState(179);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 3801143707479547916L) != 0)) {
				{
				setState(178);
				((ForstmtContext)_localctx).condiExpr = expression(0);
				}
			}

			setState(181);
			match(Semi);
			setState(183);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 3801143707479547916L) != 0)) {
				{
				setState(182);
				((ForstmtContext)_localctx).stepExpr = expression(0);
				}
			}

			setState(185);
			match(RightParen);
			setState(186);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TypeContext extends ParserRuleContext {
		public ExpressionContext expression;
		public List<ExpressionContext> size_after_empty = new ArrayList<ExpressionContext>();
		public TerminalNode Int() { return getToken(MxParser.Int, 0); }
		public TerminalNode String() { return getToken(MxParser.String, 0); }
		public TerminalNode Bool() { return getToken(MxParser.Bool, 0); }
		public TerminalNode Void() { return getToken(MxParser.Void, 0); }
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public List<TerminalNode> LeftBracket() { return getTokens(MxParser.LeftBracket); }
		public TerminalNode LeftBracket(int i) {
			return getToken(MxParser.LeftBracket, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> RightBracket() { return getTokens(MxParser.RightBracket); }
		public TerminalNode RightBracket(int i) {
			return getToken(MxParser.RightBracket, i);
		}
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_type);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(188);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 2305843009213701184L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(195);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(189);
					match(LeftBracket);
					setState(190);
					expression(0);
					setState(191);
					match(RightBracket);
					}
					} 
				}
				setState(197);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			setState(202);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(198);
					match(LeftBracket);
					setState(199);
					match(RightBracket);
					}
					} 
				}
				setState(204);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			setState(211);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(205);
					match(LeftBracket);
					setState(206);
					((TypeContext)_localctx).expression = expression(0);
					((TypeContext)_localctx).size_after_empty.add(((TypeContext)_localctx).expression);
					setState(207);
					match(RightBracket);
					}
					} 
				}
				setState(213);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BitExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode LeftShift() { return getToken(MxParser.LeftShift, 0); }
		public TerminalNode RightShift() { return getToken(MxParser.RightShift, 0); }
		public TerminalNode And() { return getToken(MxParser.And, 0); }
		public TerminalNode Caret() { return getToken(MxParser.Caret, 0); }
		public TerminalNode Or() { return getToken(MxParser.Or, 0); }
		public BitExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class OneExprContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SelfPlus() { return getToken(MxParser.SelfPlus, 0); }
		public TerminalNode SelfMinus() { return getToken(MxParser.SelfMinus, 0); }
		public TerminalNode Not() { return getToken(MxParser.Not, 0); }
		public TerminalNode Tilde() { return getToken(MxParser.Tilde, 0); }
		public TerminalNode Minus() { return getToken(MxParser.Minus, 0); }
		public OneExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArrayAccessExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode LeftBracket() { return getToken(MxParser.LeftBracket, 0); }
		public TerminalNode RightBracket() { return getToken(MxParser.RightBracket, 0); }
		public ArrayAccessExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LogicExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode AndAnd() { return getToken(MxParser.AndAnd, 0); }
		public TerminalNode OrOr() { return getToken(MxParser.OrOr, 0); }
		public LogicExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AtomExprContext extends ExpressionContext {
		public PrimaryContext primary() {
			return getRuleContext(PrimaryContext.class,0);
		}
		public AtomExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BinaryExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Mul() { return getToken(MxParser.Mul, 0); }
		public TerminalNode Div() { return getToken(MxParser.Div, 0); }
		public TerminalNode Mod() { return getToken(MxParser.Mod, 0); }
		public TerminalNode Plus() { return getToken(MxParser.Plus, 0); }
		public TerminalNode Minus() { return getToken(MxParser.Minus, 0); }
		public BinaryExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FormatExprContext extends ExpressionContext {
		public TerminalNode FormatString1() { return getToken(MxParser.FormatString1, 0); }
		public TerminalNode FormatString2() { return getToken(MxParser.FormatString2, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode FormatString4() { return getToken(MxParser.FormatString4, 0); }
		public List<TerminalNode> FormatString3() { return getTokens(MxParser.FormatString3); }
		public TerminalNode FormatString3(int i) {
			return getToken(MxParser.FormatString3, i);
		}
		public FormatExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AssignExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Assign() { return getToken(MxParser.Assign, 0); }
		public AssignExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UsefuncContext extends ExpressionContext {
		public ExpressionContext classname;
		public Token name;
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public ExprlistContext exprlist() {
			return getRuleContext(ExprlistContext.class,0);
		}
		public TerminalNode Belong() { return getToken(MxParser.Belong, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public UsefuncContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CompareExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Less() { return getToken(MxParser.Less, 0); }
		public TerminalNode LessEqual() { return getToken(MxParser.LessEqual, 0); }
		public TerminalNode Greater() { return getToken(MxParser.Greater, 0); }
		public TerminalNode GreaterEqual() { return getToken(MxParser.GreaterEqual, 0); }
		public TerminalNode NotEqual() { return getToken(MxParser.NotEqual, 0); }
		public TerminalNode Equal() { return getToken(MxParser.Equal, 0); }
		public CompareExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ThreeExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Question() { return getToken(MxParser.Question, 0); }
		public TerminalNode Colon() { return getToken(MxParser.Colon, 0); }
		public ThreeExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PointExprContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode Belong() { return getToken(MxParser.Belong, 0); }
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public PointExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 26;
		enterRecursionRule(_localctx, 26, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(238);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				{
				_localctx = new AtomExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(215);
				primary();
				}
				break;
			case 2:
				{
				_localctx = new FormatExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(216);
				match(FormatString1);
				}
				break;
			case 3:
				{
				_localctx = new FormatExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(217);
				match(FormatString2);
				setState(218);
				expression(0);
				setState(223);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==FormatString3) {
					{
					{
					setState(219);
					match(FormatString3);
					setState(220);
					expression(0);
					}
					}
					setState(225);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(226);
				match(FormatString4);
				}
				break;
			case 4:
				{
				_localctx = new UsefuncContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(228);
				((UsefuncContext)_localctx).name = match(Identifier);
				setState(229);
				match(LeftParen);
				setState(231);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 3801143707479547916L) != 0)) {
					{
					setState(230);
					exprlist();
					}
				}

				setState(233);
				match(RightParen);
				}
				break;
			case 5:
				{
				_localctx = new OneExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(234);
				_la = _input.LA(1);
				if ( !(_la==SelfPlus || _la==SelfMinus) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(235);
				expression(14);
				}
				break;
			case 6:
				{
				_localctx = new OneExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(236);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 105621835743232L) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(237);
				expression(13);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(299);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(297);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
					case 1:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(240);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(241);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 962072674304L) != 0)) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(242);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(243);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(244);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Plus || _la==Minus) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(245);
						expression(12);
						}
						break;
					case 3:
						{
						_localctx = new BitExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(246);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(247);
						((BitExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==LeftShift || _la==RightShift) ) {
							((BitExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(248);
						expression(11);
						}
						break;
					case 4:
						{
						_localctx = new CompareExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(249);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(250);
						((CompareExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 8053063680L) != 0)) ) {
							((CompareExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(251);
						expression(10);
						}
						break;
					case 5:
						{
						_localctx = new CompareExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(252);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(253);
						((CompareExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Equal || _la==NotEqual) ) {
							((CompareExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(254);
						expression(9);
						}
						break;
					case 6:
						{
						_localctx = new BitExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(255);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(256);
						((BitExprContext)_localctx).op = match(And);
						setState(257);
						expression(8);
						}
						break;
					case 7:
						{
						_localctx = new BitExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(258);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(259);
						((BitExprContext)_localctx).op = match(Caret);
						setState(260);
						expression(7);
						}
						break;
					case 8:
						{
						_localctx = new BitExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(261);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(262);
						((BitExprContext)_localctx).op = match(Or);
						setState(263);
						expression(6);
						}
						break;
					case 9:
						{
						_localctx = new LogicExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(264);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(265);
						((LogicExprContext)_localctx).op = match(AndAnd);
						setState(266);
						expression(5);
						}
						break;
					case 10:
						{
						_localctx = new LogicExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(267);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(268);
						((LogicExprContext)_localctx).op = match(OrOr);
						setState(269);
						expression(4);
						}
						break;
					case 11:
						{
						_localctx = new ThreeExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(270);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(271);
						match(Question);
						setState(272);
						expression(0);
						setState(273);
						match(Colon);
						setState(274);
						expression(2);
						}
						break;
					case 12:
						{
						_localctx = new AssignExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(276);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(277);
						match(Assign);
						setState(278);
						expression(1);
						}
						break;
					case 13:
						{
						_localctx = new UsefuncContext(new ExpressionContext(_parentctx, _parentState));
						((UsefuncContext)_localctx).classname = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(279);
						if (!(precpred(_ctx, 18))) throw new FailedPredicateException(this, "precpred(_ctx, 18)");
						setState(280);
						match(Belong);
						setState(281);
						((UsefuncContext)_localctx).name = match(Identifier);
						setState(282);
						match(LeftParen);
						setState(284);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 3801143707479547916L) != 0)) {
							{
							setState(283);
							exprlist();
							}
						}

						setState(286);
						match(RightParen);
						}
						break;
					case 14:
						{
						_localctx = new OneExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(287);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(288);
						_la = _input.LA(1);
						if ( !(_la==SelfPlus || _la==SelfMinus) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						}
						break;
					case 15:
						{
						_localctx = new ArrayAccessExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(289);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(290);
						match(LeftBracket);
						setState(291);
						expression(0);
						setState(292);
						match(RightBracket);
						}
						break;
					case 16:
						{
						_localctx = new PointExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(294);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(295);
						match(Belong);
						setState(296);
						match(Identifier);
						}
						break;
					}
					} 
				}
				setState(301);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PrimaryContext extends ParserRuleContext {
		public PrimaryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary; }
	 
		public PrimaryContext() { }
		public void copyFrom(PrimaryContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ThisPrimaryContext extends PrimaryContext {
		public TerminalNode This() { return getToken(MxParser.This, 0); }
		public ThisPrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParenPrimaryContext extends PrimaryContext {
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public ParenPrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IndentifierPrimaryContext extends PrimaryContext {
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public IndentifierPrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstPrimaryContext extends PrimaryContext {
		public MxconstContext mxconst() {
			return getRuleContext(MxconstContext.class,0);
		}
		public ConstPrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NewPrimaryContext extends PrimaryContext {
		public TerminalNode New() { return getToken(MxParser.New, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public NewPrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
	}

	public final PrimaryContext primary() throws RecognitionException {
		PrimaryContext _localctx = new PrimaryContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_primary);
		try {
			setState(319);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,30,_ctx) ) {
			case 1:
				_localctx = new ParenPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(302);
				match(LeftParen);
				setState(303);
				expression(0);
				setState(304);
				match(RightParen);
				}
				break;
			case 2:
				_localctx = new IndentifierPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(306);
				match(Identifier);
				}
				break;
			case 3:
				_localctx = new ConstPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(307);
				mxconst();
				}
				break;
			case 4:
				_localctx = new ThisPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(308);
				match(This);
				}
				break;
			case 5:
				_localctx = new NewPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(309);
				match(New);
				setState(310);
				type();
				setState(311);
				array();
				}
				break;
			case 6:
				_localctx = new NewPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(313);
				match(New);
				setState(314);
				type();
				setState(317);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,29,_ctx) ) {
				case 1:
					{
					setState(315);
					match(LeftParen);
					setState(316);
					match(RightParen);
					}
					break;
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class MxconstContext extends ParserRuleContext {
		public MxconstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mxconst; }
	 
		public MxconstContext() { }
		public void copyFrom(MxconstContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BoolConstContext extends MxconstContext {
		public TerminalNode True() { return getToken(MxParser.True, 0); }
		public TerminalNode False() { return getToken(MxParser.False, 0); }
		public BoolConstContext(MxconstContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArrayConstContext extends MxconstContext {
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public ArrayConstContext(MxconstContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IntConstContext extends MxconstContext {
		public TerminalNode IntegerConst() { return getToken(MxParser.IntegerConst, 0); }
		public IntConstContext(MxconstContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NullConstContext extends MxconstContext {
		public TerminalNode Null() { return getToken(MxParser.Null, 0); }
		public NullConstContext(MxconstContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StringConstContext extends MxconstContext {
		public TerminalNode StringConst() { return getToken(MxParser.StringConst, 0); }
		public StringConstContext(MxconstContext ctx) { copyFrom(ctx); }
	}

	public final MxconstContext mxconst() throws RecognitionException {
		MxconstContext _localctx = new MxconstContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_mxconst);
		try {
			setState(327);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IntegerConst:
				_localctx = new IntConstContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(321);
				match(IntegerConst);
				}
				break;
			case StringConst:
				_localctx = new StringConstContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(322);
				match(StringConst);
				}
				break;
			case True:
				_localctx = new BoolConstContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(323);
				match(True);
				}
				break;
			case False:
				_localctx = new BoolConstContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(324);
				match(False);
				}
				break;
			case Null:
				_localctx = new NullConstContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(325);
				match(Null);
				}
				break;
			case LeftBrace:
				_localctx = new ArrayConstContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(326);
				array();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrayContext extends ParserRuleContext {
		public TerminalNode LeftBrace() { return getToken(MxParser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(MxParser.RightBrace, 0); }
		public List<ArrayContext> array() {
			return getRuleContexts(ArrayContext.class);
		}
		public ArrayContext array(int i) {
			return getRuleContext(ArrayContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(MxParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(MxParser.Comma, i);
		}
		public List<MxconstContext> mxconst() {
			return getRuleContexts(MxconstContext.class);
		}
		public MxconstContext mxconst(int i) {
			return getRuleContext(MxconstContext.class,i);
		}
		public ArrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array; }
	}

	public final ArrayContext array() throws RecognitionException {
		ArrayContext _localctx = new ArrayContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_array);
		int _la;
		try {
			setState(353);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,34,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(329);
				match(LeftBrace);
				setState(330);
				match(RightBrace);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(331);
				match(LeftBrace);
				setState(332);
				array();
				setState(337);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(333);
					match(Comma);
					setState(334);
					array();
					}
					}
					setState(339);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(340);
				match(RightBrace);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(342);
				match(LeftBrace);
				setState(343);
				mxconst();
				setState(348);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(344);
					match(Comma);
					setState(345);
					mxconst();
					}
					}
					setState(350);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(351);
				match(RightBrace);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 13:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 12);
		case 1:
			return precpred(_ctx, 11);
		case 2:
			return precpred(_ctx, 10);
		case 3:
			return precpred(_ctx, 9);
		case 4:
			return precpred(_ctx, 8);
		case 5:
			return precpred(_ctx, 7);
		case 6:
			return precpred(_ctx, 6);
		case 7:
			return precpred(_ctx, 5);
		case 8:
			return precpred(_ctx, 4);
		case 9:
			return precpred(_ctx, 3);
		case 10:
			return precpred(_ctx, 2);
		case 11:
			return precpred(_ctx, 1);
		case 12:
			return precpred(_ctx, 18);
		case 13:
			return precpred(_ctx, 17);
		case 14:
			return precpred(_ctx, 16);
		case 15:
			return precpred(_ctx, 15);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001A\u0164\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0001\u0000\u0001\u0000\u0001\u0000\u0005\u0000"+
		"&\b\u0000\n\u0000\f\u0000)\t\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0005\u0000/\b\u0000\n\u0000\f\u00002\t\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0005\u0002B\b\u0002\n\u0002\f\u0002E\t\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0003\u0003N\b\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0003\u0003T\b\u0003\u0005\u0003V\b\u0003\n\u0003\f\u0003Y\t\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0003\u0004d\b\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004k\b\u0004\u0005"+
		"\u0004m\b\u0004\n\u0004\f\u0004p\t\u0004\u0003\u0004r\b\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0006\u0001\u0006\u0005\u0006~\b\u0006\n\u0006\f\u0006"+
		"\u0081\t\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0003\u0007\u0090\b\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u0097\b\u0007\u0001\b"+
		"\u0001\b\u0001\b\u0005\b\u009c\b\b\n\b\f\b\u009f\t\b\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\t\u00a8\b\t\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0003\u000b\u00b4\b\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00b8\b"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0005\f\u00c2\b\f\n\f\f\f\u00c5\t\f\u0001\f\u0001\f\u0005\f"+
		"\u00c9\b\f\n\f\f\f\u00cc\t\f\u0001\f\u0001\f\u0001\f\u0001\f\u0005\f\u00d2"+
		"\b\f\n\f\f\f\u00d5\t\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r"+
		"\u0001\r\u0005\r\u00de\b\r\n\r\f\r\u00e1\t\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0003\r\u00e8\b\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0003"+
		"\r\u00ef\b\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0003\r\u011d\b\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0005\r\u012a\b\r\n\r\f\r\u012d\t\r"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u013e\b\u000e\u0003\u000e"+
		"\u0140\b\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0003\u000f\u0148\b\u000f\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0005\u0010\u0150\b\u0010\n\u0010"+
		"\f\u0010\u0153\t\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0005\u0010\u015b\b\u0010\n\u0010\f\u0010\u015e"+
		"\t\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u0162\b\u0010\u0001\u0010"+
		"\u0000\u0001\u001a\u0011\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012"+
		"\u0014\u0016\u0018\u001a\u001c\u001e \u0000\b\u0003\u0000\u0006\u0006"+
		"\n\f==\u0001\u000067\u0002\u0000$$-.\u0001\u0000%\'\u0001\u0000#$\u0001"+
		"\u0000!\"\u0001\u0000\u001d \u0001\u000045\u019b\u0000\'\u0001\u0000\u0000"+
		"\u0000\u00025\u0001\u0000\u0000\u0000\u0004;\u0001\u0000\u0000\u0000\u0006"+
		"I\u0001\u0000\u0000\u0000\b\\\u0001\u0000\u0000\u0000\nv\u0001\u0000\u0000"+
		"\u0000\f{\u0001\u0000\u0000\u0000\u000e\u0096\u0001\u0000\u0000\u0000"+
		"\u0010\u0098\u0001\u0000\u0000\u0000\u0012\u00a0\u0001\u0000\u0000\u0000"+
		"\u0014\u00a9\u0001\u0000\u0000\u0000\u0016\u00af\u0001\u0000\u0000\u0000"+
		"\u0018\u00bc\u0001\u0000\u0000\u0000\u001a\u00ee\u0001\u0000\u0000\u0000"+
		"\u001c\u013f\u0001\u0000\u0000\u0000\u001e\u0147\u0001\u0000\u0000\u0000"+
		" \u0161\u0001\u0000\u0000\u0000\"&\u0003\u0004\u0002\u0000#&\u0003\b\u0004"+
		"\u0000$&\u0003\u0006\u0003\u0000%\"\u0001\u0000\u0000\u0000%#\u0001\u0000"+
		"\u0000\u0000%$\u0001\u0000\u0000\u0000&)\u0001\u0000\u0000\u0000\'%\u0001"+
		"\u0000\u0000\u0000\'(\u0001\u0000\u0000\u0000(*\u0001\u0000\u0000\u0000"+
		")\'\u0001\u0000\u0000\u0000*0\u0003\u0002\u0001\u0000+/\u0003\u0004\u0002"+
		"\u0000,/\u0003\b\u0004\u0000-/\u0003\u0006\u0003\u0000.+\u0001\u0000\u0000"+
		"\u0000.,\u0001\u0000\u0000\u0000.-\u0001\u0000\u0000\u0000/2\u0001\u0000"+
		"\u0000\u00000.\u0001\u0000\u0000\u000001\u0001\u0000\u0000\u000013\u0001"+
		"\u0000\u0000\u000020\u0001\u0000\u0000\u000034\u0005\u0000\u0000\u0001"+
		"4\u0001\u0001\u0000\u0000\u000056\u0005\u0006\u0000\u000067\u0005\u0001"+
		"\u0000\u000078\u0005\u0017\u0000\u000089\u0005\u0018\u0000\u00009:\u0003"+
		"\f\u0006\u0000:\u0003\u0001\u0000\u0000\u0000;<\u0005\u000e\u0000\u0000"+
		"<=\u0005=\u0000\u0000=C\u0005\u001b\u0000\u0000>B\u0003\u0006\u0003\u0000"+
		"?B\u0003\b\u0004\u0000@B\u0003\n\u0005\u0000A>\u0001\u0000\u0000\u0000"+
		"A?\u0001\u0000\u0000\u0000A@\u0001\u0000\u0000\u0000BE\u0001\u0000\u0000"+
		"\u0000CA\u0001\u0000\u0000\u0000CD\u0001\u0000\u0000\u0000DF\u0001\u0000"+
		"\u0000\u0000EC\u0001\u0000\u0000\u0000FG\u0005\u001c\u0000\u0000GH\u0005"+
		"1\u0000\u0000H\u0005\u0001\u0000\u0000\u0000IJ\u0003\u0018\f\u0000JM\u0005"+
		"=\u0000\u0000KL\u00053\u0000\u0000LN\u0003\u001a\r\u0000MK\u0001\u0000"+
		"\u0000\u0000MN\u0001\u0000\u0000\u0000NW\u0001\u0000\u0000\u0000OP\u0005"+
		"2\u0000\u0000PS\u0005=\u0000\u0000QR\u00053\u0000\u0000RT\u0003\u001a"+
		"\r\u0000SQ\u0001\u0000\u0000\u0000ST\u0001\u0000\u0000\u0000TV\u0001\u0000"+
		"\u0000\u0000UO\u0001\u0000\u0000\u0000VY\u0001\u0000\u0000\u0000WU\u0001"+
		"\u0000\u0000\u0000WX\u0001\u0000\u0000\u0000XZ\u0001\u0000\u0000\u0000"+
		"YW\u0001\u0000\u0000\u0000Z[\u00051\u0000\u0000[\u0007\u0001\u0000\u0000"+
		"\u0000\\]\u0003\u0018\f\u0000]^\u0005=\u0000\u0000^q\u0005\u0017\u0000"+
		"\u0000_`\u0003\u0018\f\u0000`c\u0005=\u0000\u0000ab\u00053\u0000\u0000"+
		"bd\u0003\u001a\r\u0000ca\u0001\u0000\u0000\u0000cd\u0001\u0000\u0000\u0000"+
		"dn\u0001\u0000\u0000\u0000ef\u00052\u0000\u0000fg\u0003\u0018\f\u0000"+
		"gj\u0005=\u0000\u0000hi\u00053\u0000\u0000ik\u0003\u001a\r\u0000jh\u0001"+
		"\u0000\u0000\u0000jk\u0001\u0000\u0000\u0000km\u0001\u0000\u0000\u0000"+
		"le\u0001\u0000\u0000\u0000mp\u0001\u0000\u0000\u0000nl\u0001\u0000\u0000"+
		"\u0000no\u0001\u0000\u0000\u0000or\u0001\u0000\u0000\u0000pn\u0001\u0000"+
		"\u0000\u0000q_\u0001\u0000\u0000\u0000qr\u0001\u0000\u0000\u0000rs\u0001"+
		"\u0000\u0000\u0000st\u0005\u0018\u0000\u0000tu\u0003\f\u0006\u0000u\t"+
		"\u0001\u0000\u0000\u0000vw\u0005=\u0000\u0000wx\u0005\u0017\u0000\u0000"+
		"xy\u0005\u0018\u0000\u0000yz\u0003\f\u0006\u0000z\u000b\u0001\u0000\u0000"+
		"\u0000{\u007f\u0005\u001b\u0000\u0000|~\u0003\u000e\u0007\u0000}|\u0001"+
		"\u0000\u0000\u0000~\u0081\u0001\u0000\u0000\u0000\u007f}\u0001\u0000\u0000"+
		"\u0000\u007f\u0080\u0001\u0000\u0000\u0000\u0080\u0082\u0001\u0000\u0000"+
		"\u0000\u0081\u007f\u0001\u0000\u0000\u0000\u0082\u0083\u0005\u001c\u0000"+
		"\u0000\u0083\r\u0001\u0000\u0000\u0000\u0084\u0097\u0003\f\u0006\u0000"+
		"\u0085\u0097\u0003\u0006\u0003\u0000\u0086\u0097\u0003\u0012\t\u0000\u0087"+
		"\u0097\u0003\u0014\n\u0000\u0088\u0097\u0003\u0016\u000b\u0000\u0089\u008a"+
		"\u0005\u0015\u0000\u0000\u008a\u0097\u00051\u0000\u0000\u008b\u008c\u0005"+
		"\u0016\u0000\u0000\u008c\u0097\u00051\u0000\u0000\u008d\u008f\u0005\t"+
		"\u0000\u0000\u008e\u0090\u0003\u001a\r\u0000\u008f\u008e\u0001\u0000\u0000"+
		"\u0000\u008f\u0090\u0001\u0000\u0000\u0000\u0090\u0091\u0001\u0000\u0000"+
		"\u0000\u0091\u0097\u00051\u0000\u0000\u0092\u0093\u0003\u0010\b\u0000"+
		"\u0093\u0094\u00051\u0000\u0000\u0094\u0097\u0001\u0000\u0000\u0000\u0095"+
		"\u0097\u00051\u0000\u0000\u0096\u0084\u0001\u0000\u0000\u0000\u0096\u0085"+
		"\u0001\u0000\u0000\u0000\u0096\u0086\u0001\u0000\u0000\u0000\u0096\u0087"+
		"\u0001\u0000\u0000\u0000\u0096\u0088\u0001\u0000\u0000\u0000\u0096\u0089"+
		"\u0001\u0000\u0000\u0000\u0096\u008b\u0001\u0000\u0000\u0000\u0096\u008d"+
		"\u0001\u0000\u0000\u0000\u0096\u0092\u0001\u0000\u0000\u0000\u0096\u0095"+
		"\u0001\u0000\u0000\u0000\u0097\u000f\u0001\u0000\u0000\u0000\u0098\u009d"+
		"\u0003\u001a\r\u0000\u0099\u009a\u00052\u0000\u0000\u009a\u009c\u0003"+
		"\u001a\r\u0000\u009b\u0099\u0001\u0000\u0000\u0000\u009c\u009f\u0001\u0000"+
		"\u0000\u0000\u009d\u009b\u0001\u0000\u0000\u0000\u009d\u009e\u0001\u0000"+
		"\u0000\u0000\u009e\u0011\u0001\u0000\u0000\u0000\u009f\u009d\u0001\u0000"+
		"\u0000\u0000\u00a0\u00a1\u0005\u0007\u0000\u0000\u00a1\u00a2\u0005\u0017"+
		"\u0000\u0000\u00a2\u00a3\u0003\u001a\r\u0000\u00a3\u00a4\u0005\u0018\u0000"+
		"\u0000\u00a4\u00a7\u0003\u000e\u0007\u0000\u00a5\u00a6\u0005\b\u0000\u0000"+
		"\u00a6\u00a8\u0003\u000e\u0007\u0000\u00a7\u00a5\u0001\u0000\u0000\u0000"+
		"\u00a7\u00a8\u0001\u0000\u0000\u0000\u00a8\u0013\u0001\u0000\u0000\u0000"+
		"\u00a9\u00aa\u0005\u0014\u0000\u0000\u00aa\u00ab\u0005\u0017\u0000\u0000"+
		"\u00ab\u00ac\u0003\u001a\r\u0000\u00ac\u00ad\u0005\u0018\u0000\u0000\u00ad"+
		"\u00ae\u0003\u000e\u0007\u0000\u00ae\u0015\u0001\u0000\u0000\u0000\u00af"+
		"\u00b0\u0005\u0013\u0000\u0000\u00b0\u00b1\u0005\u0017\u0000\u0000\u00b1"+
		"\u00b3\u0003\u000e\u0007\u0000\u00b2\u00b4\u0003\u001a\r\u0000\u00b3\u00b2"+
		"\u0001\u0000\u0000\u0000\u00b3\u00b4\u0001\u0000\u0000\u0000\u00b4\u00b5"+
		"\u0001\u0000\u0000\u0000\u00b5\u00b7\u00051\u0000\u0000\u00b6\u00b8\u0003"+
		"\u001a\r\u0000\u00b7\u00b6\u0001\u0000\u0000\u0000\u00b7\u00b8\u0001\u0000"+
		"\u0000\u0000\u00b8\u00b9\u0001\u0000\u0000\u0000\u00b9\u00ba\u0005\u0018"+
		"\u0000\u0000\u00ba\u00bb\u0003\u000e\u0007\u0000\u00bb\u0017\u0001\u0000"+
		"\u0000\u0000\u00bc\u00c3\u0007\u0000\u0000\u0000\u00bd\u00be\u0005\u0019"+
		"\u0000\u0000\u00be\u00bf\u0003\u001a\r\u0000\u00bf\u00c0\u0005\u001a\u0000"+
		"\u0000\u00c0\u00c2\u0001\u0000\u0000\u0000\u00c1\u00bd\u0001\u0000\u0000"+
		"\u0000\u00c2\u00c5\u0001\u0000\u0000\u0000\u00c3\u00c1\u0001\u0000\u0000"+
		"\u0000\u00c3\u00c4\u0001\u0000\u0000\u0000\u00c4\u00ca\u0001\u0000\u0000"+
		"\u0000\u00c5\u00c3\u0001\u0000\u0000\u0000\u00c6\u00c7\u0005\u0019\u0000"+
		"\u0000\u00c7\u00c9\u0005\u001a\u0000\u0000\u00c8\u00c6\u0001\u0000\u0000"+
		"\u0000\u00c9\u00cc\u0001\u0000\u0000\u0000\u00ca\u00c8\u0001\u0000\u0000"+
		"\u0000\u00ca\u00cb\u0001\u0000\u0000\u0000\u00cb\u00d3\u0001\u0000\u0000"+
		"\u0000\u00cc\u00ca\u0001\u0000\u0000\u0000\u00cd\u00ce\u0005\u0019\u0000"+
		"\u0000\u00ce\u00cf\u0003\u001a\r\u0000\u00cf\u00d0\u0005\u001a\u0000\u0000"+
		"\u00d0\u00d2\u0001\u0000\u0000\u0000\u00d1\u00cd\u0001\u0000\u0000\u0000"+
		"\u00d2\u00d5\u0001\u0000\u0000\u0000\u00d3\u00d1\u0001\u0000\u0000\u0000"+
		"\u00d3\u00d4\u0001\u0000\u0000\u0000\u00d4\u0019\u0001\u0000\u0000\u0000"+
		"\u00d5\u00d3\u0001\u0000\u0000\u0000\u00d6\u00d7\u0006\r\uffff\uffff\u0000"+
		"\u00d7\u00ef\u0003\u001c\u000e\u0000\u00d8\u00ef\u0005\u0002\u0000\u0000"+
		"\u00d9\u00da\u0005\u0003\u0000\u0000\u00da\u00df\u0003\u001a\r\u0000\u00db"+
		"\u00dc\u0005\u0004\u0000\u0000\u00dc\u00de\u0003\u001a\r\u0000\u00dd\u00db"+
		"\u0001\u0000\u0000\u0000\u00de\u00e1\u0001\u0000\u0000\u0000\u00df\u00dd"+
		"\u0001\u0000\u0000\u0000\u00df\u00e0\u0001\u0000\u0000\u0000\u00e0\u00e2"+
		"\u0001\u0000\u0000\u0000\u00e1\u00df\u0001\u0000\u0000\u0000\u00e2\u00e3"+
		"\u0005\u0005\u0000\u0000\u00e3\u00ef\u0001\u0000\u0000\u0000\u00e4\u00e5"+
		"\u0005=\u0000\u0000\u00e5\u00e7\u0005\u0017\u0000\u0000\u00e6\u00e8\u0003"+
		"\u0010\b\u0000\u00e7\u00e6\u0001\u0000\u0000\u0000\u00e7\u00e8\u0001\u0000"+
		"\u0000\u0000\u00e8\u00e9\u0001\u0000\u0000\u0000\u00e9\u00ef\u0005\u0018"+
		"\u0000\u0000\u00ea\u00eb\u0007\u0001\u0000\u0000\u00eb\u00ef\u0003\u001a"+
		"\r\u000e\u00ec\u00ed\u0007\u0002\u0000\u0000\u00ed\u00ef\u0003\u001a\r"+
		"\r\u00ee\u00d6\u0001\u0000\u0000\u0000\u00ee\u00d8\u0001\u0000\u0000\u0000"+
		"\u00ee\u00d9\u0001\u0000\u0000\u0000\u00ee\u00e4\u0001\u0000\u0000\u0000"+
		"\u00ee\u00ea\u0001\u0000\u0000\u0000\u00ee\u00ec\u0001\u0000\u0000\u0000"+
		"\u00ef\u012b\u0001\u0000\u0000\u0000\u00f0\u00f1\n\f\u0000\u0000\u00f1"+
		"\u00f2\u0007\u0003\u0000\u0000\u00f2\u012a\u0003\u001a\r\r\u00f3\u00f4"+
		"\n\u000b\u0000\u0000\u00f4\u00f5\u0007\u0004\u0000\u0000\u00f5\u012a\u0003"+
		"\u001a\r\f\u00f6\u00f7\n\n\u0000\u0000\u00f7\u00f8\u0007\u0005\u0000\u0000"+
		"\u00f8\u012a\u0003\u001a\r\u000b\u00f9\u00fa\n\t\u0000\u0000\u00fa\u00fb"+
		"\u0007\u0006\u0000\u0000\u00fb\u012a\u0003\u001a\r\n\u00fc\u00fd\n\b\u0000"+
		"\u0000\u00fd\u00fe\u0007\u0007\u0000\u0000\u00fe\u012a\u0003\u001a\r\t"+
		"\u00ff\u0100\n\u0007\u0000\u0000\u0100\u0101\u0005(\u0000\u0000\u0101"+
		"\u012a\u0003\u001a\r\b\u0102\u0103\n\u0006\u0000\u0000\u0103\u0104\u0005"+
		",\u0000\u0000\u0104\u012a\u0003\u001a\r\u0007\u0105\u0106\n\u0005\u0000"+
		"\u0000\u0106\u0107\u0005)\u0000\u0000\u0107\u012a\u0003\u001a\r\u0006"+
		"\u0108\u0109\n\u0004\u0000\u0000\u0109\u010a\u0005*\u0000\u0000\u010a"+
		"\u012a\u0003\u001a\r\u0005\u010b\u010c\n\u0003\u0000\u0000\u010c\u010d"+
		"\u0005+\u0000\u0000\u010d\u012a\u0003\u001a\r\u0004\u010e\u010f\n\u0002"+
		"\u0000\u0000\u010f\u0110\u0005/\u0000\u0000\u0110\u0111\u0003\u001a\r"+
		"\u0000\u0111\u0112\u00050\u0000\u0000\u0112\u0113\u0003\u001a\r\u0002"+
		"\u0113\u012a\u0001\u0000\u0000\u0000\u0114\u0115\n\u0001\u0000\u0000\u0115"+
		"\u0116\u00053\u0000\u0000\u0116\u012a\u0003\u001a\r\u0001\u0117\u0118"+
		"\n\u0012\u0000\u0000\u0118\u0119\u00058\u0000\u0000\u0119\u011a\u0005"+
		"=\u0000\u0000\u011a\u011c\u0005\u0017\u0000\u0000\u011b\u011d\u0003\u0010"+
		"\b\u0000\u011c\u011b\u0001\u0000\u0000\u0000\u011c\u011d\u0001\u0000\u0000"+
		"\u0000\u011d\u011e\u0001\u0000\u0000\u0000\u011e\u012a\u0005\u0018\u0000"+
		"\u0000\u011f\u0120\n\u0011\u0000\u0000\u0120\u012a\u0007\u0001\u0000\u0000"+
		"\u0121\u0122\n\u0010\u0000\u0000\u0122\u0123\u0005\u0019\u0000\u0000\u0123"+
		"\u0124\u0003\u001a\r\u0000\u0124\u0125\u0005\u001a\u0000\u0000\u0125\u012a"+
		"\u0001\u0000\u0000\u0000\u0126\u0127\n\u000f\u0000\u0000\u0127\u0128\u0005"+
		"8\u0000\u0000\u0128\u012a\u0005=\u0000\u0000\u0129\u00f0\u0001\u0000\u0000"+
		"\u0000\u0129\u00f3\u0001\u0000\u0000\u0000\u0129\u00f6\u0001\u0000\u0000"+
		"\u0000\u0129\u00f9\u0001\u0000\u0000\u0000\u0129\u00fc\u0001\u0000\u0000"+
		"\u0000\u0129\u00ff\u0001\u0000\u0000\u0000\u0129\u0102\u0001\u0000\u0000"+
		"\u0000\u0129\u0105\u0001\u0000\u0000\u0000\u0129\u0108\u0001\u0000\u0000"+
		"\u0000\u0129\u010b\u0001\u0000\u0000\u0000\u0129\u010e\u0001\u0000\u0000"+
		"\u0000\u0129\u0114\u0001\u0000\u0000\u0000\u0129\u0117\u0001\u0000\u0000"+
		"\u0000\u0129\u011f\u0001\u0000\u0000\u0000\u0129\u0121\u0001\u0000\u0000"+
		"\u0000\u0129\u0126\u0001\u0000\u0000\u0000\u012a\u012d\u0001\u0000\u0000"+
		"\u0000\u012b\u0129\u0001\u0000\u0000\u0000\u012b\u012c\u0001\u0000\u0000"+
		"\u0000\u012c\u001b\u0001\u0000\u0000\u0000\u012d\u012b\u0001\u0000\u0000"+
		"\u0000\u012e\u012f\u0005\u0017\u0000\u0000\u012f\u0130\u0003\u001a\r\u0000"+
		"\u0130\u0131\u0005\u0018\u0000\u0000\u0131\u0140\u0001\u0000\u0000\u0000"+
		"\u0132\u0140\u0005=\u0000\u0000\u0133\u0140\u0003\u001e\u000f\u0000\u0134"+
		"\u0140\u0005\u0012\u0000\u0000\u0135\u0136\u0005\r\u0000\u0000\u0136\u0137"+
		"\u0003\u0018\f\u0000\u0137\u0138\u0003 \u0010\u0000\u0138\u0140\u0001"+
		"\u0000\u0000\u0000\u0139\u013a\u0005\r\u0000\u0000\u013a\u013d\u0003\u0018"+
		"\f\u0000\u013b\u013c\u0005\u0017\u0000\u0000\u013c\u013e\u0005\u0018\u0000"+
		"\u0000\u013d\u013b\u0001\u0000\u0000\u0000\u013d\u013e\u0001\u0000\u0000"+
		"\u0000\u013e\u0140\u0001\u0000\u0000\u0000\u013f\u012e\u0001\u0000\u0000"+
		"\u0000\u013f\u0132\u0001\u0000\u0000\u0000\u013f\u0133\u0001\u0000\u0000"+
		"\u0000\u013f\u0134\u0001\u0000\u0000\u0000\u013f\u0135\u0001\u0000\u0000"+
		"\u0000\u013f\u0139\u0001\u0000\u0000\u0000\u0140\u001d\u0001\u0000\u0000"+
		"\u0000\u0141\u0148\u0005:\u0000\u0000\u0142\u0148\u0005<\u0000\u0000\u0143"+
		"\u0148\u0005\u0010\u0000\u0000\u0144\u0148\u0005\u0011\u0000\u0000\u0145"+
		"\u0148\u0005\u000f\u0000\u0000\u0146\u0148\u0003 \u0010\u0000\u0147\u0141"+
		"\u0001\u0000\u0000\u0000\u0147\u0142\u0001\u0000\u0000\u0000\u0147\u0143"+
		"\u0001\u0000\u0000\u0000\u0147\u0144\u0001\u0000\u0000\u0000\u0147\u0145"+
		"\u0001\u0000\u0000\u0000\u0147\u0146\u0001\u0000\u0000\u0000\u0148\u001f"+
		"\u0001\u0000\u0000\u0000\u0149\u014a\u0005\u001b\u0000\u0000\u014a\u0162"+
		"\u0005\u001c\u0000\u0000\u014b\u014c\u0005\u001b\u0000\u0000\u014c\u0151"+
		"\u0003 \u0010\u0000\u014d\u014e\u00052\u0000\u0000\u014e\u0150\u0003 "+
		"\u0010\u0000\u014f\u014d\u0001\u0000\u0000\u0000\u0150\u0153\u0001\u0000"+
		"\u0000\u0000\u0151\u014f\u0001\u0000\u0000\u0000\u0151\u0152\u0001\u0000"+
		"\u0000\u0000\u0152\u0154\u0001\u0000\u0000\u0000\u0153\u0151\u0001\u0000"+
		"\u0000\u0000\u0154\u0155\u0005\u001c\u0000\u0000\u0155\u0162\u0001\u0000"+
		"\u0000\u0000\u0156\u0157\u0005\u001b\u0000\u0000\u0157\u015c\u0003\u001e"+
		"\u000f\u0000\u0158\u0159\u00052\u0000\u0000\u0159\u015b\u0003\u001e\u000f"+
		"\u0000\u015a\u0158\u0001\u0000\u0000\u0000\u015b\u015e\u0001\u0000\u0000"+
		"\u0000\u015c\u015a\u0001\u0000\u0000\u0000\u015c\u015d\u0001\u0000\u0000"+
		"\u0000\u015d\u015f\u0001\u0000\u0000\u0000\u015e\u015c\u0001\u0000\u0000"+
		"\u0000\u015f\u0160\u0005\u001c\u0000\u0000\u0160\u0162\u0001\u0000\u0000"+
		"\u0000\u0161\u0149\u0001\u0000\u0000\u0000\u0161\u014b\u0001\u0000\u0000"+
		"\u0000\u0161\u0156\u0001\u0000\u0000\u0000\u0162!\u0001\u0000\u0000\u0000"+
		"#%\'.0ACMSWcjnq\u007f\u008f\u0096\u009d\u00a7\u00b3\u00b7\u00c3\u00ca"+
		"\u00d3\u00df\u00e7\u00ee\u011c\u0129\u012b\u013d\u013f\u0147\u0151\u015c"+
		"\u0161";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}