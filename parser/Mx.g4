grammar Mx;
program: (classDef | funcDef | varDef)* main (
		classDef
		| funcDef
		| varDef
	)* EOF;
main: 'int' 'main' '(' ')' suite;

classDef:
	'class' Identifier '{' (varDef | funcDef | consDef)* '}' ';';
varDef:
	type Identifier ('=' expression)? (
		',' Identifier ('=' expression)?
	)* ';';
funcDef:
	return_type = type func_name = Identifier '(' (
		type Identifier ('=' expression)? (
			',' type Identifier ('=' expression)?
		)*
	)? ')' suite;
consDef: Identifier '('  ')' suite;

suite: '{' statement* '}';
statement:
	suite						# block
	| varDef					# vardefStmt
	| ifstmt					# ifStmt
	| whilestmt					# whileStmt
	| forstmt					# forStmt
	| Break ';'					# breakStmt
	| Continue ';'				# continueStmt
	| Return expression? ';'	# returnStmt
	| exprlist ';'				# pureExprStmt
	| ';'						# emptyExprStmt;

exprlist: expression (',' expression)*;
ifstmt:
	If '(' expression ')' trueStmt = statement (
		Else falseStmt = statement
	)?;
whilestmt: While '(' expression ')' statement;
forstmt:
	For '(' initializeStmt = expression ';' condiStmt = expression ';' stepStmt = expression ')'
		statement;

type: (Int | String | Bool | Void | Identifier) (
		'[' expression ']'
	)* ('[' ']')*;

FormatString1:
	'f"' ('\\n' | '\\\\' | '\\"' | '$$' | [ !#%-[\]-~])* '"';
FormatString2:
	'f"' ('\\n' | '\\\\' | '\\"' | '$$' | [ !#%-[\]-~])* '$';
FormatString3:
	'$' ('\\n' | '\\\\' | '\\"' | '$$' | [ !#%-[\]-~])* '$';
FormatString4:
	'$' ('\\n' | '\\\\' | '\\"' | '$$' | [ !#%-[\]-~])* '"';

expression:
	primary																	# atomExpr
	| FormatString1															# formatExpr
	| FormatString2 expression (FormatString3 expression)* FormatString4	# formatExpr
	| <assoc = right> expression (SelfPlus | SelfMinus)						# oneExpr
	| <assoc = right> (SelfPlus | SelfMinus) expression						# oneExpr
	| <assoc = right> ('!' | '~' | '-') expression							# oneExpr
	| expression op = ('*' | '/' | '%') expression							# binaryExpr
	| expression op = ('+' | '-') expression								# binaryExpr
	| expression op = ('<<' | '>>') expression								# bitExpr
	| expression op = ('<' | '<=' | '>' | '>=') expression					# compareExpr
	| expression op = ('!=' | '==') expression								# compareExpr
	| expression op = '&' expression										# bitExpr
	| expression op = '^' expression										# bitExpr
	| expression op = '|' expression										# bitExpr
	| expression op = '&&' expression										# logicExpr
	| expression op = '||' expression										# logicExpr
	| <assoc = right> expression '?' expression ':' expression				# threeExpr
	| <assoc = right> expression '=' expression								# assignExpr
	| expression '.' Identifier												# pointExpr
	| expression '(' exprlist? ')'											# usefunc
	| expression '[' expression ']'											# arrayAccessExpr;

primary:
	'(' expression ')'		# parenPrimary
	| Identifier			# indentifierPrimary
	| mxconst				# constPrimary
	| This					# thisPrimary
	| 'new' type array	# newPrimary
	| 'new' type ('(' ')')?	# newPrimary;

mxconst:
	IntegerConst	# intConst
	| StringConst	# stringConst
	| BoolConst		# boolConst
	| Null			# nullConst
	| array			# arrayConst;

array:
	'{' '}'
	| '{' array (',' array)* '}'
	| '{' mxconst (',' mxconst)* '}';

Int: 'int';
If: 'if';
Else: 'else';
Return: 'return';
Void: 'void';
Bool: 'bool';
String: 'string';
New: 'new';
Class: 'class';
Null: 'null';
True: 'true';
False: 'false';
This: 'this';
For: 'for';
While: 'while';
Break: 'break';
Continue: 'continue';

LeftParen: '(';
RightParen: ')';
LeftBracket: '[';
RightBracket: ']';
LeftBrace: '{';
RightBrace: '}';

Less: '<';
LessEqual: '<=';
Greater: '>';
GreaterEqual: '>=';
LeftShift: '<<';
RightShift: '>>';

Plus: '+';
Minus: '-';
Mul: '*';
Div: '/';
Mod: '%';

And: '&';
Or: '|';
AndAnd: '&&';
OrOr: '||';
Caret: '^';
Not: '!';
Tilde: '~';

Question: '?';
Colon: ':';
Semi: ';';
Comma: ',';

Assign: '=';
Equal: '==';
NotEqual: '!=';

SelfPlus: '++';
SelfMinus: '--';

Belong: '.';
Yinghao: '"';

IntegerConst: [1-9] [0-9]* | '0';
BoolConst: True | False;
StringConst: '"' ('\\n' | '\\\\' | '\\"' | [ !#-[\]-~])* '"';
Identifier: [a-zA-Z] [a-zA-Z_0-9]*;

Whitespace: [ \t]+ -> skip;

Newline: ( '\r' '\n'? | '\n') -> skip;

BlockComment: '/*' .*? '*/' -> skip;

LineComment: '//' ~[\r\n]* -> skip;