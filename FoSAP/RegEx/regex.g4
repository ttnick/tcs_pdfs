/** RegEx grammar */
grammar regex;

expr
	: 'a' 
	| 'b' 
	| '(' expr '+' expr ')' 
	| '(' expr '.' expr ')' 
	| expr '*'
	;

WS
	: [ \t\r\n]+ -> skip
	;
